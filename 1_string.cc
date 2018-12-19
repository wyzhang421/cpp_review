/*
 * File:   string.cc
 * Time:   2018-12-18 19:36:01
 * Author: wyzhang
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

class String {
public:
    String() 
    : _ptr(nullptr) {
        _ptr = nullptr;
        cout << __FUNCTION__ << endl;
    }
    String(const char * s) 
    : _ptr(new char[strlen(s) + 1]()) {
        cout << "String(const char * s)" << endl;
        strcpy(_ptr, s);
    }

    String & operator = (const char * s) {
        cout << "String & operator = (const char * s)" << endl;
        _ptr = new char[strlen(s) + 1]();
        strcpy(_ptr, s);
    }

    String & operator = (const String & rhs) {
        cout << "String & operator = (const String & rhs)" << endl;
        if (&rhs == this) {
            return *this;
        }
        _ptr = new char[strlen(rhs._ptr)+1]();
        strcpy(_ptr, rhs._ptr);
    }
    String(const String & rhs) 
    : _ptr(new char[strlen(rhs._ptr) + 1]()) {
        cout << "String(const String & rhs)" << endl;
        strcpy(_ptr, rhs._ptr);
    }
    ~String() {
        cout << "~String()"  << endl;
        if (_ptr) {
            delete[] _ptr;
        }
    }
    void print() {
       if (!_ptr) {
           cout << "_ptr is nullptr. " << endl;
           return;
       }
       cout << "string = " << _ptr << endl;
    }
private:
    char * _ptr;
};
int main () {
    String str1;
    str1.print();

    String str2 = "hello world";
    String str3("test");

    cout << __LINE__ << ": " ; str2.print();
    cout << __LINE__ << ": " ; str3.print();

    String str4 = str3;
    cout << __LINE__ << ": " ; str4.print();

    str4 = str2;
    cout << __LINE__ << ": " ; str4.print();

    return 0;
}