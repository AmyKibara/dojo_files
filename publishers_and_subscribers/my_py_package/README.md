# MY_PY_PACKAGE
Contains a python node with multiple publishers of different data types and respective subscribers all in the same file. Execution entails logging out the subscription messages to the terminal.
## Creating the package
ros2 pkg create --build-type ament_python my_py_package \
  	--dependencies rclpy std_msgs \
  	--license Apache-2.0 \
  	--maintainer-name "Amy Kibara" \
  	--maintainer-email "amy.kibara@gmail.com" \
  	--description "This is a custom ROS 2 package for a Python node."

## Editing config files
- Confirm dependencies (all libraries to be imported) in package.xml
- In setup.py, in the entry point, define your executables

## Building
1. Navigate to root of workspace and build the specific package
```
cd ~/ros2_ws
colcon build --packages-select my_py_package
source install/setup.bash
```

Note: To create a build alias in your .bashrc that bundles both commands (building and installing) into a single command:
```
alias colcon_source="colcon build && source install/setup.bash"
```

2. Run the executable 
Any errors in the source code will fail at runtime
A) Manually using run command (name of executable defined in setup.py). 
```
ros2 run my_py_package py_node_a
```
If unsure of executable name:
```
ros2 pkg executables my_py_package
```
This outputs the results as `package_name executable_name`

If rebuilding after debugging is necessary, remove previous installs then build again, still in the root of the ROS 2 workspace (~/ros2_ws)
```
rm -rf build/ install/ log/
```

B) Using launch file  
I. In the package folder (at the same level as setup.py), create a folder named launch.  
II. Create a launch file (ends in `.launch.py`) and write it out.  
III. In setup.py modify the data_files array to include the launch directory
```
#In the data_files add this line, as well as `import os` and `from glob import glob`
(os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
```
Build, source and run using `ros2 launch` command
```
ros2 launch my_py_package my_py_launch.launch.py
```


3. Testing
- Skip testing, make them always pass or make your code align with standards


