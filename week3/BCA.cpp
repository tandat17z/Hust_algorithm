#include<bits/stdc++.h>
using namespace std;

int m, n, k, mm;
bool conf[31][31];
int x[31];
vector< vector<int>> T(31);
int load[11];
int min_load = 1e9;

void input(){
    cin >> m >> n;
    for( int i = 1; i <= m; i++){
        int u1, u2;
        cin >> u1;
        for( int j = 0 ; j < u1; j++){
            cin >> u2;
            T[u2].push_back(i);
        }
    }
    cin >> k;
    for( int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        conf[x][y] = 1;
        conf[y][x] = 1;
    }
}

bool check(int i, int k){ // gv i co the day mon k khong
    for( int v = 1; v < k ; v++){
        if( conf[v][k] && x[v] == i) return false;
    }
    return true;
}

void solution(){
    int max_ = 0;
    for( int i = 1; i <= m; i++){
        max_ = max(max_, load[i]);
    }
    if( max_ < min_load ) min_load = max_;
}

void Try(int k){
    for( auto i : T[k]){
        if( check(i, k) ){
            x[k] = i;
            load[i] ++ ;
            int pre = mm;
            if( mm < load[i] ) mm = load[i];
            if( k == n) solution();
            else if ( mm < min_load) Try(k + 1);
            mm = pre;
            load[i] --;
        }
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    input();
    Try(1);
    cout << min_load;
    return 0;
}
