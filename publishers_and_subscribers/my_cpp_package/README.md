# MY_CPP_PACKAGE
Contains a python node with multiple publishers of different data types and respective subscribers all in the same file. Execution entails logging out the subscription messages to the terminal.

## Creating the package
ros2 pkg create --build-type ament_cmake my_cpp_package \
  	--dependencies rclcpp std_msgs \
  	--license Apache-2.0 \
  	--maintainer-name "Your Name" \
  	--maintainer-email "amy.kibara@gmail.com" \
  	--description "This is a custom ROS 2 package for a C++ node."

## Editing Config files
- Confirm dependencies (all libraries to be imported) in package.xml
- In CMakeLists.txt, add dependencies, executables, installs
```
set(dependencies
  rclcpp
  std_msgs
)
//if have more executables, add more executables following the same format

add_executable(my_node_b src/node_b.cpp)
ament_target_dependencies(my_node_b ${dependencies})

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS
  my_node_b
  DESTINATION lib/${PROJECT_NAME}
)
```

## Building
Any errors in the source code (e.g syntax errors) will cause the build to fail
1. Navigate to root of workspace and build the specific package
```
cd ~/ros2_ws
colcon build --packages-select my_cpp_package
source install/setup.bash
```

Note: To create a build alias in your .bashrc that bundles both commands (building and installing) into a single command:
```
alias colcon_source="colcon build && source install/setup.bash"
```

2. Run the executable  
A) Manually using run command (name of executable defined in CMakeLists.txt). 
```
ros2 run my_cpp_package my_node_b
```
If unsure of executable name:
```
ros2 pkg executables my_cpp_package
```
This outputs the results as `package_name executable_name`

If rebuilding after debugging is necessary, remove previous installs then build again, still in the root of the ROS 2 workspace (~/ros2_ws)
```
cd ~/ros2_ws
rm -rf build/ install/ log/
```

B) Using launch file  
I) In the package folder (at the same level as setup.py), create a folder named launch.  
II. Create a launch file (ends in `.launch.py`) and write it out.  
III) In CMakeLists.txt, add this block near the bottom before the`ament_package()`line.
```
# Install launch files so ROS 2 can find them
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
```
4. Build, source and run using `ros2 launch` command
```
ros2 launch my_cpp_package cpp_launch.launch.py
```


3. Testing
- Skip testing, make them always pass or make your code align with standards

