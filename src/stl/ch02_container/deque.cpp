/** @file */
#include <deque>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    // deque - push_front,push_back - double-end - [index]
    deque<int> dq{1, 2, 3, 4};

    dq.push_front(100);
    dq.push_front(300);
    dq.push_back(500);
    dq.push_back(800);

    cout << "deque(double-end):" << endl;

    for (unsigned int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }

    cout << endl;

    // stack - LIFO - push,pop

    stack<int> st;

    st.push(100);
    st.push(200);
    st.push(300);
    st.push(400);

    cout << "stack(LIFO):" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    // queue-FIFO-front,push,pop

    queue<int> qu;

    qu.push(100);
    qu.push(200);
    qu.push(300);
    qu.push(400);

    cout << "queue(FIFO):" << endl;
    while (!qu.empty()) {
        cout << qu.front() << " ";
        qu.pop();
    }

    cout << endl;
    // priority_queue - maxHeap - push,pop,top

    priority_queue<int> pq;
    pq.push(200);
    pq.push(3300);
    pq.push(350);
    pq.push(400);
    pq.push(30);
    pq.push(100);

    cout << "priority_queue(MaxHeap):" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    return 0;
}
