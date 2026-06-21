# Cpp fundamentals 
Follows ROS2 cpp style guide: 
-max line length = 100 char
-camelCase for class names; snake_case for variable names; function names take either
## Installing gcc on ubuntu linux 
Only if c/cpp compiler missing from pc
```
sudo apt-get update
sudo apt-get install build-essential gdb
```
## compiling via the terminal
```
./myfile1
//alternatively {g++ file_name -output name_of_executable}
g++ myfile1.cpp -o myfile1
```
compiling with args
```
./myfile1 arg1 "arg2" arg345
```
## using external libraries
consider updating, then upgrading. Install if missing
```
sudo apt install libeigen3.dev
```
compiling with external libraries
```
g++ -I /usr/include/eigen3 myfile1.cpp -o myfile1
```

