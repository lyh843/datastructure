#include <climits>
#include <cstdio>
#include<iostream>

#define NUM 105

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
long long dp[NUM][NUM];
void solve(){
    for(int len = 2; len <= num; len++){
        for(int i = 1; i <= num; i++){
            long long max = 0;
            for(int k = i; k < i + len - 1; k++){
                int new_k = k;
                if(new_k > num) new_k = new_k % num;
                int result = 0;
                if((i + len - 1) > num) {
                    if(new_k == num){
                        result = dp[i][new_k] + dp[1][(i + len - 1) % num] + arr[i].head * arr[new_k].tail * arr[(i + len - 1) % num].tail;
                    }
                    else{
                        result = dp[i][new_k] + dp[new_k + 1][(i + len - 1) % num] + arr[i].head * arr[new_k].tail * arr[(i + len - 1) % num].tail;
                    }
                }    
                else{
                    if(new_k == num) result = dp[i][new_k] + dp[1][i + len - 1] + arr[i].head * arr[new_k].tail * arr[i + len - 1].tail;
                    else result = dp[i][new_k] + dp[new_k + 1][i + len - 1] + arr[i].head * arr[new_k].tail * arr[i + len - 1].tail;
                } 
                if(max < result){
                    max = result;
                }
            }
            if((i + len - 1) > num) dp[i][(i + len - 1) % num] = max;
            else dp[i][i + len - 1] = max; 
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
    long long max_result = dp[1][num];
    for(int i = 2; i <= num; i++){
        if(dp[i][i - 1] > max_result){
            max_result = dp[i][i - 1];
        }
    }
    std::cout << max_result << "\n";
}