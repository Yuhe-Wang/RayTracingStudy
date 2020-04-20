Rem This script assumes VS2019 is installed by default position

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
set "GEN=Visual Studio 16 2019"
set BuildType=Release
if not exist build (
mkdir build
cd build
call cmake -G "%GEN%" ..
cd ..
)
start build\RayTracingStudy.sln

