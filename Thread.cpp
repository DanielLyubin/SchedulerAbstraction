//
// Created by dani9 on 08/11/2019.
//

#include "Thread.h"
#include "ThreadProperties.h"
Thread::Thread(const ThreadProperties & properties): m_thread([this, properties] {
    if (properties.threadRegisterer.RegisterThread(this))
        properties.func();
}) {

}

void Thread::Join() {
    m_thread.join();
}
