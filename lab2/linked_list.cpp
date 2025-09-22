#include "CustomLinkedList.h"
#include <iostream>
#include <string>

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

template<typename T>
void LinkedList<T>::erase_back() {
    if (tail == nullptr) return;
    Node<T>* toDelete = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete toDelete;
}

template<typename T>
void LinkedList<T>::erase_front() {
    if (head == nullptr) return;
    Node<T>* toDelete = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete toDelete;
}

template<typename T>
void LinkedList<T>::add_front(T node_val) {
    Node<T>* newNode = new Node<T>(node_val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template<typename T>
T LinkedList<T>::front() {
    if (head == nullptr) {
        std::cout << "error\n";
        return T();
    }
    return head->val;
}

template<typename T>
T LinkedList<T>::back() {
    if (tail == nullptr) {
        std::cout << "error\n";
        return T();
    }
    return tail->val;
}

template<typename T>
void LinkedList<T>::clear() {
    Node<T>* node = head;
    while (node != nullptr) {
        Node<T>* next = node->next;
        delete node;
        node = next;
    }
    head = tail = nullptr;
}

template class LinkedList<int>;
template struct Node<int>;
template class LinkedList<std::string>;
template struct Node<std::string>;