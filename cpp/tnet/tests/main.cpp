#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <sstream>

#include "catch.hpp"

#include <tnet/tnet.hpp>

TEST_CASE("tnet", "super_great"){
    REQUIRE(tnet::super_great() == 32);
}