#include <cstdint>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int num = 0, width = 0;
    cin >> num >> width;
    vector<int> num_list;
    for(int i = 0; i < num; i++){
        int temp = 0;
        cin >> temp;
        num_list.push_back(temp);
    }
    queue<int> windows;
    vector<int> max;
    max.push_back(INT32_MIN);
    vector<int> min;
    min.push_back(INT32_MAX);
    for(int i = 0; i < width; i++){
        windows.push(num_list[i]);
        max[0] = max[0] > num_list[i] ? max[0] : num_list[i];
        min[0] = min[0] < num_list[i] ? min[0] : num_list[i];
    }
    for(int i = width - 1; i < num; i++){
        int before = windows.front();
        if(before == max[i - width + 1]){
            
        }
    }
}