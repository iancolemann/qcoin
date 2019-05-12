# qCoin

## About

Welcome to the repository of qCoin. Here you will find source code, instructions, wiki resources, and integration tutorials.

Contents
* Building on Linux 64-bit
* Building on Mac OSX
* Building on Windows
* Building on other platforms

## Building on Linux 64-bit

All commands below work on Ubuntu 18.*, other distributions may need different command set.

### Building with standard options

Create directory `qcoinofficial` somewhere and go there:
```
$> mkdir qcoinofficial
$> cd qcoinofficial
```

To go futher you have to have a number of packages and utilities. You need at least gcc 5.4.

* `build-essential` package:
    ```
    $qcoinofficial> sudo apt-get install build-essential
    ```

* CMake (3.0 or newer):
    ```
    $qcoinofficial> sudo apt-get install cmake
    $qcoinofficial> cmake --version
    ```
    If version is too old, follow instructions on [the official site](https://cmake.org/download/).

* Boost (1.65 or newer):
    We use boost as a header-only library via find_boost package. So, if your system has boost installed and set up, it will be used automatically.
    
    Note - there is a bug in `boost::asio` 1.66 that affects `qcoind`. Please use either version 1.65 or 1.67+.
    ```
    $qcoinofficial> sudo apt-get install libboost-dev
    ```
    If the latest boost installed is too old (e.g. for Ubuntu 16.*), then you need to download and unpack boost into the `qcoinofficial/boost` folder. 

    ```
    $qcoinofficial> wget -c 'https://dl.bintray.com/boostorg/release/1.69.0/source/boost_1_69_0.tar.gz'
    $qcoinofficial> tar -xzf ./boost_1_69_0.tar.gz
    $qcoinofficial> rm ./boost_1_69_0.tar.gz
    $qcoinofficial> mv ./boost_1_69_0/ ./boost/
    ```

* OpenSSL (1.1.1 or newer):
    Install OpenSSL to `qcoinofficial/openssl` folder. (In below commands use switch `linux-x86_64-clang` instead of `linux-x86_64` if using clang.)
    ```
    $qcoinofficial> git clone https://github.com/openssl/openssl.git
    $qcoinofficial> cd openssl
    $qcoinofficial/openssl> ./Configure linux-x86_64 no-shared
    $qcoinofficial/openssl> make -j4
    $qcoinofficial/openssl> cd ..
    ```

* LMDB
    Source files are referenced via relative paths, so you do not need to separately build it:
    Please note, we use LMDB only when building 64-bit daemons. For 32-bit daemons SQLite is used instead.

    Difference to official LMDB repository is lifted 2GB database limit if built by MSVC (even of 64-bit machine).
    ```
    $qcoinofficial> git clone https://github.com/qcoinofficial/lmdb.git

    ```

Git-clone (or git-pull) qCoin source code in that folder:
```
$qcoinofficial> git clone https://github.com/qcoinofficial/qcoin.git
```

Create build directory inside qcoin, go there and run CMake and Make:
```
$qcoinofficial> mkdir -p qcoin/build
$qcoinofficial> cd qcoin/build
$qcoinofficial/qcoin/build> cmake ..
$qcoinofficial/qcoin/build> make -j4
```

Check built binaries by running them from `../bin` folder
```
$qcoinofficial/qcoin/build> ../bin/qcoind -v
```

## Building on Mac OSX

### Building with standard options (10.11 El Capitan or newer)

You need command-line tools. Either get XCode from an App Store or run 'xcode-select --install' in terminal and follow instructions. First of all, you need [Homebrew](https://brew.sh).

Then open terminal and install CMake and Boost:

* `brew install cmake`
* `brew install boost`

Create directory `qcoinofficial` somewhere and go there:
```
$~/Downloads> mkdir qcoinofficial
$~/Downloads> cd qcoinofficial
```

Git-clone (or git-pull) qCoin source code in that folder:
```
$qcoinofficial> git clone https://github.com/qcoinofficial/qcoin.git
```

Put LMDB source code in `qcoinofficial` folder (source files are referenced via relative paths, so you do not need to separately build it):
```
$~/Downloads/qcoinofficial> git clone https://github.com/qcoinofficial/lmdb.git
```

Install OpenSSL to `qcoinofficial/openssl` folder:
```
$~/Downloads/qcoinofficial> git clone https://github.com/openssl/openssl.git
$~/Downloads/qcoinofficial> cd openssl
```

If you need binaries to run on all versions of OS X starting from El Capitan, you need to build OpenSSL targeting El Capitan SDK.
```
$~/Downloads/qcoinofficial/openssl> ./Configure darwin64-x86_64-cc no-shared -mmacosx-version-min=10.11 -isysroot/Users/user/Downloads/MacOSX10.11.sdk
```
Otherwise just use
```
$~/Downloads/qcoinofficial/openssl> ./Configure darwin64-x86_64-cc no-shared
```

```
$~/Downloads/qcoinofficial/openssl> make -j4
$~/Downloads/qcoinofficial/openssl> cd ..
```

Download amalgamated [SQLite 3](https://www.sqlite.org/download.html) and unpack it into `qcoinofficial/sqlite` folder (source files are referenced via relative paths, so you do not need to separately build it).
Please, note the direct download link is periodically updated with old versions removed, so you might need to tweak instructions below
```
$~/Downloads/qcoinofficial> wget -c https://www.sqlite.org/2018/sqlite-amalgamation-3260000.zip
$~/Downloads/qcoinofficial> unzip sqlite-amalgamation-3260000.zip
$~/Downloads/qcoinofficial> rm sqlite-amalgamation-3260000.zip
$~/Downloads/qcoinofficial> mv sqlite-amalgamation-3260000 sqlite
```

Create build directory inside qcoin, go there and run CMake and Make:
```
$~/Downloads/qcoinofficial> mkdir qcoin/build
$~/Downloads/qcoinofficial> cd qcoin/build
$~/Downloads/qcoinofficial/qcoin/build> cmake ..
$~/Downloads/qcoinofficial/qcoin/build> make -j4
```

Check built binaries by running them from `../bin` folder:
```
$qcoinofficial/qcoin/build> ../bin/qcoind -v
```

## Building on Windows

You need Microsoft Visual Studio Community 2017. [Download](https://www.visualstudio.com/vs/) and install it selecting `C++`, `git`, `cmake integration` packages.
Run `Visual Studio x64 command prompt` from start menu.

Create directory `qcoinofficial` somewhere:
```
$C:\> mkdir qcoinofficial
$C:\> cd qcoinofficial
```

Boost (1.65 or newer):
    We use boost as a header-only library via find_boost package. So, if your system has boost installed and set up, it will be used automatically. If not, you need to download and unpack boost into qcoinofficial/boost folder.

Git-clone (or git-pull) qCoin source code in that folder:
```
$C:\qcoinofficial> git clone https://github.com/qcoinofficial/qcoin.git
```

Put LMDB in the same folder (source files are referenced via relative paths, so you do not need to separately build it):
```
$C:\qcoinofficial> git clone https://github.com/qcoinofficial/lmdb.git
```

Download amalgamated [SQLite 3](https://www.sqlite.org/download.html) and unpack it into the same folder (source files are referenced via relative paths, so you do not need to separately build it).

You need to build openssl, first install ActivePerl (select "add to PATH" option, then restart console):
```
$C:\qcoinofficial> git clone https://github.com/openssl/openssl.git
$C:\qcoinofficial> cd openssl
$C:\qcoinofficial\openssl> perl Configure VC-WIN64A no-shared no-asm
$C:\qcoinofficial\openssl> nmake
$C:\qcoinofficial\openssl> cd ..
```
If you want to build 32-bit binaries, you will also need 32-bit build of openssl in separate folder (configuring openssl changes header files, so there is no way to have both 32-bit and 64-bit versions in the same folder):
```
$C:\qcoinofficial> git clone https://github.com/openssl/openssl.git openssl32
$C:\qcoinofficial> cd openssl32
$C:\qcoinofficial\openssl> perl Configure VC-WIN32 no-shared no-asm
$C:\qcoinofficial\openssl> nmake
$C:\qcoinofficial\openssl> cd ..
```

Now launch Visual Studio, in File menu select `Open Folder`, select `C:\qcoinofficial\qcoin` folder.
Wait until CMake finishes running and `Build` appears in main menu.
Select `x64-Debug` or `x64-Release` from standard toolbar, and then `Build/Build Solution` from the main menu.

## Building with options

You can build daemons that use SQLite istead of LMDB on any platform by providing options to CMake.
You may need to clean 'build' folder, if you built with default options before, due to cmake aggressive caching.

```
$qcoin/build> cmake -DUSE_SQLITE=1 ..
$qcoin/build> time make -j8
```

## Building on 32-bit x86 platforms, iOS, Android and other ARM platforms

qCoin works on 32-bit systems if SQLite is used instead of LMDB (we've experienced lots of problems building and running with lmdb in 32-bit compatibility mode, especially on iOS).

We build official x86 32-bit version for Windows only, because there is zero demand for 32-bit version for Linux or Mac.

Building source code for iOS, Android, Raspberry PI, etc is possible (we have experimental `qcoind` and `walletd` running on ARM64 iPhone) but requires major skills on your part. __TBD__

## Building on Big-Endian platforms

Currently qcoin does not work out of the box on any Big-Endian platform, due to some endianess-dependent code. This may be fixed in the future. If you wish to run on Big-Endian platform, please contact us.

## Building with parameters

If you want to use tools like `clang-tidy`, run `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..` instead of `cmake ..`

## Building daemons with hardware wallet support on Linux 64-bit

1. Clone `trezor-core` repository into the same folder where `qcoin` resides.
2. Install all Google protobuf stuff:
```
sudo apt install protobuf-compiler libprotobuf-dev
```
3. If your version of proto buffers library is not `3.0.0`, you should run `protoc` on proto files in `trezor-core/vendor/trezor-common/protob` overwriting `qcoin/src/Core/hardware/trezor/protob`.
4. Clean your `qcoin/build` folder if you have built the qCoin source code before.
