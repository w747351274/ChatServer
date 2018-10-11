//  boost process_timer.cpp  -----------------------------------------------------------//

//  Copyright Beman Dawes 1994, 2006, 2008
//  Copyright 2009-2010 Vicente J. Botet Escriba
//  Copyright (c) Microsoft Corporation 2014

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See http://www.boost.org/libs/chrono for documentation.

//--------------------------------------------------------------------------------------//
#ifndef BOOST_CHRONO_DETAIL_INLINED_WIN_PROCESS_CLOCK_HPP
#define BOOST_CHRONO_DETAIL_INLINED_WIN_PROCESS_CLOCK_HPP

#include <boost/chrono/config.hpp>
#include <boost/chrono/process_cpu_clocks.hpp>
#include <cassert>
#include <time.h>
#include <boost/assert.hpp>

#include <boost/detail/winapi/get_last_error.hpp>
#include <boost/detail/winapi/get_current_process.hpp>
#if BOOST_PLAT_WINDOWS_DESKTOP
#include <boost/detail/winapi/get_process_times.hpp>
#endif

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost
{
namespace chrono
{

process_real_cpu_clock::time_point process_real_cpu_clock::now() BOOST_NOEXCEPT
{
    clock_t c = ::clock();
    if ( c == clock_t(-1) ) // error
    {
      BOOST_ASSERT(0 && "Boost::Chrono - Internal Error");
    }
    typedef ratio_divide<giga, ratio<CLOCKS_PER_SEC> >::type R;
    return time_point(
      duration(static_cast<rep>(c)*R::num/R::den)
    );
}

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
process_real_cpu_clock::time_point process_real_cpu_clock::now(
        system::error_code & ec)
{
    clock_t c = ::clock();
    if ( c == clock_t(-1) ) // error
    {
            wjl_boost::throw_exception(
                    system::system_error(
                            errno,
                            BOOST_CHRONO_SYSTEM_CATEGORY,
                            "chrono::process_real_cpu_clock" ));
    }
    if (!BOOST_CHRONO_IS_THROWS(ec))
    {
      ec.clear();
    }
    typedef ratio_divide<giga, ratio<CLOCKS_PER_SEC> >::type R;
    return time_point(
      duration(static_cast<rep>(c)*R::num/R::den)
    );
}
#endif

#if BOOST_PLAT_WINDOWS_DESKTOP
process_user_cpu_clock::time_point process_user_cpu_clock::now() BOOST_NOEXCEPT
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    wjl_boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( wjl_boost::detail::winapi::GetProcessTimes(
            wjl_boost::detail::winapi::GetCurrentProcess(), &creation, &exit,
            &system_time, &user_time ) )
    {
        return time_point(duration(
                ((static_cast<process_user_cpu_clock::rep>(user_time.dwHighDateTime) << 32)
                  | user_time.dwLowDateTime) * 100
                ));
    }
    else
    {
        BOOST_ASSERT(0 && "Boost::Chrono - Internal Error");
        return time_point();
    }

}

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
process_user_cpu_clock::time_point process_user_cpu_clock::now(
        system::error_code & ec)
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    wjl_boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( wjl_boost::detail::winapi::GetProcessTimes(
            wjl_boost::detail::winapi::GetCurrentProcess(), &creation, &exit,
            &system_time, &user_time ) )
    {
        if (!BOOST_CHRONO_IS_THROWS(ec))
        {
            ec.clear();
        }
        return time_point(duration(
                ((static_cast<process_user_cpu_clock::rep>(user_time.dwHighDateTime) << 32)
                  | user_time.dwLowDateTime) * 100
                ));
    }
    else
    {
        wjl_boost::detail::winapi::DWORD_ cause = wjl_boost::detail::winapi::GetLastError();
        if (BOOST_CHRONO_IS_THROWS(ec))
        {
            wjl_boost::throw_exception(
                    system::system_error(
                            cause,
                            BOOST_CHRONO_SYSTEM_CATEGORY,
                            "chrono::process_user_cpu_clock" ));
        }
        else
        {
            ec.assign( cause, BOOST_CHRONO_SYSTEM_CATEGORY );
            return time_point();
        }
    }

}
#endif

