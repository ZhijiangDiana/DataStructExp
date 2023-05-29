#include "iostream"
#include "string"
#include "LStack.h"
using namespace std;

int main(){
    LStack<char> stack;
    cout<<"Input the expression string ended with '#':"<<endl;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        char c=s.at(i);
        if(c=='('){
            stack.push(c);
        }else if(c==')'){
            if(!stack.isEmpty()){
                stack.pop();
            }else{
                cout<<"Unmatched"<<endl;
                exit(0);
            }
        }
    }
    if(stack.isEmpty()){
        cout<<"Matched"<<endl;
    }else{
        cout<<"Unmatched"<<endl;
    }
}