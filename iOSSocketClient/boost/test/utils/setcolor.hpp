//  (C) Copyright Gennadiy Rozental 2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision$
//
//  Description : contains definition for setcolor iostream manipulator
// ***************************************************************************

#ifndef BOOST_TEST_UTILS_SETCOLOR_HPP
#define BOOST_TEST_UTILS_SETCOLOR_HPP

// Boost.Test
#include <boost/test/detail/config.hpp>

// STL
#include <iostream>
#include <cstdio>

#include <boost/test/detail/suppress_warnings.hpp>

#ifdef _WIN32
  #include <windows.h>

  #if defined(__MINGW32__) && !defined(COMMON_LVB_UNDERSCORE)
    // mingw badly mimicking windows.h
    #define COMMON_LVB_UNDERSCORE 0x8000
  #endif
#endif

//____________________________________________________________________________//

namespace wjl_boost {} namespace boost = wjl_boost; namespace wjl_boost {
namespace unit_test {
namespace utils {

// ************************************************************************** //
// **************                    term_attr                 ************** //
// ************************************************************************** //

struct term_attr { enum _ {
    NORMAL    = 0,
    BRIGHT    = 1,
    DIM       = 2,
    UNDERLINE = 4,
    BLINK     = 5,
    REVERSE   = 7,
    CROSSOUT  = 9
}; };

// ************************************************************************** //
// **************                   term_color                 ************** //
// ************************************************************************** //

struct term_color { enum _ {
    BLACK    = 0,
    RED      = 1,
    GREEN    = 2,
    YELLOW   = 3,
    BLUE     = 4,
    MAGENTA  = 5,
    CYAN     = 6,
    WHITE    = 7,
    ORIGINAL = 9
}; };

// ************************************************************************** //
// **************                    setcolor                  ************** //
// ************************************************************************** //

#ifndef _WIN32
class setcolor {
public:
    // Constructor
    explicit    setcolor( term_attr::_  attr = term_attr::NORMAL,
                          term_color::_ fg   = term_color::ORIGINAL,
                          term_color::_ bg   = term_color::ORIGINAL )
    {
        m_command_size = std::sprintf( m_control_command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40 );
    }

