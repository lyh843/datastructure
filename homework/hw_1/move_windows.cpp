#include<iostream>
#include<vector>
#include<deque>
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
    deque<int> q_max;
    deque<int> q_min;
    vector<int> v_max;
    vector<int> v_min;
    for(int i = 0; i < num; i++){
        while(!q_max.empty() && num_list[q_max.back()] <= num_list[i]){
            q_max.pop_back();
        }
        q_max.push_back(i);
        if(q_max.front() == i - width){
            q_max.pop_front();
        }

        while(!q_min.empty() && num_list[q_min.back()] >= num_list[i]){
            q_min.pop_back();
        }
        q_min.push_back(i);
        if(q_min.front() == i -width){
            q_min.pop_front();
        }

        if(i + 1 >= width){
            v_max.push_back(num_list[q_max.front()]);
            v_min.push_back(num_list[q_min.front()]);
        }
    }

    for(int i = 0; i < v_min.size(); i++){
        cout << v_min[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < v_max.size(); i++){
        cout << v_max[i] << " ";
    }
    cout << "\n";
    
}