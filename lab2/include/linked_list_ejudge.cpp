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
    void push_back(int value){
        Node<T>* newNode = new Node<T>(value);
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
        Node<T> *node = head;
        while(node != nullptr){
            std::cout << node->val << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    void insert_node(int node_val, int pos){
        int i = 0;
        Node<T> *newNode = new Node<T>(node_val);
        if (head == nullptr) {
            // If the list is empty, insert as the only node
            head = newNode;
            tail = newNode;
            return;
        }
        Node *dummy = head;
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
    void erase_back(){
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
    void erase_front(){
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
    void add_front(int node_val){
        Node<T>* newNode = new Node<T>(node_val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    T front(){
        if (head == nullptr) {
            std::cout << "error\n";
            return T();
        }
        return head->val;
    }
    T back(){
        if (tail == nullptr) {
            std::cout << "error\n";
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
    }
};