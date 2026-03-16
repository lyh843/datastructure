#include<iostream>

int main(){
    int m, s, t;
    std::cin >> m >> s >> t;
    bool found = false;
    int dist = s, energy = m, time = t;
    bool reached = false;

    // 先把能量用完
    while(energy >= 10 && dist > 0 && time > 0){
        dist -= 60;
        energy -= 10;
        time--;
    }

    if(dist <= 0){
        std::cout << "Yes\n" << t - time << "\n";
        return 0;
    }

    // 剩余距离大于 120 的话，用能量跑到120以内
    while(dist > 120 && time > 0){
        if(energy >= 10){
            energy -= 10;
            dist -= 60;
        }
        else energy += 4;
        time--;
    }


}