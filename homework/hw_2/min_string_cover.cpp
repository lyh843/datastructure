#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

int num_word = 0, len_string = 0;
int len = INT32_MAX, max_num = 0;

std::unordered_set<std::string> word;
std::map<std::string, int> word_last_index;

std::string string_list[100005];

// 判断目标单词是否在单词表里
bool exist_in_word(std::string target){
    return word.find(target) != word.end();
}

void refresh(int loc){
    int count = 0;
    int min_loc = loc;
    std::unordered_set<std::string> visited;
    for(int i = loc - 1; i >= 1 && count < max_num; i--){
        if(exist_in_word(string_list[i]) && visited.find(string_list[i]) == visited.end()){ // 如果这个元素没有访问过
            visited.insert(string_list[i]);
            count++;
            // 更新这个单词的下标
            word_last_index[string_list[i]] = i;
            min_loc = i;
        }
    }
    word_last_index[string_list[loc]] = loc;
    max_num += 1;
    len = loc - min_loc + 1;
    return ;
}

void check(int loc){
    int min_loc = loc;
    for(auto x : word_last_index){
        if(x.first == string_list[loc]) continue;
        if(x.second < min_loc){
            min_loc = x.second;
        }
    }
    word_last_index[string_list[loc]] = loc;
    if(loc - min_loc + 1 <= len){
        len = loc - min_loc + 1;
    }
}

int main(){
    std::cin >> num_word;
    for(int i = 1; i <= num_word; i++){
        std::string temp;
        std::cin >> temp;
        word.insert(temp);
    }
    std::cin >> len_string;
    for(int i = 1; i <= len_string; i++){
        std::cin >> string_list[i];
        if(word_last_index.find(string_list[i]) != word_last_index.end()){    // 这个字符串之前已经遇到过了
            check(i);
        }
        else if(exist_in_word(string_list[i])){   // 这个单词第一次见 
            refresh(i);
        }
    }
    std::cout << max_num << "\n" << (len == INT32_MAX ? 0 : len) << "\n";
    return 0;
}