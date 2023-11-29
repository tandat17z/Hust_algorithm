//CPP 
#include <bits/stdc++.h> 

using namespace std;

int tab[9][9];

int row[9][10];
int col[9][10];
int xxx[3][3][10];

int result;

void mark(int i, int u, int v){
    row[u][i] = 1;
    col[v][i] = 1;
    xxx[u/3][v/3][i] = 1;
}
void remark(int i, int u, int v){
    row[u][i] = 0;
    col[v][i] = 0;
    xxx[u/3][v/3][i] = 0;
}
void input(){
    for( int i = 0; i< 9; i++){
        for( int j = 0; j< 9 ;j++){
            cin >> tab[i][j];
            mark(tab[i][j], i, j);
        }
    }
}

bool check(int i, int u, int v){
    // check row + check col + check xxx
    if(row[u][i] == 0 && col[v][i] == 0 && xxx[u/3][v/3][i] == 0){
        return true;
    }
    return false;
}

void Try(int k){
    int u = k/9, v = k%9;
    if( tab[u][v] == 0 ){
        for( int i = 1; i< 10; i++){
            if( check(i, u, v) ){
                tab[u][v] = i;
                // cout << u << " " << v << " : " << i << endl;
                mark(i, u, v);
                if( k == 9*9 - 1) result += 1;
                else Try(k + 1);
                remark(i, u, v);
                tab[u][v] = 0;
            }
        }
    }
    else{
        if( k == 9*9 - 1) result += 1;
        else Try(k + 1);
    }
}
int main() 
{ 
    freopen("input.txt", "r", stdin);
    input();
    Try(0);
    cout << result;
    return 0;
}