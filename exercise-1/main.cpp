//Write a program that will read in a sentence of up to 100 characters
//    and output the sentence with spacing corrected
//    and with letters corrected for capitalization.
//In other words, in the output sentence, all strings of two
//    or more blanks should be compressed to a single blank.
//The sentence should start with an uppercase letter but should contain
//    no other uppercase letters.
//Do not worry about capitalizing proper nouns.
//Assume that the sentence ends with a period and contains no other periods.

#include <iostream>
#include <string>
#include <cassert>

std::string parse(std::string_view line);

char to_lower(const char c) { return c - 'A' + 'a'; }
char to_upper(const char c) { return c - 'a' + 'A'; }

bool is_lower(const char c) { return c >= 'a' && c <= 'z'; }
bool is_upper(const char c) { return c >= 'A' && c <= 'Z'; }

int main()
{
    // Testing
    assert(to_lower('W') == 'w');
    assert(parse("Hello World.") == "Hello world.");
    assert(parse("  Hello  World  .") == "Hello world.");
    assert(parse("  hello  World  .") == "Hello world.");

    std::string line;
    std::getline(std::cin, line);

    std::cout << parse(line) << std::endl;
    return 0;
}

void skip_spaces(std::string_view::iterator& it, const std::string_view::iterator& end)
{
  // "Assume that the sentence ends with a period". No need to check if it == end
  while (*it == ' ') { ++it; }
}

std::string parse(std::string_view line) {
    auto it = line.begin();
    const auto end = line.end();
    std::string result;

    result.reserve(line.size()); // Allocate enough space for the result

    if (it == end) { return result; }

    bool first = true;
    for (; it != end-1; ++it) {
        if (*it == ' ') {
            skip_spaces(it, end); // Don't double-count spaces
            if (*it != '.' && !first) result.push_back(' ');
            --it;
            continue;
        }
        if (first) {
            if (is_lower(*it)) result.push_back(to_upper(*it));
            else result.push_back(*it);
            first = false;
            continue;
        }
        if (is_upper(*it)) {
            result.push_back(to_lower(*it));
            continue;
        }
        result.push_back(*it);
    }
    result.push_back('.'); // "Assume that the sentence ends with a period"
    result.shrink_to_fit(); // Shrink the string to fit the actual size

    return result;
}