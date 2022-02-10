#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

struct friend_t
{
  std::string name;
  std::tm birthday;
};

void input_friends(std::vector<friend_t> &friends)
{
  std::string str_input;
  do
  {
    std::cout << "Input friend's name: " << std::endl;
    std::cin >> str_input;
    if (str_input == "end")
      continue;
    friends.resize(friends.size() + 1);
    friends[friends.size() - 1].name = str_input;

    std::cin >> std::get_time(&friends[friends.size() - 1].birthday, "%d.%m.%Y");
    std::mktime(&friends[friends.size() - 1].birthday);
  }while(str_input != "end");

}

int main()
{
  std::vector<friend_t> friends;
  input_friends(friends);
  std::time_t time_now = std::time(nullptr);
  std::tm *tm_now = std::localtime(&time_now);
  std::map<int, std::vector<friend_t>> friends_map;
  for (int i = 0; i < friends.size(); i++)
  {
    friends_map[friends[i].birthday.tm_yday - tm_now->tm_yday].push_back(friends[i]);
  }
  for (std::map<int, std::vector<friend_t>>::iterator it = friends_map.begin(); it != friends_map.end(); it++)
  {
    if (it->first >= 0)
    {
      for (int i = 0; i < it->second.size(); i++)
      {
        if (it->first == 0)
          std::cout << "Today!!! ";
        std::cout << it->second[i].name << " " << std::put_time(&it->second[i].birthday, "%d.%m") << std::endl;
      }
    }
  }
  return 0;
}
