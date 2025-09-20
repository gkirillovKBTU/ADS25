#include <iostream>
#include <vector>
using namespace std;

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
    int n; cin >> n;
    
    vector<bool> prime_sieve = get_prime_sieve(n);
    std::cout << (prime_sieve[n] ? "YES" : "NO") << std::endl;
    return 0;
}