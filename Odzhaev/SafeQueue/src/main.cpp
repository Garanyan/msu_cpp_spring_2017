#include "stdafx.h"

#include "../include/safequeue.h"

#include <future>



SafeQueue <int> qu;
void stress()
{
	int tmp;
	for (auto i = 0; i < 1000; i++) {
		qu.push(i);
		qu.wait_and_pop(tmp);
	}
}

int main(int argc, char const*argv[]) 
{
	
	std::cout<<"hi";
	SafeQueue<int> a;
	int x = 0, y = 0;
	a.push(1);
	a.push(2);
	a.try_pop(x);
	std::cout << x << std::endl;

	a.emplace(3);
	a.wait_and_pop(x);
	std::cout << x << std::endl;

	try {
		std::list<std::future<void>> vf;
		for (auto i = 0; i < 100; i++) {
			vf.push_back(std::async(std::launch::async, stress));
		}
		for (auto& f : vf) {
			f.wait();
			}
	} catch(...) {
		std::cout<<"false";
	}
	return 0;
}
