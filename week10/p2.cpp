#include<bits/stdc++.h>
using namespace std;

int n;
int x[1001];
int stt[1001];
int c[1001][1001];

void input(){
    scanf("%d", &n);
    for( int i = 1; i<=n; i++){
        scanf("%d", &x[i]);
        stt[x[i]] = i;
    }
    for( int i = 1; i<= n; i++){
        for( int j = 1; j<=n ;j++){
            scanf("%d", &c[i][j]);
        }
    }
}

int solution(){
    int m;
    scanf("%d", &m);
    for( int i = 0; i<m ;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if( stt[a] > stt[b]) return -1;
    }
    int total = 0;
    for( int i = 1; i<n; i++){
        total += c[x[i]][x[i+1]];
    }
    return total + c[x[n]][x[1]];
}

int main(){
    freopen("input/data2.txt", "r", stdin);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    
    input();
    printf("%d", solution());

    return 0;
}