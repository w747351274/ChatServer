/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_THREAD_HPP_INCLUDED_
#define BOOST_WINAPI_THREAD_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/get_current_thread.hpp>
#include <boost/winapi/get_current_thread_id.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
BOOST_SYMBOL_IMPORT wjl_boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
SleepEx(
    wjl_boost::winapi::DWORD_ dwMilliseconds,
    wjl_boost::winapi::BOOL_ bAlertable);
BOOST_SYMBOL_IMPORT wjl_boost::winapi::VOID_ BOOST_WINAPI_WINAPI_CC Sleep(wjl_boost::winapi::DWORD_ dwMilliseconds);
BOOST_SYMBOL_IMPORT wjl_boost::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC SwitchToThread(BOOST_WINAPI_DETAIL_VOID);
} // extern "C"
#endif

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace winapi {
using ::SleepEx;
using ::Sleep;
using ::SwitchToThread;
}
}

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_THREAD_HPP_INCLUDED_
