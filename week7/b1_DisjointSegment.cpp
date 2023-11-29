#include<bits/stdc++.h>
using namespace std;

typedef struct Edge{
    int a;
    int b;

    Edge(int x, int y){
        a = x;
        b = y;
    }
}Edge;

bool compare_(const Edge& s1, const Edge& s2){
    return s1.b < s2.b;
}
int n;
vector<Edge> m;

void input(){
    scanf("%d", &n);
    for( int i = 0; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        m.push_back(Edge(x, y));
    }
}

int main(){
    freopen("data1.txt", "r", stdin);
    input();
    sort(m.begin(), m.end(), compare_);
    int end = 0;
    int res = 0;
    for( auto node: m){
        if( node.a > end){
            res += 1;
            end = node.b;
        }
    }
    printf("%d", res);
    return 0;
}