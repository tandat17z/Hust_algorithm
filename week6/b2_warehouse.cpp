#include<bits/stdc++.h>
using namespace std;

int n, T, d;
int a[1001];
int t[1001];
int max_load;

int M[1001][101];

void input(){
    scanf("%d %d %d", &n, &T, &d);
    for( int i = 1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for( int i = 1; i<=n; i++){
        scanf("%d", &t[i]);
    }
}

void preprocessing(){
    for( int j= t[1]; j<= T; j++){
        M[1][j] = a[1];
    }
    
    for( int i = 2; i<= n; i++){
        M[i][ t[i] ] = a[i];
        for( int j = t[i] + 1; j <= T ; j++){
            for( int k = i-1; k >= i - d && k >= 1 ; k--){
                M[i][j] = max( M[i][j], a[i] + M[k][j - t[i]] );
            }
        }
    }
}
int main(){
    freopen("data2.txt", "r", stdin);
    input();
    preprocessing();
    for( int i = 1; i<=n ;i++){
        max_load = max(max_load, M[i][T]);
    }
    cout << max_load;
    return 0;
}