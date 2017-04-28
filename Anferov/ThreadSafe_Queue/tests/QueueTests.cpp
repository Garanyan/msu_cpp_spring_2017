//
//  tests.cpp
//  ThreadSafe_Queue
//
//  Created by Игорь Анфёров on 22.04.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#include "QueueTests.hpp"

threadsafe_queue<int> QueueTests::qd;
threadsafe_queue<int, std::list<int>> QueueTests::ql;

void QueueTests::SetUpTestCase() {
};

void QueueTests::TearDownTestCase() {
};
