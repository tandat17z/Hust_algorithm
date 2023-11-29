#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > d;

int main(){
    freopen("data3.txt", "r", stdin);
    string cmd;
    int e;
    while(true){
        cin >> cmd;
        if( cmd == "PUSH"){
            scanf("%d", &e);
            d.push(e);
        }
        else if( cmd == "POP"){
            printf("%d\n", d.top() );
            d.pop();
        }
        else if( cmd == "#") break;
    }
    return 0;
}
