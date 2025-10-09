#include <cstring>
#include <iostream>
class AString{
private:
    char* ch;
    int len;
    int maxsize;
public:
    AString(int size = 10){
        maxsize = size - 1;
        len = 0;
        ch = new char[maxsize];
    }
    AString(const char *init){
        len = strlen(init);
        ch = new char[len + 1];
        strcpy(ch, init);
        maxsize = len;
    }
    AString(const AString& ob){
        len = ob.len;
        ch = new char[len + 1];
        strcpy(ch, ob.ch);
        maxsize = ob.maxsize;
    }
    ~AString(){
        delete []ch;
    }
    int length()const{
        return len;
    }
    AString operator()(int pos, int sub_len){   // 
        if(pos >= 0 && pos < len - 1 && sub_len > 0){
            if(pos + sub_len > len){
                sub_len = len - pos; // 调整提取字符数
            }
            AString newstring(sub_len + 1);
            for(int i = 0; i < sub_len; i++){
                newstring.ch[i] = ch[pos + i];
                newstring.len++;
            }
            newstring.ch[sub_len] = '\0';
            return newstring;
        }
        else{
            AString newstring(1);
            newstring.ch[0] = '\0';
            return newstring;
        }
    }
    bool operator == (AString& ob) const{
        return strcmp(ch, ob.ch) == 0;
    }
    bool operator != (AString& ob) const{
        return strcmp(ch, ob.ch) != 0;
    }
    bool operator ! ()const{
        return len==0;
    }
    AString& operator = (AString& ob){
        if(ob != *this){
            delete []ch;
            ch = new char[ob.maxsize + 1];
            len = ob.len;
            strcpy(ch, ob.ch);
        }
        return *this;
    }
    AString& operator += (AString& ob){
        char* new_ch = new char[(len + ob.len + 1 > maxsize) ? (len + ob.len + 1) : maxsize];
        strcpy(new_ch, ch);
        strcat(new_ch, ob.ch);
        len += ob.len;
        delete []ch;
        ch = new_ch;
        return *this;
    }
    char& operator [] (int i){
        if(i >= 0 && i < len){
            return ch[i];
        }
        exit(-1);
    }
    int find(AString& pat, int k) const{
    }
    int fast_find(AString& pat, int k, int next[]) const{
        int pos_P = 0, pos_T = k;
        int len_P = pat.len;
        int len_T = len;
        while(pos_P < len_P && pos_T < len_T){
            if(pos_P == -1 || pat.ch[pos_P] == ch[pos_T]){
                pos_P++;
                pos_T++;
            }
            else{
                pos_P = next[pos_P];
            }
        }
        if(pos_P < len_P) return -1;
        else return pos_T - len_P;
    }
    void getnext(int next[]) const{
        int j = 0, k = -1, len_p = len;
        next[0] = -1;
        while(j < len_p){
            if(k == -1 || ch[k] == ch[j]){
                k++;
                j++;
                next[j] = k;
            }
            else{
                k = next[k];
            }
        }
    }
    void print() const{
        for(int i = 0; i < len; i++){
            std::cout << ch[i];
        }
        std::cout <<"\n";
    }
};