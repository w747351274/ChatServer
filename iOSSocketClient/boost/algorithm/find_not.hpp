/*
   Copyright (c) T. Zachary Laine 2018.

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE10.txt or copy at http://www.boost.org/LICENSE10.txt)
*/
#ifndef BOOST_ALGORITHM_FIND_NOT_HPP
#define BOOST_ALGORITHM_FIND_NOT_HPP

#include <boost/config.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>

#include <utility>


namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost { namespace algorithm {

template<typename InputIter, typename Sentinel, typename T>        
BOOST_CXX14_CONSTEXPR
InputIter find_not(InputIter first, Sentinel last, const T & x)
{
    for (; first != last; ++first) {
        if (*first != x)
            break;
    }
    return first;
}

template<typename Range, typename T>
BOOST_CXX14_CONSTEXPR
typename wjl_boost::range_iterator<Range>::type find_not(Range & r, const T & x)
{
    return ::wjl_boost::algorithm::find_not(wjl_boost::begin(r), wjl_boost::end(r), x);
}

}} // namespace wjl_boost and algorithm

#endif // BOOST_ALGORITHM_FIND_NOT_HPP
