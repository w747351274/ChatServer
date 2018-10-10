//
// detail/cstdint.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_DETAIL_CSTDINT_HPP
#define BOOST_ASIO_DETAIL_CSTDINT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_CSTDINT)
# include <cstdint>
#else // defined(BOOST_ASIO_HAS_CSTDINT)
# include <boost/cstdint.hpp>
#endif // defined(BOOST_ASIO_HAS_CSTDINT)

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace asio {

#if defined(BOOST_ASIO_HAS_CSTDINT)
using std::int16_t;
using std::int_least16_t;
using std::uint16_t;
using std::uint_least16_t;
using std::int32_t;
using std::int_least32_t;
using std::uint32_t;
using std::uint_least32_t;
using std::int64_t;
using std::int_least64_t;
using std::uint64_t;
using std::uint_least64_t;
using std::uintmax_t;
#else // defined(BOOST_ASIO_HAS_CSTDINT)
using wjl_boost::int16_t;
using wjl_boost::int_least16_t;
using wjl_boost::uint16_t;
using wjl_boost::uint_least16_t;
using wjl_boost::int32_t;
using wjl_boost::int_least32_t;
using wjl_boost::uint32_t;
using wjl_boost::uint_least32_t;
using wjl_boost::int64_t;
using wjl_boost::int_least64_t;
using wjl_boost::uint64_t;
using wjl_boost::uint_least64_t;
using wjl_boost::uintmax_t;
#endif // defined(BOOST_ASIO_HAS_CSTDINT)

} // namespace asio
} // namespace wjl_boost

#endif // BOOST_ASIO_DETAIL_CSTDINT_HPP
