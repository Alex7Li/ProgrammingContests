cmake_minimum_required(VERSION 3.15)
project(CLion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-sign-compare -D _GLIBCXX_DEBUG -D _GLIBCXX_DEBUG_PEDANTIC")


add_executable(Codeforces/1560E.cpp Codeforces/1560E.cpp)

if (FALSE)
    add_executable(A A.cpp)
    add_executable(B B.cpp)
    add_executable(C C.cpp)
    add_executable(D D.cpp)
    add_executable(E E.cpp)
    add_executable(F F.cpp)
    add_executable(G G.cpp)
    add_executable(H H.cpp)
    add_executable(I I.cpp)
    add_executable(J J.cpp)
    add_executable(K K.cpp)
endif ()
