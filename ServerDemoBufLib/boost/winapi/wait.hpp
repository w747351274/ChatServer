/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 * Copyright 2017 James E. King, III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_WAIT_HPP_INCLUDED_
#define BOOST_WINAPI_WAIT_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
BOOST_SYMBOL_IMPORT wjl_boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForSingleObjectEx(
    wjl_boost::winapi::HANDLE_ hHandle,
    wjl_boost::winapi::DWORD_ dwMilliseconds,
    wjl_boost::winapi::BOOL_ bAlertable);
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
BOOST_SYMBOL_IMPORT wjl_boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
SignalObjectAndWait(
    wjl_boost::winapi::HANDLE_ hObjectToSignal,
    wjl_boost::winapi::HANDLE_ hObjectToWaitOn,
    wjl_boost::winapi::DWORD_ dwMilliseconds,
    wjl_boost::winapi::BOOL_ bAlertable);
#endif
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_SYMBOL_IMPORT wjl_boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForSingleObject(
    wjl_boost::winapi::HANDLE_ hHandle,
    wjl_boost::winapi::DWORD_ dwMilliseconds);

BOOST_SYMBOL_IMPORT wjl_boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForMultipleObjects(
    wjl_boost::winapi::DWORD_ nCount,
    wjl_boost::winapi::HANDLE_ const* lpHandles,
    wjl_boost::winapi::BOOL_ bWaitAll,
    wjl_boost::winapi::DWORD_ dwMilliseconds);

BOOST_SYMBOL_IMPORT wjl_boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForMultipleObjectsEx(
    wjl_boost::winapi::DWORD_ nCount,
    wjl_boost::winapi::HANDLE_ const* lpHandles,
    wjl_boost::winapi::BOOL_ bWaitAll,
    wjl_boost::winapi::DWORD_ dwMilliseconds,
    wjl_boost::winapi::BOOL_ bAlertable);
#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM

} // extern "C"
#endif

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace winapi {

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
using ::WaitForSingleObjectEx;
#endif
#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
using ::SignalObjectAndWait;
#endif
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
using ::WaitForMultipleObjects;
using ::WaitForMultipleObjectsEx;
using ::WaitForSingleObject;
#endif

#if defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ INFINITE_ = INFINITE;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_ABANDONED_ = WAIT_ABANDONED;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_OBJECT_0_ = WAIT_OBJECT_0;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_TIMEOUT_ = WAIT_TIMEOUT;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_FAILED_ = WAIT_FAILED;

#else // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ INFINITE_ = (DWORD_)0xFFFFFFFF;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_ABANDONED_ = 0x00000080L;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_OBJECT_0_ = 0x00000000L;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_TIMEOUT_ = 0x00000102L;
BOOST_CONSTEXPR_OR_CONST DWORD_ WAIT_FAILED_ = (DWORD_)0xFFFFFFFF;

#endif // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ infinite = INFINITE_;
BOOST_CONSTEXPR_OR_CONST DWORD_ wait_abandoned = WAIT_ABANDONED_;
BOOST_CONSTEXPR_OR_CONST DWORD_ wait_object_0 = WAIT_OBJECT_0_;
BOOST_CONSTEXPR_OR_CONST DWORD_ wait_timeout = WAIT_TIMEOUT_;
BOOST_CONSTEXPR_OR_CONST DWORD_ wait_failed = WAIT_FAILED_;

BOOST_CONSTEXPR_OR_CONST DWORD_ max_non_infinite_wait = (DWORD_)0xFFFFFFFE;

}
}

#endif // BOOST_WINAPI_WAIT_HPP_INCLUDED_
