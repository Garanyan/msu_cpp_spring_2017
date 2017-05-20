#pragma once

#include <list>
//#include <mutex>
#include <thread>
#include <condition_variable>

template <class T, class safeQueue = std::list<T>>
class SafeQueue
{
	safeQueue safeQueue_;
	std::mutex mutex_;
	std::condition_variable cv_;
public:
	SafeQueue() = default;
	
	bool empty()
	{
		return safeQueue_.empty();
	}
	
	int size()
	{
		return safeQueue_.size();
	}

	void push(const T& value)
	{
		std::unique_lock<std::mutex> lock(mutex_);
		safeQueue_.push_back(value);
		cv_.notify_one();
	}
	
	void emplace(T&& value)
	{
		std::unique_lock<std::mutex> lock(mutex_);
		safeQueue_.emplace_back(value);
		cv_.notify_one();
	}
	
	bool try_pop(T& value)
	{
		std::unique_lock<std::mutex> lock(mutex_);
		if (!safeQueue_.empty()) {
			value = safeQueue_.front();
			safeQueue_.pop_front();
			return true;
		} else {
			return false;
		}
	
	}
	
	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lock(mutex_);
		if (safeQueue_.empty()) {
			cv_.wait(lock);
		}
		value = safeQueue_.front();
		safeQueue_.pop_front();
	}

};

