#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
  std::cout << "Input timeout (mm.ss): " << std::endl;
  std::tm tm_to;
  std::cin >> std::get_time(&tm_to, "%M.%S");
  std::time_t time_now = std::time(nullptr);
  std::time_t time_to = time_now + tm_to.tm_min * 60 + tm_to.tm_sec;
  do
  {
    while(time_now == std::time(nullptr));
    time_now = std::time(nullptr);
    std::time_t time_remain = (std::time_t)std::difftime(time_to, time_now);
    std::cout << std::setw(2) << std::setfill('0') << time_remain / 60  << "."
      << std::setw(2) << std::setfill('0') << time_remain % 60 << std::endl;
  }while(0.5 <= std::difftime(time_to, std::time(nullptr)));
  std::cout << "DING! DING! DING!" << std::endl;
  return 0;
}
