#include<iostream>

void f(int* a){
    a = new int(114514);
}
int main(){
    int *a = nullptr;
    f(a);
    std::cout << *a << "\n";
}