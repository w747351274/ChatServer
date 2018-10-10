//
// detail/type_traits.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_DETAIL_TYPE_TRAITS_HPP
#define BOOST_ASIO_DETAIL_TYPE_TRAITS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)
# include <type_traits>
#else // defined(BOOST_ASIO_HAS_TYPE_TRAITS)
# include <boost/type_traits/add_const.hpp>
# include <boost/type_traits/conditional.hpp>
# include <boost/type_traits/decay.hpp>
# include <boost/type_traits/integral_constant.hpp>
# include <boost/type_traits/is_base_of.hpp>
# include <boost/type_traits/is_class.hpp>
# include <boost/type_traits/is_const.hpp>
# include <boost/type_traits/is_convertible.hpp>
# include <boost/type_traits/is_function.hpp>
# include <boost/type_traits/is_same.hpp>
# include <boost/type_traits/remove_pointer.hpp>
# include <boost/type_traits/remove_reference.hpp>
# include <boost/utility/enable_if.hpp>
# include <boost/utility/result_of.hpp>
#endif // defined(BOOST_ASIO_HAS_TYPE_TRAITS)

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace asio {

#if defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)
using std::add_const;
using std::conditional;
using std::decay;
using std::enable_if;
using std::false_type;
using std::integral_constant;
using std::is_base_of;
using std::is_class;
using std::is_const;
using std::is_convertible;
using std::is_function;
using std::is_same;
using std::remove_pointer;
using std::remove_reference;
#if defined(BOOST_ASIO_HAS_STD_INVOKE_RESULT)
template <typename> struct result_of;
template <typename F, typename... Args>
struct result_of<F(Args...)> : std::invoke_result<F, Args...> {};
#else // defined(BOOST_ASIO_HAS_STD_INVOKE_RESULT)
using std::result_of;
#endif // defined(BOOST_ASIO_HAS_STD_INVOKE_RESULT)
using std::true_type;
#else // defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)
using wjl_boost::add_const;
template <bool Condition, typename Type = void>
struct enable_if : wjl_boost::enable_if_c<Condition, Type> {};
using wjl_boost::conditional;
using wjl_boost::decay;
using wjl_boost::false_type;
using wjl_boost::integral_constant;
using wjl_boost::is_base_of;
using wjl_boost::is_class;
using wjl_boost::is_const;
using wjl_boost::is_convertible;
using wjl_boost::is_function;
using wjl_boost::is_same;
using wjl_boost::remove_pointer;
using wjl_boost::remove_reference;
using wjl_boost::result_of;
using wjl_boost::true_type;
#endif // defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)

} // namespace asio
} // namespace wjl_boost

#endif // BOOST_ASIO_DETAIL_TYPE_TRAITS_HPP
