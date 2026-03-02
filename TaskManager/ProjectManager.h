#pragma once
#include <iostream>
#include <vector>
#include "Models.h"

class ProjectManager
{
private:
	std::vector<Project>projects;
public:

	//Project
	bool AddProject(const std::string& projName);
	bool DeleteProject(const std::string& projName);
	//Task
	bool AddTask(const std::string& projName, const std::string& taskName);
	bool DeleteTask(const std::string& projName, const std::string& taskName);
	//SubTask
	bool AddSubTask(const std::string& projName, const std::string& taskName, const std::string& subTaskName);
	bool DeleteSubTask(const std::string& projName, const std::string& taskName, const std::string& subTaskName);

	const std::vector<Project>& GetProjects();

	//Helper Functions
	Project* FindProject(const std::string& projectName);
	Task* FindTask(const std::string& projectName, const std::string& taskName);
};

