// Write a program that reads in a line of text and replaces all four-letter words with the word "love".
// If the four-letter word starts with a capital letter, it should be replaced with "Love".
// A word is any string consisting of the letters of the alphabet and delimited at each end by a blank,
// the end of the line, or any other character that is not a letter.

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

std::string parse(std::string_view line);

int main()
{
    assert(parse("The quick brown fox jumps over the lazy dog.") == "The quick brown fox jumps love the love dog.");

    std::string line;
    std::getline(std::cin, line);
    std::cout << parse(line) << std::endl;
    return 0;
};

std::string parse(std::string_view line)
{
    std::string result;

    auto word_start = line.begin();
    auto word_end = line.begin();
    const auto end = line.end();

    while (word_start != end)
    {
        //
    }

    return result;
}