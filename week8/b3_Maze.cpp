#include<bits/stdc++.h>
using namespace std;

int n, m, r, c;
int A[1000][1000];
bool visited[1000][1000];

struct Node{
    int r, c;
    int step;
    Node(int row, int col, int s){
        r = row;
        c = col;
        step = s;
    }
};

void input(){
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for(int i = 1; i <= n; i++){
        for( int j = 1; j <= m; j++){
            scanf("%d", &A[i][j]);
        }
    }
}

vector<Node> neighborhood(Node x){
    vector<Node> child;
    int plus_r[] = {1, -1, 0, 0};
    int plus_c[] = {0, 0, 1, -1};
    for( int i = 0; i<4 ; i++){
        int a = x.r + plus_r[i];
        int b = x.c + plus_c[i];
        if( a > 0 && a <= n && b > 0 && b <=m  && A[a][b] == 0)
            child.push_back(Node(a, b, x.step + 1));
    }
    return child;
}

int BFS(){
    deque<Node> dq;
    dq.push_back(Node(r, c, 0));
    while( !dq.empty() ){
        Node x = dq.front(); dq.pop_front();
        for(auto i : neighborhood(x)){
            if( visited[i.r][i.c] == false){
                if(i.r == 1 || i.c == 1 || i.r == n || i.c == m)
                    return i.step + 1;
                visited[i.r][i.c] = true;
                dq.push_back(i);
            }
        }
    }
    return -1;
}
int main(){
    freopen("data3.txt", "r", stdin);
    input();
    cout << BFS();
    return 0;
}