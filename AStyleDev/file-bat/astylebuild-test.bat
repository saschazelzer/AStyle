@echo off
REM call the astylebuild batch files for testing
REM the VS project files will use the macro $(FrameworkVersion) 
REM     or $(TargetedRuntimeVersion)

REM vs2005
REM vs2008
REM vs2010
REM debug
REM release

call astylebuild-dll-TEST vs2008 debug

REM pause
