# filepath: /Users/mcduck/Works/SPECTRUM/spectrum-live-studio/cmake/FindFFmpeg.cmake
find_path(FFMPEG_INCLUDE_DIR libavcodec/avcodec.h
  HINTS
    $ENV{FFMPEG_DIR}
    ${FFMPEG_DIR}
    ${CMAKE_PREFIX_PATH}
    /usr/local/include
    /usr/include
)

find_library(AVCODEC_LIBRARY avcodec
  HINTS
    $ENV{FFMPEG_DIR}
    ${FFMPEG_DIR}
    ${CMAKE_PREFIX_PATH}
    /usr/local/lib
    /usr/lib
)

find_library(AVUTIL_LIBRARY avutil
  HINTS
    $ENV{FFMPEG_DIR}
    ${FFMPEG_DIR}
    ${CMAKE_PREFIX_PATH}
    /usr/local/lib
    /usr/lib
)

find_library(AVFORMAT_LIBRARY avformat
  HINTS
    $ENV{FFMPEG_DIR}
    ${FFMPEG_DIR}
    ${CMAKE_PREFIX_PATH}
    /usr/local/lib
    /usr/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FFmpeg DEFAULT_MSG FFMPEG_INCLUDE_DIR AVCODEC_LIBRARY AVUTIL_LIBRARY AVFORMAT_LIBRARY)

if(FFmpeg_FOUND)
  set(FFmpeg_INCLUDE_DIRS ${FFMPEG_INCLUDE_DIR})
  set(FFmpeg_LIBRARIES ${AVCODEC_LIBRARY} ${AVUTIL_LIBRARY} ${AVFORMAT_LIBRARY})
endif()