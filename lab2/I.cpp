#include <iostream>
#include <climits>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

// #include "CustomLinkedList.h"
template<typename T>
struct Node {
    T val;
    Node<T> *next, *prev;
    Node(T val) : val(val), next(nullptr), prev(nullptr) {}
};

template<typename T>
class LinkedList {
public:
    Node<T> *head, *tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    };
    void push_back(T value){
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        std::cout << "ok" << std::endl;
    }
    void print(){
        Node<T> *node = head;
        while(node != nullptr){
            std::cout << node->val << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    void insert_node(T node_val, int pos){
        int i = 0;
        Node<T> *newNode = new Node<T>(node_val);
        if (head == nullptr) {
            // If the list is empty, insert as the only node
            head = newNode;
            tail = newNode;
            std::cout << "ok" << std::endl;
            return;
        }
        Node<T> *dummy = head;
        if (pos == 0){
            newNode->next = dummy;
            head = newNode;
        }

        while((i != pos - 1) && dummy->next != nullptr){
            dummy = dummy->next;
            i++;
        }
        if(dummy->next != nullptr){
            Node<T> *temp = dummy->next;
            newNode->next = temp;
            temp->prev = newNode;
        }
        dummy->next = newNode;
        newNode->prev = dummy;   
        tail = newNode;
        std::cout << "ok" << std::endl;
    }
    void erase_back(){
        if (tail == nullptr) {
            cout << "error" << endl;
            return;
        }
        Node<T>* toDelete = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        std::cout << toDelete->val << std::endl;
        delete toDelete;
    }
    void erase_front(){
        if (head == nullptr) {
            cout << "error" << endl;
            return;
        }
        Node<T>* toDelete = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;

        }
        std::cout << toDelete->val << std::endl;
        delete toDelete;
    }
    void add_front(T node_val){
        Node<T>* newNode = new Node<T>(node_val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        std::cout << "ok" << std::endl;
    }
    T front(){
        if (head == nullptr) {
            std::cout << "error";
            return T();
        }
        return head->val;
    }
    T back(){
        if (tail == nullptr) {
            std::cout << "error";
            return T();
        }
        return tail->val;
    }
    void clear(){
        Node<T>* node = head;
        while (node != nullptr) {
            Node<T>* next = node->next;
            delete node;
            node = next;
        }
        head = tail = nullptr;
        std::cout << "ok" << std::endl;
    }
};


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
    v1_methods["add_back"] = [](LinkedList<string>& ll, string val) { ll.push_back(val); };

    string argument;
    while (getline(cin, command) && command != "exit") {
        if(v0_methods.find(command) != v0_methods.end()){
            v0_methods[command](ll);
        }else{
            int space_pos = command.find(" ");
            argument = command.substr(space_pos+1);
            command = command.substr(0, space_pos);
            // cout << "Argument consumed" << endl;
            v1_methods[command](ll, argument);
        }
    }
    cout << "goodbye" << endl;

    return 0;
}