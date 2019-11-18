![Logo](https://github.com//Solisuom/Mahjong/blob/master/resources/Screenshots/Logo.png?raw=true)


## Windows
**1. Install a C++11 compiler:**  
MinGW https://osdn.net/projects/mingw/releases/

**2. Install Git:**  
	https://git-scm.com/downloads

**3. Install CMake:**  
	https://cmake.org/download

**4. Install OpenAL:**  
	https://www.openal.org/downloads

**5. Open git-bash and type:**  
```console
git clone https://github.com/Solisuom/Mahjong.git --recursive
cd Mahjong 
mkdir build && cd build
cmake ..
cmake --build . --config Release
./Mahjong
```

## Ubuntu
**1. install git cmake and g++**
```console
sudo apt-get -y install cmake git g++ 
```

**2. install additional packets (OpenGL, OpenAL etc)**
```console
sudo apt-get -y install libx11-dev libudev-dev xorg-dev freeglut3-dev libalut-dev libvorbis-dev libflac-dev
```

**3. download Space Invaders repository**
```console
git clone https://github.com/Solisuom/Mahjong.git --recursive
```

**4. build project** 
```console
cd Mahjong
mkdir build && cd build
cmake ..
cmake --build . --config Release
./Mahjong
```
