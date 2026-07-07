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
Dependencies editted later on; building done in main workspace with specific package name 
```
cd ~/ros2_ws
colcon build --packages-select articubot && source ~/ros2_ws/install/setup.bash
```

## 2. Subfolders 
Within src, create the following folders:
`config`
`description`: Contains xacro files (bot_core.xacro, bot.urdf.xacro)
`launch`
`worlds`
`meshes` : Contains imported STL files

## 3. URDF and Xacro files


Can have multiple spilt up xacros all linked to one main file
### Links
Properties defined under `visual`, `inertial`, `collision`
1. Visual: shape color texture material
2. Inertial: mass inertia
3. Collision: boundaries of geometries, not as complicated as the visual, used for contact physics

Meshing done in visual and collision, CAD models imported as STL files and linked to in geometry, meshes kept in `meshes` folder. 

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
Within the <robot></robot>, define material colors, e.g:
```
<material name = "white">
    <color rgba="1 1 1 1"/>
</material>
```
Base link set between the center of the two drive wheels, other parts described referenced from that origin. Dimensioning in metres 
Axes such that  x-forward; y-left; z-up (right-hand with x-index finger, y-middle finger, z-thumb);

Defining the link
```
```
Defining the joint
```
<joint name="chassis_joint" type="fixed">
    <parent link="base_link" />
    <parent link="base_link" />
    <origin xyz="-0.1, 0, 0" />
</joint>
```

Origin of inertial properties to match the ones in visual




## 4. Launching





#### TO-DO
diff btwn lauch file and node
colcon ignore
share directory
if build == build_1 then colcon build_1 ?
can i use hex to define my material colors
what does the a in rgba stand for
what if i have four drive wheels where does my base link go