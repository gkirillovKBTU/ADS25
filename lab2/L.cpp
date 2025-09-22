# include <iostream>
# include <algorithm>
# include <cassert>
# include <climits>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
	// Implement this function
    int max_so_far = INT_MIN, max_ending_here = 0;
    while(head != nullptr){
        max_ending_here += head->val;
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0){
            max_ending_here = 0;
        }
        head = head->next;
    }
    return max_so_far;
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
