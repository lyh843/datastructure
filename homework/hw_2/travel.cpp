#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define NUMNODE 200010
#define NUMEDGE 2000100

unsigned long long num_node, num_edge;

struct Node {
    unsigned long long _id;
    unsigned long long _weight;
    unsigned long long _cost;
    Node(unsigned long long id, unsigned long long weight, unsigned long long cost)
        : _id(id), _weight(weight), _cost(cost) {}
};

struct cmp {
    bool operator()(const Node& a, const Node& b) const {
        if (a._cost == b._cost) return a._weight > b._weight;
        return a._cost < b._cost;
    }
};

std::priority_queue<Node, std::vector<Node>, cmp> map[NUMNODE];

int main() {
    std::cin >> num_node >> num_edge;
    unsigned long long* cost = new unsigned long long[NUMNODE];
    for (unsigned long long i = 1; i <= num_node; i++) {
        std::cin >> cost[i];
    }
    for (unsigned long long i = 1; i <= num_edge; i++) {
        unsigned long long a, b, w;
        std::cin >> a >> b >> w;
        if (cost[a] < cost[b]) {
            map[b].push(Node(a, w, cost[a]));
        } else if (cost[b] < cost[a]) {
            map[a].push(Node(b, w, cost[b]));
        } else {
            map[a].push(Node(b, w, cost[b]));
            map[b].push(Node(a, w, cost[a]));
        }
    }
    // 寻找最大连通变量
    bool* visited = new bool[NUMNODE];
    memset(visited, false, sizeof(bool) * NUMNODE);
    unsigned long long sum_cost = 0;
    unsigned long long count_node = 1;
    std::vector<unsigned long long> visited_node;
    visited_node.push_back(1);
    visited[1] = true;
    bool reach_all = false;
    while (!reach_all) {
        unsigned long long max_cost = 0, min_weight = ULLONG_MAX, min_node = 0, target_node = 0;
        reach_all = true;
        // 从所有访问过的节点
        for (unsigned long long i : visited_node) {
            while (map[i].size() != 0 && visited[map[i].top()._id]) {
                map[i].pop();
            }
            if (map[i].empty()) continue;
            // 费用小的直接pass
            if (map[i].top()._cost < max_cost) continue;
            // 如果费用相等，进一步比较权重
            if (max_cost == map[i].top()._cost) {
                if(min_weight > map[i].top()._weight){
                    min_node = map[i].top()._id;
                    min_weight = map[i].top()._weight;
                    reach_all = false;
                    target_node = i;
                }
            } else{
                min_node = map[i].top()._id;
                max_cost = map[i].top()._cost;
                min_weight = map[i].top()._weight;
                reach_all = false;
                target_node = i;
            }
        }
        if (reach_all) break;
        sum_cost += min_weight;
        visited[min_node] = true;
        visited_node.push_back(min_node);
        map[target_node].pop();
        count_node++;
    }
    std::cout << count_node << " " << sum_cost << "\n";
}