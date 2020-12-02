#include "catch.hpp"
#include <tnet/listener.hpp>

TEST_CASE("listen", "tnet"){
    auto listener = tnet::listener(tnet::protocol::tcp{}, 7543);
    auto retcode = listener.listen();
    REQUIRE(!retcode);
    auto listener2 = tnet::listener(tnet::protocol::udp{}, 7543);
    retcode = listener.listen();
    REQUIRE(!retcode);
}