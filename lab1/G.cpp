#include <iostream>
#include <vector>
using namespace std;

bool is_prime_triv(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

vector<bool> get_prime_sieve(int limit){
    vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2; i * i <= limit; i++){
        if(sieve[i]){
            for(int j = i*i; j <= limit; j += i){
                sieve[j] = false;
            }
        }
    }
    return sieve;
}


int main() {
    int n, curdigit; cin >> n;
    curdigit = 1;
    int count = 0;
    
    vector<bool> prime_sieve = get_prime_sieve(n);
    while (n){
        curdigit++;
        if (is_prime_triv(curdigit)){
            count++;
            if(is_prime_triv(count)){
                n--;
            }
        }
    }
    std::cout << curdigit << std::endl;
    return 0;
}