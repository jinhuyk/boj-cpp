#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    int n;
    cin >> n;

    stack<int> st;
    for(int i =0;i<n;i++){
        string s;
        
        cin >> s;
        if(s == "push"){
            int num;
            cin >> num;
            st.push(num);
        } 
        else if (s == "pop")
        {   
            if(!st.empty()) {
                cout << st.top()<<endl;
                st.pop();
            }
            else cout << "-1"<<endl;
            
        }
        else if (s == "size"){
            if(!st.empty()) cout << st.size() << endl;
            else cout << "0"<<endl;
        }
        else if (s == "empty"){
            if(st.empty()) cout << "1"<<endl;
            else cout << "0"<<endl;
        }
        else if (s == "top"){
            if(!st.empty()) cout << st.top()<<endl;
            else cout << "-1"<<endl;
        }
    }
}