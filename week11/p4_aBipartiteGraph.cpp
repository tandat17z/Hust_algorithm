#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> a;
bool visited[100000];

vector<vector<bool>> g(2, vector<bool>(100000,false));

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

bool explore(int k, bool gr){
    visited[k] = true;
    g[gr][k] = true;
    // printf("%d ", k);
    for( auto i : a[k]){
        if( g[gr][i] == true) return false;
        if( visited[i] == false) explore(i, !gr);
    }
    return true;
}

int check(){
    for( int i = 1; i<=n ;i++){
        if( visited[i] == false) {
            g[0][i] = true;
            if( !explore(i, 0)) return 0;
        }
    }
    return 1;
}
int main(){
    freopen("input/data4.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << check();

    return 0;
}