/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2014-2014
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTRUSIVE_DETAIL_REVERSE_ITERATOR_HPP
#define BOOST_INTRUSIVE_DETAIL_REVERSE_ITERATOR_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/intrusive/detail/config_begin.hpp>
#include <boost/intrusive/detail/iterator.hpp>
#include <boost/intrusive/detail/mpl.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace intrusive {

template<class It>
class reverse_iterator
{
   public:
   typedef typename wjl_boost::intrusive::iterator_traits<It>::pointer             pointer;
   typedef typename wjl_boost::intrusive::iterator_traits<It>::reference           reference;
   typedef typename wjl_boost::intrusive::iterator_traits<It>::difference_type     difference_type;
   typedef typename wjl_boost::intrusive::iterator_traits<It>::iterator_category   iterator_category;
   typedef typename wjl_boost::intrusive::iterator_traits<It>::value_type          value_type;


   typedef It iterator_type;

   reverse_iterator()
      : m_current()  //Value initialization to achieve "null iterators" (N3644)
   {}

   explicit reverse_iterator(It r)
      : m_current(r)
   {}

   reverse_iterator(const reverse_iterator& r)
      : m_current(r.base())
   {}

   template<class OtherIt>
   reverse_iterator( const reverse_iterator<OtherIt>& r
                   , typename wjl_boost::intrusive::detail::enable_if_convertible<OtherIt, It>::type* =0
                   )
      : m_current(r.base())
   {}

   reverse_iterator & operator=( const reverse_iterator& r)
   {  m_current = r.base();   return *this;  }

   template<class OtherIt>
   typename wjl_boost::intrusive::detail::enable_if_convertible<OtherIt, It, reverse_iterator &>::type
         operator=( const reverse_iterator<OtherIt>& r)
   {  m_current = r.base();   return *this;  }

   It base() const
   {  return m_current;  }

   reference operator*() const
   {
      It temp(m_current);
      --temp;
      reference r = *temp;
      return r;
   }

   pointer operator->() const
   {
      It temp(m_current);
      --temp;
      return iterator_arrow_result(temp);
   }

   reference operator[](difference_type off) const
   {
      return this->m_current[-off - 1];
   }

   reverse_iterator& operator++()
   {
      --m_current;
      return *this;
   }

   reverse_iterator operator++(int)
   {
      reverse_iterator temp((*this));
      --m_current;
      return temp;
   }

   reverse_iterator& operator--()
   {
      ++m_current;
      return *this;
   }

   reverse_iterator operator--(int)
   {
      reverse_iterator temp((*this));
      ++m_current;
      return temp;
   }

   friend bool operator==(const reverse_iterator& l, const reverse_iterator& r)
   {  return l.m_current == r.m_current;  }

   friend bool operator!=(const reverse_iterator& l, const reverse_iterator& r)
   {  return l.m_current != r.m_current;  }

   friend bool operator<(const reverse_iterator& l, const reverse_iterator& r)
   {  return l.m_current > r.m_current;  }

   friend bool operator<=(const reverse_iterator& l, const reverse_iterator& r)
   {  return l.m_current >= r.m_current;  }

   friend bool operator>(const reverse_iterator& l, const reverse_iterator& r)
   {  return l.m_current < r.m_current;  }

   friend bool operator>=(const reverse_iterator& l, const reverse_iterator& r)
   {  return l.m_current <= r.m_current;  }

   reverse_iterator& operator+=(difference_type off)
   {  m_current -= off; return *this;  }

   reverse_iterator& operator-=(difference_type off)
   {  m_current += off; return *this;  }

   friend reverse_iterator operator+(reverse_iterator l, difference_type off)
   {  return (l += off);  }

   friend reverse_iterator operator+(difference_type off, reverse_iterator r)
   {  return (r += off);   }

   friend reverse_iterator operator-(reverse_iterator l, difference_type off)
   {  return (l-= off);  }

   friend difference_type operator-(const reverse_iterator& l, const reverse_iterator& r)
   {  return r.m_current - l.m_current;  }

   private:
   It m_current;   // the wrapped iterator
};

} //namespace intrusive {
} //namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {

#include <boost/intrusive/detail/config_end.hpp>

#endif //BOOST_INTRUSIVE_DETAIL_REVERSE_ITERATOR_HPP
