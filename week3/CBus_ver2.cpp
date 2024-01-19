#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n, k;
int route[2*N]; // hanh trinh dang di

int c[2*N][2*N];
bool visited[2*N]; // danh dau diem da di qua
int load = 0; // so khach tren xe
int cur = 0; // quang duong da di
int res = 100000;
int d_min = 1e9 + 7;

void input(){
	scanf("%d %d", &n, &k);
	for( int i = 0; i<=2*n; i++){
		for( int j = 0; j<=2*n ;j++){
			scanf("%d", &c[i][j]);
			if( c[i][j] != 0)
				d_min = min(d_min, c[i][j]);
		}
	}
}

void solution(){
//	for( int i = 0; i<= 2*n; i++){
//		cout << route[i] << " ";
//	}
//	cout << endl;
	res = min(res, cur + c[route[2*n]][0]);
}
bool check(int x, int i){
	if( visited[i] == true) return false;
	if( i <= n){// don khach len xe
		if( load < k) return true;
		else return false;
	}
	else{// tra khach xuong xe
		if( visited[i - n] == true ) return true;
		else return false;
	}
}

void Try(int x){
	for( int i = 1; i<= 2*n; i++){
		if( check(x, i) ){
			route[x] = i;
			
			cur += c[route[x -1]][i];
			visited[i] = true;
			if( i <= n) load += 1;
			else load -= 1;
			
			if( x == 2*n ) solution();
			else if( cur + (2*n + 1 - x)* d_min < res ) Try(x + 1);
			
			//recover
			cur -= c[route[x -1]][i];
			visited[i] = false;
			if( i <= n) load -= 1;
			else load += 1;
		}
	}
}
void solve(){
	Try(1);
}
int main(){
	freopen("input/data2.txt", "r", stdin);
	input();
	solve();
	cout << res;
	return 0;
}
