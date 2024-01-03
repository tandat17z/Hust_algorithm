#include<bits/stdc++.h>

using namespace std;

int n, m;
int d[10000]; // duration i
vector<int> adj[10000]; // Danh sách kề
int F[10000]; // Thời gian sớm nhất để bắt đầu công việc i

// sắp xếp topo
int deg_enter[10000];

void input(){
    freopen("input/data4.txt", "r", stdin);
    cin >> n >> m;
    for( int i = 1; i<=n; i++){
        cin >> d[i];
    }
    for( int i =0 ; i<m ;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg_enter[v] += 1;
    }
}

vector<int> topoSort(){ // đồ thị không có chu trình
    queue<int> Q;
    for( int i = 1; i<=n; i++) if (deg_enter[i] == 0){
        Q.push(i);
    }
    vector<int> L; // danh sách đã sắp xếp topo
    while( !Q.empty()){
        int v = Q.front(); Q.pop();
        L.push_back(v);
        for(auto i: adj[v]){
            deg_enter[i] -= 1;
            if( deg_enter[i] == 0) Q.push(i);
        }
    }
    return L;
}

void solve(){
    vector<int> topoList = topoSort();
    int res = 0;
    for( auto u : topoList){
        int t = F[u] + d[u];
        for( auto v: adj[u]){
            F[v] = max(F[v], t);
            res = max(res, F[v] + d[v]);
        }
    }
    cout << res;
}
int main(){
    input();
    solve();
    return 0;
}