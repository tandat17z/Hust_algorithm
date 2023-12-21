// Sử dụng DFS 2 pha --- O(n)

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
struct Edge{
    int node, w;
    Edge(int node, int w): node(node), w(w){

    }
};

int n;
vector<Edge> adj[N];

int root;
int d[N]; // d[u] is the sum of weights of path from (descendant of u) to u
int num[N]; //num[u] is the number of descendant of u
int f[N]; // f[u] is the sum of weight of path from other nodes to u
int pa[N]; // pa[u] is the parent of u

vector<bool> visited(N, 0);

void input(){
    cin >> n;
    for( int i = 0; i<n-1 ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }
}

void dfs1(int u){ // Tính d[x], num[x] của tất cả các nút con của u
    visited[u] = true;
    for(auto e: adj[u]){
        int v = e.node, w = e.w;
        if( !visited[v] ){
            dfs1(v);
            d[u] += d[v] + w*num[v];
            num[u] += num[v];
        }
    }
}

void dfs2(int u){ // Tính đầy đủ f(v) là các con của u ( khi đã biết f(u))
    visited[u] = true;
    for( auto e : adj[u]){
        int v = e.node, w = e.w;
        if( !visited[v]){
            int f_ = f[u] - (d[v] + w*num[v]); // tổng đường đi từ nút (không phải con v) tới v
            f[v] = f_ + d[v] + w*(n - num[v]); 
            dfs2(v);
        }
    }
}

void init(){
    visited = vector<bool>(n, 0);
}
void solve(){
    root = 1;
    visited = vector<bool>(n, 0);
    for( int i = 1; i<=n; i++) num[i] = 1;
    dfs1(1);

    visited = vector<bool>(n, 0);
    f[1] = d[1];
    dfs2(1);
    int res = 1;
    for( int i = 2; i<=n ; i++){
        if(f[res] < f[i]) res = i;
    }
    cout << f[res];
}
int main(){
    freopen("input/data5.txt", "r", stdin);
    input();
    solve();
}