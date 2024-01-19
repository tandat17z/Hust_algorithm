#include<bits/stdc++.h>

using namespace std;

const int N = 1e6;
int T;
int n, m;
int a[N];
int b[N];

void solve(){
	int res = 0;
	sort( a, a+n);
	sort( b, b+m);
	int i = 0, j = 0;
	
	while( i < n && j < m){
		if( a[i] == b[j] ) {
			i += 1;
			j += 1;
			res += 1;
		}
		else{
			if( a[i] < b[j]) i += 1;
			else j += 1;
		}
	}
	cout << res << endl;
}

void input(){
	cin >> T;
	for( int _ = 0; _<T; _++){
		cin >> n;
		for( int i = 0; i<n ;i++){
			cin >> a[i];
		}
		cin >> m;
		for( int i = 0; i<m ;i++){
			cin >> b[i];
		}
		solve();	
	}
}


int main(){
	freopen("input/data1.txt", "r", stdin);
	input();
	return 0;
}
