//==================================================================================================
// FileSystemProxyMock.cpp
//
//     This file contains the definitions for the file system proxy classes for the file system
//     proxy mock object.
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

#include "FileSystemProxyMock.h"
#include <stdlib.h>
#include <string>

using namespace std;
using namespace FSProxy;


DirectoryIteratorMock::DirectoryIteratorMock (const std::wstring /* path */)
{
    // Not yet implemented.
}

DirectoryIteratorMock::~DirectoryIteratorMock()
{
    // Not yet implemented.
}

bool DirectoryIteratorMock::next()
{
    // Not yet implemented.
    return false;
}

bool DirectoryIteratorMock::isDirectory() const
{
    // Not yet implemented.
    return false;
}

const wchar_t* DirectoryIteratorMock::name() const
{
    // Not yet implemented.
    return L"xxx";
}



FileSysProxyMock::FileSysProxyMock (const wstring mockDirFileName)
{
    if (S_OK == _wfopen_s(&m_mockDirFile, mockDirFileName.c_str(), L"r, ccs=UNICODE"))
    {
        // Do nothing with the file for now.
        fclose (m_mockDirFile);
    }
}


DirectoryIterator* FileSysProxyMock::newDirectoryIterator (const std::wstring path) const
{
    // Not yet implemented.
    return new DirectoryIteratorMock(path);
}


bool FileSysProxyMock::setCurrentDirectory (const std::wstring path)
{
    // Sets the current working directory. Returns true if the directory is valid.
    m_currentDir = path;

    // NOT YET IMPLEMENTED: For now, just always accept the directory.
    return true;
}