    friend std::ostream&
    operator<<( std::ostream& os, setcolor const& sc )
    {
       if (&os == &std::cout || &os == &std::cerr) {
          return os.write( sc.m_control_command, sc.m_command_size );
       }
       return os;
    }

private:
    // Data members
    char        m_control_command[13];
    int         m_command_size;
};

#else

class setcolor {

protected:
  void set_console_color(std::ostream& os, WORD *attributes = NULL) const {
    DWORD console_type;
    if (&os == &std::cout) {
      console_type = STD_OUTPUT_HANDLE;
    }
    else if (&os == &std::cerr) {
      console_type =  STD_ERROR_HANDLE;
    }
    else {
      return;
    }
    HANDLE hConsole = GetStdHandle(console_type);

    if(hConsole == INVALID_HANDLE_VALUE || hConsole == NULL )
      return;

    if(attributes != NULL) {
      SetConsoleTextAttribute(hConsole, *attributes);
      return;
    }

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    //if(!has_written_console_ext) {
        saved_attributes = consoleInfo.wAttributes;
    //}

    WORD fg_attr = 0;
    switch(m_fg)
    {
    case term_color::WHITE:
      fg_attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
    case term_color::BLACK:
      fg_attr = 0;
      break;
    case term_color::RED:
      fg_attr = FOREGROUND_RED;
      break;
    case term_color::GREEN:
      fg_attr = FOREGROUND_GREEN;
      break;
    case term_color::CYAN:
      fg_attr = FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
    case term_color::MAGENTA:
      fg_attr = FOREGROUND_RED | FOREGROUND_BLUE;
      break;
    case term_color::BLUE:
      fg_attr = FOREGROUND_BLUE;
      break;
    case term_color::YELLOW:
      fg_attr = FOREGROUND_RED | FOREGROUND_GREEN;
      break;
    case term_color::ORIGINAL:    
    default:
      fg_attr = saved_attributes & (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }

    WORD bg_attr = 0;
    switch(m_bg)
    {
    case term_color::BLACK:
      bg_attr = 0;
      break;
    case term_color::WHITE:
      bg_attr = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
      break;
    case term_color::RED:
      bg_attr = BACKGROUND_RED;
      break;
    case term_color::GREEN:
      bg_attr = BACKGROUND_GREEN;
      break;
    case term_color::BLUE:
      bg_attr = BACKGROUND_BLUE;
      break;
    case term_color::ORIGINAL:    
    default:
      bg_attr = saved_attributes & (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
      break;
    }

    WORD text_attr = 0;
    switch(m_attr)
    {
    case term_attr::BRIGHT:
      text_attr = FOREGROUND_INTENSITY;
      break;
    case term_attr::UNDERLINE:
      text_attr = COMMON_LVB_UNDERSCORE;
      break;
    default:
      break;
    }

    SetConsoleTextAttribute(hConsole, fg_attr | bg_attr | text_attr); 

    //has_written_console_ext = true;
    return;
  }

public:
  // Constructor
  explicit    setcolor( 
    term_attr::_  attr = term_attr::NORMAL,
    term_color::_ fg   = term_color::ORIGINAL,
    term_color::_ bg   = term_color::ORIGINAL ) 
  : /*has_written_console_ext(false)
  , */m_attr(attr)
  , m_fg(fg)
  , m_bg(bg)
  {}

  friend std::ostream&
    operator<<( std::ostream& os, setcolor const& sc )
  {
    sc.set_console_color(os);
    return os;
  }

private:
  term_attr::_ m_attr;
  term_color::_ m_fg;
  term_color::_ m_bg;

protected:
  // Data members
  mutable WORD saved_attributes;
  //mutable bool has_written_console_ext;
};

#endif
// ************************************************************************** //
// **************                 scope_setcolor               ************** //
// ************************************************************************** //

#ifndef _WIN32

struct scope_setcolor {
    scope_setcolor() : m_os( 0 ) {}
    explicit    scope_setcolor( std::ostream& os,
                                term_attr::_  attr = term_attr::NORMAL,
                                term_color::_ fg   = term_color::ORIGINAL,
                                term_color::_ bg   = term_color::ORIGINAL )
    : m_os( &os )
    {
        os << setcolor( attr, fg, bg );
    }
    ~scope_setcolor()
    {
        if( m_os )
            *m_os << setcolor();
    }
private:
    scope_setcolor(const scope_setcolor& r);
    scope_setcolor& operator=(const scope_setcolor& r);
    // Data members
    std::ostream* m_os;
};

#else

struct scope_setcolor : setcolor {
  scope_setcolor() : m_os( 0 ) {}
  explicit    scope_setcolor( 
    std::ostream& os,
    term_attr::_  attr = term_attr::NORMAL,
    term_color::_ fg   = term_color::ORIGINAL,
    term_color::_ bg   = term_color::ORIGINAL )
    : 
    setcolor(attr, fg, bg), 
    m_os( &os )
  {
    os << *this;
  }

  ~scope_setcolor()
  {
    if (m_os) {
      set_console_color(*m_os, &this->saved_attributes);
    }
  }
private:
  scope_setcolor(const scope_setcolor& r);
  scope_setcolor& operator=(const scope_setcolor& r);
  // Data members
  std::ostream* m_os;
};


#endif

#define BOOST_TEST_SCOPE_SETCOLOR( is_color_output, os, attr, color )       \
    utils::scope_setcolor const sc(                                         \
              os,                                                           \
              is_color_output ? utils::attr : utils::term_attr::NORMAL,     \
              is_color_output ? utils::color : utils::term_color::ORIGINAL);\
    ut_detail::ignore_unused_variable_warning( sc )                         \
/**/

} // namespace utils
} // namespace unit_test
} // namespace wjl_boost

#include <boost/test/detail/enable_warnings.hpp>

#endif // BOOST_TEST_UTILS_SETCOLOR_HPP