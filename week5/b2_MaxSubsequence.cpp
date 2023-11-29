#include<bits/stdc++.h>

using namespace std;

int A[1000000];
int e[1000000];

int main(){
    freopen("data2.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%d", &A[0]);
    int res = A[0];
    e[0] = A[0];
    for( int i = 1; i<n ;i++){
        scanf("%d", &A[i]);
        e[i] = A[i];
        if( e[i - 1] > 0 ) e[i] += e[i - 1]; 
        res = max( res, e[i]);
    }
    cout << res;
}