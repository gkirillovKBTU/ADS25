#pragma once

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
    LinkedList();
    void push_back(T value);
    void print();
    void insert_node(T node_val, int pos);
    void erase_back();
    void erase_front();
    void add_front(T node_val);
    T front();
    T back();
    void clear();

};