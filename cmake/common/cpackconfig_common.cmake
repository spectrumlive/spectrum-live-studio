# OBS CMake common CPack module

include_guard(GLOBAL)

# Set default global CPack variables
set(CPACK_PACKAGE_NAME spectrum-studio)
set(CPACK_PACKAGE_VENDOR "${OBS_WEBSITE}")
set(CPACK_PACKAGE_HOMEPAGE_URL "${OBS_WEBSITE}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${OBS_COMMENTS}")
set(CPACK_PACKAGE_CHECKSUM SHA256)

set(CPACK_PACKAGE_VERSION_MAJOR ${SPECTRUM_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${SPECTRUM_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${SPECTRUM_VERSION_PATCH})
