#include <math.h>

#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    std::string s_value;
    int count = 0;
    int count_2 = 1;
    int sum_space_count = 0;
    int space_count = 0;
    std::vector<int> space;
    std::vector<int> result;
    while (std::cin >> s_value) {
        count++;
        if (s_value == "null") {
            space_count += 1;
        } else {
            int value = std::stoi(s_value);
            result.push_back(value);
        }
        if (count == (int) std::pow(2, count_2) - 1 - sum_space_count) {
            if (result.size() != 0) {
                if (count_2 % 2 == 0) {
                    for (int i = result.size() - 1; i >= 0; i--) {
                        std::cout << result[i] << " ";
                    }

                } else {
                    for (int i = 0; i < result.size(); i++) {
                        std::cout << result[i] << " ";
                    }
                }
                std::cout << "\n";
            }
            result.clear();
            space.push_back(space_count);
            for (int i = 0; i < space.size(); i++) {
                sum_space_count += space[i] * pow(2, space.size() - i);
            }
            count_2++;
            space_count = 0;
        }
    }
    if (!result.empty()) {
        if (count_2 % 2 == 0) {
            for (int i = result.size() - 1; i >= 0; i--) std::cout << result[i] << " ";
        } else {
            for (int i = 0; i < result.size(); i++) std::cout << result[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
};