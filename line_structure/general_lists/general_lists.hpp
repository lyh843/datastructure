#include <istream>
enum UTYPE{head, data, sub_list};

template <typename T>
// 广义表结点类定义
struct general_list_node{
    UTYPE utype;
    union{
        int ref;
        T value;
        general_list_node<T> *tlink;
    }info;

    general_list_node<T>* tlink;
    general_list_node():utype(head), tlink(nullptr){    // 默认构造函数
        info.ref = 0;
    }
    general_list_node(general_list_node<T>& R){     // 拷贝构造函数
        utype = R.utype;
        tlink = R.tlink;
        info = R.info;
    }
};

template <typename T>
// 返回值的类结构定义
struct Items{
    UTYPE utype;
    union{
        int ref; // 存放引用数
        T value; // 存放数值
        general_list_node<T> *tlink; //存放指向子表的指针
    }info;
    Items():utype(UTYPE::head){
        info.ref = 0;
    }
    Items(Items<T>& R){
        utype = R.utype;
        info = R.info;
    }
};

template<typename T>
class general_list{
private:
    general_list_node<T>* head;
    general_list_node<T>* copy(general_list_node<T>* ls);
    int length(general_list_node<T>* ls);
    int depth(general_list_node<T>* ls);
    bool equal(general_list_node<T> *s, general_list_node<T>* t);
    void remove(general_list_node<T>* ls);
    void createlist(std::istream& in, general_list_node<T>* ls);
    friend std::istream& operator >> (std::istream& in, general_list<T>& L);
public:
    general_list();
    ~general_list();
    bool list_head(Items<T>& x) const;  // x返回表头元素
    bool list_tail(general_list<T>& It) const;  // It返回表尾
    general_list_node<T>* first() const;    // 返回第一个元素
    general_list_node<T>* next(general_list_node<T>* elem) const;   //返回表元素elem的直接后继元素
    void copy(const general_list<T>& R);    // 广义表的复制
    int length() const; // 计算广义表长度
    int depth() const;  // 计算非递归表深度
};