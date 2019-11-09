//
// Created by dani9 on 08/11/2019.
//

#ifndef UNTITLED_ITHREADREGISTERER_H
#define UNTITLED_ITHREADREGISTERER_H

class Thread; // Forward declaration
class IThreadRegisterer {
public:
    virtual bool RegisterThread(Thread *) = 0;
    virtual ~IThreadRegisterer() = default;
};

#endif //UNTITLED_ITHREADREGISTERER_H
