#include<bits/stdc++.h>
using namespace std;

int n, K, Q;
int d[15];
int c[15][15];
int m;
bool F[15][15];


int num_visited; // số nơi đã giao
int dist; // khoảng cách đã đi
vector<int> route[15]; // tuyến đường đã đi
int load[15]; // lượng hiện tại đang tải
bool visited[15]; // đã thăm chưa

int result = 1e9;

void input(){
    scanf("%d %d %d", &n, &K, &Q);
    for(int i = 1; i<=n; i++){
        scanf("%d", &d[i]);
    }
    for( int i = 0; i<=n; i++){
        for( int j = 0; j<=n; j++)
            scanf("%d", &c[i][j]);
    }
    
    scanf("%d", &m);
    for( int i = 0; i<m ;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        F[u][v] = true; F[v][u] = true;
    }
}

bool check(int id, int i){ // i != 0
    if( id != 1 && route[id].size() + 1 > route[id-1].size()) return false; // xe sau không đc đi dài hơn xe trước
    if(visited[i]) return false; // đã thăm
    if( load[id] + d[i] > Q) return false; // vượt quá tải Q
    
    for( auto x: route[id]){
        if( F[i][x] ) return false; // check ràng buộc cặp (i, j)
    }
    return true;
}

void try_(int id, int loc){// xe id và vị trí hiện tại loc
    // cout << id << " " << loc << endl;
    for( int i = 1; i<=n; i++){
        if( check(id, i) ){
            num_visited += 1;
            visited[i] = true;
            dist += c[route[id].back()][i];
            load[id] += d[i];
            route[id].push_back(i);
            
            if(dist < result) try_(id, i);

            route[id].pop_back();
            load[id] -= d[i];
            dist -= c[route[id].back()][i];
            visited[i] = false;
            num_visited -= 1;
        }
    }
    if( route[id].size() > 1){
        int i = 0;
        dist += c[route[id].back()][0];
        if( dist < result)
            if( num_visited == n) {
                cout << dist << endl;
                result = min(result, dist);
            }
            if( id < K) {
                route[id + 1].push_back(0);
                try_(id + 1, 0);
                route[id + 1].pop_back();
            }

        dist -= c[route[id].back()][0];
    }
}

int main(){
    freopen("input/data4.txt", "r", stdin);
    input();

    route[1].push_back(0);
    try_(1, 0);

    if(result < 1e9) cout << result;
    else cout << -1;
    return 0;
} 