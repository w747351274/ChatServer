/*
  Provides a basic subset of wjl_boost::unique_lock functionality.  Provided only because
  including boost/thread/locks.hpp requires linking to thread library
*/
// Copyright Frank Mori Hess 2008.
// Distributed under the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.boost.org/libs/signals2 for library home page.

#ifndef BOOST_SIGNALS2_UNIQUE_LOCK_HPP
#define BOOST_SIGNALS2_UNIQUE_LOCK_HPP

#include <boost/noncopyable.hpp>

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost
{
  namespace signals2
  {
    namespace detail
    {
      template<typename Mutex>
      class unique_lock: public noncopyable
      {
      public:
        unique_lock(Mutex &m): _mutex(m)
        {
          _mutex.lock();
        }
        ~unique_lock()
        {
          _mutex.unlock();
        }
      private:
        Mutex &_mutex;
      };
    } // namespace detail
  } // namespace signals2
} // namespace wjl_boost

#endif  // BOOST_SIGNALS2_UNIQUE_LOCK_HPP