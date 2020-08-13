mkdir build
cd build
cmake ..
msbuild GenericServerAndClient.sln /p:Configuration=Release
msbuild GenericServerAndClient.sln /p:Configuration=Debug
pause