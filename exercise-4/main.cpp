// Write a program that allows the user to type in any one-line question and then answer that question.
// The program will not really pay any attention to the question but will simply read the question line and discard all that it reads.
// It always gives one of the following answers:
// - "I'm not sure but I think you will find the answer in Chapter 20."
// - "That's a good question."
// - "If I were you, I would not worry about such things."
// - "That question has puzzled philosophers for centuries."
// - "I don't know. I'm just a machine."
// - "Think about it and the answer will come to you."
// - "I used to know the answer to that question, but I've forgotten it."
// - "The answer can be found in a secret place in the woods."

// These answers are stored, one per line, in the file answers.txt.
// Your program should simply read the next answer from the file and write it out as the answer to the question.
// Allow the user to continue asking questions until they choose to exit the program.
// After your program has read the entire file, it simply closes the file, reopens the file, and starts down the list of answers again.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void read_lines(const std::string &filename, std::vector<std::string> &lines);

int main()
{
    /*
    Instead of closing and opening the file, which is a costly operation,
    I will read the file once and store the answers in a vector, then
    loop through the vector to get the answers, restarting from the beginning
    when the end of the vector is reached.
    */
    const std::string filename = "answers.txt";

    std::vector<std::string> lines;
    read_lines(filename, lines);

    const auto begin = lines.begin();
    const auto end = lines.end();
    auto it = begin;

    auto next_answer = [&it, &begin, &end]() {
        it++;
        if (it == end)
        {
            it = begin;
        }
    };

    while (true)
    {
        std::string question;
        std::cout << "Ask a question (\"exit\" to exit): ";
        std::getline(std::cin, question);

        if (question == "exit")
        {
            break;
        }

        std::cout << *it << std::endl;
        next_answer();
    }

    return 0;
}

void read_lines(const std::string &filename, std::vector<std::string> &lines)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file \"" + filename + "\"");
    }

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    file.close();

    return;
}