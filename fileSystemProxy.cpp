//==================================================================================================
// FileSystemProxy.cpp
//
//     This file contains the definitions for the file system proxy classes for the Windows file
//     system.
//
// _________________________________________________________________________________________________
// Copyright © 2017 Steve Hollasch
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//==================================================================================================

#include "FileSystemProxy.h"
#include <stdlib.h>
#include <string>
#include <filesystem>

using namespace std;
using namespace FSProxy;



/*
// Directory Iterator Methods

DirectoryIterator::DirectoryIterator (const wstring path)
{
    // NOT YET IMPLEMENTED
}

DirectoryIterator::~DirectoryIterator()
{
    // NOT YET IMPLEMENTED
}


*/
bool DirectoryIterator::next()
{
    // Advances the iterator to the first/next entry.

    // NOT YET IMPLEMENTED
    return false;
}



bool DirectoryIterator::isDirectory() const
{
    // Returns true if the current entry is a directory.

    // NOT YET IMPLEMENTED
    return false;
}



const wchar_t* DirectoryIterator::name() const
{
    // Returns the name of the current entry.

    // NOT YET IMPLEMENTED
    return L"";
}



DirectoryIterator* FileSysProxy::newDirectoryIterator (const wstring path) const
{
    return new DirectoryIterator(path);
}


bool FileSysProxy::setCurrentDirectory (const wstring path)
{
    // Sets the current working directory. Returns true if the directory is valid.

    // NOT YET IMPLEMENTED
    return true;
}
