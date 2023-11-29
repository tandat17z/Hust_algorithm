#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;

int n;
int m[3][1001]; // chuoi bat dau bang 0, 1, 2

void preprocessing(){
    m[0][1] = 1;
    m[1][1] = 1;
    m[2][1] = 1;
    for( int i = 2; i<=n; i++){
        m[0][i] = (m[1][i-1] % N + m[2][i-1] % N)% N;
        m[1][i] = (m[0][i-1] % N + m[2][i-1] % N)% N ;
        m[2][i] = ((m[0][i-1] % N + m[1][i-1] % N)% N + m[2][i-1] % N)% N;
    }
}
int main(){
    freopen("input/data5.txt", "r", stdin);
    scanf("%d", &n);
    preprocessing();
    cout << ((m[0][n] % N + m[1][n] % N)% N + m[2][n] % N)% N;
    return 0;
}