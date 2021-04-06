/** @file */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

/**
 * @brief 判断是否是合法字符
 */
bool isValidchar(char c) { return !(isalpha(c)); }
/**
 * @brief 统计键盘输入的单词及频率，非字母输入将忽略
 */

int main() {
    /**
     * @brief 从键盘获取输入，Ubuntu 中 Ctrl+D 结束输入
     */
    istream_iterator<string> end;
    istream_iterator<string> ins(cin);

    map<string, int> wordFrequencies;

    while (ins != end) {
        string word = *ins++;
        word.erase(remove_if(word.begin(), word.end(), &isValidchar),
                   word.end());

        if (wordFrequencies.find(word) != wordFrequencies.end()) {
            wordFrequencies[word]++;
        } else {
            wordFrequencies[word] = 1;
        }
    }

    cout << "Result is:" << endl;
    for (const auto& p : wordFrequencies) {
        cout << p.first << " : " << p.second << endl;
    }

    cout << flush;

    // end the cin by  Cril+d

    return 0;
}
