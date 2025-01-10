//
// Created by bgriebel on 1/8/25.
//
#include <array>

#include "plugboard.h"

Plugboard::Plugboard() {
    char start = 'a';
    for (char &wire : wires) {
        wire = start;
        start++;
    }
}

void Plugboard::add_wire(const char start, const char end) {
    const int start_idx = start - 'a';
    const int end_idx = end - 'a';
    wires.at(start_idx) = end;
    wires.at(end_idx) = start;
}

void Plugboard::remove_wire(const char start, const char end) {
    const int start_idx = start - 'a';
    const int end_idx = end - 'a';
    wires.at(start_idx) = start;
    wires.at(end_idx) = end;
}

char Plugboard::translate(const char input) const {
    const int idx = input - 'a';
    return wires.at(idx);
}

void Plugboard::clear_wires() {
    for (int idx=0; idx < 26; idx++) {
        wires.at(idx) = 'a'+idx;
    }
}


