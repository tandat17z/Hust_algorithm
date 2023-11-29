#include<bits/stdc++.h>
using namespace std;

int n, M;
int c[16][16];
int x[17];
int cur = 0;
bool visited[16];
int count_tour = 0;
void input(){
    cin >> n >> M;
    for( int i = 1 ; i<=n ; i++){
        for( int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
}
bool check(int i, int k){
    if( visited[i] ) return false;
    return true;
}
void solution(){
    count_tour += 1;
}

void Try(int k){
    for( int i = 2; i <= n ; i++){
        if( check(i, k) ){
            x[k] = i;
            visited[i] = true;
            cur += c[x[k-1]][i];
            if( k == n-1 ){
                if( cur + c[i][1] <= M ) solution();
            }
            else if( cur <= M) Try(k + 1);
            visited[i] = false;
            cur -= c[x[k-1]][i];
        }
    }
}

int main(){
    freopen("data4.txt", "r", stdin);
    input();
    x[0] = 1;
    Try(1);
    cout << count_tour;
    return 0;
}
