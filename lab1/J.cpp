#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {
    char ch;
    std::deque<int> zhan_deq;
    int el;
    while(std::cin.get(ch) && ch != '!'){
        switch(ch){
            case '+':
                cin >> el;
                zhan_deq.push_front(el);
                break;
            case '-':
                cin >> el;
                zhan_deq.push_back(el);
                break;
            case '*':
                if(!zhan_deq.empty()){
                    std::cout << zhan_deq.front() + zhan_deq.back() << std::endl;
                    zhan_deq.pop_back();
                    if(!zhan_deq.empty()){zhan_deq.pop_front();}
                }else{
                    std::cout << "error" << std::endl;
                }
                break;
        }
    }
    return 0;
}