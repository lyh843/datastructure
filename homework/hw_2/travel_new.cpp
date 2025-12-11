#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#define NUMNODE 100005
#define NUMEDGE 1000006

int num_node, num_edge;

struct Node{
    int _id;
    unsigned int _weight;
    Node(int id, unsigned int weight):_id(id), _weight(weight){}
};

struct cmp{
    bool operator()(const Node &a, const Node &b) const{
        return a._weight > b._weight;
    }    
};

std::priority_queue<Node, std::vector<Node>, cmp> map[NUMNODE];

int main(){
    std::cin >> num_node >> num_edge;
    unsigned int* cost = new unsigned int[NUMNODE];
    for(int i = 1; i <= num_node; i++){
        std::cin >> cost[i];
    }
    for(int i = 1; i <= num_edge; i++){
        int a, b, w;
        std::cin >> a >> b >> w;
        if(cost[a] < cost[b]){
            map[b].push(Node(a, w));
        }
        else if(cost[b] < cost[a]){
            map[a].push(Node(b, w));
        }
        else{
            map[a].push(Node(b, w));
            map[b].push(Node(a, w));
        }
    }
    delete []cost;
    // 寻找最大连通变量
    bool* visited = new bool[NUMNODE];
    memset(visited, false, sizeof(bool) * NUMNODE);
    unsigned int sum_cost = 0;
    unsigned int count_node = 1;
    std::vector<int> visited_node;
    visited_node.push_back(1);
    visited[1] = true;
    bool reach_all = false;
    while(!reach_all){
        unsigned int min_weight = UINT32_MAX, min_node = 0, target_node = 0;
        reach_all = true;
        for(int i : visited_node){
            while(map[i].size() != 0 && visited[map[i].top()._id]){
                map[i].pop();
            }
            if(map[i].empty()) continue;
            if(min_weight > map[i].top()._weight){
                min_node = map[i].top()._id;
                min_weight = map[i].top()._weight;
                reach_all = false;
                target_node = i;
            }
        }
        if(reach_all) break;
        sum_cost += min_weight;
        visited[min_node] = true;
        visited_node.push_back(min_node);
        map[target_node].pop();
        count_node++;
    }
    std::cout << count_node << " " << sum_cost;
}