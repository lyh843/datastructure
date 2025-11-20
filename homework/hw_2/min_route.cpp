#include<iostream>
#include <vector>

#define N 10004

struct Node{
    int start;
    int dest;
    long long weight;
    Node(int start = 0, int dest = 0, long long weight = 0):start(start), dest(dest), weight(weight){}
};

std::vector<Node> node_list;
std::vector<long long> target_route;

int num_dots, num_edges, target_point;

int main(){
    std::cin >> num_dots >> num_edges >> target_point;
    for(int i = 1; i <= num_edges; i++){
        int a = 0, b = 0;
        long long w = 0;
        std::cin >> a >> b >> w;
        Node temp(a, b, w);
        node_list.push_back(temp);
    }
}