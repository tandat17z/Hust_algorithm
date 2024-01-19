//Cho dãy s? nguyên a. Dãy con c?a a là dãy thu du?c b?ng cách xóa di m?t s? ph?n t? c?a a (có th? không xóa
//ph?n t? nào, cung có th? xóa h?t t?t c?). M?t dãy con du?c g?i là d?p n?u ph?n t? d?ng sau l?n hon ph?n t?
//d?ng tru?c dúng m?t don v?.
//Yêu c?u: Hãy tìm dãy con d?p dài nh?t c?a dãy a.
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
int T, n;
int a[N];
int M[N]; // M[i]: do dai day con dep ket thuc tai i
void solve(){
	int res = 0;
	for( int i = 0; i<n; i++){
		M[a[i]] = max(M[a[i]], M[a[i] - 1] + 1);
		res = max(M[a[i]], res);
	}
	cout << res;
}
void input(){
	cin >> T;
	for( int _ = 0; _ < T; _ ++){
		cin >> n;
		for( int i = 0; i<n ; i++){
			cin >> a[i];
		}
		solve();
	}
}
int main(){
	freopen("input/data2.txt", "r", stdin);
	input();
	return 0;
}
