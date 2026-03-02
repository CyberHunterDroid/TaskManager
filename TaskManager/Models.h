#pragma once
#include <iostream>
#include <vector>


enum Status
{
	Todo,
	InProgress,
	Done,
	Bugs,
	Review
};
struct SubTask
{
	std::string subTaskName;
	bool isDone;
};

struct Task
{
	std::string taskName;
	std::vector<SubTask> subTasks;
	Status status = Todo;
	bool isDone=false;
};
struct Project
{
	std::string projectName;
	std::vector<Task> tasks;

};

