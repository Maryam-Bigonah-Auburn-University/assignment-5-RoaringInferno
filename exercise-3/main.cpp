// Write a program that merges the numbers from file1.txt and file2.txt and writes all the numbers to file3.txt.
// Assume that each input file contains a list of ints in sorted order from the smallest to the largest.
// After the program is run, the output file will contain all the numbers in the two input files in one longer
//     list in sorted order from smallest to largest.
// Your program should implement a function that is called with the two input-file streams and the output-file streams its arguments.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void merge_lines(std::ifstream &input_file_1, std::ifstream &input_file_2, std::ofstream &output_file);

int main()
{
    const std::string input_filepath_1 = "file1.txt";
    const std::string input_filepath_2 = "file2.txt";
    const std::string output_filepath = "file3.txt";

    std::ifstream input_file_1(input_filepath_1);
    std::ifstream input_file_2(input_filepath_2);
    std::ofstream output_file(output_filepath);

    if (!input_file_1.is_open())
    {
        std::cerr << "Failed to open file: " << input_filepath_1 << std::endl;
        return 1;
    }
    if (!input_file_2.is_open())
    {
        std::cerr << "Failed to open file: " << input_filepath_2 << std::endl;
        return 1;
    }
    if (!output_file.is_open())
    {
        std::cerr << "Failed to open file: " << output_filepath << std::endl;
        return 1;
    }

    merge_lines(input_file_1, input_file_2, output_file);

    input_file_1.close();
    input_file_2.close();
    output_file.close();

    return 0;
};

void merge_lines(std::ifstream &input_file_1, std::ifstream &input_file_2, std::ofstream &output_file)
{
    std::vector<int> merged_nums;
    std::string line;
    while (std::getline(input_file_1, line))
    {
        merged_nums.push_back(std::stoi(line));
    }
    while (std::getline(input_file_2, line))
    {
        merged_nums.push_back(std::stoi(line));
    }

    std::sort(merged_nums.begin(), merged_nums.end()); // sorted in ascending order

    for (const auto &num : merged_nums)
    {
        output_file << std::to_string(num) << std::endl;
    }

    return;
}