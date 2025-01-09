add_executable(tests
    test_machine.cpp
    test_plugboard.cpp
    test_reflector.cpp
    test_rotor.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)