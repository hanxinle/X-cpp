/** @file */
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

/** map work ok

    int main ()  {
    map<string, string> stringMap;
    stringMap.insert({"hello","world"});

    cout << stringMap["hello"] << endl;

    return 0;

    }

**/

struct SimpleObject {

    SimpleObject() : x(1), y(2), z("stuff") {}

    SimpleObject(int x, int y, const string& zz) : x(x), y(y), z(zz) {}

    int x;
    int y;
    string z;
};

int main() {
    map<string, SimpleObject> objectMap;
    /**
     * @brief m.insert(pair<t1,t2>) insert with pair
     */
    objectMap.insert(
        pair<string, SimpleObject>("fisrt", SimpleObject(4, 8, "hello")));
    /**
     * @brief m[t1] = construtor func; insert with []
     */

    objectMap["second"] = SimpleObject();
    /**
     * @brief [] allows insert though same key exists
     */

    objectMap["second"] = SimpleObject(0, 0, "overwritten");
    objectMap["third"] = SimpleObject(1, 6, "world");
    /**
     * @brief m.insert({t1,t2}) insert with {} make a pair
     */

    objectMap.insert({"fourth", SimpleObject(1, 1, "number4")});
    /**
     * @brief const auto [iterator, inserted] =
     * @brief objectMap.insert({});
     * @brief insert() return [index of insertItem , boolen if key_inserted]
     */

    const auto [iterator, inserted] =
        objectMap.insert({"fifth", SimpleObject()});

    if (inserted) {
        cout << "Item " << iterator->first << "->" << iterator->second.z
             << " inserted" << endl;
    } else {
        cout << "key \"third\" already exists, can't insert." << endl;
    }
    /**
     * @brief x.first,x.second 返回元素 x 的 key 及 value
     */
    for (auto& x : objectMap) {
        cout << x.first << "->" << x.second.z << endl;
    }

    for (map<string, SimpleObject>::iterator it = objectMap.begin();
         it != objectMap.end(); it++) {
        cout << it->first << "=>" << it->second.z << endl;
    }
    /**
     * @brief m.erase(t1) map 清除特定 key 的元素
     */
    objectMap.erase("second");
    cout << "erase \"second\"" << endl;

    auto ptr = objectMap.find("third");
    if (ptr == objectMap.end()) {
        cout << "Unable to find \"third\"" << endl;
    } else {
        objectMap.erase(ptr, objectMap.end());
        cout << "Erase from \"third\" to the end" << endl;
    }

    for (auto& x : objectMap) {
        cout << x.first << "=>" << x.second.z << endl;
    }
    /**
     * @brief m.clear() 清理 map 后 map.size() 为零 
     */
    objectMap.clear();
    cout << "objectmap length now: " << objectMap.size() << endl;

    return 0;
}
