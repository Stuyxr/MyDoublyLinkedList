#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
using namespace std;
int main() {
    MyList<Person> list;
    Person p1("John", 30);
    Person p2("Jane", 25);
    cout << "------Test easy functions of MyList------" << endl;
    list.push_front(p1);
    list.push_front(Person("stuyxr", 23));
    list.push_back(Person("stuzkb", 22));
    list.push_front(std::move(p2));
    cout << "size of list: " << list.size() << endl;
    list.show();
    list.pop_front();
    list.show();
    cout << endl;
    cout << "------Test use rvalue of Person to construct Node------" << endl;
    // p2 is moved
    cout << "p1: " << p1 << ", p2:" << p2 << endl;
    cout << endl;
    cout << "------Test copy constructor------" << endl;

    MyList<Person> copy_list = list;
    cout << "show copy list:" << endl;
    copy_list.show();
    cout << "show list:" << endl;
    list.show();
    cout << endl;
    cout << "------Test move constructor------" << endl;
    MyList<Person> move_list = std::move(list);
    cout << "show move list:" << endl;
    move_list.show();
    cout << "show list:" << endl;
    list.show();
    cout << endl;
    cout << "------Test iterator------" << endl;
    for (MyList<Person>::MyIterator it = move_list.begin();
         it != move_list.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}