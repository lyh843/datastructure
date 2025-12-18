#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

std::vector<std::string> node;

TreeNode* makeTree(){
    if(node[0] == "null"){
        return nullptr;
    }
    TreeNode* root = new TreeNode(std::stoi(node[0]));
    std::queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty() && i < node.size()){
        TreeNode* curr = que.front();
        que.pop();
        if(node[i] != "null"){
            curr->left = new TreeNode(std::stoi(node[i]));
            que.push(curr->left);
        }
        i++;
        if(i < node.size() && node[i] != "null"){
            curr->right = new TreeNode(std::stoi(node[i]));
            que.push(curr->right);
        }
        i++;
    }
    return root;
}
std::vector<std::vector<int>> zigzaglevelOrder(TreeNode* root){
    std::stack<TreeNode*> s1, s2;
    std::vector<std::vector<int>> result;
    std::vector<int> levelAns;
    if(root == nullptr){
        return result;
    }
    if(root->left) s2.push(root->left);
    if(root->right) s2.push(root->right);
    levelAns.push_back(root->val);
    result.push_back(levelAns);
    while(!s2.empty()){
        levelAns.clear();
        while(!s2.empty()){
            levelAns.push_back(s2.top()->val);
            if(s2.top()->right) s1.push(s2.top()->right);
            if(s2.top()->left) s1.push(s2.top()->left);
            s2.pop();
        }
        result.push_back(levelAns);
        levelAns.clear();
        while(!s1.empty()){
            levelAns.push_back(s1.top()->val);
            if(s1.top()->left) s2.push(s1.top()->left);
            if(s1.top()->right) s2.push(s1.top()->right);
            s1.pop();
        }
        result.push_back(levelAns);
    }
    return result;
}

int main(){
    std::string temp;
    while(std::cin >> temp){
        node.push_back(temp);
    }
    TreeNode* root = makeTree();
    std::vector<std::vector<int>> result = zigzaglevelOrder(root);
    for(std::vector<int> level_result : result){
        for(int i : level_result){
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}