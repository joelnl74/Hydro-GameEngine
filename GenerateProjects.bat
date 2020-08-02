@echo off
pushd %~dp0\..\
call E:\Dev\Engine\Hydro-GameEngine\Vendor\bin\premake5.exe vs2019
popd
PAUSE