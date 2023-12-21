cmake_minimum_required(VERSION 3.23)
project(graph-puzzle-game-ceren-oz)

set(graph-puzzle-game-ceren-oz)

add_executable(main.exe main.cpp  Edge.h  EdgeList.h  Graph.h  Queue.h )

add_library(graph-puzzle-game-ceren-oz main.cpp Edge.h EdgeList.h Graph.h Queue.h )