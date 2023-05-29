#include "iostream"
#include "string"
#include "LStack.h"
using namespace std;

LStack<int> num;
LStack<char> ope;

void calculate(char op){
    int b=num.pop();
    int a=num.pop();
    switch (op) {
        case '+':
            num.push(a+b);
            break;
        case '-':
            num.push(a-b);
            break;
        case '*':
            num.push(a*b);
            break;
        case '/':
            num.push(a/b);
            break;
    }
}

int main(){
    cout<<"Input the expression string ended with '#':"<<endl;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        char c=s.at(i);
        if('0'<=c&&c<='9'){
            LStack<int> oneNum;
            for(;i<s.length()&&'0'<=s.at(i)&&s.at(i)<='9';i++){
                oneNum.push(s.at(i)-'0');
            }
            i--;
            int number=0;
            for(int j=1;!oneNum.isEmpty();j*=10){
                number+=j*oneNum.pop();
            }
            num.push(number);
        }else if(c=='('){
            ope.push(c);
        }else if(c==')'){
            for(char op=ope.peek();op!='(';op=ope.peek()){
                calculate(ope.pop());
            }
            ope.pop();
        }else{
            if(c=='+'||c=='-'){
                try{
                    for(char op=ope.peek();op!='(';op=ope.peek()){
                        calculate(ope.pop());
                    }
                } catch (...){}
                ope.push(c);
            }else if(c=='*'||c=='/'){
                try{
                    for(char op=ope.peek();(op=='*'||op=='/');op=ope.peek()){
                        calculate(ope.pop());
                    }
                }catch (...){}
                ope.push(c);
            }
        }
    }
    while(!ope.isEmpty()){
        calculate(ope.pop());
    }
    cout<<num.pop()<<endl;
}