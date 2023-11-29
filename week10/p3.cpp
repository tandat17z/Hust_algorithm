#include<bits/stdc++.h>
using namespace std;

int n, M;
int a[10001];
int cnt = 0;
int curr = 0;

void input(){
    scanf("%d %d", &n, &M);
    for( int i = 1; i<=n ;i++){
        scanf("%d", &a[i]);
    }
}

void Try(int k){
    for( int i = 0; i<= (M - curr) / a[k] ; i++){
        curr += a[k]*i;
        if( curr == M ) cnt += 1;
        if ( k < n && curr < M) Try(k + 1);
        curr -= a[k]*i;
    }
}
int main(){
    freopen("input/data3.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    Try(1);
    cout << cnt;
    return 0;
}