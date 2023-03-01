#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void){
    bool isFinish = false;
    while(true){
        bool flag = true;
        bool isVPS = true;
        bool isNew = true;
        stack<char> s;
        string str;
        getline(cin , str);

        for(int i = 0;i<str.length();i++){
            if(!isVPS) break;
            if( str[i] == '.'){
                if(isNew) return 0;
                break;
            }
            if(str[i] == '(' || str[i] == '['){
                s.push(str[i]);
            }
            if(str[i]==')'){
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }
                else{
                    isVPS = false;
                }
            }
            if(str[i]==']'){
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }
                else{
                    isVPS = false;
                }
            }
            isNew = false;
        }
        if(!s.empty()) isVPS = false;
        if(isVPS) cout << "yes"<<endl;
        else cout << "no" << endl;

    }
}