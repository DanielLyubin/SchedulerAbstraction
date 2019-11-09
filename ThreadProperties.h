//
// Created by dani9 on 08/11/2019.
//

#ifndef UNTITLED_THREADPROPERTIES_H
#define UNTITLED_THREADPROPERTIES_H
#include <functional>
#include <utility>
#include "IThreadRegisterer.h"
struct ThreadProperties {
    ThreadProperties(IThreadRegisterer& threadRegisterer,std::function<void()>  func):
    func(std::move(func)),
    threadRegisterer(threadRegisterer)
    {}

    std::function<void()> func;
    IThreadRegisterer& threadRegisterer;
    // add stuff for FreeRTOS
};

#endif //UNTITLED_THREADPROPERTIES_H
