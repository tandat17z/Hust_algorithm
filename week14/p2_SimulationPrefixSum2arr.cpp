#include <bits/stdc++.h>
using namespace std;

#define N 1001

int n, m, Q;
int a[N][N];
int M[N][N];
int r1, r2, c1, c2;

void input(){
	scanf("%d %d",&n, &m);
	int sum = 0;
	for(int i = 1; i <= n; i++){
        for( int j = 1; j<=m ; j++){
            scanf("%d", &a[i][j]);
            M[i][j] = M[i][j-1] + M[i-1][j] - M[i-1][j-1] + a[i][j];
        }
	}
	scanf("%d",&Q);    
	for(int i = 1; i <= Q; i++){
		cin >> r1 >> c1 >> r2 >> c2;
        // cout << M[r2][c2] << endl;
		cout << M[r2][c2] - M[r1-1][c2] - M[r2][c1 - 1] + M[r1-1][c1-1] << endl;
	}
}

int main(){
	freopen("input/data2.txt","r",stdin);
	input();
	return 0;
}
