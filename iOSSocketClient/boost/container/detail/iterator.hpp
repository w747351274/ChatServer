//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2014-2014.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_DETAIL_ITERATOR_HPP
#define BOOST_CONTAINER_DETAIL_ITERATOR_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/intrusive/detail/iterator.hpp>
#include <boost/move/utility_core.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace container {

using ::wjl_boost::intrusive::iterator_traits;
using ::wjl_boost::intrusive::iterator_distance;
using ::wjl_boost::intrusive::iterator_advance;
using ::wjl_boost::intrusive::iterator;
using ::wjl_boost::intrusive::iterator_enable_if_tag;
using ::wjl_boost::intrusive::iterator_disable_if_tag;
using ::wjl_boost::intrusive::iterator_arrow_result;

template <class Container>
class back_emplacer
{
   private:
   Container& container;

   public:
   typedef std::output_iterator_tag iterator_category;
   typedef void                     value_type;
   typedef void                     difference_type;
   typedef void                     pointer;
   typedef void                     reference;

   back_emplacer(Container& x)
      : container(x)
   {}

   template<class U>
   back_emplacer& operator=(BOOST_FWD_REF(U) value)
   {
      container.emplace_back(wjl_boost::forward<U>(value));
      return *this;
   }
   back_emplacer& operator*()    { return *this; }
   back_emplacer& operator++()   { return *this; }
   back_emplacer& operator++(int){ return *this; }
};


}  //namespace container {
}  //namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {

#endif   //#ifndef BOOST_CONTAINER_DETAIL_ITERATORS_HPP
