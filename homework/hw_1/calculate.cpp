#include <cctype>
#include<iostream>
#include <string>
#include<vector>
#include<deque>
#include<cmath>
using namespace std;

deque<int> v_opnd;
vector<char> v_optr;
vector<char> v_behind;
vector<int> fin_result;

int get_mid_optr_inside(char a){
    if(a == '=') return 0;
    else if(a == '+') return 3;
    else if(a == '-') return 3;
    else if(a == '*') return 5;
    else if(a == '/') return 5;
    else if(a == '(') return 1;
    else if(a == ')') return 9;
    else if(a == '^') return 6;
    else cout << "wrong2\n";
    return -100;
}
int get_mid_optr_outside(char a){
    if(a == '=') return 0;
    else if(a == '+') return 3;
    else if(a == '-') return 3;
    else if(a == '*') return 4;
    else if(a == '/') return 4;
    else if(a == '(') return 8;
    else if(a == ')') return 1;
    else if(a == '^') return 7;
    else cout << "wrong3\n";
    return -100;
}
int calculate(int a, int b, int optr){
    if(optr == '+') return a + b;
    else if(optr == '-') return a - b;
    else if(optr == '*') return a * b;
    else if(optr == '/') return a / b;
    else if(optr == '^') return pow(a, b);
    else cout << "wrong4\n";
    return -100;
}

void make_behind_eq(string infix){
    infix = '('+ infix + ")=";
    v_optr.push_back('=');
    for(int i = 0; i < infix.size(); i++){
        if(isdigit(infix[i])){
            v_opnd.push_back(infix[i] - '0');
            v_behind.push_back(infix[i]);
        }
        else if(infix[i] == ')'){
            int optr = v_optr[v_optr.size() - 1];
            if(optr == '(') continue;
            v_behind.push_back(optr);
            v_optr.pop_back();
            while(optr != '('){
                int b = v_opnd[v_opnd.size() - 1];
                v_opnd.pop_back();
                int a = v_opnd[v_opnd.size() - 1];
                v_opnd.pop_back();
                int result = calculate(a, b, optr);
                v_opnd.push_back(result);
                optr = v_optr[v_optr.size() - 1];
                if (optr != '('){
                    v_behind.push_back(optr);
                }
                v_optr.pop_back();
            }
        }
        else if(infix[i] == '='){ // 这里得到的是一个有限集绝对递增的数列
            // cout << "result is " << v_opnd[v_opnd.size() - 1] << "\n";
            return;
        }
        else{
            if(!v_optr.empty()){
                while(get_mid_optr_outside(infix[i]) <= get_mid_optr_inside(v_optr[v_optr.size() - 1])){
                    int optr = v_optr[v_optr.size() - 1];
                    v_behind.push_back(optr);
                    v_optr.pop_back();
                    int b = v_opnd[v_opnd.size() - 1];
                    v_opnd.pop_back();
                    int a = v_opnd[v_opnd.size() - 1];
                    v_opnd.pop_back();
                    int result = calculate(a, b, optr);
                    v_opnd.push_back(result);
                }
                v_optr.push_back(infix[i]);                    
            }
        }
    }
}

void print_behind(){
    for(int i = 0; i < v_behind.size(); i++){
        cout << v_behind[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < v_behind.size(); i++){
        if(isdigit(v_behind[i])){
            fin_result.push_back(v_behind[i] - '0');
        }
        else{
            int b = fin_result[fin_result.size() - 1];
            fin_result.pop_back();
            int a = fin_result[fin_result.size() - 1];
            fin_result.pop_back();
            int result = calculate(a, b, v_behind[i]);
            fin_result.push_back(result);
            for(int j = 0; j < fin_result.size(); j++){
                cout << fin_result[j] << " ";
            }
            for(int j = i + 1; j < v_behind.size(); j++){
                cout << v_behind[j] << " ";
            }
            cout << "\n";
        }
    }
}
int main(){
    string infix;
    getline(cin, infix);
    make_behind_eq(infix);
    print_behind();
    return 0;
}