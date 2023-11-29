#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("data.txt", "r", stdin);
    map<string, int> m;
    string s;
    while( cin >> s ){
        m[s] += 1;
    }
    for( map<string, int>::iterator p = m.begin(); p != m.end(); p++){
        cout << p->first << " " << p->second << endl;
    }
    return 0;
}