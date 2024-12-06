#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

void getListsFromFile(std::vector<uint32_t>& list1, std::vector<uint32_t>& list2)
{
   std::ifstream file("Puzzle1.txt");
   if (file.is_open())
   {
      std::string word;
      uint32_t wordCount = 0;

      while (file >> word)
      {
         if (wordCount % 2 == 0)
            list1.push_back(std::stoll(word));
         else
            list2.push_back(std::stoll(word));

         ++wordCount;
      }

   }
   file.close();
}

int main()
{
   std::vector<uint32_t> list1, list2;
   getListsFromFile(list1, list2);

   std::ranges::sort(list1);
   std::ranges::sort(list2);

   uint32_t distance = 0;
   for (auto i = 0; i < list1.size(); ++i)
   {
      distance += (list1[i] > list2[i]) ? (list1[i] - list2[i]) : (list2[i] - list1[i]);
   }

   std::cout << "Reconciled distance: " << distance << std::endl;

   uint32_t similarityScore = 0;
   for (const auto element : list1)
   {
      const auto numOccurances = std::ranges::count(list2, element);
      similarityScore += (element * numOccurances);
   }

   std::cout << "Similarity Score: " << similarityScore << std::endl;

   return 0;
}