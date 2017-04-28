//
//  tests.hpp
//  ThreadSafe_Queue
//
//  Created by Игорь Анфёров on 22.04.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef QueueTests_hpp
#define QueueTests_hpp

#include <list>

#include "gtest/gtest.h"

#include "tsqueue.hpp"

class QueueTests : public ::testing::Test
{
public:
    static threadsafe_queue<int> qd;
    static threadsafe_queue<int, std::list<int>> ql;
    
    static void SetUpTestCase();
    static void TearDownTestCase();
};

#endif /* QueueTests_hpp */
