//==================================================================================================
// FileSystemProxyMock.h
//
//     Windows file system proxy, using the FileSystemProxy base.
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
#include <windows.h>
#include <string>


namespace FSProxy {


const size_t c_MaxPath = 256;     // Maximum path length in mock file system.



class DirectoryIteratorMock : public DirectoryIterator {
    // This class implements a directory iterator for the mock file system.

  public:
    DirectoryIteratorMock (const std::wstring path);
    ~DirectoryIteratorMock();

    // Advance to first/next entry.
    bool next() override;

    // True => current entry is a directory.
    bool isDirectory() const override;

    // Return name of the current entry.
    const wchar_t* name() const override;
};



class FileSysProxyMock : public FileSysProxy {
    // This class provides an mock file system to test out the generic FileSysProxy class.

  public:
    FileSysProxyMock (const std::wstring mockDirFileName);
    virtual ~FileSysProxyMock() {}

    size_t maxPathLength() const override { return c_MaxPath; }

    // Return a directory iterator object.
    // NOTE: User must delete this object!
    DirectoryIterator* newDirectoryIterator (const std::wstring path) const;

    // Set the current working directory. Returns true if the directory does not exist.
    virtual bool setCurrentDirectory (const std::wstring path);

  private: 
    FILE*        m_mockDirFile;     // Mock Directory Source File
    std::wstring m_currentDir;      // Current working directory
};


};   // namespace FileSystemProxy


#endif   // _FileSystemProxyMock_h
