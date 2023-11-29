#include<bits/stdc++.h>

using namespace std;

int n;
int arr[21][21];
int d[21];
bool visited[21];
int cur, cmin = 1e9;
int min_ = 1e9;

void input(){
	cin >> n;
	for( int i = 0; i< n; i++){
		for( int j = 0; j< n; j++){
			int x;
			cin >> x;
			arr[i][j] = x;
			if( i != j && cmin > x) cmin = x;
		}
	}
}
bool check(int i, int k){
	if( visited[i] ) return false;
	return true;
}

void solution(){
	if( cur + arr[d[n-1]][0] < min_ ) min_ = cur + arr[d[n-1]][0];
}
void Try(int k){
	for( int i = 1; i < n; i++){
		if(check(i, k)){
			d[k] = i;
			visited[i] = 1;
			cur += arr[d[k-1]][i];
			if( k == n-1) solution();
			else if( cur + cmin*(n - k) < min_) Try(k + 1);
			visited[i] = 0;
			cur -= arr[d[k-1]][i];
		}
	}	
}
int main(){
	input();
	Try(1);
	cout << min_;
	return 0;
}