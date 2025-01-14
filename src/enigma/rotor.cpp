//
// Created by bgriebel on 1/8/25.
//

#include "rotor.h"

// region constructor
Rotor::Rotor(const std::string& wheel_config, const std::string& notch_config) {
    int idx = 0;
    for (char c : wheel_config) {
        c = std::tolower(c);
        rotor_array_forward[idx] = c;
        rotor_array_reverse[c-'a'] = 'a'+idx;
        idx++;
    }
    for (char c : notch_config) {
        notches.insert(c);
    }
    offset = 0;
}
// endregion constructor

// region main functions
bool Rotor::advance() {
    const char prev = 'a' + offset;
    offset = (offset+1)%26;
    if (notches.count(prev)) {
        return true;
    }
    return false;
}

void Rotor::set_offset(const int offset_setting) {
    offset = offset_setting;
}


char Rotor::translate_forward(const char char_in) const {
    return 'a' + WrappedMath::subtract(rotor_array_forward[WrappedMath::add(char_in - 'a', offset, 26)] - 'a',offset,26);
}

char Rotor::translate_reverse(const char char_in) const {
    return 'a' + WrappedMath::subtract(rotor_array_reverse[WrappedMath::add(char_in - 'a', offset, 26)] - 'a',offset,26);
}
// endregion main functions

std::string Rotor::wheel_config_from_wheel_number(int wheel_number) {
    switch (wheel_number) {
        case 1:
            return "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        case 2:
            return "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        case 3:
            return "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        case 4:
            return "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        case 5:
            return "VZBRGITYUPSDNHLXAWMJQOFECK";
        case 6:
            return "JPGVOUMFYQBENHZRDKASXLICTW";
        case 7:
            return "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        case 8:
            return "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        default:
            return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
}

std::string Rotor::wheel_notches_from_wheel_number(int wheel_number) {
    switch (wheel_number) {
        case 1:
            return "Q";
        case 2:
            return "E";
        case 3:
            return "V";
        case 4:
            return "J";
        case 5:
            return "Z";
        case 6:
        case 7:
        case 8:
            return "ZM";
        default:
            return "A";
    }
}

