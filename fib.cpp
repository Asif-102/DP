#include <bits/stdc++.h>
using namespace std;

long long ara[101];

long long fib(int n){
    if(n <= 2){
        return 1;
    }
    if(ara[n] != 0){
        return ara[n];
    }
    ara[n] = fib(n-1) + fib(n-2);
    return ara[n];
}

int main() {
    cout << fib(5) << '\n';
    cout << fib(15) << '\n';
    cout << fib(50) << '\n';
    return 0;
}