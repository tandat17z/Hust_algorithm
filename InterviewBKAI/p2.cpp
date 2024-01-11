#include<bits/stdc++.h>

using namespace std;

char code[200];

int main(){
    freopen("input/data2.txt", "r", stdin);

    for(char i = 'a'; i<='z'; i++){
        char c;
        scanf("%c", &c);
        code[c] = i;
    }
    char x;
    getchar();
    while( (x = getchar())){
        if (int(x) == -1) break;
        if(code[x] != 0) cout << code[x];
        else cout << x;
    }
}