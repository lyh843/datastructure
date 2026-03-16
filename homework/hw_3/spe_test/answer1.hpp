#include <bits/stdc++.h>
using namespace std;

int answer1(int n, int p, int q, int* a){
    multiset<int, greater<int>> st1; 
    multiset<int> st2;
    int ans = a[q] - a[p];

    int minn = 2e9;
    for (int i = p; i <= q; i++) {
        minn = min(minn, a[i]);
        st1.insert(a[i]);
        if (i == q) continue;
        ans = max(ans, a[q] - minn);
    }
    ans = max(ans, *st1.begin() - minn);

    int windowMax = *st1.begin();
    for (int i = q + 1; i <= n; i++) {
        minn = min(minn, a[i]);
        if (a[i] < windowMax) {
            st1.insert(a[i]);
            st1.erase(st1.begin()); 
            windowMax = *st1.begin();
        }
        ans = max(ans, windowMax - minn);
    }

    int maxn = 0;
    for (int i = q; i >= p; i--) {
        maxn = max(maxn, a[i]);
        st2.insert(a[i]);
        if (i == p) continue;
        ans = max(ans, maxn - a[p]);
    }
    int windowMin = *st2.begin();
    ans = max(ans, maxn - windowMin);

    for (int i = p - 1; i >= 1; i--) {
        maxn = max(maxn, a[i]);
        if (a[i] > windowMin) {
            st2.insert(a[i]);
            st2.erase(st2.begin()); 
            windowMin = *st2.begin();
        }
        ans = max(ans, maxn - windowMin);
    }

    return ans;
}