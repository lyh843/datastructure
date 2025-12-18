#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class BTreeNode {
public:
    bool leaf;
    int m;  // 最大孩子数
    vector<int> keys;
    vector<BTreeNode*> children;

    BTreeNode(int _m, bool _leaf) : m(_m), leaf(_leaf) {}

    // 中序遍历
    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!leaf)
                children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!leaf)
            children[i]->traverse();
    }

    // 查找
    BTreeNode* search(int k) {
        int i = 0;
        while (i < keys.size() && k > keys[i])
            i++;

        if (i < keys.size() && keys[i] == k)
            return this;

        if (leaf)
            return nullptr;

        return children[i]->search(k);
    }

    // 非满节点插入
    void insertNonFull(int k) {
        int i = keys.size() - 1;

        if (leaf) {
            keys.push_back(0);
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
        } else {
            while (i >= 0 && keys[i] > k)
                i--;

            if (children[i + 1]->keys.size() == m - 1) {
                splitChild(i + 1);
                if (keys[i + 1] < k)
                    i++;
            }
            children[i + 1]->insertNonFull(k);
        }
    }

    // 分裂第 i 个孩子
    void splitChild(int i) {
        BTreeNode* y = children[i];
        BTreeNode* z = new BTreeNode(m, y->leaf);

        // 正确的中位数（关键修正点）
        int mid = m / 2;  // floor(m / 2)

        // 中位 key 上移
        keys.insert(keys.begin() + i, y->keys[mid]);

        // z 拿右半部分
        for (int j = mid + 1; j < y->keys.size(); j++)
            z->keys.push_back(y->keys[j]);

        // y 保留左半部分
        y->keys.resize(mid);

        // 子指针处理
        if (!y->leaf) {
            for (int j = mid + 1; j < y->children.size(); j++)
                z->children.push_back(y->children[j]);
            y->children.resize(mid + 1);
        }

        children.insert(children.begin() + i + 1, z);
    }

};

class BTree {
public:
    BTreeNode* root;
    int m;

    BTree(int _m) : m(_m), root(nullptr) {}

    void traverse() {
        if (root)
            root->traverse();
    }

    BTreeNode* search(int k) {
        return root ? root->search(k) : nullptr;
    }

    void insert(int k) {
        if (!root) {
            root = new BTreeNode(m, true);
            root->keys.push_back(k);
            return;
        }

        if (root->keys.size() == m - 1) {
            BTreeNode* s = new BTreeNode(m, false);
            s->children.push_back(root);
            s->splitChild(0);

            int i = (s->keys[0] < k) ? 1 : 0;
            s->children[i]->insertNonFull(k);

            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
};

int main() {
    BTree tree(3);  // m = 5 → key ∈ [ceil(5/2)-1=2, 4]

    int arr[] = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int x : arr)
        tree.insert(x);

    cout << "B-Tree traversal: ";
    tree.traverse();
    cout << endl;

    return 0;
}
