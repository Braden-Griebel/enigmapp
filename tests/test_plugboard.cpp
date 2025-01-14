//
// Created by bgriebel on 1/8/25.
//

#include "catch2/catch_test_macros.hpp"

#include "plugboard.h"

TEST_CASE("Plugboard Testing", "[plugboard]") {
    auto plugboard = Plugboard {};
    // Start by testing that all characters initially translate to themselves
    for (auto c = 'a'; (c <= 'z'); c++) {
        CHECK(plugboard.translate(c)==c);
    }
    // Add some wires, from b<->d, s<->q, m<->p
    plugboard.add_wire('b','d');
    plugboard.add_wire('s','q');
    plugboard.add_wire('m','p');
    // Check that the wires were added
    CHECK(plugboard.translate('b')=='d');
    CHECK(plugboard.translate('s')=='q');
    CHECK(plugboard.translate('m')=='p');
    // Check that the wires were symetrical
    CHECK(plugboard.translate('d')=='b');
    CHECK(plugboard.translate('q')=='s');
    CHECK(plugboard.translate('p')=='m');
    // Remove one of the wires
    plugboard.remove_wire('b', 'd');
    // Check that the wire was removes
    CHECK(plugboard.translate('b')=='b');
    CHECK(plugboard.translate('d')=='d');
    // Make sure it didn't impact the other translations
    CHECK(plugboard.translate('q')=='s');
    // Clear all the wires
    plugboard.clear_wires();
    // Make sure wires were correctly cleared
    for (auto c = 'a'; (c <= 'z'); c++) {
        CHECK(plugboard.translate(c)==c);
    }

}
