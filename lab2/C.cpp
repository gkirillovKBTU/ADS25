#include <iostream>
#include <deque>
#include <string>
using namespace std;

#include "CustomLinkedList.h"

// struct Node {
//     int val;
//     Node *next, *prev;
//     Node(int val) : val(val), next(nullptr), prev(nullptr) {}
// };

// class LinkedList {
// public:
//     Node *head, *tail;
//     LinkedList(){
//         head = nullptr;
//         tail = nullptr;
//     };
//     void push_back(int value){
//         Node *newNode = new Node(value);
//         if (tail == nullptr) {
//             tail = newNode;
//             head = newNode;
//         } else {
//             newNode->prev = tail;
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
//     void print(){
//         Node *node = head;
//         while(node != nullptr){
//             std::cout << node->val << " ";
//             node = node->next;
//         }
//         std::cout << std::endl;
//     }
// };

int main() {
    int n, el; cin >> n;
    LinkedList<int> ll;
    for(int i=0; i < n; i++){
        cin >> el;
        ll.push_back(el);
    }
    Node<int>* dummy = ll.head;
    for(int i=1; i < n; i+=2){
        dummy->next = dummy->next->next;
        dummy = dummy->next;
    }
    ll.print();
    return 0;
}