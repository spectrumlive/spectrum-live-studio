message(STATUS "PRISM Plugin: prism-sticker-source")

project(prism-sticker-source)

add_library(prism-sticker-source MODULE)

add_definitions(-D_PRISM_PLUGIN)
add_definitions(-DQT_NO_VERSION_TAGGING)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(FFmpeg REQUIRED COMPONENTS avcodec avutil avformat)
include_directories(${FFmpeg_INCLUDE_DIRS})

target_sources(prism-sticker-source 
    PRIVATE
    prism-sticker-source.hpp
    prism-giphy-sticker-source.hpp
    prism-sticker-source.cpp
    prism-giphy-sticker-source.cpp
    plugin-main.cpp)

target_link_libraries(prism-sticker-source
    ${FFmpeg_LIBRARIES}
    OBS::libobs
    common-libs::utils-api
    common-libs::log)

if(OS_WINDOWS)
    if(MSVC)
        target_link_libraries(prism-sticker-source OBS::w32-pthreads)
    endif()
endif()