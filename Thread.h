//
// Created by dani9 on 08/11/2019.
//

#ifndef UNTITLED_THREAD_H
#define UNTITLED_THREAD_H
#ifndef TARGET
#include <thread>
#else
#endif
struct ThreadProperties;
class Thread {
public:
    explicit Thread(const ThreadProperties&);
    void Join();
private:
#ifndef TARGET
    std::thread m_thread;
#else
#endif
};
#endif //UNTITLED_THREAD_H
