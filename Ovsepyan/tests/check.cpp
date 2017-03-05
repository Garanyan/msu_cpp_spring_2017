//
//  check.cpp
//  Ovsepyan
//
//  Created by Эрик on 05.03.17.
//
//

#include "stdafx.h"

#include "../src/buttons.hpp"
using namespace std;
class Nokia_test: public ::testing::Test {
public:
    Nokia nokia;
    map<string,string> cases= {
        { "a", "2"      },
        { "b", "22"     },
        { "c", "222"    },
        { "d", "3"      },
        { "e", "33"     },
        { "f", "333"    },
        { "g", "4"      },
        { "h", "44"     },
        { "i", "444"    },
        { "j", "5"      },
        { "k", "55"     },
        { "l", "555"    },
        { "m", "6"      },
        { "n", "66"     },
        { "o", "666"    },
        { "p", "7"      },
        { "q", "77"     },
        { "r", "777"    },
        { "s", "7777"   },
        { "t", "8"      },
        { "u", "88"     },
        { "v", "888"    },
        { "w", "9"      },
        { "x", "99"     },
        { "y", "999"    },
        { "z", "9999"   }
        
    };
    std::map<string,string> word_cases = {
        { "aaa", "2 2 2"     },
        { "abc", "2 22 222"  },
        { "hi ", "44 444"    },
        { " hi", "44 444"    },
        { "yes", "999337777" },
        { "foo  bar", "333666 6660 022 2777" },
        { "hello world", "4433555 555666096667775553" },
    };
};

TEST_F(Nokia_test, chars)
{
    for(std::map<string,string>::iterator iter = cases.begin(); iter != cases.end(); ++iter)
        EXPECT_STREQ(iter->second.c_str(),nokia.n(iter->first).c_str());
}

TEST_F(Nokia_test, words)
{
    for(map<string,string>::iterator iter = word_cases.begin(); iter != word_cases.end();++iter)
        EXPECT_STREQ(iter->second.c_str(),nokia.n(iter->first).c_str());
}
