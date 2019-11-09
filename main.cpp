#include <iostream>
#include "Thread.h"
#include "Scheduler.h"
#include "ThreadProperties.h"
#include <mutex>
#include <atomic>
bool turn = true;
std::mutex gameMutex;
std::atomic_bool finish;
void pinger() {
    while (!finish) {
        std::lock_guard<std::mutex> lockGuard(gameMutex);
        if (turn) {
            std::cout << "ping" << std::endl;
            turn = false;
        }
    }
}

void ponger() {
    while (!finish) {
        std::lock_guard<std::mutex> lockGuard(gameMutex);
        if (!turn) {
            std::cout << "pong" << std::endl;
            turn = true;
        }
    }
}

int main() {
    Scheduler scheduler;
    ThreadProperties properties1(scheduler,pinger);

    ThreadProperties properties2(scheduler,ponger);


    Thread t1(properties1);
    Thread t2(properties2);
    std::cout << "Starting Scheduler" << std::endl;
    scheduler.Start();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    finish = true;
    scheduler.End();
    return 0;
}