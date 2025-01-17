===================================
05-01-23\
Update Master from Beta branch.\
- Version 2.007.009
- Release 2.007.009 published


SpoutCommon.h
- Disable Visual Studio warning 26812) (unscoped enums)

Spout.cpp
- 10.04.22	- ReceiveSenderData() - correct duplication of DX9 formats
- 16.04.22	- Add more log notices to GetSenderAdapter
- 18.04.22	- Change default invert from true to false for fbo sending functions
- 28.04.22	- SelectSenderPanel - if SpoutPanel is not found,\
			  show a MessageBox and direct to the Spout home page
- 05.05.22	- SendFbo - mods for default framebuffer
- 30.07.22	- SendFbo - avoid using glGetIntegerv if width and height are passed in\
		      Revert to default invert true after further testing with default framebuffer.
- 28.10.22	- Add GetPerformancePreference, SetPerformancePreference, GetPreferredAdapterName
- 01.11.22	- Add SetPreferredAdapter
- 03.11.22	- Add IsPreferenceAvailable\
			  SetAdapter - GL/DX compatibility is re-tested in OpenSpout
- 07.11.22	- Add IsApplicationPath\
			  Update ReceiveSenderData code comments for Windows Graphics Preferences
- 28.11.22	- SelectSenderPanel - correct warning if SpoutPanel is not found instead of the \
			  ShellExecute Windows error and allow user the option to open the Spout home page.
- 05.12.22	- Add CleanSenders to SetSenderName
- 07.12.22	- SelectSender return bool
- 12.12.22	- SetSenderName - return if the same name
- 13.12.22	- SetSenderName revise for null name passed
- 14.12.22	- Remove SetAdapter. Requires OpenGL setup.
- 18.12.22	- Change unused bDX9 argument to const with default
- 20.12.22	- More checks for null arguments
- 22.12.22	- Compiler compatibility check\
		      Conditional compile of preference functions

SpoutCopy.cpp
- 10.04.22 - Casting changes to avoid Warning C26451 : Arithmetic overflow
- 07.10.22 - Corrected missing alpha from rgb2rba and rgb2bgra functions
- 24.10.22 - Add experimental rgb_to_bgrx_sse
- 28.10.22 - Cleanup / code documentation
- 11.12.22 - test for null args in conversion functions
- 22.12.22 - Compiler compatibility check\
		   Change all {} initializations to "={}"

SpoutDirectX.cpp
- 29.03.22	- CreateDX11Texture, CreateSharedDX11Texture, CreateDX11StagingTexture\
		  Switch on HRESULT instead of LOWORD so that DXGI cases are recognised 
- 07.04.22	- CreateDX11Texture - cast to int the LOWORD from hresult for error report
- 15.05.22	- CreateSharedDX11Texture change Fatal logs to Warning
- 26.10.22	- Correct GetAdapterIndex maximum size for wchar convert
- 28.10.22	- Add GetPerformancePreference, SetPerformancePreference, GetPreferredAdapterName\
			  Code cleanup and documentation
- 01.11.22	- Add SetPreferredAdapter
- 02.11.22	- Add IsPreferenceAvailable to detect availability\
			  of Windows Graphics Performance settings.
- 04.11.22	- Change GetAdapterIndex argument from char* to to const char*\
			  Correct to return -1 on failure instead of "false"
- 07.11.22	- Add IsApplicationPath
- 01.12.22	- GetPerformancePreference change logs to warning
- 03.12.22	- Avoid use of "description" char array due to definition in SpoutSenderNames.h
- 17.12.22	- Corrections for code analysis
- 18.12.22	- Catch any exception by using Release in destructor\
			  Use std::string for error text in CreateDX11StagingTexture / CreateSharedDX11Texture
- 22.12.22	- Compiler compatibility check\
			  Change all {} initializations to "={}"
- 31.12.22	- SpoutDirectX.h\
			   Remove WDK_NTDDI_VERSION in case it's not defined\
			   Add comments concerning use of dxgi_6 with older DirectX SDK.

SpoutFrameCount.cpp
- 28.10.22	- Code documentation
- 10.11.22	- Revise HoldFps\
			  Remove m_millisForFrame\
			  Include TimeBeginPeriod/TimeEndPeriod\ 
			  to reduce Windows timing period to minimum.
- 18.11.22	- Move performance counter functions to SpoutUtils
- 21.11.22	- Extend CleanupFrameCount and use in destructor\
			- Correct average frame rate in UpdateSenderFps\
			- Correct GetNewFrame for receiver started.
- 17.12.22	- Use smart pointers for m_FrameStartPtr etc to avoid using new/delete
- 18.12.22	- Change back to new/delete due to incompatibility with SpoutLibrary
- 22.12.22	- Compiler compatibility check

