#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
using namespace std;

// #include "CustomLinkedList.h"
struct Node {
    int val;
    Node *next, *prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
public:
    Node *head, *tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    };
    void push_back(int value){
        Node *newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void print(){
        Node *node = head;
        while(node != nullptr){
            std::cout << node->val << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    void insert_node(int node_val, int pos){
        int i = 0;
        Node *newNode = new Node(node_val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        Node *dummy = head;
        if (pos == 0){
            newNode->next = dummy;
            head = newNode;
            return;
        }

        while((i != pos - 1) && dummy->next != nullptr){
            dummy = dummy->next;
            i++;
        }
        if(dummy->next != nullptr){
            Node *temp = dummy->next;
            newNode->next = temp;
            temp->prev = newNode;
        }
        dummy->next = newNode;
        newNode->prev = dummy;   
        tail = newNode;
    }
};

int main() {
    int n, data, pos; cin >> n;
    LinkedList ll;
    for(int i=0; i < n; i++){
        cin >> data;
        ll.push_back(data);
    }
    cin >> data >> pos;
    ll.insert_node(data, pos);
    ll.print();
    return 0;
}