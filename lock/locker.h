#ifndef LOCKER_H
#define LOCKER_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>

// 信号量
class sem {
private:
    sem_t m_sem;

public:
    // 构造函数
    /*  sem_init函数用于初始化一个未命名的信号量
        sem_destory函数用于销毁信号量
        sem_wait函数将以原子操作方式将信号量减一,信号量为0时,sem_wait阻塞
        sem_post函数以原子操作方式将信号量加一,信号量大于0时,唤醒调用sem_post的线程
    */
    sem() {
        // 信号量初始化
        if (sem_init(&m_sem, 0, 0) != 0) {
            throw std::exception();
        }
    }
    sem(int num) {
        if (sem_init(&m_sem, 0, num) != 0) {
            throw std::exception();
        }
    }
    // 析构函数
    ~sem() {
        // 信号量摧毁
        sem_destroy(&m_sem);
    }
    bool wait() {
        return sem_wait(&m_sem) == 0;
    }
    bool post() {
        return sem_post(&m_sem) == 0;
    }
};

#endif