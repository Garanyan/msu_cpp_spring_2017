#include "stdafx.h"
#include "../include/ThreadSafeDeque.h"

threadsafe_deque<int> deque;

void get()
{
    int x;
    for (auto i = 0; i < 100; i++) {
        deque.wait_and_pop(x);
    }
}

void insert()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    for (auto i = 0; i < 100; i++) {
        if (i % 2) {
            deque.push(i);
        } else {
            auto tmp = i;
            deque.emplace(std::move(tmp));
        }
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
    std::thread insertTread(insert);
    std::thread getTread(get);

    insertTread.join();
    getTread.join();
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
