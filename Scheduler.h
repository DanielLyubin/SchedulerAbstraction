//
// Created by dani9 on 08/11/2019.
//

#ifndef UNTITLED_SCHEDULER_H
#define UNTITLED_SCHEDULER_H

#include "IScheduler.h"
#ifndef TARGET
#include <vector>
#include "Barrier.h"
#include <atomic>
#include <thread>
#else
#endif
class Scheduler : public IScheduler {
public:
    Scheduler();
    void Start() override;
    void End() override;
    bool RegisterThread(Thread *thread) override;
    ~Scheduler() override;
private:
#ifndef TARGET
    void WaitForNewThreads();
    void ActivateNewThreads();
    std::vector<Thread*> m_threads;
    std::vector<Thread*> m_pendingThreads;
    Barrier m_runBarrier,m_schedulingBarrier;
    std::thread m_schedulerThread;
    std::mutex m_threadListMutex;
    std::atomic_bool m_ended;

#else
#endif
};


#endif //UNTITLED_SCHEDULER_H
