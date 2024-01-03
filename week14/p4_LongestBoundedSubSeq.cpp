#include<bits/stdc++.h>

using namespace std;

int n, Q;
int a[1000000];
int m[1000000];

void input(){
    cin >> n >> Q;
    for( int i = 1; i<=n ;i++){
        scanf("%d", &a[i]);
        m[i] = m[i-1] + a[i];
    }
}

void solve(){
    int res = -1;
    int i = 1;
    int j = 2;
    while( j <= n ){
        if (m[j] - m[i-1] <= Q ){
            if( j - i + 1 > res) res = j - i + 1;
            j += 1;
        }
        else i += 1;
    }
    cout << res;
}

void solve___(){ // không cần tốn thêm bộ nhớ
    int res = 0;
    int S = 0;
    int l = 1;
    for( int r = 1; r <= n; r ++){
        S = S + a[r];
        while( S > Q){
            S = S - a[l];
            l += 1;
        }
        res = max(res, r - l + 1);
    }
    cout << res;
}
int main(){
    freopen("input/data4.txt", "r", stdin);
    input();
    // solve();
    solve___();
}
