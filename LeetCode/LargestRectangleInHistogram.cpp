#include<bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& h) {
    int size = h.size();
    vector<int> R(size);
    vector<int> L(size);

    stack<int> st;
    for( int i = 0; i< size; i++){
        while( !st.empty() && h[i] < h[st.top()]){
            R[st.top()] = i;
            st.pop(); 
        }
        st.push(i);
    }
    while( !st.empty()){
        R[st.top()] = size;
        st.pop(); 
    }

    for( int i = size - 1; i >= 0; i--){
        while( !st.empty() && h[i] < h[st.top()]){
            L[st.top()] = i;
            st.pop(); 
        }
        st.push(i);
    }
    while( !st.empty()){
        L[st.top()] = -1;
        st.pop(); 
    }

    int maxarea = 0;
    for( int i = 0 ; i<size; i++){
        int height = R[i] - L[i] -1;
        // cout << h[i] << " " << R[i] << " " << L[i] << " : " << endl;
        maxarea = max(maxarea, h[i] * height);
    }
    return maxarea;
}

int main(){
    vector<int> h = {2,4};
    cout << largestRectangleArea(h);
}