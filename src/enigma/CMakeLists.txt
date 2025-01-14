add_library(enigma
    machine.cpp
    machine.h
    math_helper.cpp
    math_helper.h
    plugboard.cpp
    plugboard.h
    reflector.cpp
    reflector.h
    rotor.cpp
    rotor.h
)

target_include_directories(enigma PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})