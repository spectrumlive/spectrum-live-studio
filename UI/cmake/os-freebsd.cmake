target_sources(spectrum-studio PRIVATE platform-x11.cpp)
target_compile_definitions(spectrum-studio PRIVATE OBS_INSTALL_PREFIX="${OBS_INSTALL_PREFIX}")
target_link_libraries(spectrum-studio PRIVATE Qt::GuiPrivate Qt::DBus procstat)

target_sources(spectrum-studio PRIVATE system-info-posix.cpp)

if(TARGET OBS::python)
  find_package(Python REQUIRED COMPONENTS Interpreter Development)
  target_link_libraries(spectrum-studio PRIVATE Python::Python)
  target_link_options(spectrum-studio PRIVATE LINKER:-no-as-needed)
endif()

configure_file(cmake/linux/com.obsproject.Studio.metainfo.xml.in com.obsproject.Studio.metainfo.xml)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/com.obsproject.Studio.metainfo.xml"
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/metainfo"
)

install(FILES cmake/linux/com.obsproject.Studio.desktop DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/applications")

install(
  FILES cmake/linux/icons/obs-logo-128.png
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/icons/hicolor/128x128/apps"
  RENAME com.obsproject.Studio.png
)

install(
  FILES cmake/linux/icons/obs-logo-256.png
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/icons/hicolor/256x256/apps"
  RENAME com.obsproject.Studio.png
)

install(
  FILES cmake/linux/icons/obs-logo-512.png
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/icons/hicolor/512x512/apps"
  RENAME com.obsproject.Studio.png
)

install(
  FILES cmake/linux/icons/obs-logo-scalable.svg
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/icons/hicolor/scalable/apps"
  RENAME com.obsproject.Studio.svg
)
