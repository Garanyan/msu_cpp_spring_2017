#include <deque>
#include <iostream>
#include <future>
#include <mutex>
#include <condition_variable>

template <class T, class Container = std::deque<T>>
class threadsafe_queue
{
    Container container_;
    std::mutex usage_mutex_;
    std::condition_variable cv_;
public:
    threadsafe_queue() = default;

    void push(const T& value)
    {
        std::unique_lock<std::mutex> lock(usage_mutex_);
        container_.push_back(value);
        cv_.notify_one();
    }

    void emplace(T&& value)
    {
        std::unique_lock<std::mutex> lock(usage_mutex_);
        container_.emplace_back(value);
        cv_.notify_one();
    }

    bool try_pop(T& value)
    {
        std::unique_lock<std::mutex> lock(usage_mutex_);
        if (container_.empty()) {
            value = container_.back();
            container_.pop_back();
            return true;
        } else {
            return false;
        }

    }

    void wait_and_pop(T& value)
    {
        std::unique_lock<std::mutex> lock(usage_mutex_);
        if (container_.empty()) {
            cv_.wait(lock);
        }
        value = container_.back();
        container_.pop_back();
    }
};
