#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

TreeNode *builtTree(vector<string> &nodes) {
    if (nodes.empty() || nodes[0] == "null") {
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode *parent = q.front();
        q.pop();
        if (nodes[i] != "null") {
            TreeNode *newNode = new TreeNode(stoi(nodes[i]));
            parent->left = newNode;
            q.push(newNode);
        }
        i++;
        if (nodes[i] != "null" && i < nodes.size()) {
            TreeNode *newNode = new TreeNode(stoi(nodes[i]));
            parent->right = newNode;
            q.push(newNode);
        }
        i++;
    }
    return root;
}


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    // TODO
    vector<vector<int> > ans;
    stack<TreeNode *> s1, s2;
    if (root == nullptr) {
        return ans;
    }
    vector<int> first_level;
    first_level.push_back(root->val);
    ans.push_back(first_level);
    s1.push(root);
    while (!s1.empty()) {
        vector<int> cur_level;
        while (!s1.empty()) {
            TreeNode *cur = s1.top();
            s1.pop();
            if (cur->right) {
                cur_level.push_back(cur->right->val);
                s2.push(cur->right);
            }
            if (cur->left) {
                cur_level.push_back(cur->left->val);
                s2.push(cur->left);
            }
        }
        if (!cur_level.empty())ans.push_back(cur_level);
        cur_level.clear();
        while (!s2.empty()) {
            TreeNode *cur = s2.top();
            s2.pop();
            if (cur->left) {
                cur_level.push_back(cur->left->val);
                s1.push(cur->left);
            }
            if (cur->right) {
                cur_level.push_back(cur->right->val);
                s1.push(cur->right);
            }
        }
        if (!cur_level.empty())ans.push_back(cur_level);
    }
    return ans;
}

int main() {
    vector<string> nodes;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    while (ss >> token) {
        nodes.push_back(token);
    }
    TreeNode *root = builtTree(nodes);
    vector<vector<int> > ans;
    ans = zigzagLevelOrder(root);
    if (!ans.empty()) {
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
