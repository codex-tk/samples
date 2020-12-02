#ifndef __tnet_listener_h__
#define __tnet_listener_h__

#include <iostream>

namespace tnet{
    namespace protocol{
        struct tcp{
            using port_type = std::uint16_t;
        };
        struct udp{
            using port_type = std::uint16_t;
        };
    }

    class null_listener{};
    class tcp_listener{
    public:
        tcp_listener( const protocol::tcp::port_type port){
            std::cout << "Tcp listener : " << port << std::endl;
        }

        std::error_code listen(void){
            return std::error_code{};
        }
    };
    class udp_listener{
    public:
        udp_listener( const protocol::tcp::port_type port){
            std::cout << "Udp listener : " << port << std::endl;
        }
        std::error_code listen(void){
            return std::error_code{};
        }
    };

    template <typename T>
    constexpr auto listener(const T&, const typename T::port_type& port){
        if constexpr( std::is_same_v<T, protocol::tcp>)
            return tcp_listener{port};
        else
            return udp_listener{port};
    }
}

#endif