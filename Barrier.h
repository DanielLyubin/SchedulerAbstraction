//
// Created by dani9 on 09/11/2019.
//

#ifndef UNTITLED_BARRIER_H
#define UNTITLED_BARRIER_H

#include <mutex>
#include <condition_variable>
struct Barrier {
    std::mutex mutex;
    std::condition_variable conditionVariable;
};
#endif //UNTITLED_BARRIER_H
