#include "stdafx.h"
#include "../include/ThreadSafeDeque.h"

threadsafe_deque<int> deque;
threadsafe_deque<int> stressdeque;
int sum;

void get()
{
    int x;
    for (auto i = 0; i < 1000; i++) {
        deque.wait_and_pop(x);
        sum -= x;
    }
}

void insert()
{
    for (auto i = 0; i < 1000; i++) {
        sum += i;
        // std::cout << i << std::endl;
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (i % 2) {
            deque.push(i);
        } else {
            auto tmp = i;
            deque.emplace(std::move(tmp));
        }
    }
}

void stress()
{
    int tmp;
    for (auto i = 0; i < 1000; i++) {
        stressdeque.push(i);
        stressdeque.wait_and_pop(tmp);
    }
}

TEST(SafeDequeTesting, OneThread) {
    threadsafe_deque<int> a;
    int x = 0;
    a.push(1);
    a.push(2);
    EXPECT_TRUE(a.try_pop(x));
    EXPECT_EQ(x, 2);

    a.emplace(3);
    a.wait_and_pop(x);
    EXPECT_EQ(x, 3);
    a.wait_and_pop(x);
    EXPECT_EQ(x, 1);
    EXPECT_FALSE(a.try_pop(x));
}

TEST(SafeDequeTesting, MultiThread) {
    sum = 0;
    std::thread insertTread(insert);
    std::thread getTread(get);

    insertTread.join();
    getTread.join();
    EXPECT_EQ(sum, 0);
    // insertTread.detach();
    // getTread.detach();
    // 
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

TEST(SafeDequeTesting, StressMultiThread) {
    try {
        std::vector<std::future<void>> vf;
        for (auto i = 0; i < 100; i++) {
            vf.push_back(std::async(std::launch::async, stress));
        }
        for (auto& f : vf) {
            f.wait();
        }
    } catch(...) {
        EXPECT_FALSE(true);
    }
}


TEST(SafeDequeTesting, Vector) {
    threadsafe_deque<int, std::vector<int>> a;
    int x = 0;
    a.push(1);
    a.push(2);
    EXPECT_TRUE(a.try_pop(x));
    EXPECT_EQ(x, 2);

    a.emplace(3);
    a.wait_and_pop(x);
    EXPECT_EQ(x, 3);
    a.wait_and_pop(x);
    EXPECT_EQ(x, 1);
    EXPECT_FALSE(a.try_pop(x));
}
