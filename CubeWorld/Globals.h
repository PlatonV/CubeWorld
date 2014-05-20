#ifndef GLOBALS_H
#define GLOBALS_H
#pragma once

#include <sstream>
#include "Precompiled.h"

#define DBOUT( s )            \
{                             \
   std::ostringstream os_;    \
   os_ << s;                   \
   OutputDebugString( os_.str().c_str() );  \
}

namespace CW
{
	//extern sf::Font ArialFont;
}

#endif