#include <iostream>
#include "string.hpp"
// 假设 AString 类定义在这里...

int main() {
    std::cout << "=== AString 类综合测试 ===\n\n";
    
    // 测试1: 默认构造函数
    std::cout << "测试1: 默认构造函数\n";
    AString s1;
    std::cout << "s1: ";
    s1.print();
    std::cout << "s1长度: " << s1.length() << std::endl;
    std::cout << "!s1: " << (!s1 ? "true" : "false") << std::endl;
    std::cout << std::endl;
    
    // 测试2: C字符串构造函数
    std::cout << "测试2: C字符串构造函数\n";
    AString s2("Hello");
    AString s3("World");
    std::cout << "s2: ";
    s2.print();
    std::cout << "s3: ";
    s3.print();
    std::cout << "s2长度: " << s2.length() << std::endl;
    std::cout << "s3长度: " << s3.length() << std::endl;
    std::cout << std::endl;
    
    // 测试3: 拷贝构造函数
    std::cout << "测试3: 拷贝构造函数\n";
    AString s4(s2);
    std::cout << "s4(拷贝s2): ";
    s4.print();
    std::cout << "s2 == s4: " << (s2 == s4 ? "true" : "false") << std::endl;
    std::cout << "s2 != s4: " << (s2 != s4 ? "true" : "false") << std::endl;
    std::cout << std::endl;
    
    // 测试4: 赋值运算符
    std::cout << "测试4: 赋值运算符\n";
    AString s5;
    s5 = s3;
    std::cout << "s5(赋值s3): ";
    s5.print();
    std::cout << "s3 == s5: " << (s3 == s5 ? "true" : "false") << std::endl;
    std::cout << std::endl;
    
    // 测试5: 自赋值测试
    std::cout << "测试5: 自赋值测试\n";
    s2 = s2;
    std::cout << "s2自赋值后: ";
    s2.print();
    std::cout << std::endl;
    
    // 测试6: 字符串连接
    std::cout << "测试6: 字符串连接\n";
    AString s6("Hello");
    AString s7(" World!");
    s6 += s7;
    std::cout << "s6 += s7: ";
    s6.print();
    std::cout << "连接后长度: " << s6.length() << std::endl;
    std::cout << std::endl;
    
    // 测试7: 多重连接
    std::cout << "测试7: 多重连接\n";
    AString s8("Start");
    AString s9(" Middle");
    AString s10(" End");
    s8 += s9;
    s8 += s10;
    std::cout << "多重连接结果: ";
    s8.print();
    std::cout << std::endl;
    
    // 测试8: 下标运算符
    std::cout << "测试8: 下标运算符\n";
    AString s11("ABCDEFG");
    std::cout << "s11: ";
    s11.print();
    std::cout << "s11[0]: '" << s11[0] << "'" << std::endl;
    std::cout << "s11[3]: '" << s11[3] << "'" << std::endl;
    
    // 修改通过下标访问的字符
    s11[1] = 'X';
    std::cout << "修改s11[1]='X'后: ";
    s11.print();
    std::cout << std::endl;
    
    // 测试9: 提取子串运算符
    std::cout << "测试9: 提取子串运算符\n";
    AString s12("Hello World");
    std::cout << "s12: ";
    s12.print();
    
    AString sub1 = s12(0, 5);
    std::cout << "s12(0,5): ";
    sub1.print();
    
    AString sub2 = s12(6, 5);
    std::cout << "s12(6,5): ";
    sub2.print();
    
    AString sub3 = s12(3, 20);  // 超过边界
    std::cout << "s12(3,20): ";
    sub3.print();
    
    AString sub4 = s12(20, 5);  // 无效位置
    std::cout << "s12(20,5): ";
    sub4.print();
    
    AString sub5 = s12(0, 0);   // 长度为0
    std::cout << "s12(0,0): ";
    sub5.print();
    std::cout << std::endl;
    
    // 测试10: 逻辑非运算符
    std::cout << "测试10: 逻辑非运算符\n";
    AString empty;
    AString nonEmpty("Test");
    std::cout << "!empty: " << (!empty ? "true" : "false") << std::endl;
    std::cout << "!nonEmpty: " << (!nonEmpty ? "true" : "false") << std::endl;
    std::cout << std::endl;
    
    // 测试11: 比较运算符
    std::cout << "测试11: 比较运算符\n";
    AString a("Apple");
    AString b("Apple");
    AString c("Banana");
    
    std::cout << "a: "; a.print();
    std::cout << "b: "; b.print();
    std::cout << "c: "; c.print();
    
    std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
    std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
    std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
    std::cout << "a != c: " << (a != c ? "true" : "false") << std::endl;
    std::cout << std::endl;
    
    // 测试12: 复杂组合操作
    std::cout << "测试12: 复杂组合操作\n";
    AString base("Programming");
    AString part1 = base(0, 3);  // "Pro"
    AString part2 = base(3, 4);  // "gram"
    AString result = part1;
    result += part2;
    std::cout << "base: "; base.print();
    std::cout << "part1: "; part1.print();
    std::cout << "part2: "; part2.print();
    std::cout << "组合结果: "; result.print();
    
    // 修改组合后的字符串
    result[0] = 'B';
    result[1] = 'r';
    std::cout << "修改后结果: "; result.print();

    std::cout << "=== KMP算法测试 ===\n\n";
    
    // 测试1: 基本模式匹配
    std::cout << "测试1: 基本模式匹配\n";
    AString text1("ABABABABC");
    AString pattern1("ABABC");
    int next1[pattern1.length()];  // 长度等于模式串长度
    
    pattern1.getnext(next1);
    std::cout << "模式串: "; pattern1.print();
    std::cout << "模式串长度: " << pattern1.length() << std::endl;
    std::cout << "next数组: ";
    for(int i = 0; i < pattern1.length(); i++) {
        std::cout << next1[i] << " ";
    }
    std::cout << std::endl;
    
    int result1 = text1.fast_find(pattern1, 0, next1);
    std::cout << "文本串: "; text1.print();
    std::cout << "查找结果位置: " << result1 << std::endl;
    std::cout << std::endl;
    
    // 测试2: 从指定位置开始查找
    std::cout << "测试2: 从指定位置开始查找\n";
    AString text2("ABCABCDABABCDABCDABDE");
    AString pattern2("ABCDABD");
    int next2[pattern2.length()];
    
    pattern2.getnext(next2);
    std::cout << "模式串: "; pattern2.print();
    std::cout << "模式串长度: " << pattern2.length() << std::endl;
    std::cout << "next数组: ";
    for(int i = 0; i < pattern2.length(); i++) {
        std::cout << next2[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "文本串: "; text2.print();
    int result2 = text2.fast_find(pattern2, 0, next2);
    std::cout << "从位置0查找结果: " << result2 << std::endl;
    
    int result3 = text2.fast_find(pattern2, 5, next2);
    std::cout << "从位置5查找结果: " << result3 << std::endl;
    std::cout << std::endl;
    
    // 测试3: 重复模式测试
    std::cout << "测试3: 重复模式测试\n";
    AString text3("AAAAAABAAAAAAC");
    AString pattern3("AAAAAC");
    int next3[pattern3.length()];
    
    pattern3.getnext(next3);
    std::cout << "模式串: "; pattern3.print();
    std::cout << "模式串长度: " << pattern3.length() << std::endl;
    std::cout << "next数组: ";
    for(int i = 0; i < pattern3.length(); i++) {
        std::cout << next3[i] << " ";
    }
    std::cout << std::endl;
    
    int result4 = text3.fast_find(pattern3, 0, next3);
    std::cout << "文本串: "; text3.print();
    std::cout << "查找结果位置: " << result4 << std::endl;
    std::cout << std::endl;
    
    // 测试4: 找不到模式的情况
    std::cout << "测试4: 找不到模式的情况\n";
    AString text4("ABCDEFGHIJK");
    AString pattern4("XYZ");
    int next4[pattern4.length()];
    
    pattern4.getnext(next4);
    std::cout << "模式串: "; pattern4.print();
    std::cout << "模式串长度: " << pattern4.length() << std::endl;
    std::cout << "next数组: ";
    for(int i = 0; i < pattern4.length(); i++) {
        std::cout << next4[i] << " ";
    }
    std::cout << std::endl;
    
    int result5 = text4.fast_find(pattern4, 0, next4);
    std::cout << "文本串: "; text4.print();
    std::cout << "查找结果位置: " << result5 << " (未找到)" << std::endl;
    std::cout << std::endl;
    
    // 测试5: 空模式串测试
    std::cout << "测试5: 空模式串测试\n";
    AString text5("Hello World");
    AString pattern5("");
    
    // 空模式串的特殊处理
    if(pattern5.length() > 0) {
        int next5[pattern5.length()];
        pattern5.getnext(next5);
        std::cout << "模式串: "; pattern5.print();
        std::cout << "next数组: 空" << std::endl;
    } else {
        std::cout << "模式串: 空" << std::endl;
        std::cout << "next数组: 空" << std::endl;
    }
    
    // 对于空模式串，需要特殊处理next数组
    int dummy_next[1] = {-1};
    int result6 = text5.fast_find(pattern5, 0, dummy_next);
    std::cout << "文本串: "; text5.print();
    std::cout << "空模式查找结果位置: " << result6 << std::endl;
    std::cout << std::endl;
    
    // 测试6: 边界情况测试
    std::cout << "测试6: 边界情况测试\n";
    AString text6("ABC");
    AString pattern6("ABC");
    int next6[pattern6.length()];
    
    pattern6.getnext(next6);
    std::cout << "模式串: "; pattern6.print();
    std::cout << "模式串长度: " << pattern6.length() << std::endl;
    std::cout << "next数组: ";
    for(int i = 0; i < pattern6.length(); i++) {
        std::cout << next6[i] << " ";
    }
    std::cout << std::endl;
    
    int result7 = text6.fast_find(pattern6, 0, next6);
    std::cout << "文本串: "; text6.print();
    std::cout << "完全相同字符串查找结果: " << result7 << std::endl;
    
    // 在边界位置查找
    int result8 = text6.fast_find(pattern6, 3, next6);
    std::cout << "从位置3查找结果: " << result8 << " (越界)" << std::endl;
    std::cout << std::endl;
    
    // 测试7: 验证next数组计算的正确性
    std::cout << "测试7: next数组计算验证\n";
    AString testPattern("ABABAC");
    int testNext[testPattern.length()];
    
    testPattern.getnext(testNext);
    std::cout << "测试模式串: "; testPattern.print();
    std::cout << "期望next数组: -1 0 0 1 2 3" << std::endl;
    std::cout << "实际next数组: ";
    for(int i = 0; i < testPattern.length(); i++) {
        std::cout << testNext[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}