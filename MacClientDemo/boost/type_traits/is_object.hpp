
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_OBJECT_HPP_INCLUDED
#define BOOST_TT_IS_OBJECT_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/is_function.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {

template <class T> struct is_object
   : public 
      integral_constant<
         bool, 
         ! ::wjl_boost::is_reference<T>::value && ! ::wjl_boost::is_void<T>::value && ! ::wjl_boost::is_function<T>::value > 
{};

} // namespace wjl_boost

#endif // BOOST_TT_IS_OBJECT_HPP_INCLUDED
