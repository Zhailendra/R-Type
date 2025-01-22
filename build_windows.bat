echo "Installing dependencies"
git submodule update --init --recursive
echo "Creating build directory..."
if not exist "build-windows" mkdir "build-windows"
cd build-windows
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release
xcopy /y/s r-type-client.exe ..\r-type-client.exe
xcopy /y/s r-type-server.exe ..\r-type-server.exe