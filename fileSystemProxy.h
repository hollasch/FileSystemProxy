//==================================================================================================
// FileSystemProxy
//
// Declarations for the file system proxy classes. These objects proxy the file system of the
// underlying operating system, or test harness.
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

#ifndef _FileSystemProxy_h
#define _FileSystemProxy_h

#include <string>



namespace FileSystemProxy {


class DirectoryIterator {

    // This abstract base class provides a way to iterate through file & directory entries in a
    // directory.

  public:
    DirectoryIterator() {}
    virtual ~DirectoryIterator() {}

    // Advance to first/next entry. Returns true until there are no more directory entries.
    virtual bool next() = 0;

    // True => current entry is a directory.
    virtual bool isDirectory() const = 0;

    // True => current entry is a file.
    virtual bool isFile() const = 0;

    // Return name of the current entry.
    virtual const std::string name() const = 0;
};



class FSProxy {

    // This abstract base class provides a general file system interface across different file
    // systems, including test harnesses.

  public:
    FSProxy() { };
    virtual ~FSProxy() {}

    // Returns the maximum path length of the file system. For file systems without a maxmimum path
    // length, returns zero.
    virtual size_t maxPathLength() const { return 0; }

    // Set the current working directory. Returns false if the directory does not exist.
    virtual bool setCurrentDirectory (const std::string path) = 0;

    // Return a directory iterator object. If the path is empty, then it iterates the current
    // working directory. NOTE: User must delete this object! It is recommended that you hold the
    // return value in a unique_ptr<>.
    virtual DirectoryIterator* newDirectoryIterator (const std::string path) const = 0;
};



};  // namespace FileSystemProxy

#endif   // ifndef _FileSystemProxy_h
