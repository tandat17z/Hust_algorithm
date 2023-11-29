#include<bits/stdc++.h>
using namespace std;

int n, m;
int M[30][1000000];
int A[1000000];

void preprocessing(){
    for( int j = 1; (1<<j) <= n; j++){
        for( int i = 0; i + (1<<j) - 1 < n; i++)
            M[j][i] = ( A[ M[j-1][i] ] <= A[ M[j-1][i + (1<<(j-1))] ] ) ? M[j][i] = M[j-1][i]: M[j-1][i + (1<<(j-1))];
    }
}

int rmq(int i, int j){
    int k = log2(j-i+1);
    int p2k = (1<<k);
    return ( A[ M[k][i] ] <= A[ M[k][j + 1 - p2k]] ) ? M[k][i] : M[k][j - p2k + 1];
    
}

int main(){
    freopen("data1.txt", "r", stdin);
    scanf("%d", &n);
    for( int i = 0; i<n ; i++){
        scanf("%d", &A[i]);
        M[0][i] = i;
    }
    preprocessing();

    int Q = 0;
    int i, j;
    scanf("%d", &m);
    for( int k = 0; k<m ;k++){
        scanf("%d %d", &i, &j);
        Q += A[rmq(i, j)];
    }
    printf("%d", Q);
    return 0;
}