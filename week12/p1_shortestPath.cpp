#include<bits/stdc++.h>
using namespace std ;

#define N 100001
#define pii pair<int, int>

const int INF = 1e9;

struct Arc{
    int node; // other endpoint
    int weight; // weight

    Arc( int _node, int _w){
        node = _node;
        weight = _w;
    }
};

int n, m, s, t;
vector<Arc> A[N];// 
int d[N]; // upper bound of the length or the shortest path from s to v
int p[N]; // the predecessor the v on the upper-bound path

void input(){
    scanf("%d %d", &n, &m);
    for( int i = 0; i<m ; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        A[u].push_back(Arc(v, w));
    }
    scanf("%d %d", &s, &t);
}

int selectMin(set<int> &F){
    int minD = INF; int select = -1;
    for( set<int>::iterator p = F.begin(); p != F.end(); p++){
        if( minD > d[*p] ){
            minD = d[*p];
            select = *p;
        }
    }
    return select;
}

void init(){
    for( int v= 1; v <=n ; v++){
        d[v] = INF;
        p[v] = -1;
    }
}
int dijkstra(){
    set<int> F;
    init();
    for( int i = 1; i<=n; i++) F.insert(i);

    d[s] = 0;
    while( F.size()  > 0){
        int u = selectMin(F);
        F.erase(u);
        if( u == t) return d[t];
        for( int i = 0; i < A[u].size(); i++){
            int v = A[u][i].node;
            int w = A[u][i].weight;
            if( F.find(v)  != F.end()){
                if( d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    p[v] = u;
                }
            }
        }
    }
    return 0;
}

int dijkstra_PriorityQueue(){
    init();
    priority_queue< pii, vector<pii>, greater<pii> > F;
    F.push(make_pair(0, s));
    d[s] = 0;
    while( !F.empty() ){
        pii p = F.top(); F.pop();
        int u = p.second;
        d[u] = p.first;

        if( u == t) return d[u];
        for (int i = 0; i< A[u].size(); i++){
            int  v = A[u][i].node;
            int w = A[u][i].weight;
            if( d[v] > d[u] + w){
                d[v] = d[u] + w;
                F.push(make_pair(d[v], v));
            }
        }
    }
    return 0;
}
int main(){
    freopen("input/data1.txt", "r", stdin);
    input();
    // cout << dijkstra();
    cout << dijkstra_PriorityQueue();
    return 0;
}