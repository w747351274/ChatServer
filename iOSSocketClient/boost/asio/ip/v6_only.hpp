//
// ip/v6_only.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_IP_V6_ONLY_HPP
#define BOOST_ASIO_IP_V6_ONLY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/socket_option.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace asio {
namespace ip {

/// Socket option for determining whether an IPv6 socket supports IPv6
/// communication only.
/**
 * Implements the IPPROTO_IPV6/IP_V6ONLY socket option.
 *
 * @par Examples
 * Setting the option:
 * @code
 * wjl_boost::asio::ip::tcp::socket socket(io_context); 
 * ...
 * wjl_boost::asio::ip::v6_only option(true);
 * socket.set_option(option);
 * @endcode
 *
 * @par
 * Getting the current option value:
 * @code
 * wjl_boost::asio::ip::tcp::socket socket(io_context); 
 * ...
 * wjl_boost::asio::ip::v6_only option;
 * socket.get_option(option);
 * bool v6_only = option.value();
 * @endcode
 *
 * @par Concepts:
 * GettableSocketOption, SettableSocketOption.
 */
#if defined(GENERATING_DOCUMENTATION)
typedef implementation_defined v6_only;
#elif defined(IPV6_V6ONLY)
typedef wjl_boost::asio::detail::socket_option::boolean<
    IPPROTO_IPV6, IPV6_V6ONLY> v6_only;
#else
typedef wjl_boost::asio::detail::socket_option::boolean<
    wjl_boost::asio::detail::custom_socket_option_level,
    wjl_boost::asio::detail::always_fail_option> v6_only;
#endif

} // namespace ip
} // namespace asio
} // namespace wjl_boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_IP_V6_ONLY_HPP
