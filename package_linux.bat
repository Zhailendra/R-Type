
echo "Creating release directory..."
if not exist "release-windows" mkdir "release-windows"
cd release-windows
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release
make install

xcopy /s/e/y ..\assets .
xcopy /s/e/y ..\maps .

Compress-Archive -Path ../release-windows -DestinationPath ../release-windows.zip
