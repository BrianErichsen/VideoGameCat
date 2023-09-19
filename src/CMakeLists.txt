#the project contains an executable named testSFML that uses the following cpp files
add_executable(testSFML)
target_sources(testSFML PRIVATE
  helloSFML.cpp
  Classes.cpp
)
#create a folder named "cmake" at the top of your project and put the
#findSFML.cmake file in it.  This line tells Cmake to look there for
#find____.cmake files
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

#this says find the graphics, window, and system libraries
#it uses the FindSFML.cmake file to do so and sets
#some variables ($SFML_LIBRARIES and SFML_INCLUDE_DIRECTORIES) that are
#used below
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

#tells Cmake that the asteroids executable needs to be linked with SFML
target_link_libraries(testSFML sfml-graphics)

#passes an option to clang when compiling to use recent c++ stuff
target_compile_options(testSFML PUBLIC -std=c++17)