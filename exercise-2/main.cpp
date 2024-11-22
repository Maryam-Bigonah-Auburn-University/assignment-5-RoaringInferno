// Write a program that reads in a line of text and replaces all four-letter words with the word "love".
// If the four-letter word starts with a capital letter, it should be replaced with "Love".
// A word is any string consisting of the letters of the alphabet and delimited at each end by a blank,
// the end of the line, or any other character that is not a letter.

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

char to_lower(const char c) { return c - 'A' + 'a'; }
char to_upper(const char c) { return c - 'a' + 'A'; }

bool is_lower(const char c) { return c >= 'a' && c <= 'z'; }
bool is_upper(const char c) { return c >= 'A' && c <= 'Z'; }

bool is_letter(const char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

std::string parse(std::string_view line);

int main()
{

    assert(parse("The quick brown fox jumps over the lazy dog.") == "The quick brown fox jumps love the love dog.");

    std::string line;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, line);
    std::cout << parse(line) << std::endl;
    return 0;
};

std::string parse(std::string_view line)
{
    const bool DEBUGGING = false;

    std::string result;

    auto word_start = line.begin();
    auto word_end = line.begin();
    const auto end = line.end();

    while (word_start != end)
    {
        if(DEBUGGING) std::cout << "\tword_start: \"" << *word_start << "\"" << std::endl; //DEBUG
        if (*word_start == ' ') // If it's not a word
        {
            while (word_start != end && *word_start == ' ') // Skip spaces
            {
                ++word_start;
            }
            result.push_back(' ');
            continue;
        }
        if (!is_letter(*word_start)) // If it's not a word
        {
            while (word_start != end && !is_letter(*word_start)) // Skip non-letters
            {
                result.push_back(*word_start);
                ++word_start;
            }
            continue;
        }
        word_end = word_start;
        while (word_end != end && is_letter(*word_end)) // Find the end of the word
        {
            ++word_end;
        }
        // word_start is now the first letter of the word
        // word_end is now the first character after the word
        // check length of word
        if(DEBUGGING) std::cout << "\tword: \"" << std::string(word_start, word_end) << "\"" << std::endl; //DEBUG
        if (word_end - word_start == 4)
        {
            if (is_upper(*word_start))
            {
                result.push_back('L');
                result.push_back('o');
                result.push_back('v');
                result.push_back('e');
            }
            else
            {
                result.push_back('l');
                result.push_back('o');
                result.push_back('v');
                result.push_back('e');
            }
        }
        else
        {
            for (auto it = word_start; it != word_end; ++it)
            {
                result.push_back(*it);
            }
        }
        word_start = word_end; // Move to the next word
    }

    if(DEBUGGING) std::cout << "\tresult: " << result << std::endl; //DEBUG
    return result;
}