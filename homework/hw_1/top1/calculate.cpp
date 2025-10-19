#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<cmath>

using namespace std;

int main(){
    stack<char> optr;
    stack<int> opnd;
    string arr, infix;
    cin>>arr;

    map<char, int> value_in_stack, value_out_stack;
    value_in_stack['('] = 1;
    value_in_stack['*'] = 5;
    value_in_stack['/'] = 5;
    value_in_stack['+'] = 3;
    value_in_stack['-'] = 3;
    value_in_stack['^'] = 6;
    value_in_stack[')'] = 8;
    value_out_stack['('] = 8;
    value_out_stack['*'] = 4;
    value_out_stack['/'] = 4;
    value_out_stack['+'] = 2;
    value_out_stack['-'] = 2;
    value_out_stack['^'] = 7;
    value_out_stack[')'] = 1;

    for(char &c : arr){
        if(c >= '0' && c <= '9') infix.push_back(c);
        else{
            if(optr.empty()) optr.push(c);
            else{
                char top = optr.top();
                if(value_out_stack[c] > value_in_stack[top]) optr.push(c);
                else{
                    if(c == ')'){
                        while(top != '('){
                            infix.push_back(top);
                            optr.pop();
                            top = optr.top();
                        }
                        optr.pop();
                    } else{
                        while(value_out_stack[c] < value_in_stack[top]){
                            infix.push_back(top);
                            optr.pop();
                            if(optr.empty()) break;
                            top = optr.top();
                        }
                        optr.push(c);
                    }
                }
            }
        }
    }
    while(!optr.empty()) {
        char top = optr.top();
        infix.push_back(top);
        optr.pop();
    }
    for(char &c : infix) cout<<c<<" ";
    cout<<endl;

    int len = infix.length();
    for(int i = 0; i < len; ++i){
        char c = infix[i];
        if(c >= '0' && c <= '9') opnd.push(c - '0');
        else{
            int num1, num2;
            num1 = opnd.top();
            opnd.pop();
            num2 = opnd.top();
            opnd.pop();
            switch(c){
                case '+':
                    opnd.push(num1+num2);
                    break;
                case '-':
                    opnd.push(num2-num1);
                    break;
                case '*':
                    opnd.push(num1*num2);
                    break;
                case '/':
                    opnd.push(num2/num1);
                    break;
                case '^':
                    opnd.push((int)pow(num2, num1));
                    break;
            }
            stack<int> sub_dump;
            for(stack<int> dump = opnd; !dump.empty(); dump.pop()) sub_dump.push(dump.top());
            for(; !sub_dump.empty(); sub_dump.pop()) cout<<sub_dump.top()<<" ";
            for(int j = i + 1; j < len; ++j) cout<<infix[j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}