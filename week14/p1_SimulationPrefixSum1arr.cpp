#include <bits/stdc++.h>
using namespace std;

#define N 1000000

int n, Q;
int a[N];
int M[N];
void input(){
	scanf("%d",&n);
	int sum = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		M[i] = M[i-1] + a[i];
	}
	scanf("%d",&Q);
	for(int i = 1; i <= Q; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		cout << M[v] - M[u-1] << endl;
	}
}

int main(){
	freopen("input/data1.txt","r",stdin);
	input();
	return 0;
}
