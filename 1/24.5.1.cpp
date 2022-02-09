#include <iostream>
#include <ctime>
#include <string>
#include <vector>

struct task_t
{
  std::time_t begin;
  std::time_t end;
  std::string name;
};

int main()
{
  std::vector<task_t> tasks;
  task_t *current_task = nullptr;
  std::string command;
  do
  {
    std::cout << "Input command:" << std::endl;
    std::cin >> command;
    if (command == "exit")
      continue;
    else if (command == "begin")
    {
      if (current_task != nullptr)
      {
        current_task->end = std::time(nullptr);
      }
      tasks.resize(tasks.size() + 1);
      current_task = &tasks[tasks.size() - 1];
      current_task->end = current_task->begin = std::time(nullptr);
      std::cout << "Input the name of the task:" << std::endl;
      std::cin >> std::ws;
      std::getline(std::cin, current_task->name);
    }
    else if (command == "end")
    {
      if (current_task != nullptr)
      {
        current_task->end = std::time(nullptr);
        current_task = nullptr;
      }
      else
        std::cout << "There is no active task" << std::endl;
    }
    else if (command == "status")
    {
      for (int i = 0; i < tasks.size(); i++)
      {
        if (tasks[i].end != tasks[i].begin)
        {
          std::time_t dt = std::difftime(tasks[i].end, tasks[i].begin);
          std::cout << "Task " << tasks[i].name << " finished in " << dt << " seconds" << std::endl;
        }
      }
      if (current_task != nullptr)
      {
        std::cout << "Task " << current_task->name << " is active now" << std::endl;
      }
    }
    else
      std::cout << "Invalid command" << std::endl;
  }while(command != "exit");
  return 0;
}
