#include "ProjectManager.h"
#include <algorithm>
using namespace std;

bool ProjectManager::AddProject(const string& projectName) {

	if (projectName.empty()) return false;
	if (FindProject(projectName)) return false;
	projects.push_back(Project{ projectName });
	return true;
}
bool ProjectManager::DeleteProject(const string& projectName) {

	if (projectName.empty()) return false;

	auto it = remove_if(projects.begin(), projects.end(), [&](const Project& existingProject) {

		return existingProject.projectName == projectName;
		});
	if (it == projects.end()) return false;
	
	projects.erase(it, projects.end());
	return true;

}
bool ProjectManager::AddTask(const string& projectName, const string& taskName) {

	if (projectName.empty() || taskName.empty()) return false;
	if (FindTask(projectName, taskName)) return false;
	Project* project = FindProject(projectName);
	if (project != nullptr) 
	{
		project->tasks.push_back(Task{ taskName });
		return true;
	}
	return false;
}
bool ProjectManager::DeleteTask(const string& projectName, const string& taskName) {

	if (projectName.empty() || taskName.empty()) return false;
	Project* project = FindProject(projectName);

	if (project!=nullptr) {

		auto it = remove_if(project->tasks.begin(), project->tasks.end(), [&](const Task& task) {

			return task.taskName == taskName;

			});

		if (it == project->tasks.end()) return false;
		project->tasks.erase(it, project->tasks.end());
		return true;
	}
	return false;
}

//Helper Function Defenitions
Project* ProjectManager:: FindProject(const string& projectName) 
{
	auto projectIt = find_if(projects.begin(), projects.end(), [&](const Project& existingProject) {

		return existingProject.projectName == projectName;
		});

	if (projectIt == projects.end()) {
		return nullptr;
	}
	return &*projectIt;
}
Task* ProjectManager::FindTask(const string& projectName, const string& taskName) {

	auto projectIt = find_if(projects.begin(), projects.end(), [&](const Project& existingProject) {

		return existingProject.projectName == projectName;
		});

	if (projectIt == projects.end()) {
		return nullptr;
	}

	auto taskIt = find_if(projectIt->tasks.begin(), projectIt->tasks.end(), [&](const Task& existingTask) {

		return existingTask.taskName == taskName;

		});

	if (taskIt == projectIt->tasks.end()) {
		return nullptr;
	}

	return &*taskIt;
	
}