
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, 
//      Howard Hinnant and John Maddock 2000, 2010. 
//  (C) Copyright Mat Marcus, Jesse Jones and Adobe Systems Inc 2001

//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_REFERENCE_HPP_INCLUDED
#define BOOST_TT_IS_REFERENCE_HPP_INCLUDED

#include <boost/type_traits/is_lvalue_reference.hpp>
#include <boost/type_traits/is_rvalue_reference.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {

template <class T> struct is_reference 
   : public 
   integral_constant<
      bool, 
      ::wjl_boost::is_lvalue_reference<T>::value || ::wjl_boost::is_rvalue_reference<T>::value>
{};

} // namespace wjl_boost

#endif // BOOST_TT_IS_REFERENCE_HPP_INCLUDED

