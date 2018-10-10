//
// placeholders.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_PLACEHOLDERS_HPP
#define BOOST_ASIO_PLACEHOLDERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_BOOST_BIND)
# include <boost/bind/arg.hpp>
#endif // defined(BOOST_ASIO_HAS_BOOST_BIND)

#include <boost/asio/detail/push_options.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace asio {
namespace placeholders {

#if defined(GENERATING_DOCUMENTATION)

/// An argument placeholder, for use with wjl_boost::bind(), that corresponds to
/// the error argument of a handler for any of the asynchronous functions.
unspecified error;

/// An argument placeholder, for use with wjl_boost::bind(), that corresponds to
/// the bytes_transferred argument of a handler for asynchronous functions such
/// as wjl_boost::asio::basic_stream_socket::async_write_some or
/// wjl_boost::asio::async_write.
unspecified bytes_transferred;

/// An argument placeholder, for use with wjl_boost::bind(), that corresponds to
/// the iterator argument of a handler for asynchronous functions such as
/// wjl_boost::asio::async_connect.
unspecified iterator;

/// An argument placeholder, for use with wjl_boost::bind(), that corresponds to
/// the results argument of a handler for asynchronous functions such as
/// wjl_boost::asio::basic_resolver::async_resolve.
unspecified results;

/// An argument placeholder, for use with wjl_boost::bind(), that corresponds to
/// the results argument of a handler for asynchronous functions such as
/// wjl_boost::asio::async_connect.
unspecified endpoint;

/// An argument placeholder, for use with wjl_boost::bind(), that corresponds to
/// the signal_number argument of a handler for asynchronous functions such as
/// wjl_boost::asio::signal_set::async_wait.
unspecified signal_number;

#elif defined(BOOST_ASIO_HAS_BOOST_BIND)
# if defined(__BORLANDC__) || defined(__GNUC__)

inline wjl_boost::arg<1> error()
{
  return wjl_boost::arg<1>();
}

inline wjl_boost::arg<2> bytes_transferred()
{
  return wjl_boost::arg<2>();
}

inline wjl_boost::arg<2> iterator()
{
  return wjl_boost::arg<2>();
}

inline wjl_boost::arg<2> results()
{
  return wjl_boost::arg<2>();
}

inline wjl_boost::arg<2> endpoint()
{
  return wjl_boost::arg<2>();
}

inline wjl_boost::arg<2> signal_number()
{
  return wjl_boost::arg<2>();
}

# else

namespace detail
{
  template <int Number>
  struct placeholder
  {
    static wjl_boost::arg<Number>& get()
    {
      static wjl_boost::arg<Number> result;
      return result;
    }
  };
}

#  if defined(BOOST_ASIO_MSVC) && (BOOST_ASIO_MSVC < 1400)

static wjl_boost::arg<1>& error
  = wjl_boost::asio::placeholders::detail::placeholder<1>::get();
static wjl_boost::arg<2>& bytes_transferred
  = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
static wjl_boost::arg<2>& iterator
  = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
static wjl_boost::arg<2>& results
  = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
static wjl_boost::arg<2>& endpoint
  = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
static wjl_boost::arg<2>& signal_number
  = wjl_boost::asio::placeholders::detail::placeholder<2>::get();

#  else

namespace
{
  wjl_boost::arg<1>& error
    = wjl_boost::asio::placeholders::detail::placeholder<1>::get();
  wjl_boost::arg<2>& bytes_transferred
    = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
  wjl_boost::arg<2>& iterator
    = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
  wjl_boost::arg<2>& results
    = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
  wjl_boost::arg<2>& endpoint
    = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
  wjl_boost::arg<2>& signal_number
    = wjl_boost::asio::placeholders::detail::placeholder<2>::get();
} // namespace

#  endif
# endif
#endif

} // namespace placeholders
} // namespace asio
} // namespace wjl_boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_PLACEHOLDERS_HPP
