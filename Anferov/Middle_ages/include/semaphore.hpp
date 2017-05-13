#include <thread>

class Semaphore {
    int high;
    std::mutex m;
    std::condition_variable cv;
public:
    Semaphore(int i);
    void down();
    void up();
};
