#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, m;
vector<int> adj[N];
int num[N], low[N];// Dùng cho Jarjan
int t = 0; // Thời gian -> tính thời điểm duyệt qua các node

vector<pair<int, int>> bridges;
unordered_set<int> articulationPoints;


void input(){
    freopen("input/data6.txt", "r", stdin);
    cin >> n >> m;
    for( int i = 0; i<m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int pa){
    t += 1;
    num[u] = t; low[u] = t;

    int numChild = 0;
    for( auto v : adj[u]){
        if( v == pa) continue;
        if( num[v] == 0) {// v chưa được duyệt qua - (u, v) là cạnh xuôi
            numChild += 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if( low[v] > num[u]) bridges.push_back(make_pair(u, v));
            if( pa != u ){
                if( low[v] >= num[u] ) articulationPoints.insert(u);
            }
        }
        else low[u] = min(low[u], num[v]);
    }
    if( numChild > 1 && pa == u){
        articulationPoints.insert(u);
    }

}

void solve(){
    t = 0;
    for( int u = 1; u<=n; u++){
        if( num[u] == 0) dfs(u, u);
    }
    cout << articulationPoints.size() << " " << bridges.size();
}
int main(){
    input();
    solve();
    return 0;
}