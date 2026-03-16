#include <cstdlib>
#include<iostream>

#define N 200005

int cmp(const void* a, const void *b){
    int* new_a = (int*) a;
    int* new_b = (int*) b;
    return *new_a - *new_b;
}

int arr[N];
int new_arr[N];
int origin_p, origin_q;
int main(){
    int n, p, q;
    std::cin >> n >> p >> q;
    for(int i = 1; i <= n; i++){
        std::cin >> arr[i];
    }
    int result = 0;
    for(int i = 1; i <= n; i++){
        new_arr[i] = arr[i];
    }
    std::qsort(&new_arr[p], q - p + 1, sizeof(int), cmp);
    origin_p = new_arr[p];
    origin_q = new_arr[q];
    result = std::max(new_arr[q] - new_arr[p], result);
    for(int i = 1; i <= n; i++){
        new_arr[i] = arr[i];
    }
    std::qsort(&new_arr[1], n, sizeof(int), cmp);
    origin_p = new_arr[p];
    origin_q = new_arr[q];
    result = std::max(new_arr[q] - new_arr[p], result);
    for(int l = p; l >= 1; l--){
        if(arr[l] <= origin_q) break;
        for(int i = 1; i <= n; i++){
            new_arr[i] = arr[i];
        }
        std::qsort(&new_arr[l], q - l + 1, sizeof(int), cmp);
        result = std::max(new_arr[q] - new_arr[p], result);
    }
    for(int r = n; r >= q; r--){
        if(arr[r] >= origin_p) break;
        for(int i = 1; i <= n; i++){
            new_arr[i] = arr[i];
        }
        std::qsort(&new_arr[p], r - p + 1, sizeof(int), cmp);
        result = std::max(new_arr[q] - new_arr[p], result);
    }
    
    std::cout << result << std::endl;
    return 0;
}