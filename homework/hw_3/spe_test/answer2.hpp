#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int answer2(int n, int p, int q, int* arr){
    int res=-1;
    vector<int> arr_pq1;
    vector<int> arr_pq2;
    int base_min=INT_MAX;
    int base_max=INT_MIN;
    for(int i=p;i<=q;i++) {
        arr_pq1.push_back(arr[i]);
        arr_pq2.push_back(arr[i]);
        if(arr[i]<base_min) base_min=arr[i];
        if(arr[i]>base_max) base_max=arr[i];
    }
    res=base_max-base_min;
    for(int j=q+1;j<=n;j++) {
        arr_pq1.push_back(arr[j]);
        if(arr[j]<base_min) {
            sort(arr_pq1.begin(), arr_pq1.end());
            base_min=arr_pq1[0];
            int ans=arr_pq1[q-p]-arr_pq1[0];
            if(ans>res) res=ans;
        }
    }
    for(int j=p-1;j>=1;j--) {
        arr_pq2.push_back(arr[j]);
        if(arr[j]>base_max) {
            sort(arr_pq2.begin(), arr_pq2.end());
            base_max=arr_pq2[arr_pq2.size()-1];
            int ans=arr_pq2[arr_pq2.size()-1]-arr_pq2[arr_pq2.size()-(q-p+1)];
            if(ans>res) res=ans;
           
        }
    }
    return res;
}