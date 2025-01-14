#include "catch2/catch_test_macros.hpp"

#include "rotor.h"

TEST_CASE("Test Translation", "[rotor]") {
    // Check that constructor doesn't throw error
    REQUIRE_NOTHROW([](){auto default_rotor = Rotor {1};});
    // Actually create the object to test
    auto test_rotor = Rotor{1};
    test_rotor.set_offset(0);
    // Test forward translate
    CHECK(test_rotor.translate_forward('u')=='a');
    CHECK(test_rotor.translate_forward('a')=='e');
    // Test reverse translate
    CHECK(test_rotor.translate_reverse('e')=='a');
    CHECK(test_rotor.translate_reverse('o')=='m');
    // Test the identity rotor
    auto identity_rotor = Rotor{"abcdefghijklmnopqrstuvwxyz", "a"};
    // Check that characters translate to themselves
    for (char test_char = 'a'; test_char <= 'z'; ++test_char) {
        CHECK(identity_rotor.translate_forward(test_char)==test_char);
        CHECK(identity_rotor.translate_reverse(test_char)==test_char);
    }
}

TEST_CASE("Test Stepping Rotors", "[rotor]") {
    // Create the test rotor
    auto test_rotor = Rotor{1};
    test_rotor.set_offset(0);
    // Check translation
    CHECK(test_rotor.translate_forward('a')=='e');
    CHECK(test_rotor.translate_forward('b')=='k');
    CHECK(test_rotor.translate_forward('k')=='n');
    // Reverse Translate
    CHECK(test_rotor.translate_reverse('t')=='l');
    // Step the rotor
    test_rotor.advance();
    CHECK(test_rotor.translate_forward('a')=='j');
}
