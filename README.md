# TinyWebServer
一个轻量级WebServer

2023/4/18  
新增Config文件

2023/4/19  
更新lock部分（信号量， 互斥锁， 条件变量）

更新locker.h:
类中主要是Linux下三种锁进行封装，将锁的创建于销毁函数封装在类的构造与析构函数中，实现RAII机制(资源获取即初始化)

更新threadpool线程池

treadpool.h

2023/4/20  
block_queue.h:
循坏数组实现的阻塞队列，保证线程安全，每个操作前都先加互斥锁，操作完解锁

2023/4/22  
Implemented block_queue.h