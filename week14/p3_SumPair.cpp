#include<bits/stdc++.h>

using namespace std;

int n, M;
int a[1000000];
int check[1000000];

int cnt = 0;
void input(){
    cin >> n >> M;
    for( int i = 1; i<=n ;i++){
        scanf("%d", &a[i]);
        if( check[M - a[i]] > 0) cnt += check[M - a[i]];
        check[a[i]] += 1;

    }
    cout << cnt;
}

void solve(){
    sort(a + 1, a + n + 1);

    cnt = 0;
    int i = 1;
    int j = n;
    while( i != j){
        if( a[i] + a[j] == M){
            cnt += 1;
            i += 1;
            j -= 1;
        }
        else if( a[i] + a[j] > M) j -= 1;
        else i += 1;
    }
    cout << cnt;
}
int main(){
    freopen("input/data3.txt", "r", stdin);
    input();
    solve();
}
