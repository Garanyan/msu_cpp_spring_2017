//
//  tests.cpp
//  ThreadSafe_Queue
//
//  Created by Игорь Анфёров on 22.04.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

#include "tsqueue.hpp"

#include "QueueTests.hpp"

void fillqd() {
    for (int i=5; i<10; i++) {
        QueueTests::QueueTests::qd.emplace(std::move(i));
    }
}

TEST(QueueTests, container_deque) {
    std::vector<int> res;
    
    for (int i=0; i<5; i++) {
        QueueTests::qd.push(i);
    }
    for (int i=0; i<5; i++) {
        int j;
        QueueTests::qd.wait_and_pop(j);
        res.push_back(j);
    }
    int j;
    if (QueueTests::qd.try_pop(j)) {
        res.push_back(j);
    }
    std::thread t(fillqd);
    for (int i=0; i<5; i++) {
        int j;
        QueueTests::qd.wait_and_pop(j);
        res.push_back(j);
    }
    t.join();
    for (int i=0; i<10; i++) {
        ASSERT_EQ(res[i], i);
    }
}

void fillql() {
    for (int i=5; i<10; i++) {
        QueueTests::QueueTests::ql.emplace(std::move(i));
    }
}

TEST(QueueTests, container_list) {
    std::vector<int> res;
    
    for (int i=0; i<5; i++) {
        QueueTests::ql.push(i);
    }
    for (int i=0; i<5; i++) {
        int j;
        QueueTests::ql.wait_and_pop(j);
        res.push_back(j);
    }
    int j;
    if (QueueTests::ql.try_pop(j)) {
        res.push_back(j);
    }
    std::thread t(fillql);
    for (int i=0; i<5; i++) {
        int j;
        QueueTests::ql.wait_and_pop(j);
        res.push_back(j);
    }
    t.join();
    for (int i=0; i<10; i++) {
        ASSERT_EQ(res[i], i);
    }
}

void filldq(int begin, int end) {
    for (int i=begin; i<end; i++) {
        QueueTests::QueueTests::qd.emplace(std::move(i));
    }
}

TEST(QueueTests, concurrency) {
    const int elems_per_thread = 10000;
    const int num_threads = 7;
    
    std::vector<std::thread> threads;
    
    for (int th = 0; th<num_threads; th++) {
        threads.emplace_back(std::thread(filldq,
                                      elems_per_thread * th,
                                      elems_per_thread * (th + 1)));
    }
    
    std::vector<int> res;
    
    for (int i=0; i < num_threads * elems_per_thread; i++) {
        int j;
        QueueTests::qd.wait_and_pop(j);
        res.push_back(j);
    }
    
    for (int th = 0; th<num_threads; th++) {
        threads[th].join();
    }

    std::sort(res.begin(), res.end());
    
    for (int i=0; i < num_threads * elems_per_thread; i++) {
        ASSERT_EQ(res[i], i);
    }
}
