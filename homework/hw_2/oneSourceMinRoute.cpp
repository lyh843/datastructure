#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

#define MAXNODE 10004
#define MAXEDGE 500005

struct Node{
    int weight;
    int tail;
    Node(int tail, int weight):weight(weight), tail(tail){}
};

int dist[MAXNODE];
bool S[MAXNODE];
int count;
int main(){
    const int MAXWEIGHT = INT_MAX;
    std::vector<Node> map[MAXNODE];
    int num_node, num_edge, target;
    std::cin >> num_node >> num_edge >> target;
    for(int i = 1; i <= num_node; i++){
        dist[i] = MAXWEIGHT;
    }
    dist[target] = 0;
    memset(S, false, sizeof(S));
    S[target] = true;
    for(int i = 1; i <= num_edge; i++){
        int a, b; int w;
        std::cin >> a >> b >> w;
        map[a].push_back(Node(b, w));
        if(a == target){
            dist[b] = std::min(dist[b], w);
        }
    }
    while(true){
        int new_node = -1, min_dist = MAXWEIGHT;
        for(int i = 1; i <= num_node; i++){
            if(S[i] == false && dist[i] < min_dist){
                new_node = i;
                min_dist = dist[i];
            }
        }
        if(new_node == -1) break;
        S[new_node] = true;
        for(auto node : map[new_node]){
            if(!S[node.tail]){
                dist[node.tail] = std::min(dist[node.tail], dist[new_node] + node.weight);
            }
        }
    }
    for(int i = 1; i <= num_node; i++){
        if(dist[i] == MAXWEIGHT){
            std::cout << "NA ";
        }
        else{
            std::cout << dist[i] << " ";
        }
    }
}