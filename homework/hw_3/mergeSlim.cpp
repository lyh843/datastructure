#include <climits>
#include <cstdio>
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
int dp[NUM][NUM];
int sum[NUM][NUM];
void solve(){
    for(int len = 2; len <= num; len++){
        for(int i = 1; i <= num; i++){
            int max = 0;
            for(int k = i; k < i + len - 1; k++){
                if(k > num) k = k % num;
                int result = 0;
                if((i + len - 1) > num) {
                    result = dp[i][k] + dp[k + 1][(i + len - 1) % num] + arr[i].head * arr[k].tail * arr[(i + len - 1) % num].tail;
                }
                else{
                    result = dp[i][k] + dp[k + 1][i + len - 1] + arr[i].head * arr[k].tail * arr[i + len - 1].tail;
                } 
                if(max < result){
                    max = result;
                }
            }
            dp[i][i + len - 1] = max;
        }
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

        dp[i][i] = 0;
    }
    solve();
    int max_result = dp[1][num];
    for(int i = 2; i <= num; i++){
        if(dp[i][i - 1] > max_result){
            max_result = dp[i][i - 1];
        }
    }
    printf("%d", max_result);
}