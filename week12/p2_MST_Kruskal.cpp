#include<bits/stdc++.h>
using namespace std;

struct Arc{
    int weight;
    int node1;
    int node2;

    Arc(int w, int n1, int n2){
        weight = w;
        node1 = n1;
        node2 = n2;
    }

    bool operator < (const Arc& other){
        return weight < other.weight;
    }
};

struct DSU{
    vector<int> par, sz; //parent, size(height)
    DSU(int k){
        par.resize(k+1);
        for(int i = 1; i<=k ;i++)
            par[i] = i;
        sz.assign(k+1, 1);
    }
    int find(int v){
        if( v == par[v])
            return v;
        return par[v] = find(par[v]);
    }
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if( u == v)
            return;
        if( sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
    int size(int u){
        return sz[find(u)];
    }
};

int n, m;
vector<Arc> A;

void input(){
    scanf("%d %d", &n, &m);
    for( int i = 1; i<=m ;i++){
        int u, v, w; 
        scanf("%d %d %d ", &u, &v, &w);
        A.push_back(Arc(w, u, v));
    }
}

int weight_res = 0;
void kruskal(){
    DSU G(n);
    sort(A.begin(), A.end());
    for( auto i : A){
        int u = i.node1;
        int v = i.node2;
        int w = i.weight;
        if( G.find(u) != G.find(v)){
            weight_res += w;
            G.join(u, v);
        }
    }
}
int main(){
    freopen("input/data2.txt", "r", stdin);
    input();
    kruskal();
    cout << weight_res;
    return 0;
}