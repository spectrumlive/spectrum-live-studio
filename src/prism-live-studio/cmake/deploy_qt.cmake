# CONFIG QT_DIR DEV_OUTPUT_DIR TARGET OS_WINDOWS OS_MACOS

message(STATUS "deploy target qt libraries.")
message(STATUS "CONFIG=${CONFIG}")
message(STATUS "QT_DIR=${QT_DIR}")
message(STATUS "DEV_OUTPUT_DIR=${DEV_OUTPUT_DIR}")
message(STATUS "TARGET=${TARGET}")
message(STATUS "OS_WINDOWS=${OS_WINDOWS}")
message(STATUS "OS_MACOS=${OS_MACOS}")

if(${CONFIG} STREQUAL "Debug")
    set(OUTPUT_DIR "${DEV_OUTPUT_DIR}/Debug")
else()
    set(OUTPUT_DIR "${DEV_OUTPUT_DIR}/Release")
endif()

if (OS_WINDOWS)
	if (EXISTS "${OUTPUT_DIR}/${TARGET}.exe")
		execute_process(COMMAND "${QT_DIR}/bin/windeployqt.exe" "${OUTPUT_DIR}/${TARGET}.exe" --no-translations)
	elseif (EXISTS "${OUTPUT_DIR}/${TARGET}.dll")
		execute_process(COMMAND "${QT_DIR}/bin/windeployqt.exe" "${OUTPUT_DIR}/${TARGET}.dll" --no-translations)
	elseif (EXISTS "${OUTPUT_DIR}/bin/64bit/${TARGET}.exe")
		execute_process(COMMAND "${QT_DIR}/bin/windeployqt.exe" "${OUTPUT_DIR}/bin/64bit/${TARGET}.exe" --no-translations)
	elseif (EXISTS "${OUTPUT_DIR}/bin/64bit/${TARGET}.dll")
		execute_process(COMMAND "${QT_DIR}/bin/windeployqt.exe" "${OUTPUT_DIR}/bin/64bit/${TARGET}.dll" --no-translations)
	endif()
endif()