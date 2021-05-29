cmake_minimum_required(VERSION 3.17)
project(DataStructureCPP)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructureCPP main.cpp util/util.h util/util.cpp sort/quick_sort.h stack/Stack.cpp stack/Stack.h)

# allow multi-main
file(GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()