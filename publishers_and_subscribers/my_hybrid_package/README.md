# MY_HYBRID_PACKAGE
A hybrid ROS 2 package containing both a Python publisher and a dual setup of C++ and Python subscribers sharing the same topic.  
- While this package demonstrates that you can put C++ and Python in the same package using ament_cmake_python, it is highly recommended to build separate packages for different languages.
- A cpp node doesn't know or care that a python node wrote the message, as long as they both use the same message type. Can create separate packages that each use one language, but share the topic, and build the two packages that communicate to each other

## Creating the package
1. Navigate to workspace source directory/ where you wanna store the package
cd /home/kitana/ros2_ws/src/dojo2026/publishers_and_subscribers/hybrid
2. Run command to create package, modifying package name, maintainer name and email, and other flags if necessary
ros2 pkg create --build-type ament_cmake my_hybrid_package \
    --dependencies rclcpp rclpy std_msgs\
    --license Apache-2.0 \
    --maintainer-name "Amy Kibara" \
    --maintainer-email "amy.kibara@gmail.com" \
    --description "This is a hybrid ROS 2 package containing both C++ and Python nodes."
## Edits
- Add shebang line at the start of python file  
`#!/usr/bin/env python3`
- Confirm dependencies in package.xml and add the Python build tool inside the <package> tags
`<buildtool_depend>ament_cmake_python</buildtool_depend>`
- In CMakeList.txt add dependencies, executables, installs
```
# Find both C++ and Python tools
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# NOTE: Do NOT put rclpy in this list! 
# C++ nodes cannot link against Python libraries.
set(dependencies
  rclcpp
  std_msgs
)

include_directories(
  include
)

# --- C++ Executables ---
add_executable(my_node_c src/my_cpp_sub.cpp)
ament_target_dependencies(my_node_c ${dependencies})

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS my_node_c
  DESTINATION lib/${PROJECT_NAME}
)

# --- Python Executables ---
# Install Python modules for import
ament_python_install_package(${PROJECT_NAME})

# Install Python scripts
install(
  PROGRAMS
  my_hybrid_package/my_py_pub.py
  my_hybrid_package/my_py_sub.py
  DESTINATION lib/${PROJECT_NAME}
)

# Add this BEFORE ament_package()
ament_export_include_directories(include)
```

## Building
Any errors in the source code (e.g syntax errors) will cause the build to fail or runtime errors
1. Navigate to root of workspace and build the specific package
```
cd ~/ros2_ws
colcon build --packages-select my_hybrid_package
source install/setup.bash
```

Note: To create a build alias in your .bashrc that bundles both commands (building and installing) into a single command:
```
alias colcon_source="colcon build && source install/setup.bash"
```

2. Run the executables
A) Manually using run command (name of executable defined in CMakeLists.txt). Three terminals for three running nodes.  
List executables if unsure of executable name:
```
ros2 pkg executables my_hybrid_package
```
This outputs the results as `package_name executable_name`  
Terminal 1:
```
ros2 run my_hybrid_package my_node_c
```
Terminal 2:
```
ros2 run my_hybrid_package my_node_c
```
Terminal 3:
```
ros2 run my_hybrid_package my_node_c
```

If rebuilding after debugging is necessary, remove previous installs then build again, still in the root of the ROS 2 workspace (~/ros2_ws)
```
cd ~/ros2_ws
rm -rf build/ install/ log/
```

B) Using launch file  
I) In the package folder (at the same level as setup.py), create a folder named launch.  
II) Create a launch file (ends in `.launch.py`) and write it out.  
III) In CMakeLists.txt, add this block near the bottom before the`ament_package()`line.
```
# Install launch files so ROS 2 can find them
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
```
IV) Build, source and run using `ros2 launch` command
```
ros2 launch my_hybrid_package hybrid_launch.launch.py
```

3. Testing
- Skip testing, make them always pass or make your code align with standards








