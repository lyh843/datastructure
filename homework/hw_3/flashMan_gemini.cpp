#include<iostream>

int main(){
    int m, s, t;
    std::cin >> m >> s >> t;

    int energy_dist = 0;
    int total_dist = 0;
    for(int i = 1; i <= t; i++){
        if(m >= 10){
            energy_dist += 60;
            m -= 10;
        }else{
            m += 4;
        }

        total_dist = std::max(energy_dist, total_dist + 17);

        if(total_dist >= s){
            std::cout << "Yes\n" << i;
            return 0;
        }
    }
    std::cout << "No\n" << total_dist;
    return 0;
}