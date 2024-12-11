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
