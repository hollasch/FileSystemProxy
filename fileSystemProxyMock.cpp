//==================================================================================================
// FileSystemProxyMock.cpp
//
//     This file contains the definitions for the file system proxy classes for the file system
//     proxy mock object.
//
// _________________________________________________________________________________________________
// MIT License
//
// Copyright © 2017 Steve Hollasch
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
using namespace FileSystemProxy;


MockDirectoryIterator::MockDirectoryIterator (const string path) {
    // Not yet implemented.
}

MockDirectoryIterator::~MockDirectoryIterator() {
    // Not yet implemented.
}

bool MockDirectoryIterator::next() {
    // Not yet implemented.
    return false;
}

bool MockDirectoryIterator::isDirectory() const {
    // Not yet implemented.
    return false;
}

bool MockDirectoryIterator::isFile() const {
    // Not yet implemented.
    return false;
}

const string MockDirectoryIterator::name() const {
    // Not yet implemented.
    return string("<nyi>");
}



MockFS::MockFS (const string mockDirFileName, const string startingDirectory) {
    // Not Yet Implemented

    // This should be validated.
    m_currentDir = startingDirectory;
}


MockFS::~MockFS() {
}


size_t MockFS::maxPathLength() const {
    return 0;   // Indicate unlimited path length.
}


DirectoryIterator* MockFS::newDirectoryIterator (const string path) const
{
    // Not Yet Implemented
    return new MockDirectoryIterator(path);
}


bool MockFS::setCurrentDirectory (const string path)
{
    // Sets the current working directory. Returns true if the directory is valid.
    m_currentDir = path;

    // NOT YET IMPLEMENTED: For now, just always accept the directory.
    return true;
}