#include <bits/stdc++.h>
using namespace std;
#define N 10001

vector<int> T[N];// T[i] list cac dinh (ben phai, staff) ke voi i
int match[N]; // match[i] la dinh matched voi dinh i (i: ben phai)
int p[N];// p[j] dinh cha cua j (j: ben phai)
int q[N];// q[i] dinh cha cua i (i: ben trai)
int rMatch[N]; // rMatch[j] la dinh matched voi j (j: ben trai)
int n,m;
void input(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		int k; scanf("%d",&k);
		for(int j = 1; j <= k; j++){
			int u; scanf("%d",&u);
			T[i].push_back(u);
		}
	}
}
int findPath(int u){
	//cout << "findPath(" << u << ")" << endl;
	for(int i = 1; i <= n;i++) q[i] = -1; // not visited
	for(int j = 1; j <= m; j++) p[j] = -1;
	queue<int> Q;
	for(int v: T[u]){
			Q.push(v);p[v] = u;
		//cout << "init push " << v << endl;
	}
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		//cout << "findPath(" << u << ") pop " << v << " match[" << v << " = " << match[v] << endl;
		if(match[v] == -1) return v;
		int mv = match[v];
		for(int x: T[mv]) if(p[x] == -1){
			Q.push(x); p[x] = mv;
			//cout << "findPath(" << u << ") from " << v << ", mv = " << mv << " push x " << endl;
		}
	}
	return -1;// not fonud augmenting path
}
void solve(){
	for(int j = 1; j <= m; j++) match[j] = -1;
	for(int i = 1; i <= n; i++) rMatch[i] = -1;
	int res = 0;
	int cnt = 0;
	while(true){
		//cnt++; if(cnt > 100) break;
		bool foundPath = false;
		for(int u = 1; u <= n; u++) if(rMatch[u] == -1){
			int v = findPath(u);
			if(v != -1){// found augmenting path
				//cout << "found path from " << u << " to " << v << " p[" << u << "] = " << p[u] << endl;
				int x = v;
				//int cnt = 0;
				while(p[x] != u){
						//cnt++; if(cnt > 10) break;
					int px = p[x];
					int nx = rMatch[px];
					match[x] = px;
					rMatch[px] = x;
					x = nx;

				}
				match[x] = p[x];
				rMatch[p[x]] = x;
				//cout << "match " << x << " and " << p[x] << endl;

				res += 1;
				foundPath = true;
				break;
			}else{
				//break;
			}
		}
		if(!foundPath) break;
	}
	cout << res;
}
int main(){
	freopen("input/data1.txt","r",stdin);
	input();
	solve();
	return 0;
}
