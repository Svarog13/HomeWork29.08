#include<iostream>
#include<vector>

class Task
{
private:
	std::string title;
	bool completed;
public:
	Task(const std::string & title): title(title),completed(false){}

	std::string getTitle()const
	{
		return title;
	}
	bool isCompleted()const
	{
		return completed;
	}
	void completedTask()
	{
		completed = true;
	}
	void uncompletedTask()
	{
		completed = false;
	}
};
class Model
{
private:
	std::vector<Task> tasks;
public:
	void addTask(const std::string& title)
	{
		tasks.push_back(Task(title));
	}
	void removeTask(int index)
	{
		if (index >=0 && index < tasks.size())
		{
			tasks.erase(tasks.begin() + index);
		}
	}
	void toggleTask(int index)
	{
		if (index >=0 && index <tasks.size())
		{
			if (tasks[index].isCompleted())
			{
				tasks[index].uncompletedTask();
			}
			else
			{
				tasks[index].completedTask();
			}
		}
	}
	const std::vector <Task>& getTasks()const
	{
		return tasks;
	}
};
class View
{
public:
	void showTasks(const std::vector<Task>& tasks)
	{
		std::cout << "Tasks: " << std::endl;
		for (int i = 0; i < tasks.size(); i++)
		{
		std:: cout << "[" << (tasks[i].isCompleted() ? "X" : " ") << "] " << tasks[i].getTitle() << std::endl;
		}
	}
};
class Controller
{
private:
	Model model;
	View view;
public:
	void addTask(const std::string& title)
	{
		model.addTask(title);
		updateView();
	}
	void removeTask(int index)
	{
		model.removeTask(index);
		updateView();
	}
	void toggleTask(int index)
	{
		model.toggleTask(index);
		updateView();
	}
	void updateView()
	{
		view.showTasks(model.getTasks());
	}
};

int main()
{
	Controller controller;
	controller.addTask("Go to the It Step class");
	controller.addTask("Write some code with many bugs");
	controller.toggleTask(0);
	controller.updateView();
	controller.removeTask(1);
	controller.updateView();

	return 0;
}