#include<iostream>

int m, s, t;

int bfs(int distance, int time, int energy){
    if(distance <= 0) return - time - 1;
    if(time == 0) return distance;

    int result = bfs(distance - 17, time - 1, energy);
    if(energy >= 10){
        int temp = bfs(distance - 60, time - 1, energy - 10);
        result = std::min(result, temp);
    }
    result = std::min(result, bfs(distance, time - 1, energy + 4));

    return result;
}

int main(){
    std::cin >> m >> s >> t;
    int result = bfs(s, t, m);
    if(result < 0){
        std::cout << "Yes\n" << t - (-result - 1);
    }
    else{
        std::cout << "No\n" << s - result;
    }
}