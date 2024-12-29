# SPECTRUM Live Studio
![spectrumlive](https://github.com/user-attachments/assets/fdb88ec5-04c2-470e-99d1-05d35c2bcb47)


**Visit [our official web site](http://spectrumlive.xyz) for more information and [Latest updates on SPECTRUM Live Studio](http://spectrumlive.xyz/pcapp/)**.

## About SPECTRUM Live Studio
SPECTRUM Live studio PC version helps beginners stream like professionals. It is a desktop application for live broadcasting.
With easy operation, anyone can easily make broadcasts and send it stably to various platforms.

SPECTRUM Live Studio used the OBS engine as the core module. We would thank all the developers with their wonderful work of OBS project.

## Overview


This application currently only supports 64-bit Windows.

## Build on Windows
Before build, please prepare install Visual Studio 2022 and QT 6.3.1 version first and set the enviroment variables as:
```
QT631: QT install directory/6.3.1/msvc2019_64
```

1. Please enter in build/windows directory and config project:
```
> configure.cmd
```

2. Please enter in src/spectrum-live-studio/build, and use VS2022 to open the solution under:
```
> open spectrum-live-studio.sln
```

Then, you could find a bin/spectrum/windows/Debug or bin/spectrum/windows/Release directory generated under root.
And please find the file SPECTRUMLiveStudio.exe in bin/64bit
which is the main program file of SPECTRUM Live Studio

## Build on Macos
Before build, please prepare install XCode and QT 6.3.1 version first and set the enviroment variables as:
```
QTDIR: QT install directory/6.3.1/macos
```

1. Please enter in build/mac directory and config project:
```
> ./01_configure.sh
```

2. Please enter in src/spectrum-live-studio/build, and use XCode to open the solution under:
```
> open spectrum-live-studio.xcodeproj
```

Then, you could find a src/spectrum-live-studio/build/spectrum-live-studio/SPECTRUMLiveStudio/Debug/SPECTRUMLiveStudio.app or src/spectrum-live-studio/build/spectrum-live-studio/SPECTRUMLiveStudio/Release/SPECTRUMLiveStudio.app,
which is the bundle file of SPECTRUM Live Studio

## Community

[Github issues](https://github.com/spectrumlive/spectrum-live-studio/issues)  
If you have any question, please contact us by [mail:spectrumlive@spectrumlive.xyz](mailto://spectrumlive@spectrumlive.xyz)

Environment Note:
- MacOS
  - Required
    ```aiignore
    $ brew install qt
    ```
    Create Update.sh in src/obs-studio directory
    ```aiignore
      #!/bin/bash    
      $ git submodule add https://github.com/obsproject/libdshowcapture.git plugins/win-dshow/libdshowcapture
      $ git submodule add https://github.com/palana/Syphon-Framework.git plugins/mac-syphon/syphon-framework
      $ git submodule add https://github.com/obsproject/obs-amd-encoder.git plugins/enc-amf
      $ git submodule add https://github.com/naver/obs-browser.git plugins/obs-browser
      $ git submodule add https://github.com/Mixer/ftl-sdk.git plugins/obs-outputs/ftl-sdk
      $ git submodule add https://github.com/obsproject/obs-websocket.git plugins/obs-websocket
    ```
    In obs-studio directory run, (note: we may need to check out the buildspec.json from the original repo)
   ```aiignore
     $ cmake --list-presets
     $ cmake --preset macos
   ```
   ```
      $ cd src
      $ git submodule init
      $ git submodule update
      $ cd obs-studio
      $ ./update.sh
    ```
    ```----- McDuck for Spectrum ----
        export CMAKE_HOST_SYSTEM_NAME="Darwin"
        export CMAKE_SYSTEM_NAME="Darwin"
        export PATH="~/Works/SPECTRUM/spectrum-live-studio/src/obs-studio/.deps/obs-deps-2024-03-19-universal/bin:$PATH"
        export QTDIR="/opt/homebrew"
        export CMAKE_PREFIX_PATH="~/Works/SPECTRUM/spectrum-live-studio/src/obs-studio/.deps/obs-deps-2024-03-19-universal:$CMAKE_PREFIX_PATH"
        export INCLUDE="$INCLUDE:~/Works/SPECTRUM/spectrum-live-studio/src/obs-studio/.deps/obs-deps-2024-03-19-universal/include"
        export LIB="$LIB:~/Works/SPECTRUM/spectrum-live-studio/src/obs-studio/.deps/obs-deps-2024-03-19-universal/lib"
        export PATH=$PATH:~/Works/SPECTRUM/spectrum-live-studio/src/obs-studio/.deps/obs-deps-2024-03-19-universal/bin
    ```
- Windows


