#include "semaphore.hpp"

Semaphore::Semaphore(int i) {
    high = i;
}

void Semaphore::down() {
    std::unique_lock<std::mutex> lock(m);
    while(high == 0)
        cv.wait(lock);
    --high;
}

void Semaphore::up() {
    std::unique_lock<std::mutex> lock(m);
    ++high;
    cv.notify_one();
}
