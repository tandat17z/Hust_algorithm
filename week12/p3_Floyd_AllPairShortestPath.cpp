#include<bits/stdc++.h>

using namespace std;

#define N 10000
const int INT = 1e8;
int n, m;
int d[N][N];

void input(){
    scanf("%d %d", &n, &m);
    for( int i = 0; i<m ; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        d[u][v] = w;
    }
}
void init(){
    for( int i = 1; i<= n ; i ++){
        for( int j = 1; j<= n; j ++){ 
            if( d[i][j] == 0 && i != j) d[i][j] = INT;
        }
    }
}
void floyd(){
    init();
    for( int k = 1; k <= n; k ++){
        for( int i = 1; i<= n ; i ++){
            for( int j = 1; j<= n; j ++){
                if( d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}
int main(){
    freopen("input/data3.txt", "r", stdin);
    input();
    floyd();
    for( int i = 1; i<= n ; i ++){
        for( int j = 1; j<= n; j ++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}