/** @file */
#include <fstream>
#include <iostream>
#include <set>

using namespace std;
/**
 * @brief  统计文本中的单词的个数及不重复的单词个数
 */
int main() {
    ifstream in("illiad.txt");
    set<string> words;
    string word = "";
    unsigned long long totalCount = 0;

    while (!in.eof()) {
        in >> word;
        totalCount++;
        words.insert(word);
    }

    cout << "Text contains " << words.size() << " unqiue words out of "
         << totalCount << endl;

    in.close();

    return 0;
}
