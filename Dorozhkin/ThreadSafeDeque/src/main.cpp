#include "threadSafeQueue.h"

int main(int argc, char const *argv[]) {
    threadsafe_queue<int> a;
    a.push(1);
    a.push(2);
    int x, y;
    a.try_pop(x);
    std::cout << x << std::endl;

    a.emplace(3);
    a.try_pop(x);
    std::cout << x << std::endl;

    return 0;
}
