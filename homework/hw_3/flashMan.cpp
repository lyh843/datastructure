#include <algorithm>
#include <cstdint>
#include<iostream>

#define T 300005
#define M 1003

// #define T 30
// #define M 100

int dp[T][M];
int m, s, t;

int solve(){
    for(int i = t; i >= 1; i--){
        for(int j = 20 > m ? 20 : m; j >= 0; j--){
            if(dp[i][j] == INT32_MAX) continue;
            else{
                dp[i - 1][j] = dp[i][j] - 17;
                if(dp[i - 1][j] <= 0){
                    return i - 1;
                }
                if(j < 10) dp[i - 1][j + 4] = dp[i][j];
                if(j >= 10){
                    dp[i - 1][j - 10] = dp[i][j] - 60;
                    if(dp[i - 1][j - 10] <= 0){
                        return i - 1;
                    }
                } 
            }
        }
    }
    return -1;
}

int main(){
    std::cin >> m >> s >> t;
    for(int i = 0; i < T; i++){
        for(int j = 0; j < M; j++){
            dp[i][j] = INT32_MAX;
        }
    }
    dp[t][m] = s;

    int result = solve();

    if(result != -1){
        std::cout << "Yes\n" << t - result;
    }
    else{
        std::cout << "No\n";
        int min = INT32_MAX;
        for(int i = 0; i < M; i++){
            if(dp[0][i] < min){
                min = dp[0][i];
            }
        }
        std::cout << s - min;
    }
}