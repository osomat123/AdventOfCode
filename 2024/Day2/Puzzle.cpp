#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
   std::ifstream file("Puzzle.txt");

   if (file.is_open())
   {
      std::string line;
      uint32_t numSafeReports = 0;

      while (std::getline(file, line))
      {
         std::stringstream report(line);


         std::string strNum;

         report >> strNum;
         uint16_t prevValue = std::stoul(strNum);

         report >> strNum;
         uint16_t curValue = std::stoul(strNum);
         
         const auto isInRange = [](const auto prevValue, const auto curValue)
            {
               const auto difference = std::abs(curValue - prevValue);
               return difference >= 1 && difference <= 3;
            };

         bool isIncreasing = prevValue < curValue;
         bool isReportSafe = isInRange(prevValue, curValue);

         while (isReportSafe && report >> strNum)
         {
            prevValue = curValue;
            curValue = std::stoul(strNum);

            bool isOrderCorrect = isIncreasing ? (prevValue < curValue) : (prevValue > curValue);
            isReportSafe = isOrderCorrect && isInRange(prevValue, curValue);
         }

         if (isReportSafe)
         {
            ++numSafeReports;
         }
      }

      std::cout << "Number of safe reports: " << numSafeReports << std::endl;
   }

   return 0;
}