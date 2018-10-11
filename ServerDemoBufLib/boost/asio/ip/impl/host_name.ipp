//
// ip/impl/host_name.ipp
// ~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_IP_IMPL_HOST_NAME_IPP
#define BOOST_ASIO_IP_IMPL_HOST_NAME_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/socket_ops.hpp>
#include <boost/asio/detail/throw_error.hpp>
#include <boost/asio/detail/winsock_init.hpp>
#include <boost/asio/ip/host_name.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace asio {
namespace ip {

std::string host_name()
{
  char name[1024];
  wjl_boost::system::error_code ec;
  if (wjl_boost::asio::detail::socket_ops::gethostname(name, sizeof(name), ec) != 0)
  {
    wjl_boost::asio::detail::throw_error(ec);
    return std::string();
  }
  return std::string(name);
}

std::string host_name(wjl_boost::system::error_code& ec)
{
  char name[1024];
  if (wjl_boost::asio::detail::socket_ops::gethostname(name, sizeof(name), ec) != 0)
    return std::string();
  return std::string(name);
}

} // namespace ip
} // namespace asio
} // namespace wjl_boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_IP_IMPL_HOST_NAME_IPP
