#include <iostream>
#include <cctype>
#include <string>
using namespace std;

enum UTYPE { head, data, sub_list };

template <typename T>
struct general_list_node {
    UTYPE utype;
    union {
        int ref;
        T value;
        general_list_node<T>* tlink;
    } info;
    general_list_node<T>* tlink;

    general_list_node() : utype(UTYPE::head), tlink(nullptr) { info.ref = 0; }

    general_list_node(general_list_node<T>& R) {
        utype = R.utype;
        tlink = R.tlink;
        info = R.info;
    }
};

template <typename T>
struct Items {
    UTYPE utype;
    union {
        int ref;
        T value;
        general_list_node<T>* tlink;
    } info;
    Items() : utype(UTYPE::head) { info.ref = 0; }
    Items(Items<T>& R) {
        utype = R.utype;
        info = R.info;
    }
};

template <typename T>
class general_list {
private:
    general_list_node<T>* head;

    general_list_node<T>* copy(general_list_node<T>* ls) {
        if (!ls) return nullptr;
        general_list_node<T>* q = new general_list_node<T>;
        q->utype = ls->utype;
        switch (ls->utype) {
            case UTYPE::head: q->info.ref = ls->info.ref; break;
            case UTYPE::data: q->info.value = ls->info.value; break;
            case UTYPE::sub_list: q->info.tlink = copy(ls->info.tlink); break;
        }
        q->tlink = copy(ls->tlink);
        return q;
    }

    int length(general_list_node<T>* ls)const{
        int len = 0;
        general_list_node<T>* p = ls->tlink;
        while (p) {
            ++len;
            p = p->tlink;
        }
        return len;
    }

    int depth(general_list_node<T>* ls)const{
        if (!ls || !ls->tlink) return 1;
        general_list_node<T>* temp = ls->tlink;
        int m = 0;
        while (temp) {
            if (temp->utype == UTYPE::sub_list) {
                int n = depth(temp->info.tlink);
                if (m < n) m = n;
            }
            temp = temp->tlink;
        }
        return m + 1;
    }

    bool equal(general_list_node<T>* s, general_list_node<T>* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        if (s->utype != t->utype) return false;
        switch (s->utype) {
            case UTYPE::data:
                if (s->info.value != t->info.value) return false;
                break;
            case UTYPE::sub_list:
                if (!equal(s->info.tlink, t->info.tlink)) return false;
                break;
            default: break;
        }
        return equal(s->tlink, t->tlink);
    }

    void remove(general_list_node<T>* ls) {
        if (!ls) return;
        ls->info.ref--;
        if (ls->info.ref <= 0) {
            general_list_node<T>* q;
            while (ls->tlink) {
                q = ls->tlink;
                if (q->utype == UTYPE::sub_list) {
                    remove(q->info.tlink);
                    if (q->info.tlink && q->info.tlink->info.ref <= 0)
                        delete q->info.tlink;
                }
                ls->tlink = q->tlink;
                delete q;
            }
        }
    }

    // 从输入流创建广义表
    void createlist(istream& in, general_list_node<T>* ls) {
        char ch;
        in >> ch;
        if (ch != '(') return;
        general_list_node<T>* p = nullptr;
        general_list_node<T>* q = nullptr;
        while (true) {
            in >> ws;
            ch = in.peek();
            if (ch == ')') { in.get(); break; }
            else if (ch == '(') {
                q = new general_list_node<T>;
                q->utype = UTYPE::sub_list;
                q->info.tlink = new general_list_node<T>;
                q->info.tlink->utype = UTYPE::head;
                q->info.tlink->info.ref = 1;
                q->info.tlink->tlink = nullptr;
                createlist(in, q->info.tlink);
            } else {
                T val;
                in >> val;
                q = new general_list_node<T>;
                q->utype = UTYPE::data;
                q->info.value = val;
            }
            q->tlink = nullptr;
            if (!ls->tlink)
                ls->tlink = p = q;
            else {
                p->tlink = q;
                p = q;
            }
            in >> ws;
            ch = in.peek();
            if (ch == ',') in.get();
        }
    }

    friend istream& operator>>(istream& in, general_list<T>& L) {
        L.remove(L.head);
        L.head = new general_list_node<T>;
        L.head->utype = UTYPE::head;
        L.head->tlink = nullptr;
        L.createlist(in, L.head);
        return in;
    }

public:
    general_list() { head = new general_list_node<T>; }

    ~general_list() { remove(head); }

    bool list_head(Items<T>& x) const {
        if (!head->tlink) return false;
        x.utype = head->tlink->utype;
        x.info = head->tlink->info;
        return true;
    }

    bool list_tail(general_list<T>& It) const {
        if (!head->tlink) return false;
        It.head->utype = UTYPE::head;
        It.head->info.ref = 0;
        It.head->tlink = copy(head->tlink->tlink);
        return true;
    }

    general_list_node<T>* first() const {
        return head->tlink;
    }

    general_list_node<T>* next(general_list_node<T>* elem) const {
        if (!elem) return nullptr;
        return elem->tlink;
    }

    void copy(const general_list<T>& R) {
        if (this == &R) return;
        remove(head);
        head = copy(R.head);
    }

    int length() const {
        return length(head);
    }

    int depth() const {
        return depth(head);
    }

    void delvalue(general_list_node<T>* ls, T x) {
        if (!ls || !ls->tlink) return;
        general_list_node<T>* p = ls->tlink;
        general_list_node<T>* prev = ls;
        while (p) {
            if (p->utype == UTYPE::data && p->info.value == x) {
                prev->tlink = p->tlink;
                delete p;
                p = prev->tlink;
            } else {
                if (p->utype == UTYPE::sub_list)
                    delvalue(p->info.tlink, x);
                prev = p;
                p = p->tlink;
            }
        }
    }
};

