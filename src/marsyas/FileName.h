/*
** Copyright (C) 1998-2005 George Tzanetakis <gtzan@cs.uvic.ca>
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software 
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/


#ifndef MARSYAS_FILENAME_H
#define MARSYAS_FILENAME_H

#include <string>

namespace Marsyas
{
/** 
    \class FileName
	\ingroup Notmar
    \brief Various utilities

    FileName is a class bundling together various rather 
unrelated convenience utilities related to filenames. 
*/


class FileName
{
private:
  std::string filename_;
  
public:
  FileName();
  FileName(std::string filename);
  ~FileName();  
  std::string fullname();			// full filename (path+file)
  std::string name();			// returns just the file (no path)
  std::string nameNoExt(); // returns just the file (no path, no ext)
  std::string path();	// returns the filename path 
  std::string ext();				// returns the filename extension
};

}//namespace Marsyas

#endif
