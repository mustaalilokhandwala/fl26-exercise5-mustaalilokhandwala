// ECE 3574 Exercise: Word Count - starter code

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

int main() {
    std::ifstream file("mobydick.txt");

        std::map<std::string, int> wordCount;
        std::string word;

        while (file >> word)
        {
            for (char& c : word)
            {
                c = std::tolower(c);
            }

            wordCount[word]++;
        }

        std::vector<std::pair<std::string, int>> words;

        for (const auto& item : wordCount)
        {
            words.push_back(item);
        }

        std::sort(words.begin(), words.end(),
            [](const std::pair<std::string, int>& a,
               const std::pair<std::string, int>& b)
            {
                return a.second > b.second;
            });

        for (int i = 0; i < 10; i++)
        {
            std::cout << i + 1 << ". "
                      << words[i].first << ": "
                      << words[i].second << " times"
                      << std::endl;
        }

        return EXIT_SUCCESS;
}
