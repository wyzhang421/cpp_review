/*
 * File:   stack.cc
 * Time:   2018-12-19 11:14:15
 * Author: wyzhang
*/

#include <cstdio>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Stack {
public:
    Stack() {

    }
    Stack(int n) {
        nums.reserve(n); //capacity
    }
    ~Stack() {
        nums.clear();
    }
    void push(int num) {
        if (full()) {
            cout << "can not push, stk is full. input is " << num << endl; 
            return;
        }
        nums.push_back(num);
    }
    void pop() {
        if (empty()) {
            cout << "can not pop, stk is empty." << endl;
            return;
        }
        nums.pop_back();
    }
    int top() {
        if (empty()) {
            cout << "can not get top, stk is empty." << endl;
            return -1;
        }
        return nums.back();
    }
    bool empty() {
        return nums.size() == 0;
    }
    bool full() {
        return nums.size() == nums.capacity();
    }
private:
    vector<int> nums;
};

int main () {
    Stack stk = Stack(2);
    stk.push(10);
    stk.push(12);
    stk.push(14);
    
    cout << "top of stk is " << stk.top() << endl;
    stk.pop();
    cout << "top of stk is " << stk.top() << endl;

    cout << "stk is emtpy : " << stk.empty() << endl;
    cout << "stk is full : " << stk.full() << endl;
    return 0;
}