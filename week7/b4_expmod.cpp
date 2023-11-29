#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int  N = 1e9 + 7;

ull exp(ull a, ull b){
    if( b == 0) return 1;
    ull T = exp(a, b/2);
    T = (T*T) % N;
    if( b % 2 ) T = (T * a) % N;
    return T;
}
int main(){
    freopen("data4.txt", "r", stdin);
    ull a, b;
    scanf("%llu %llu", &a, &b);

    cout << exp(a%N, b);
    return 0;
}