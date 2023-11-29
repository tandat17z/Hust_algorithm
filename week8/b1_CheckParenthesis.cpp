#include<bits/stdc++.h>

using namespace std;

bool check_parenthesis(string s){
    stack<char> st;
    for(auto c: s){
        if( c == '(' || c == '[' || c == '{')
            st.push(c);
        else if(st.empty()) return false;
        else if(st.top() == '{' && c == '}')
            st.pop();
        else if(st.top() == '[' && c == ']')
            st.pop();
        else if(st.top() == '(' && c == ')')
            st.pop();
        else return false;
    }
    return st.empty();
}
int main(){
    freopen("data1.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    cout << check_parenthesis(s);
    return 0;
}