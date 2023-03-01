#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    int n;
    cin >> n;

    for(int i = 0;i<n;i++){

        string s;
        cin >> s;
        stack<char> st;
        bool isVPS = true;
        for(int i =0;i<s.length();i++){
            if(!isVPS) break;
            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else isVPS = false;
            }
            else isVPS = false;
        }
        if(!st.empty()) isVPS = false;
        
        if(isVPS) cout << "YES" << endl;
        else cout << "NO" <<endl;

    }
}