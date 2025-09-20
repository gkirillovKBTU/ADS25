#include "CustomLinkedList.h"
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
void LinkedList<T>::push_back(T value) {
    Node<T> *newNode = new Node<T>(value);
    if (tail == nullptr) {
        tail = newNode;
        head = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
void LinkedList<T>::print(){
    Node<T> *node = head;
    while(node != nullptr){
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedList<T>::insert_node(T node_val, int pos){
    int i = 0;
    Node<T> *newNode = new Node<T>(node_val);
    if (head == nullptr) {
        // If the list is empty, insert as the only node
        head = newNode;
        tail = newNode;
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
}
