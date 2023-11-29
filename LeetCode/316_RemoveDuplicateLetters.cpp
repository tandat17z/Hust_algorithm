#include<bits/stdc++.h>

using namespace std;
string removeDuplicateLetters(string s){
    string result;
    for( int i = s.length()-1; i>= 0; i--){
        int x = result.find(s[i]);
        if( x < 0 && x >= result.length() ){
            result = s[i] + result;
        }
        else{
            if( s[i] < result[0]){
                result.erase(result.find(s[i]), 1);
                result = s[i] + result;
            }
        }
    }
    return result;
}

int main(){
    string s= "LeTanDat";
    // s.erase(s.find('a'), 1);
    // cout << s;
    cout << removeDuplicateLetters(s);
    return 0;
}