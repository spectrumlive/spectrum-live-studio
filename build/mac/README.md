# SPECTRUM Live Studio
![spectrumlive](https://github.com/user-attachments/assets/fdb88ec5-04c2-470e-99d1-05d35c2bcb47)

# MacOS build

## Qt 
required version 6.7.3
```
brew install qt
```
after install, required to set QT_DIR
```
export QT_DIR=/opt/homebrew
```

## Install dependencies
### ffmpeg current version 7.1
```
brew install ffmpeg
```
create new FindFFmpeg.cmake in /src/prism-live-studio/cmake is required.

Also modify CMakeLists.txt in /src/prism-live-studio/PRISMLiveStudio/plugins/source/prism-stiker-source/CMakeLists.txt is required.

### ntv2sdkmac_17.1.0.900
```
https://github.com/aja-video/libajantv2
```
Note: After download libajantv2 and extract into local drive. We need to export path as below.
```
export AJASDKPath=/path/to/ntv2sdkmac_17.1.0.900
export INCLUDE=$INCLUDE:/path/to/ntv2sdkmac_17.1.0.900/includes
export LIB=$LIB:/path/to/ntv2sdkmac_17.1.0.900/lib
```
Note: I added above export into .zshrc instead of sperate setenv file.
NOte: ntv2 17.11 is not working with obs 30.1.2 
```
https://github.com/obsproject/obs-studio/issues/10771
```
```
https://github.com/obsproject/obs-studio/pull/10037
```
^^^^ check this out!!!

### VulkanSDK
```
https://vulkan.lunarg.com/sdk/home