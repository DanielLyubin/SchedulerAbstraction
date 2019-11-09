//
// Created by dani9 on 08/11/2019.
//

#include "Scheduler.h"
#include "Thread.h"
#include <algorithm>
void Scheduler::Start() {
    m_schedulingBarrier.conditionVariable.notify_one();
}

void Scheduler::End() {
    m_ended = true;
    m_schedulerThread.join();
}

bool Scheduler::RegisterThread(Thread *thread) {
    {
        std::lock_guard<std::mutex> lockGuard(m_threadListMutex);
        if (m_ended)
            return false;
        m_pendingThreads.push_back(thread);
    }
    std::unique_lock<std::mutex> runBarrierLock(m_runBarrier.mutex);
    m_runBarrier.conditionVariable.wait(runBarrierLock);
    return !m_ended;
}

Scheduler::Scheduler() : m_schedulerThread([this] {
    std::unique_lock<std::mutex> startScheduleLock(m_schedulingBarrier.mutex);
    m_schedulingBarrier.conditionVariable.wait(startScheduleLock);
    while (!m_ended) {
        WaitForNewThreads();
        ActivateNewThreads();
    }
    m_runBarrier.conditionVariable.notify_all();
    std::for_each(m_pendingThreads.begin(), m_pendingThreads.end(), [](Thread * t) { t->Join();});
    std::for_each(m_threads.begin(), m_threads.end(), [](Thread * t) { t->Join();});
}), m_ended(false) {}

void Scheduler::WaitForNewThreads() {
    size_t size = 0;
    while (size == 0 && !m_ended) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lockGuard(m_threadListMutex);
        size = m_pendingThreads.size();
    }
}

void Scheduler::ActivateNewThreads() {
    std::lock_guard<std::mutex> lockGuard(m_threadListMutex);
    m_threads.insert(m_threads.end(), m_pendingThreads.begin(), m_pendingThreads.end());
    m_pendingThreads.clear();
    m_runBarrier.conditionVariable.notify_all();
}

Scheduler::~Scheduler() = default;

