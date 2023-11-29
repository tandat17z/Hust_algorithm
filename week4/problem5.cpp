#include<bits/stdc++.h>
using namespace std;
int n, m;
int s_max = 1;
int a[1001][1001];
void input(){
    cin >> n >> m;
    for( int i = 0; i < n ; i++){
        for( int j = 0; j < m ; j++){
            cin >> a[i][j];
        }
    }
}

int dientich(int u, int v){
    int s = 1;
    int w = m, h = 0;
    for( int i = 0; i < n - u ; i ++ ){
        if( a[u + i][v] == 0 ) break;
        h += 1;
        int w_ = 1;
        for( int j = 1; j < m -v; j++){
            if( a[u + i][v + j] == 0) break;
            if( w_+1 > w) break;
            w_ += 1;
        }
        if( w_ < w) w = w_;
        // cout << h << " " << w << endl;
        s = max(s, h*w);
    }
    return s;
}
int main(){
    freopen("data5.txt", "r", stdin);
    input();
    
    for( int i = 0 ; i < n-s_max/m; i++){
        for( int j = 0; j < m ; j++){
            if( (m-j)*(n-i) < s_max) break;
            if( a[i][j] ) 
                s_max = max(s_max, dientich(i, j));
        }
    }
    cout << s_max;
    // cout << dientich(11, 0);
    return 0;
}
