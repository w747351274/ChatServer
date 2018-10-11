//  (c) Copyright Fernando Luis Cacciola Carballal 2000-2004
//  Use, modification, and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.boost.org/libs/numeric/conversion
//
// Contact the author at: fernando_cacciola@hotmail.com
// 
#ifndef BOOST_NUMERIC_CONVERSION_CONVERSION_TRAITS_FLC_12NOV2002_HPP
#define BOOST_NUMERIC_CONVERSION_CONVERSION_TRAITS_FLC_12NOV2002_HPP

#include "boost/numeric/conversion/detail/conversion_traits.hpp"
#include "boost/detail/workaround.hpp"
#include "boost/config.hpp"

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost { namespace numeric
{

template<class T, class S>
struct conversion_traits 
    : convdetail::get_conversion_traits<T,S>::type 
{
} ;

} } // namespace wjl_boost::numeric

#endif
//
///////////////////////////////////////////////////////////////////////////////////////////////


