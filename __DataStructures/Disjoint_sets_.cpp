#include<bits/stdc++.h>

using namespace std;

//------------Disjoint Sets Union----------------------------
struct DSU{
    vector<int> par, sz; //parent, size(height)
    DSU(int k){
        par.resize(k+1);
        for(int i = 1; i<=k ;i++)
            par[i] = i;
        sz.assgin(k+1, 1);
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
int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    clock_t begin = clock();
    return 0;
}