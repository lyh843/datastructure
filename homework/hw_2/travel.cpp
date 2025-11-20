#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

#define MAXNODE 100005
#define MAXEDGE 1000006

struct Node{
    int weight;
    int tail;
    Node(int tail, int weight):weight(weight), tail(tail){}
};
long long cost[MAXNODE];
long long dist[MAXNODE][MAXNODE];
bool path[MAXNODE][MAXNODE];
int main(){
    int num_node, num_edge;
    std::vector<Node> map[MAXNODE];
    std::cin >> num_node >> num_edge;
    for(int i = 1; i <= num_node; i++){
        std::cin >> cost[i];
    }
    memset(path, false, sizeof(path));
    memset(dist, LONG_LONG_MAX, sizeof(dist));
    for(int i = 1; i <= num_node; i++){
        dist[i][i] = 0;
    }
    for(int i = 1; i <= num_edge; i++){
        int a, b;
        long long node_dist;
        std::cin >> a >> b >> node_dist;
        if(cost[a] < cost[b]){
            map[b].push_back(Node(a, node_dist));
            dist[b][a] = std::min(dist[b][a], node_dist);
        }
        else if(cost[b] < cost[a]){
            map[a].push_back(Node(b, node_dist));
            dist[a][b] = std::min(dist[a][b], node_dist);
        }
        else{
            map[a].push_back(Node(b, node_dist));
            map[b].push_back(Node(a, node_dist));
            dist[a][b] = std::min(dist[a][b], node_dist);
            dist[b][a] = std::min(dist[b][a], node_dist);
        }
    }
    for(int i = 1; i <= num_node; i++){
        for(int j = 1; j <= num_node; j++){
            if(i != j && dist[i][j] != LONG_LONG_MAX){
                path[i][j] = i;
            }
            else{
                path[i][j] = 0;
            }
        }
    }

    for(int k = 1; k <= num_node; k++){
        for(int i = 1; i <= num_node; i++){
            for(int j = 1; j <= num_node; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = true;
                }
            }
        }
    }
}