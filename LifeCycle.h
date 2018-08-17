//Hamza Ilyas
//hi3zk
//LifeCycle.h
//1_26_18

#include <iostream>
#ifndef LIFECYCLE_H
#define LIFECYCLE_H
using namespace std;


class MyObject {
 public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor
    string getName() const {
        return name;
    }
    void setName(const string newName) {
        name = newName;
    }
    friend ostream& operator<<(ostream& output, const MyObject& obj);
 private:
    string name;
    int id;
};

#endif
