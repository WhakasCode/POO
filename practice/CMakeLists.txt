cmake_minimum_required(VERSION 3.6)
project(practice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Droide.cpp Droide.h
        Informe.cpp Informe.h Piloto.h Piloto.cpp
        Pieza.cpp Pieza.h StarFighter.cpp StarFighter.h Escuadron.cpp Escuadron.h)
add_executable(practice ${SOURCE_FILES})