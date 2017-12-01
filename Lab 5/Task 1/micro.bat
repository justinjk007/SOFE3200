@echo off
title Lab 5 task 1
echo This batch script will open Microsoft Visual Studio 2017 and DOS cmd.
pause
echo OpeningMSVS2017
START C:\"Program Files (x86)"\"Microsoft Visual Studio"\2017\Professional\Common7\IDE\devenv.exe
echo Opening cmd 
START cmd /k echo This window was opened with a batch script.
