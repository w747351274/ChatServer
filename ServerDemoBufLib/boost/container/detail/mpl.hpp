//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2013.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_MPL_HPP
#define BOOST_CONTAINER_CONTAINER_DETAIL_MPL_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/container/detail/config_begin.hpp>
#include <boost/container/detail/workaround.hpp>
#include <boost/move/detail/type_traits.hpp>
#include <boost/intrusive/detail/mpl.hpp>

#include <cstddef>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace container {
namespace dtl {

using wjl_boost::move_detail::integral_constant;
using wjl_boost::move_detail::true_type;
using wjl_boost::move_detail::false_type;
using wjl_boost::move_detail::enable_if_c;
using wjl_boost::move_detail::enable_if;
using wjl_boost::move_detail::enable_if_convertible;
using wjl_boost::move_detail::disable_if_c;
using wjl_boost::move_detail::disable_if;
using wjl_boost::move_detail::disable_if_convertible;
using wjl_boost::move_detail::is_convertible;
using wjl_boost::move_detail::if_c;
using wjl_boost::move_detail::if_;
using wjl_boost::move_detail::identity;
using wjl_boost::move_detail::bool_;
using wjl_boost::move_detail::true_;
using wjl_boost::move_detail::false_;
using wjl_boost::move_detail::yes_type;
using wjl_boost::move_detail::no_type;
using wjl_boost::move_detail::bool_;
using wjl_boost::move_detail::true_;
using wjl_boost::move_detail::false_;
using wjl_boost::move_detail::unvoid_ref;
using wjl_boost::move_detail::and_;
using wjl_boost::move_detail::or_;
using wjl_boost::move_detail::not_;
using wjl_boost::move_detail::enable_if_and;
using wjl_boost::move_detail::disable_if_and;
using wjl_boost::move_detail::enable_if_or;
using wjl_boost::move_detail::disable_if_or;

template <class FirstType>
struct select1st
{
   typedef FirstType type;

   template<class T>
   const type& operator()(const T& x) const
   {  return x.first;   }

   template<class T>
   type& operator()(T& x)
   {  return const_cast<type&>(x.first);   }
};

template <class T, class=void>
struct is_transparent
{
   static const bool value = false;
};

template <class T>
struct is_transparent<T, typename T::is_transparent>
{
   static const bool value = true;
};

template <typename C, typename K, typename R>
struct enable_if_transparent
   : wjl_boost::move_detail::enable_if_c<dtl::is_transparent<C>::value, R>
{};


}  //namespace dtl {
}  //namespace container {
}  //namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {

#include <boost/container/detail/config_end.hpp>

#endif   //#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_MPL_HPP
