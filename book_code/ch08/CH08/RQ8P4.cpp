#include "priority_queue.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
  KW::priority_queue<std::string> pq;
  std::string word;
  while (std::cin >> word) 
    pq.push(word);
  std::vector<std::string> the_data = pq.get_container();
  for (size_t i = 0; i < the_data.size(); i++)
    std::cout << the_data[i] << std::endl;
}
