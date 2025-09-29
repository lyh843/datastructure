#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode () : val (0), next (nullptr) {}
    ListNode (int x) : val (x), next (nullptr) {}
    ListNode (int x, ListNode *next) : val (x), next (next) {}
};

class Solution {
public:
    ListNode* reverseBetween (ListNode* dumpy, int left, int right) {
        // TODO
        ListNode* l_prev = dumpy;
        ListNode* l_ptr = dumpy->next;
        ListNode* r_ptr = dumpy->next;
        for(int i = 1; i < left; i++){
            l_ptr = l_ptr->next;
            l_prev = l_prev->next;
            r_ptr = r_ptr->next;
        }
        for(int i = left; i < right; i++){
            r_ptr = r_ptr->next;
        }
        l_prev->next = r_ptr;
        ListNode* curr = l_ptr->next;
        ListNode* prev = l_ptr;
        l_ptr->next = r_ptr->next;
        while(prev != r_ptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return dumpy->next;
    }
};

ListNode* stringToListNode (const string& str){
    stringstream ss (str);
    string item;
    ListNode* dummy = new ListNode ();
    ListNode* current = dummy;
    while (ss >> item) {
        current->next = new ListNode (stoi (item));
        current = current->next;
    }
    return dummy->next;
}

int main(){
    string a;
    getline(cin, a);
    ListNode* dumpy = new ListNode();
    dumpy->next = stringToListNode(a);
    int left, right;
    cin >> left >> right;
    Solution s;
    s.reverseBetween(dumpy, left, right);
    ListNode* curr = dumpy->next;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    } 
}