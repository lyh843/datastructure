#include <climits>
#include <cstdio>
#include <iostream>
#define NUM 10

int stone[NUM];
int dp[NUM][NUM];
int sum[NUM];
int num = 0;
void solve(){
    for(int len = 2; len <= num; len++){
        for(int i = 1; i <= num - len + 1; i++){
            dp[i][i + len - 1] = INT_MAX;
            for(int k = i; k <= i + len - 1; k++){
                int min = dp[i][k] + dp[k + 1][i + len - 1] + sum[i + len - 1] - sum[i - 1];
                if(min < dp[i][i + len - 1]){
                    dp[i][i + len - 1] = min;
                }
            }
        }
    }
}

int main(){
    std::cin >> num;
    for(int i = 1; i <= num; i++){
        std::cin >> stone[i];
        dp[i][i] = 0;
    }
    for(int i = 1; i <= num; i++){
        sum[i] = sum[i - 1] + stone[i];
    }
    solve();
    printf("%d", dp[1][num]);
}