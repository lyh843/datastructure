#include<iostream>

class TreeNode{
private:
    int value;
    bool is_null;
    TreeNode* left_child, *right_child;
public:
    TreeNode(int value = 0, TreeNode* left_child = nullptr, TreeNode* right_child = nullptr, bool is_null = false)
        :value(value), left_child(left_child), right_child(right_child){}
    int get_value(){return value;}
    TreeNode* get_left_child(){return left_child;}
    TreeNode* get_right_child(){return right_child;}
    bool null(){return is_null;}
};

int main(){
    TreeNode *root;
    TreeNode *curr;
    std::string s_value;
    while(std::cin >> s_value){
        if(s_value != "null"){

        }
    }
}
