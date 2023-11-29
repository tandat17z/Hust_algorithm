#include<bits/stdc++.h>
using namespace std;

int n, kk;
int x[25];
int c[25][25];
bool visited[25];
int f, cmin= 1e9, fmin_ = 1e9;
int d; // so nguoi tren xe luon <= k;

void input(){
    cin >> n >> kk;
    for( int i = 0; i<= 2*n ; i++){
        for( int j = 0; j<= 2*n ; j++){
            cin >> c[i][j];
            if(i != j && cmin > c[i][j] ) cmin = c[i][j];
        }
    }
}

bool check(int i, int k){
    if( visited[i] == true) return false; // tham roi khong len
    if( i <= n && d == kk) return false; // vuot qua kha nang
    if( visited[i-n] == false && i > n) return false;// chua len xe k di qua
    return true;
}

void solution(){
    if( f + c[x[2*n]][0] < fmin_) fmin_ = f + c[x[2*n]][0];
}

void Try(int k){
    for( int i = 1; i <= 2*n; i++){
        if( check(i, k) ){
            x[k] = i;
            visited[i] = true;
            f += c[x[k-1]][i];
            if( i <= n) d += 1;
            else d -= 1;

            if( k == 2*n) solution();
            else if( f + cmin*(2*n-k) < fmin_) Try(k + 1);

            visited[i] = false;
            f -= c[x[k-1]][i];
            if( i <= n) d -= 1;
            else d += 1;
        }
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    input();
    Try(1);
    cout << fmin_;
    return 0;
}
