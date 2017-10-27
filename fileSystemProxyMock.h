//==================================================================================================
// FileSystemProxyMock.h
//
//     Mock file system proxy.
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

#ifndef _FileSystemProxyMock_h
#define _FileSystemProxyMock_h

// Includes

#include <FileSystemProxy.h>
#include <string>


namespace FileSystemProxy {



class MockDirectoryIterator : public DirectoryIterator {
    // This class implements a directory iterator for the mock file system.

  public:
    MockDirectoryIterator (const std::string path);
    ~MockDirectoryIterator();

    // Advance to first/next entry.
    bool next() override;

    // True => current entry is a directory.
    bool isDirectory() const override;

    // True => current entry is a file.
    bool isFile() const override;

    // Return name of the current entry.
    const std::string name() const override;
};



class MockFS : public FSProxy {
    // This class provides an mock file system to test out the generic FileSysProxy class.

  public:
    MockFS (std::string mockDirFileName, const std::string startingDirectory);
    virtual ~MockFS();

    size_t maxPathLength() const override;

    // Return a directory iterator object. If the path is empty, then it iterates the current
    // working directory. NOTE: User must delete this object! It is recommended that you hold the
    // return value in a unique_ptr<>.
    DirectoryIterator* newDirectoryIterator (const std::string path) const override;

    // Set the current working directory. Returns true if the directory does not exist.
    bool setCurrentDirectory (const std::string path) override;

  private: 
    std::string m_currentDir;      // Current working directory
};


};   // namespace FileSystemProxy


#endif   // _FileSystemProxyMock_h
