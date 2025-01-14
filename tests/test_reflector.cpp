#include "catch2/catch_test_macros.hpp"

#include "reflector.h"

bool test_loop(const Reflector& reflector) {
    auto passed = true;
    for (auto test_char = 'a'; test_char <= 'z'; ++test_char) {
        if(reflector.translate(reflector.translate(test_char))!=test_char) passed = false;
    }
    return passed;
};

TEST_CASE("Test Reflector Translation", "[reflector]") {
    auto test_reflector = Reflector {'a'};
    test_reflector.set_offset(0);
    CHECK(test_reflector.translate('a')=='e');
}

TEST_CASE("Test Configurations", "[reflector]") {
    CHECK(test_loop(Reflector {'a'}));
    CHECK(test_loop(Reflector {'b'}));
    CHECK(test_loop(Reflector {'c'}));
}