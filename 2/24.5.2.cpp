#include <iostream>
#include <ctime>
#include <string>
#include <vector>

struct friend_t
{
  std::string name;
  std::time_t birthday;
};

bool input_friend(friend_t &frnd)
{
  std::cout << "Input friend's name: " << std::endl;
  std::cin >> frnd.name;
  if (frnd.name == "end")
    return false;

  return true;
}

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
