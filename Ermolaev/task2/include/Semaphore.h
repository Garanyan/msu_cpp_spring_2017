#pragma once

#include "stdafx.h"

// Semaphore
class Semaphore{
    int counter_;
    std::mutex mutex_;
    std::condition_variable condition_;

public:
    explicit Semaphore(int initialValue)
            :counter_(initialValue)
    {
    }
    void enter()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this](){
            return counter_ > 0;
        });
        --counter_;
    }
    void leave()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        ++counter_;
        condition_.notify_one();
    }
};

