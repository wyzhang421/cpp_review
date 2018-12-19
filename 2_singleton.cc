/*
 * File:   singleton.cc
 * Time:   2018-12-19 10:22:18
 * Author: wyzhang
*/

//要求： 在内存中只能创建一个对象
//1. 该对象不能是栈(全局)对象
//2. 该对象只能放在堆中

//应用场景：
//1. 直接替换任意的全局对象（变量）//因为全局对象越少越好
//2. 配置文件
//3. 词典类

//实现步骤：
//1. 将构造函数私有化
//2. 在类中定一个静态的指针对象（一般设置为私有），并且在类外初始化为空
//3. 定义一个返回值为类指针的静态成员函数，
//      如果2中的指针对象为空，则初始化对象，以后在有对象调用该静态成员函数的时候，不再初始化对象，
//      而是直接返回对象，保证类在内存中只有一个对象


#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

class Singleton {
public:
    static Singleton * getInstance() {  //不是静态的成员函数就没法调用，因为没有对象，需要类名调用
        if (!_pInstance) {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
    static void destory() {
        if (_pInstance) {
            delete _pInstance;
        }
    }
    void print() {
        cout << "Singleton::print() " ;
        if (_pInstance) {
            printf("_pInstance = %p \n", _pInstance);
        }
    }
private:
    Singleton() {
        cout << "Singleton()" << endl;
    }
    ~Singleton() {
        cout << "~Singleton(): " ;
        printf("_pInstance = %p \n", _pInstance);
    }
    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = 0;

/*
wyzhang@IdeaPad:~/code/c++/20181214/homework$ ./singleton
Singleton()
p1 = 0x555eef444e70
p2 = 0x555eef444e70
Singleton::print() _pInstance = 0x555eef444e70 
~Singleton(): _pInstance = 0x555eef444e70 
Singleton::print() _pInstance = 0x555eef444e70 
~Singleton(): _pInstance = 0x555eef444e70 
*/

int main () {
    Singleton * p1 = Singleton::getInstance();
    Singleton * p2 = Singleton::getInstance();
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);

    p1->print();
    p1->destory();
    
    //可能写的有bug？能调用析构函数两次？
    p2->print();
    p2->destory();

    return 0;
}