SpoutGL.cpp
- 21.03.22	- LoadGLextensions - correct  && to & for (m_caps & GLEXT_SUPPORT_PBO)\
			  UnloadTexturePixels - casting pitch*width for size compare avoids warning C26451
- 29.03.22	- OpenDeviceKey - correct dwSize from MAX_PATH to 256 in RegOpenKeyExA\
			  ReadTextureData - create unsigned long variables for temp src char array\
			  ReadTextureData - Delete temporary "src" char array created with "new"
- 19.04.22	- Restore host fbo in SetSharedTextureData instead of default 0
- 04.06.22	- SetSharedTextureData - corrected glCheckFramebufferStatus from != to == for textureID 0
- 29.07.22	- OpenSpout - default CPU share until tested
- 28.10.22	- Documentation cleanup
- 26.11.22	- Change SetVerticalSync argument to integer to allow adaptive vsync
- 18.12.22	- ReadTextureData - use std::unique_ptr to create intermediate invert buffer\
			  OpenDeviceKey use std::string "at" instead of direct index\
			  Catch any exception by using cleanup functions in destructor\
- 19.12.22	- Add DoDiagnostics to create a log file for CreateInterop failure
- 22.12.22	- Compiler compatibility testing\
			  Remove std::unique_ptr and go back to new/delete\
			  Change all {} initializations to "={}"
- 30.12.22	- Check and confirm fix for issue #85 and PR #86\
			  Check and confirm fix for issue #87
- 05-01-23	- ReadGLDXtexture - Test for no texture read or zero texture\
			  moved to the beginning to avoid redundant texture lock.

SpoutGLextensions.cpp
- 18.03.22	- Change LogLevel to ExtLoglevel to make unique for ExtLog function\
			  Change to C++11 enum class for ExtLogLevel to isolate the definitions
- 14.04.22	- Change back to C enums for compatibility with earlier compilers.\
			  Rename ExtLoglevel enum names to be more strongly unique.\
			  Add option in SpoutCommon.h to disable warning 26812 (unscoped enums).
- 18.04.22	- Add glCheckNamedFramebufferStatus
- 17.12.22	- Some cleanup for code analysis
- 22.12.22	- Compiler compatibility check

SpoutReceiver.cpp
- 18.04.22	- Change default invert from true to false for fbo sending functions
- 31.10.22	- Add GetPerformancePreference, SetPerformancePreference, GetPreferredAdapterName
- 01.11.22	- Add SetPreferredAdapter
- 03.11.22	- Add IsPreferenceAvailable
- 07.11.22	- Add IsApplicationPath
- 14.12.23	- Remove SetAdapter. Requires OpenGL setup.

SpoutSender.cpp
- 31.10.22	- Add GetPerformancePreference, SetPerformancePreference, GetPreferredAdapterName
- 01.11.22	- Add SetPreferredAdapter
- 03.11.22	- Add IsPreferenceAvailable
- 07.11.22	- Add IsApplicationPath
- 26.11.22	- Change SetVerticalSync argument to integer to allow adaptive vsync

SpoutSenderNames.cpp
- 29.03.22 - change int len to size_t len in setActiveSenderName
- 25.04.22 - Add create memory check and warning logs to setActiveSenderName\
		   Remove duplicate shared memory creation in RegisterSenderName\
		   GetActiveSender - rename temp name string to be more clear
- 09.05.22 - Include SPOUT_ALREADY_CREATED for setActiveSenderName create shared memory success
- 30.07.22 - Throughout - remove redundant code
- 28.10.22 - Code documentation
- 31.10.22 - Include SPOUT_ALREADY_EXISTS for setActiveSenderName create shared memory success
- 13.12.22 - Add SpoutLogWarning to CleanSenders when an orphaned sender is removed
- 17.12.22 - Some cleanup for code analysis
- 22.12.22 - Compiler compatibility check
	
SpoutSharedMemory.cpp
- 14.04.22 - Add option in SpoutCommon.h to disable warning 26812 (unscoped enums).
- 28.10.22 - Code documentation
- 18.12.22 - Catch any exception from using Close in destructor

SpoutUtils.cpp
- 25.02.22 - OpenSpoutConsole - check AllocConsole error for existing console\
		   Fix for Processing.
- 14.04.22 - Add option in SpoutCommon.h to disable warning 26812 (unscoped enums)
- 23.06.22 - Add ElapsedMicroseconds (usec since epoch)
- 30.10.22 - Code cleanup and documentation
- 01.11.22 - Add IsLaptop(char* computername)
- 30.11.22 - Update Version to "2.007.009"
- 05.12.22 - Change ordering of _logtofile function to avoid ambiguous warning.\
		   GetSpoutLog - optional log file argument. Remove redundant file open.\
		   See SpoutSettongs "Log" option.
