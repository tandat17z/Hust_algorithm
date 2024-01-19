//Cho d�y s? nguy�n a. D�y con c?a a l� d�y thu du?c b?ng c�ch x�a di m?t s? ph?n t? c?a a (c� th? kh�ng x�a
//ph?n t? n�o, cung c� th? x�a h?t t?t c?). M?t d�y con du?c g?i l� d?p n?u ph?n t? d?ng sau l?n hon ph?n t?
//d?ng tru?c d�ng m?t don v?.
//Y�u c?u: H�y t�m d�y con d?p d�i nh?t c?a d�y a.
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
