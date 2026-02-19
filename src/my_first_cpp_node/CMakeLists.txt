cmake_minimum_required(VERSION 3.8)
project(my_first_cpp_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# 告訴系統我們要編譯一個名為 hello_node 的執行檔，來源是 src/hello_node.cpp
add_executable(hello_node src/hello_node.cpp)

# 告訴系統這個執行檔需要用到 rclcpp 的函式庫
ament_target_dependencies(hello_node rclcpp)

# 告訴系統編譯完之後，要把執行檔放在哪裡（這樣 ros2 run 才找得到）
install(TARGETS
  hello_node
  DESTINATION lib/${PROJECT_NAME}
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

ament_package()
