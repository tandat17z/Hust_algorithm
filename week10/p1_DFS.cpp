#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> a;
bool visited[100000];

void input(){
    scanf("%d %d", &n, &m);
    a = vector<set<int>>(n + 1);

    for( int _ = 0; _ < m; _ ++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].insert(v);
        a[v].insert(u);
    }
}

void explore(int k){
    visited[k] = true;
    printf("%d ", k);
    for( auto i : a[k]){
        if( visited[i] == false) explore(i);
    }
}

void dfs(){
    explore(1);
}
int main(){
    freopen("input/data1.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    dfs();

    return 0;
}