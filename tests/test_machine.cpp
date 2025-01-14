#include "catch2/catch_test_macros.hpp"

#include "machine.h"

TEST_CASE("Test Enigma Translation", "[machine]") {
    auto test_encoder = Machine{1,2,3,'b'};
    auto test_decoder = Machine{1,2,3,'b'};
    auto encoded = test_encoder.translate("aaaa");
    auto decoded = test_decoder.translate(encoded);
    CHECK_FALSE(encoded == decoded);
    CHECK_FALSE(encoded == "aaaa");
    CHECK("aaaa" == decoded);
    CHECK("nqxh" == encoded);
}

TEST_CASE("Test Enigma Plugboard", "[machine]") {
    auto test_encoder = Machine{1,2,3,'c'};
    test_encoder.set_plugboard("a-e,b-c,x-z,m-n");
    Machine test_decoder = test_encoder; // Clone hopefully

    auto encoded = test_encoder.translate("this is a coded message");
    auto decoded = test_decoder.translate(encoded);

    CHECK_FALSE(encoded == "this is a coded message");
    CHECK(decoded == "this is a coded message");
}

TEST_CASE("Test Long Translation", "[machine]") {
    auto test_encoder = Machine{1,2,3,'b'};
    test_encoder.set_plugboard("d-r,g-m,k-o,t-y");
    Machine test_decoder = test_encoder;

    auto to_encode = "this is a long message that will be encoded. woot.";

    auto encoded = test_encoder.translate(to_encode);
    auto decoded = test_decoder.translate(encoded);

    CHECK_FALSE(to_encode == encoded);
    CHECK(to_encode==encoded);
}