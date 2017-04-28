//
//  tsqueue.hpp
//  ThreadSafe_Queue
//
//  Created by Игорь Анфёров on 22.04.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef tsqueue_hpp
#define tsqueue_hpp

#include <deque>
#include <mutex>
#include <condition_variable>

template <class T, class Container = std::deque<T>>
class threadsafe_queue
{
    Container queue;
    std::mutex m;
    std::condition_variable queue_is_not_empty;
    
public:
    void push(const T& value) {
        std::unique_lock<std::mutex> lock(m);
        queue.push_back(value);
        queue_is_not_empty.notify_one();
    };
    
    void emplace(const T&& value) {
        std::unique_lock<std::mutex> lock(m);
        queue.emplace_back(value);
        queue_is_not_empty.notify_one();
    };
    
    bool try_pop(T& value) {
        std::unique_lock<std::mutex> lock(m);
        if (queue.empty()) {
            return false;
        }
        value = queue.front();
        queue.pop_front();
        return true;
    };
    
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lock(m);
        while (queue.empty()) {
            queue_is_not_empty.wait(lock);
        }
        value = queue.front();
        queue.pop_front();
    };
};


#endif /* tsqueue_hpp */
