/** @file */
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;
/**
 * @brief main() 统计文本中每个单词的频率及所在位置
 * @brief multimap 容器保存的是有序的键/值对，但它可以保存重复的元素
 */

int main() {
    ifstream in("illiad.txt");

    multimap<string, pair<int, int>> wordPositions;
    int lineNumber = 0, wordInLine = 0;

    string line = "";

    while (!in.eof()) {
        lineNumber++;
        getline(in, line);
        /**
         * @brief istringstream iss(string str) returns words stream in object
         * @brief str
         */

        istringstream iss(line);
        string word = "";

        while (!iss.eof()) {
            wordInLine++;  // index of each word
            iss >> word;
            wordPositions.insert(
                make_pair(word, make_pair(lineNumber, wordInLine)));
        }
        wordInLine = 0;
    }

    cout << "read in " << lineNumber << " lines of text" << endl;

    for (auto it = wordPositions.cbegin(), it2 = it; it != wordPositions.cend();
         it = it2) {
        unsigned int count = wordPositions.count(it->first);
        cout << "\"" << it->first << "\" occures " << count
             << " times,and is on: " << endl;
        for (; it2 != wordPositions.cend() && it2->first == it->first; ++it2) {
            auto [line, position] = it2->second;
            cout << "\tline " << line << ", position " << position << endl;
        }
    }

    in.close();

    return 0;
}
