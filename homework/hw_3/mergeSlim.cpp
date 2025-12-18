#include<iostream>

#define NUM 100

struct Node{
    int head;
    int tail;
    Node(int head = 0, int tail = 0):head(head), tail(tail){} 
};

Node arr[NUM];

struct dpNode{
    long long value;
    int k;
};

int num = 0;
int dp[NUM][NUM][NUM];

void solve(){
    for(int len = 2; len <= num; len++){

    }
}

int main(){
    std::cin >> num;
    for(int i = 1; i <= num; i++){
        int temp = 0;
        std::cin >> temp;
        arr[i].head = temp;
        if(i == 1) arr[num].tail = temp;
        else arr[i - 1].tail = temp;
    }
    solve();
}