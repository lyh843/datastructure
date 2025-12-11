#include <sys/types.h>
#include<iostream>
#include <vector>

#define NUMEDGE 200005
#define NUMNODE 400005

struct Edge{
    int head1;
    int head2;
};

int num_node, num_edge, times;

struct Node{
    bool used;
    int index;
    Node():used(true), index(-1){};
};



std::vector<int> spe_node;
std::vector<int> map[NUMNODE];
Edge edge[NUMNODE];
Node tree[NUMNODE];
std::vector<int> result;
int parent(int x){
    if(tree[x].index < 0) return x;
    return tree[x].index = parent(tree[x].index);
}

int main(){
    std::cin >> num_node >> num_edge;
    for(int i = 1; i <= num_edge; i++){
        int a = 0, b = 0;
        std::cin >> a >> b;
        edge[i].head1 = a;
        edge[i].head2 = b;
    }
    std::cin >> times;
    for(int i = 1; i <= times; i++){
        int temp = 0;
        std::cin >> temp;
        tree[temp].used = false;
        spe_node.push_back(temp);
    }

    result.push_back(num_node - times);

    // 遍历edge，开始存边
    for(int i = 1; i <= num_edge; i++){
        int node1 = edge[i].head1, node2 = edge[i].head2;
        if(!tree[node1].used || !tree[node2].used) continue;
        int parent1 = parent(node1), parent2 = parent(node2);
        if(parent1 != parent2){
            tree[parent1].index += tree[parent2].index;
            tree[parent2].index = parent1;
            result[0]--;
        }
    }

    for(int i = 1; i <= num_edge; i++){
        int node1 = edge[i].head1, node2 = edge[i].head2;
        if(!tree[node1].used || !tree[node2].used){
            map[node1].push_back(node2);
            map[node2].push_back(node1);
        }
    }

    for(int i = 0; i < spe_node.size(); i++){
        result.push_back(result[i] + 1);
        int node = spe_node[spe_node.size() - i - 1];
        tree[node].used = true;
        for(auto j : map[node]){
            if(!tree[j].used) continue;
            int parent1 = parent(node), parent2 = parent(j);
            if(parent1 != parent2){
                tree[parent1].index += tree[parent2].index;
                tree[parent2].index = parent1;
                result[i + 1]--;
            }
        }
    }

    for(int i = result.size() - 1; i >= 0; i--){
        std::cout << result[i] << "\n";
    }
}