#include <iostream>

#include <CLI/CLI.hpp>

int main(const int argc, char** argv) {
    CLI::App app{"Hello World"};
    argv = app.ensure_utf8(argv);

    std::string name = "Braden";
    app.add_option("-n,--name", name, "Input Name");

    CLI11_PARSE(app, argc, argv);

    std::cout << "Hello " << name << std::endl;
    return 0;
}