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
    // printf("%d ", k);
    for( auto i : a[k]){
        if( visited[i] == false) explore(i);
    }
}

void countComponent(){
    int cnt = 0;
    for( int i = 1; i<=n ;i++){
        if( visited[i] == false) {
            cnt += 1;
            explore(i);
        }
    }
    cout << cnt ;
}
int main(){
    freopen("input/data3.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    countComponent();

    return 0;
}