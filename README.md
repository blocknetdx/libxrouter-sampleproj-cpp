XROUTER SAMPLE PROJECT
=====================================

[![Build Status](https://travis-ci.org/blocknetdx/blocknet.svg?branch=master)](https://travis-ci.org/blocknetdx/blocknet)

https://blocknet.co

This is the XRouter sample project for the XRouter C++ library.

[Website](https://blocknet.co) | [API](https://api.blocknet.co) | [Documentation](https://docs.blocknet.co) | [Discord](https://discord.gg/2e6s7H8)
-------------|-------------|-------------|-------------

GETTING STARTED
---------------

In order to get started with the XRouter C++ library you must build it first, including all dependencies. After building all required libraries you can include them into your project.

### Step 1. Clone the main blocknet repository

```
git clone --single-branch --branch master https://github.com/blocknetdx/blocknet.git
```

### Step 2. Build the blocknet repository dependencies

```
cd blocknet
./autogen.sh
cd depends/
make -j8 && cd ../
```

### Step 3. Build the blocknet libraries

Be sure to set the absolute path of your project directory below (ABSOLUTE_PATH_OF_PROJECTDIR) as well as --enable-xrouterclient. This example uses gcc8, you can use another version, or the default by removing  CC and CXX entries in the command below.

Linux
```
CONFIG_SITE=[ABSOLUTE_PATH_OF_PROJECTDIR]/blocknet/depends/x86_64-pc-linux-gnu/share/config.site ./configure CC=gcc-8 CXX=g++-8 CXXFLAGS="-Wno-deprecated" --without-gui --disable-bench --disable-tests --disable-wallet --enable-xrouterclient 
make -j8
```

MacOS
```
CONFIG_SITE=[ABSOLUTE_PATH_OF_PROJECTDIR]/blocknet/depends/x86_64-apple-darwin14/share/config.site ./configure CXXFLAGS="-Wno-deprecated" --without-gui --disable-bench --disable-tests --disable-wallet --enable-xrouterclient 
make -j8
```

Windows
```
CONFIG_SITE=[ABSOLUTE_PATH_OF_PROJECTDIR]/blocknet/depends/x86_64-w64-mingw32/share/config.site ./configure CXXFLAGS="-Wno-deprecated" --without-gui --disable-bench --disable-tests --disable-wallet --enable-xrouterclient 
make -j8
```

### Step 4. Build Sample project with cmake

```
cmake .
cmake --build . --target xrouter-dev -- -j8
```

CLion (First setup a build configuration) and run the Reload CMake Project command.
```
cmake --build cmake-build-debug --target xrouter-dev -- -j8
cmake --build cmake-build-release --target xrouter-dev -- -j8
```

### Step 5. Run or debug your executable

License
-------

Blocknet is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

The MIT License (MIT)

Copyright (c) 2020 The Blocknet Developers

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
