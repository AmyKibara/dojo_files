cmake_minimum_required(VERSION 3.8)
project(my_hybrid_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(dependencies
  rclcpp
  std_msgs
)

include_directories(
  include
)

add_executable(my_node_c src/my_cpp_sub.cpp)
ament_target_dependencies(my_node_c ${dependencies})

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS
  my_node_c
  DESTINATION lib/${PROJECT_NAME}
)

#Install python modules for import
ament_python_install_package(${PROJECT_NAME})

# add this section to install py scripts
install(
  PROGRAMS
  my_hybrid_package/my_py_pub.py
  my_hybrid_package/my_py_sub.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)

ament_package()
