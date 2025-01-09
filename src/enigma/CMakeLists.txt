add_library(enigma
    machine.cpp
    plugboard.cpp
    reflector.cpp
    rotor.cpp
)

target_include_directories(enigma PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})