- 07.12.22 - EnableSpoutLogFile allow null file name argument.\
		   If a file name was not specified, use the executable name.\
		   Use "GetCurrentModule" instead of NULL for GetModuleFileNameA\
		   in case the process is a dll (https://gist.github.com/davidruhmann/8008844).
- 08.12.22 - _dolog - clean up file log code.\
		 - Corrected ExecuteProcess for EndTiming milliseconds return.
- 11.12.22 - Initialize all char arrays and structures with {}\
		   https://en.cppreference.com/w/cpp/language/zero_initialization
- 14.12.22 - Add RemoveSpoutLogFile
- 18.12.22 - Add buffer size argument to ReadPathFromRegistry\
		   Correct code review warnings where possible\
		   Add more documentation to Group: Logs
- 19.12.22 - Add GetCurrentModule / LogsEnabled / LogFileEnabled / GetSpoutLogPath
- 20.12.22 - Add SPOUT_DLLEXP to all header function declarations for dll export.\
		 - Code cleanup
- 22.12.22 - Compiler compatibility check\
		   Change all {} initializations to "={}"
- 31.12.22 - increase log char buffer from 512 to 1024
- 01.12.22 - Registry functions\
		     check for empty subkey and valuename strings\
			 include valuename in warnings

SpoutDX.cpp
- 01.11.22	- Add GetPerformancePreference, SetPerformancePreference,\
			  GetPreferredAdapterName, SetPreferredAdapter
- 08.11.22	- Add IsPreferenceAvailable, IsApplicationPath
- 16.11.22	- HoldFps double fps argument instead of int
- 26.12.22	- Initialize all arrays and structures\
			  Const arg for SendImage
			  
SpoutLibrary.cpp
- 21.03.22 - Change local LogLevel enum to more unique SpoutLibLogLevel\
		   Initialize Spout object pointer
- 11.04.22 - Option disable warning C26812 (unscoped enums) for Visual Studio
- 10.05.22 - Correct OpenSpoutConsole to use "spoututils::"
- 12.05.22 - Rebuild VS2022 - 32/64 bit /MD\
		   Spout Version 2.007.008
- 31.10.22 - Add GetPerformancePreference, SetPerformancePreference, GetPreferredAdapterName\
		   Corrected SpoutLog to use _dolog
- 01.11.22 - Add SetPreferredAdapter, GetSDKversion, IsLaptop
- 03.11.22 - Add IsPreferenceAvailable
- 25.22.33 - Revise SpoutSenderNmaes UpdateSenderFps / HoldFps\
		   Add GetRefreshRate
- 30.11.22 - Add IsApplicationPath
- 22.12.22 - Compiler compatibility check\
		   Conditional compile of preference functions
- 26.12.22 - Add missing SPOUT_LOG_NONE to SpoutLibLogLevel\
		   Rebuild release VS2022 - 32/64 bit /MD\
		   Spout Version 2.007.009

INSTALL folder
- Header and library files from INSTALL build with CMake
- Update CMake documentation for INSTALL build

Examples updated
- Cinder
- ofExample Graphics Sender/Receiver
- SpoutDX Tutorial04 - code comment update for HoldFps

User binaries updated
- Demo Sender/Receiver rebuild
- SpoutSettings
	Allows user access to Windows Graphics Preferences directly.\
	Diagnostics extended.
- SpoutPanel
	Show more information about the sender texture, computer type, graphics adapters present and the one used by the sender application.


===================================\
26-07-21\
Update Master from Beta branch.\
Version 2.007.003

Spout.cpp
- 22.06.21 - Move code for GetSenderCount and GetSender to SpoutSenderNames class
- 03.07.21 - Use changed SpoutSenderNames "GetSender" function name.
- 04.07.21 - Additional code comments concerning update in ReceiveTexture.

SpoutCopy.cpp
- 09.07.21 - memcpy_sse2 - return for null dst or src
 
SpoutDirectX.cpp
- 19.06.21 - Remove output check from FindNVIDIA	

SpoutFrameCount.cpp
- 21.07.21 - Remove debug comment
 
SpoutGL.cpp
- 26.07.21 - Remove memorysize check from GetMemoryBufferSize for receiver
 
SpoutSenderNames.cpp
- 22.06.21 - Restore 2.006 GetSenderNames function
- 03.07.21 - Change GetSenderNames to GetSender to align with Spout class.\
  Change existing GetSender to FindSenderName.\
  Change duplicate FindSenderName to FindSender overload\
  testing function
  
SpoutUtils.cpp
- 26.07.21 - Update Version to "2.007.003"

BUILD binaries updated
- CMake build 32/64bit /MD - requires Visual Studio 2017 runtime to be installed

===================================\
14-06-21\
Update Master from Beta branch\
Version 2.007.002

Spout.cpp
- ReceiveSenderData : Check if the name is in the sender list
- Add GetSenderGLDXready() for receiver
- Add SetSenderID
- Rename functions GetSenderCPU and GetSenderGLDX
- memoryshare.CloseSenderMemory() in ReleaseSender
- IsFrameNew - return frame.IsFrameNew()
- memoryshare.CloseSenderMemory() in ReleaseReceiver
- Add event functions SetFrameSync/WaitFrameSync
- Add data functions WriteMemoryBuffer/ReadMemoryBuffer
- Close sync event in ReleaseSender
- SendFbo - protect against fail for default framebuffer if iconic
- ReceiveTexture - return if flagged for update only if there is a texture to receive into.
- ReceiveTexture - allow for the possibility of a 2.007 sender with 2.006 memoryshare mode for data functions.

SpoutCopy.cpp
- Change CopyPixels and FlipBuffer to accept GL_LUMINANCE

SpoutDirectX.cpp
- Add zero width/height check to CreateDX11Texture

SpoutFrameCount.cpp
- Add sync event functions SetFrameSync/WaitFrameSync/OpenFrameSync/CloseFrameSync
- CloseFrameSync public for use by other classes
- WaitFrameSync - close handle on error
  
SpoutGL.cpp
- Introduced m_bTextureShare and m_bCPUshare flags to handle mutiple options
- WriteDX11texture, ReadTextureData, OpenSpout, LoadGLextensions cleanup
- OpenSpout look for DirectX to prevent repeat
- Change m_bSenderCPUmode to m_bSenderCPU
- Add m_bSenderGLDX
- Change SetSenderCPUmode to include CPU sharing mode and GLDX compatibility
- Change SetSenderCPUmode name to SetSenderID
- Add m_bMemoryShare for possible older 2.006 apps
- Add memoryshare.CreateSenderMemory
- memoryshare.CloseSenderMemory() in destructor
- Add WriteMemoryPixels
- Change ReadMemoryPixels to accept GL_LUMINANCE
- Use reinterpret_cast for memoryshare.LockSenderMemory()
- Remove m_bNewFrame
- Add memoryshare.GetSenderMemoryName()
- Disable frame sync in destructor
- Change ReadMemory to ReadMemoryTexture
- Add GetSenderMemory
- Remove ReadMemoryBuffer open error log
- Remove memoryshare struct from header and replace with SpoutSharedMemory object.
- Close shared memory and sync event in SpoutGL class destructor
- Add GetMemoryBufferSize
- Add CreateMemoryBuffer, DeleteMemoryBuffer
- All data functions return false if 2.006 memoryshare mode.
  
SpoutReceiver.cpp
- Add GetCPUshare and SetCPUshare
- Add GetSenderGLDXready
- Rename functions GetSenderCPU and GetSenderGLDX
- Add event functions SetFrameSync/WaitFrameSync
- Add data function ReadMemoryBuffer
- Add OpenGL shared texture access functions
- Add GetMemoryBufferSize

SpoutSender.cpp
- Add GetCPUshare and SetCPUshare
- Add event functions SetFrameSync/WaitFrameSync
- Add data function WriteMemoryBuffer
- Add GetCPU and GetGLDX
- Add OpenGL shared texture access functions
- Add CreateMemoryBuffer, DeleteMemoryBuffer, GetMemoryBufferSize

SpoutSenderNames.cpp
- GetActiveSender - erase the active sender memory map if the sender info is closed
- Change SetSenderCPUmode to include CPU sharing mode and GLDX compatibility
- Change SetSenderCPUmode name to SetSenderID
- Add GetSender to retrieve class sender.
- Remove SenderDebug

SpoutUtils.cpp
- Add std::string GetSDKversion()
- Fix code if USE_CHRONO not defined
- Disable close button on console and bring the main window to the top again
- Remove noisy warning from ReadPathFromRegistry
- Update version number to "2.007.002"

SpoutDirectX
- Add SpoutDX9 support class and examples
- Add SpoutDX12 support class and examples

SpoutDX.cpp
- SetNewFrame before texture copy
- Add memoryshare struct, ReadMemoryBuffer and WriteMemoryBuffer
- memoryshare.CloseSenderMemory() in destructor and ReleaseSender
- Add SetFrameSync and WaitFrameSync

Examples
- Add Cinder example

ofSpoutExample
- Add binaries
- Add Data sender/receiver examples
- Update source and binaries

SpoutPanel.exe
- Update compatible texture formats. Vers 2.43

Cmake build
- Update for 32/64 bit - Spout.dll, SpoutLibrary.dll, SpoutDX.dll, Spout_static.lib
