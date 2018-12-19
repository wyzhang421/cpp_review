/*
 * File:   queue.cc
 * Time:   2018-12-19 11:45:10
 * Author: wyzhang
*/

#include <cstdio>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Queue {
public:
    Queue()
    : first(0)
    , rear(0)
    , size(0)
    , capacity(0) {
    }
    Queue(int num) 
    : first(0)
    , rear(0)
    , size(0)
    , capacity(num) {
        nums.reserve(num);
    }
    ~Queue() {
        nums.clear();
        first = rear = -1;
        size = capacity = 0;
    }
    void push(int num) {
        if (full()) {
            cout << "can not push element, queue is full. input is " << num << endl;
            return;
        }
        ++size;
        nums[rear] = num;
        rear = (rear + 1) % capacity;
    }
    void pop() {
        if (empty()) {
            cout << "can not pop, queue is empty." << endl;
            return;
        }
        --size;
        first = (first + 1) % capacity;
    }
    int front() {
        if (empty()) {
            cout << "can not get front, queue is empty." << endl;
            return -1;
        }
        return nums[first];
    }
    int back() {
        if (empty()) {
            cout << "can not get back, queue is empty." << endl;
            return -1;
        }
        int tmp_rear = ((rear + capacity) - 1) % capacity;
        return nums[tmp_rear];
    }
    bool empty() {
        return size == 0;
    }
    bool full() {
        return size == capacity;
    }

private:
    vector<int> nums;
    int first, rear, size, capacity;

    void print() {
        printf("capacity = %d, size = %d, first = %d, rear = %d, [", capacity, size, first, rear);
        for (int i = 0; i < capacity; ++i) {
            printf(" %d", nums[i]);
        }
        printf("]\n");
    }
};

int main () {
    Queue que = Queue(3);
    que.push(1);
    printf("%d: que.front = %d, que.back = %d\n", __LINE__, que.front(), que.back());
    que.push(2);
    que.push(3);
    que.push(4);
    printf("%d: que.front = %d, que.back = %d\n", __LINE__, que.front(), que.back());
    que.pop();
    printf("%d: que.front = %d, que.back = %d\n", __LINE__, que.front(), que.back());
    
    printf("begin while loop\n");
    while (!que.empty()) {
        printf("%d: que.front = %d, que.back = %d\n", __LINE__, que.front(), que.back());
        que.pop();        
    }
    return 0;
}
