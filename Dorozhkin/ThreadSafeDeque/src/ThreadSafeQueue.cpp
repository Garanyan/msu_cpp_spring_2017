#include "threadSafeQueue.h"

// void threadsafe_queue::push(const T& value)
// {
//     std::unique_lock<std::mutex> lock(m_);
//     container_.insert(value);
// }
//
// void threadsafe_queue::emplace(const Container&& value)
// {
//     std::unique_lock<std::mutex> lock(m_);
//     container_ = value;
// }
//
// bool threadsafe_queue::try_pop(T& value)
// {
//     if (m_.try_lock()) {
//         value = container_.pop();
//         m_.unlock();
//         return true;
//     } else {
//         return false;
//     }
//
// }
//
// void threadsafe_queue::wait_and_pop(T& value)
// {
//     std::unique_lock<std::mutex> lock(m_);
//     value = container_.pop();
// }
