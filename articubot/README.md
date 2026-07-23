# Simulation Tutorials

## 1. Package creation
```
ros2 pkg create --build-type ament_cmake articubot \
        --dependencies rclcpp rclpy \
        --license Apache-2.0 \
        --maintainer-name "Amy Kibara" \
        --maintainer-email "amy.kibara@gmail.com" \
        --description "Simulation tutorials"
```
Editing cmake lists to include new folders
```
# Install launch, description, config, meshes, and worlds directories to the share folder
install(
  DIRECTORY launch description config meshes worlds
  DESTINATION share/${PROJECT_NAME}
)

```
Building done in main workspace with specific package name 
```
cd ~/ros2_ws
colcon build --packages-select articubot && source ~/ros2_ws/install/setup.bash
```


## 2. Subfolders 
Within src, create the following folders:
`config` : contains rviz files
`description`: contains xacro files (bot_core.xacro, bot.urdf.xacro)
`launch` : contains launch files
`worlds` : contains simulation models for worlds
`meshes` : contains imported STL files

## 3. URDF and Xacro files
Can have multiple spilt up xacros all linked to one main file
### Links
Properties defined under `visual`, `inertial`, `collision`
1. Visual: shape color texture material
2. Inertial: mass inertia
3. Collision: boundaries of geometries, not as complicated as the visual, used for contact physics

- Origin of inertial properties to match the ones in visual
- Inertial properties define mass distribution,size/form, can be condensed into an inertial_macros xacro to keep the urdf file clean then imported
- Meshing done in visual and collision, CAD models imported as STL files and linked to in geometry, meshes kept in `meshes` folder. 

### Joints
Properties under `type`, `parent`, `child`
1. Type: revolute (fixed span of rotation), fixed (fully constrained), continuous (infinite rotations), prismatic (sliding along one axis), planar (about a plane), floating (unconstrained)
2. Parent / child: primary secondary


### Edits
Introduction
```
<?xml version="1.0"?>
<robot xmlns:xacro="http://www.ros.org/wiki/xacro">
</robot>
```

Within the <robot></robot> is where the code goes.
a) Includes - imported xacro files
```
<xacro:include filename="path_to_xacro_file"/>
```
b) Material definition
material colors, e.g:
```
<material name = "white">
    <color rgba="1 1 1 1"/>
</material>
```
c) Links and joints - Ideally define a link together with its joint
Defining the link - define all three parameters
```
<link name="right_wheel">
        <visual>
            <geometry>
                <cylinder radius="0.05" length="0.04"/>
            </geometry>
            <material name="blue"/>
        </visual>
        <collision>
            <geometry>
                <cylinder radius="0.05" length="0.04"/>
            </geometry>
        </collision>
        <xacro:inertial_cylinder mass="0.5" length="0.04" radius="0.05">
            <origin xyz="0 0 0" rpy="0 0 0"/>
        </xacro:inertial_cylinder>
    </link>
```
Note: 
- Base link set between the center of the two drive wheels, other parts described referenced from that origin.
- Axes such that  x-forward; y-left; z-up (right-hand with x-index finger, y-middle finger, z-thumb);
- S.I. units are used (kg, metres)

Defining the joint
```
<joint name="chassis_joint" type="fixed">
    <parent link="base_link" />
    <child link="chassis" />
    <origin xyz="-0.1, 0, 0" />
</joint>
```

## 4. Launch files and configuration files
#### Launching
RViz requires a URDF/Xacro description of the robot, and tf transforms (coordinate frame transformations connecting the ase, wheel, etc). `robot_state_publisher` is a node that listens to joint angles (/joint_states) and calculated 3D math to broadcast TF transforms. Almost every robot visualization needs `robot_state_publisher` so its often isolated in rsp.launch.py so other launch files can include it. 
#### Launch file structure
```
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    # Get the path to the robot description file
    pkg_path = os.path.join(get_package_share_directory('package_name'))
    xacro_file = os.path.join(pkg_path, 'description', 'urdf.xacro_file')

    # Process xacro file into plain URDF XML string
    robot_description_config = xacro.process_file(xacro_file).toxml()

    # Create a robot_state_publisher node
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{
            'robot_description': robot_description_config,
            'use_sim_time': False #set to true for simulation in gazebo, leave as false for real physical hardware or rviz and jsp sims
            }]
    )

    # Launch!
    return LaunchDescription([
        node_robot_state_publisher
    ])
```
Build the package. Can use symlink install to keep track of edits within exixting files. Adding new files requires rebuilding. To build a specific package e.g. articubot `colcon build --symlink-install --packages-select articubot && source install/setup.bash`
##### Terminal 1 - launching rsp:
```
#within root of wworkspace, buiild and install
cd ~/ros2_ws && colcon build --symlink-install --packages-select articubot && source install/setup.bash
#launch
ros2 launch articubot rsp.launch.py
```
rsp.launch.py only starts robot_state_publisher—it doesn't open RViz automatically unless you tell it to. It can be opened in a new terminal or it can also be added to the launch file, or to a `display.launch.py`. The GUI publisher also has to be launched. 
##### Terminal 2 - launching rsp gui publisher:
```
source ~/ros2_ws/install/setup.bash
ros2 run joint_state_publisher_gui joint_state_publisher_gui
```
##### Terminal 3 - launching rviz:
```
source ~/ros2_ws/install/setup.bash
rviz2
```
`Fixed frame` is set to base_link, click `Add` and select `RobotModel`, and in the RobotModel properties, set `Description Topic` to `/robot_description`. To see axes, click `Add` and select `TF`. The axes can be moved using the jsp gui.
 
##### Terminal 4 - topic list
Verify topics via terminal
```
ros2 topic echo /robot_description
ros2 topic echo /joint_states
ros2 run tf2_tools view_frames
```

#### Configurations 
Save basic states as rviz files within the configs folder. On rviz, click `file`->`save config as`->save to configs folder. Launch jsp before launching this. If previous states dont come up before, just save again. It should launch you robot as you left it
```
rviz2 -d box-1.rviz
```

## 5. Gazebo setup

- Launch rsp with sim_time = true to synchronize time with gazebo
```
ros2 launch articubot rsp.launch.py use_sim_time:=true
#verify in a new terminal 
ros2 param get /robot_state_publisher use_sim_time
```
- Launch with launch file 
```
ros2 launch gazebo_ros gazebo.launch.py
```
-Spawn robot into opened sim
```
ros2 run gazebo_ros spawn_entity.py -topic robot_description -entity bot_name
```
- Create a launch file that included rsp,   


#### TO-DO
diff btwn lauch file and node
colcon ignore
share directory
if build == build_1 then colcon build_1 ?
can i use hex to define my material colors
what does the a in rgba stand for
what if i have four drive wheels where does my base link go
Can i do size instead of xyz