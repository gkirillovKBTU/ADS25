#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* findPrev(Node* start, int p){
    Node* cur = start;
    for (int i = 0; i < p && cur->next; ++i) cur = cur->next;
    return cur;
}

Node* insert(Node* head, Node* node, int p){
    Node dummy;
    dummy.next = head;
    Node* prev = findPrev(&dummy, max(0, p));
    node->next = prev->next;
    prev->next = node;
    return dummy.next;
}

Node* remove(Node* head, int p){
    if (!head) return head;
    Node dummy;
    dummy.next = head;
    Node* prev = findPrev(&dummy, p);
    if (prev->next){
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
    }
    return dummy.next;
}

Node* replace(Node* head, int p1, int p2){
    if (!head || p1 == p2) return head;
    Node dummy;
    dummy.next = head;
    Node* prev1 = findPrev(&dummy, p1);
    if (!prev1->next) return dummy.next;
    Node* node1 = prev1->next;
    prev1->next = node1->next;
    Node* prev2 = findPrev(&dummy, max(0, p2));
    node1->next = prev2->next;
    prev2->next = node1;
    return dummy.next;
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nx = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nx;
    }
    return prev;
}

void print(Node* head){
    if(!head){
        cout << "-1\n";
        return;
    }
    Node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << "\n";
}

Node* cyclic_left(Node* head, int x, bool reversed = false){
    if (!head || x == 0) return head;
    int n = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        ++n;
    }
    int k = x % n;
    if (k == 0) return head;
    if (reversed) k = (n - k) % n;
    Node* new_tail = head;
    for (int i = 1; i < k; ++i) new_tail = new_tail->next;
    Node* new_head = new_tail->next;
    tail->next = head;
    new_tail->next = nullptr;
    return new_head;
}

Node* cyclic_right(Node* head, int x){
    return cyclic_left(head, x, true);
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}
