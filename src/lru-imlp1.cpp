/**
 * 题目：已有1个库函数query，实现一个本地缓存函数 query_from_LRUCache，
 * n秒内调用相同的key，返回query上一次的内容。
 * 考察双向链表的设计
 * Time Complexity: LRUCache(int): O(1)
 *                  put: O(1)
 * (query_from_LRUCache)get: O(1)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;

class LRUCache {
private:
   class Node {
   public:
       int key, val;
       Node * prev, *next;
       Node(int k, int v) :key(k), val(v), prev(nullptr), next(nullptr) {
       }
   };

   int capacity;
   unordered_map<int, Node*> data;
   Node * dummyHead;
   Node * tail;

public:

   LRUCache(int cap = 3) :capacity(cap) {
       dummyHead = new Node(-1, -1);
       tail = new Node(-1, -1);

       dummyHead->next = tail;
       tail->prev = dummyHead;
   }
   // 释放双向链表
   ~LRUCache() {
       Node * cur = dummyHead;
       while (cur != nullptr) {
           Node * p = cur->next;
           delete cur;
           cur = nullptr;
           cur = p;
       }
   }

   void put(int key, int value) {
       if (data.count(key)) {
           data[key]->val = value;
           moveToHead(data[key]);
           return;
       }

       data[key] = new Node(key, value);
       addFirst(data[key]);

       if (data.size() > capacity) {
           int del_key = removeLast();
           data.erase(del_key);
       }
   }
   // query_from_LRUCache
   int get(int key) {
       if (data.count(key)) {
           moveToHead(data[key]);
           return dummyHead->next->val;
       }
       return -1;
   }
private:
   // 链表中节点 node 移动到表头（dummyHead下一个）
   void moveToHead(Node* node) {
       node->prev->next = node->next;
       node->next->prev = node->prev;

       node->prev = node->next = NULL;
       addFirst(node);
   }

   // 添加节点 node 到表头
   void addFirst(Node* node) {

       node->next = dummyHead->next;
       node->next->prev = node;

       node->prev = dummyHead;
       dummyHead->next = node;
   }

   // 移除尾部节点（非tail）
   int removeLast() {

       if (tail->prev != dummyHead) {
           Node* del_node = tail->prev;

           tail->prev = tail->prev->prev;
           tail->prev->next = tail;
           int res = del_node->key;

           delete del_node;
           del_node = nullptr;

           return res;
       }
       return -1;
   }
};

// int main() {
//    LRUCache LRUCache(2);
//    LRUCache.put(1, 1);
//    LRUCache.put(2, 2);
//    cout << LRUCache.get(1) << endl;  // 1
//    LRUCache.put(3, 3);
//    cout << LRUCache.get(2) << endl;  //-1
//    LRUCache.put(4, 4);
//    cout << LRUCache.get(1) << endl;  //-1
//    cout << LRUCache.get(3) << endl;  // 3
//    cout << LRUCache.get(4) << endl;  // 4

//    return 0;

// }