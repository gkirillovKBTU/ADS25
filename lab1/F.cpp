#include <iostream>
using namespace std;

bool is_prime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, curdigit; cin >> n;
    curdigit = 1;
    while (n){
        curdigit++;
        if (is_prime(curdigit)){
            n--;
        }
    }
    std::cout << curdigit << std::endl;
    return 0;
}