process_system_cpu_clock::time_point process_system_cpu_clock::now() BOOST_NOEXCEPT
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    wjl_boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( wjl_boost::detail::winapi::GetProcessTimes(
            wjl_boost::detail::winapi::GetCurrentProcess(), &creation, &exit,
            &system_time, &user_time ) )
    {
        return time_point(duration(
                ((static_cast<process_system_cpu_clock::rep>(system_time.dwHighDateTime) << 32)
                                    | system_time.dwLowDateTime) * 100
                ));
    }
    else
    {
      BOOST_ASSERT(0 && "Boost::Chrono - Internal Error");
      return time_point();
    }

}

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
process_system_cpu_clock::time_point process_system_cpu_clock::now(
        system::error_code & ec)
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    wjl_boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( wjl_boost::detail::winapi::GetProcessTimes(
            wjl_boost::detail::winapi::GetCurrentProcess(), &creation, &exit,
            &system_time, &user_time ) )
    {
        if (!BOOST_CHRONO_IS_THROWS(ec))
        {
            ec.clear();
        }
        return time_point(duration(
                ((static_cast<process_system_cpu_clock::rep>(system_time.dwHighDateTime) << 32)
                                    | system_time.dwLowDateTime) * 100
                ));
    }
    else
    {
        wjl_boost::detail::winapi::DWORD_ cause = wjl_boost::detail::winapi::GetLastError();
        if (BOOST_CHRONO_IS_THROWS(ec))
        {
            wjl_boost::throw_exception(
                    system::system_error(
                            cause,
                            BOOST_CHRONO_SYSTEM_CATEGORY,
                            "chrono::process_system_cpu_clock" ));
        }
        else
        {
            ec.assign( cause, BOOST_CHRONO_SYSTEM_CATEGORY );
            return time_point();
        }
    }

}
#endif

process_cpu_clock::time_point process_cpu_clock::now()  BOOST_NOEXCEPT
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    wjl_boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( wjl_boost::detail::winapi::GetProcessTimes(
            wjl_boost::detail::winapi::GetCurrentProcess(), &creation, &exit,
            &system_time, &user_time ) )
    {
        time_point::rep r(process_real_cpu_clock::now().time_since_epoch().count()
                            ,
                ((static_cast<process_user_cpu_clock::rep>(user_time.dwHighDateTime) << 32)
                        | user_time.dwLowDateTime
                ) * 100,
                ((static_cast<process_system_cpu_clock::rep>(system_time.dwHighDateTime) << 32)
                        | system_time.dwLowDateTime
                ) * 100
        );
        return time_point(duration(r));
    }
    else
    {
      BOOST_ASSERT(0 && "Boost::Chrono - Internal Error");
      return time_point();
    }

}

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
process_cpu_clock::time_point process_cpu_clock::now(
        system::error_code & ec )
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    wjl_boost::detail::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( wjl_boost::detail::winapi::GetProcessTimes(
            wjl_boost::detail::winapi::GetCurrentProcess(), &creation, &exit,
            &system_time, &user_time ) )
    {
        if (!BOOST_CHRONO_IS_THROWS(ec))
        {
            ec.clear();
        }
        time_point::rep r(process_real_cpu_clock::now().time_since_epoch().count()
                            ,
                ((static_cast<process_user_cpu_clock::rep>(user_time.dwHighDateTime) << 32)
                        | user_time.dwLowDateTime
                ) * 100,
                ((static_cast<process_system_cpu_clock::rep>(system_time.dwHighDateTime) << 32)
                        | system_time.dwLowDateTime
                ) * 100
        );
        return time_point(duration(r));
    }
    else
    {
        wjl_boost::detail::winapi::DWORD_ cause = wjl_boost::detail::winapi::GetLastError();
        if (BOOST_CHRONO_IS_THROWS(ec))
        {
            wjl_boost::throw_exception(
                    system::system_error(
                            cause,
                            BOOST_CHRONO_SYSTEM_CATEGORY,
                            "chrono::process_cpu_clock" ));
        }
        else
        {
            ec.assign( cause, BOOST_CHRONO_SYSTEM_CATEGORY );
            return time_point();
        }
    }

}
#endif
#endif
} // namespace chrono
} // namespace wjl_boost

#endif