cmake_minimum_required(VERSION 3.15)
project(SchedulerAbstraction)

set(CMAKE_CXX_STANDARD 14)

add_executable(SchedulerAbstraction main.cpp IThreadRegisterer.h IScheduler.h Scheduler.h Thread.h Thread.cpp ThreadProperties.h Scheduler.cpp Barrier.h)