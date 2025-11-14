#include <iostream>
#include <vector>
#include <cmath>


int main(){
    std::string s_value;
    int count = 0;
    int count_2 = 1;
    int sum_space_count = 0;
    int space_count = 0;
    std::vector<int> result;
    while(std::cin >> s_value){
        count++;
        if(s_value == "null"){
            space_count += 1;
            continue;
        }
        int value =std::stoi(s_value);
        result.push_back(value);
        if(count == (int)std::pow(2, count_2) - 1 - sum_space_count){
            if(count_2 % 2 == 0){
                for(int i = result.size() - 1; i >= 0; i--){
                    std::cout << result[i] << " ";
                }
                std::cout << "\n";
            }
            else{
                for(int i = 0; i < result.size(); i++){
                    std::cout << result[i] << " ";
                }
                std::cout << "\n";
            }
            result.clear();
            sum_space_count = (sum_space_count + space_count) * 2;
            count_2++;
            space_count = 0;
        }
    }
    if(!result.empty()){
        if(count_2 % 2 == 0){
            for(int i = result.size() - 1; i >= 0; i--){
                std::cout << result[i] << " ";
            }
            std::cout << "\n";
        }
        else{
            for(int i = 0; i < result.size(); i++){
                std::cout << result[i] << " ";
            }
            std::cout << "\n";
        }
    }
    return 0;
};