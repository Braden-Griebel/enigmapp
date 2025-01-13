#include <fstream>
#include <iostream>
#include <optional>

#include <CLI/CLI.hpp>

#include "build/_deps/catch2-src/src/catch2/internal/catch_stdstreams.hpp"
#include "machine.h"

int main(const int argc, char **argv) {
    CLI::App app{"Enigma++"};
    argv = app.ensure_utf8(argv);

    // Set up the options
    // Positional option for file input
    std::optional<std::string> in_file;
    app.add_option("file", in_file,
                   "Path to file to translate, will read from stdin if not provided");
    // Rotors to use,
    std::vector<int> rotor_selection = {1,2,3};
    app.add_option("-r,--rotors", rotor_selection,
                   "Choose rotors to use by number (1-8)");
    // Reflector to use
    char reflector = 'a';
    app.add_option("-f,--reflector", reflector,
                   "Choose reflector to use by letter (a,b, or c)");
    // Setting for the rotors and the reflector
    std::string machine_setting = "abcd";
    app.add_option("-m,--machine", machine_setting,
                   "Specify setting for rotors and reflector, "
                   "should be 4 characters (the first 3 describing rotor settings, "
                   "the last describing reflector setting) e.g. agsd");
    // Plugboard setting
    std::string plugboard_setting;
    app.add_option("-p,--plugboard", plugboard_setting,
                   "Wires to connect on the plugboard, specified by <start>-<end>,... e.g. a-c,d-z");
    // Parse the command line input
    CLI11_PARSE(app, argc, argv);

    // If a file was provided read that into input, otherwise try to read form stdin
    std::string input_string;
    std::string file_buffer;
    if (in_file.has_value()) {
        std::ifstream input_file_stream {in_file.value()};

        while (std::getline(input_file_stream, file_buffer)) {
            input_string += file_buffer;
            input_string.push_back('\n');
        }
    } else {
        while (std::getline(std::cin, file_buffer)) {
            input_string += file_buffer;
        }
    }

    // Set up the enigma machine
    if (rotor_selection.size() != 3) {
        std::cerr << "Must select exactly 3 or 0 rotors, but " << rotor_selection.size()<< " rotors were selected" << std::endl;
        return EXIT_FAILURE;
    }
    auto machine = Machine {rotor_selection[0], rotor_selection[1], rotor_selection[2], reflector};
    if (machine_setting.length() != 4) {
        std::cerr << "Machine setting must contain exactly 4 characters, but "<< machine_setting.length() << " characters were provided" << std::endl;
        return EXIT_FAILURE;
    }
    machine.set_rotors(machine_setting.at(0), machine_setting.at(1), machine_setting.at(2));
    machine.set_reflector(machine_setting.at(3));
    machine.set_plugboard(plugboard_setting);
    // Now translate the desired input
    std::string output_string = machine.translate(input_string);
    // Print the result to stdout
    std::cout << output_string << std::endl;
    return EXIT_SUCCESS;
}
