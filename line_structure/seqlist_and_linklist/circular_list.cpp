#include <iostream>
#include <string>
#include "circular_list.hpp"   // 假设你的类定义在这个头文件里

using namespace std;

int main() {
    cout << "=== 测试 int 类型循环链表 ===" << endl;
    Circular_list<int> clist;

    // 插入元素
    clist.insert(10, 0);  // 在第0个后插入（即头结点后）
    clist.insert(20, 1);
    clist.insert(30, 2);
    clist.insert(40, 3);

    cout << "链表长度: " << clist.getlength() << endl;
    for(int i = 1; i <= clist.getlength(); i++) {
        cout << "第 " << i << " 个元素: " << clist.getdata(i) << endl;
    }

    // 更新第2个元素
    cout << "\n更新第2个元素为 99" << endl;
    clist.update(99, 2);

    for(int i = 1; i <= clist.getlength(); i++) {
        cout << "第 " << i << " 个元素: " << clist.getdata(i) << endl;
    }

    // 搜索元素
    int key = 30;
    auto node = clist.search(key);
    cout << "\n搜索元素 30: " << (node ? "找到" : "未找到") << endl;

    // 删除第3个元素
    cout << "\n删除第3个元素" << endl;
    clist.remove(3);
    for(int i = 1; i <= clist.getlength(); i++) {
        cout << "第 " << i << " 个元素: " << clist.getdata(i) << endl;
    }

    // 清空链表
    cout << "\n清空链表" << endl;
    clist.clear();
    cout << "链表是否为空: " << (clist.isEmpty() ? "是" : "否") << endl;

    // -----------------------------
    cout << "\n=== 测试 string 类型循环链表 ===" << endl;
    Circular_list<string> slist;
    slist.insert("apple", 0);
    slist.insert("banana", 1);
    slist.insert("cherry", 2);
    slist.insert("date", 3);

    cout << "链表长度: " << slist.getlength() << endl;
    for(int i = 1; i <= slist.getlength(); i++) {
        cout << "第 " << i << " 个元素: " << slist.getdata(i) << endl;
    }

    // 更新
    slist.update("blueberry", 2);
    cout << "\n更新第2个元素为 blueberry:" << endl;
    for(int i = 1; i <= slist.getlength(); i++) {
        cout << "第 " << i << " 个元素: " << slist.getdata(i) << endl;
    }

    // 搜索
    string fruit = "cherry";
    auto snode = slist.search(fruit);
    cout << "\n搜索 cherry: " << (snode ? "找到" : "未找到") << endl;

    // 删除
    slist.remove(1);
    cout << "\n删除第1个元素:" << endl;
    for(int i = 1; i <= slist.getlength(); i++) {
        cout << "第 " << i << " 个元素: " << slist.getdata(i) << endl;
    }

    return 0;
}
