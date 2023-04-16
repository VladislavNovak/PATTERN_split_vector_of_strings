#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // remove_if
#include <cctype> // ispunct

using std::cout;
using std::endl;
using std::vector;
using std::string;

void removeSigns(string &str) {
    auto it = std::remove_if(str.begin(), str.end(), [](char &c) {
        return std::ispunct(c);
    });

    str.erase(it, str.end());
}

void splitString(string const &str, const char delim, vector<string> &words){
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        string result = str.substr(start, end - start);

        words.push_back(result);
    }
}

int main() {
    const char delim = ' ';
    vector<string> source = {
            "Every day I have three or four classes, so I do not usually have much time for meals.",
            "There are different kinds of sandwiches, sausages, bacon with eggs and jam.",
            "As there is a student canteen at the university, I often go there for dinner after classes.",
    };

    for (auto &line : source) {
        vector<string> list;

        removeSigns(line);

        splitString(line, delim, list);

        cout << "------------------" << endl;
        for (auto &word : list) cout << word << endl;
    }
}