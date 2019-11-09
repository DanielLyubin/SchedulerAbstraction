//
// Created by dani9 on 08/11/2019.
//

#ifndef UNTITLED_ISCHEDULER_H
#define UNTITLED_ISCHEDULER_H

#include "IThreadRegisterer.h"
class IScheduler : public IThreadRegisterer {
public:
    virtual void Start() = 0;
    virtual void End() = 0;
};

#endif //UNTITLED_ISCHEDULER_H
