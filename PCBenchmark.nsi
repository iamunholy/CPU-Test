; Define the name of the installer
Name "PC Benchmark"

; Define the output file name
OutFile "PCBenchmarkInstaller.exe"

; Define the default installation directory
InstallDir $PROGRAMFILES\PCBenchmark

; Request application privileges for Windows Vista and higher
RequestExecutionLevel admin

; Pages to show in the installer
Page directory ; Allow the user to choose the installation directory
Page instfiles ; Show the installation progress

; Sections define the components to install
Section "MainSection" ; Define a section named "MainSection"

; Set the output path to the installation directory
SetOutPath $INSTDIR

; Include your main executable
File "D:\Programs\Performance Test\PCBenchmark.exe"

; Include any required DLLs or other files
File "D:\C++ Extension\ucrt64\bin\libgcc_s_seh-1.dll"

; Create a shortcut in the Start Menu
CreateShortcut "$SMPROGRAMS\PC Benchmark.lnk" "$INSTDIR\PCBenchmark.exe"

; Create an uninstaller
WriteUninstaller "$INSTDIR\Uninstall.exe"

; End of the section
SectionEnd

; Uninstall Section
Section "Uninstall"

; Remove installed files
Delete "$INSTDIR\PCBenchmark.exe"
Delete "$INSTDIR\libgcc_s_seh-1.dll"

; Remove shortcuts
Delete "$SMPROGRAMS\PC Benchmark.lnk"

; Remove uninstaller
Delete "$INSTDIR\Uninstall.exe"

; Remove the installation directory
RMDir "$INSTDIR"

; End of the uninstall section
SectionEnd


