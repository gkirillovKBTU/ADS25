#include <iostream>
#include <climits>
#include <string>
#include <unordered_map>
#include <functional>
#include "CustomLinkedList.h"
using namespace std;

int main() {
    LinkedList<string> ll;
    string command;
    unordered_map<string, std::function<void(LinkedList<string>&)>> v0_methods;
    v0_methods["erase_front"] = &LinkedList<string>::erase_front;
    v0_methods["erase_back"] = &LinkedList<string>::erase_back;
    v0_methods["clear"] = &LinkedList<string>::clear;
    v0_methods["print"] = &LinkedList<string>::print;
    v0_methods["front"] = [](LinkedList<string>& ll) { std::cout << ll.front() << std::endl; };
    v0_methods["back"]  = [](LinkedList<string>& ll) { std::cout << ll.back() << std::endl; };

    unordered_map<string, std::function<void(LinkedList<string>&, string)>> v1_methods;
    v1_methods["add_front"] = [](LinkedList<string>& ll, string val) { ll.add_front(val); };
    v1_methods["push_back"] = [](LinkedList<string>& ll, string val) { ll.push_back(val); };

    string argument;
    while (getline(cin, command) && command != "exit") {
        if(v0_methods.find(command) != v0_methods.end()){
            v0_methods[command](ll);
        }else if (v1_methods.find(command) != v1_methods.end()){
            cin >> argument;
            v1_methods[command](ll, argument);
        }else{
            cout << "goodbye" << endl;
        }
    }

    return 0;
}