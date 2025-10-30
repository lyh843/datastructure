#include "general_lists.hpp"
int main() {
    general_list<char> L;
    cout << "输入广义表 (如: (a,(b,c),d)): ";
    cin >> L;
    cout << "深度: " << L.depth() << endl;
    cout << "长度: " << L.length() << endl;
    return 0;
}
