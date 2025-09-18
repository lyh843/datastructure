#include <cstdlib>
#include<iostream>
#include <ostream>
#include <vector>

std::vector<int> result;

void push_back(int num){
    if(num < 0 && result.size() != 0 && result[result.size() - 1] > 0){
        bool boom = false;
        while(!boom && (result[result.size() - 1] > 0)){
            if(result[result.size() - 1] < std::abs(num)){
                result.pop_back();
                if(result.size() == 0) result.push_back(num);
            }
            else if(result[result.size() - 1] == std::abs(num)){
                result.pop_back();
                boom = true;
            }
            else{
                boom = true;
            }
        }
    }
    else{
        result.push_back(num);
    }
}

void print(){
    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int num = 0;
    std::cin >> num;
    for(int i = 0; i < num; i++){
        int temp = 0;
        std::cin >> temp;
        push_back(temp);
    }
    print();
    return 0;
}