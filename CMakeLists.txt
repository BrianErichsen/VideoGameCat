#To use cmake, you create a folder for all the compiled/build files
#and don't usually compile things in the same directory as your source files

#I usually do something like the following:
#for xcode:
#mkdir xcode
#cd xcode
#cmake -G Xcode .. #tells cmake to make an XCode project, and that the CMakelists.txt file is in the directory above
#you can then open the asteroids.xcodeproj file with xcode
#in product -> scheme, select asteroids to run that executable when you press
#the play button

# to use make, I do something like
#mkdir build
#cd build
#cmake .. #by default it creates a makefile for you
#make #calls the make command which looks in Makefile to see what to do
#./asteroids  #run the resulting file


#use a recent version of CMake
cmake_minimum_required(VERSION 3.15)

#the project is called asteroids
project(testSFML LANGUAGES CXX) 
add_subdirectory(src)