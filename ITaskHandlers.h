#pragma once
#include <functional>
#include <chrono>

typedef std::chrono::time_point time_point;

template <class ReturnType>
typedef std::function<ReturnType()> Task;

typedef Task<void> DefaultTask;

struct ITaskExecutor
{
	void execute(DefaultTask) = 0;
	~ITaskExecutor() {}
};

template <class ReturnType>
struct IAsyncTaskExecutor
{
	void execute(Task<ReturnType>, std::function<void(ReturnType)>) = 0;
	~ITaskExecutor() {}
};

template <class TaskType>
struct ITaskScheduler
{
	void schedule(TaskType) = 0;
	~ITaskExecutor() {}
};

template <class ReturnType>
struct IAsyncTaskExecutor
{
	void execute(Task<ReturnType>, std::function<void(ReturnType)>) = 0;
	~ITaskExecutor() {}
};