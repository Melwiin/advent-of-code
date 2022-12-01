#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input ("input.txt");

    std::vector<int> calories;

    if (input.is_open())
    {
        int elfCalories = 0;
        while ( std::getline (input,line) )
            //Check for empty line
            if(line == "") {
                calories.push_back(elfCalories);
                elfCalories = 0;
            }else elfCalories += std::stoi(line);
        input.close();
    }

    //sort descending
    std::sort(calories.begin(), calories.end(), std::greater<int>());

    int answer1 = calories[0];
    int answer2 = calories[0] + calories[1] + calories[2];

    std::cout << "Answer 1: " << answer1 << ", Answer 2: " << answer2;

    return 0;
}
