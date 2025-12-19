struct datalist{
    int x;
    int len;
    bool operator <=(datalist& other){
        return x <= other.x;
    }
    int length(){return len;}
};

// l1 里是初始乱序的数据，l2放排好序后的数据，[left, mid]是第一段，[mid + 1, right]是第二段
void merge(datalist* l1, datalist* l2, const int left, const int mid, const int right){
    int k, i, j;
    i = left; j = mid + 1; k = left;
    while(i <= mid && j <= right){
        if(l1[i] <= l1[j]){
            l2[k++] = l1[i++];
        }
        else{
            l2[k++] = l1[j++];
        }
    }
    while(i <= mid) l2[k++] = l1[i++];
    while(j <= right) l2[k++] = l1[j++];
}
// 数据一开始只存储在 l1 中，l2为空，len 为当前每个小段的长度
void mergePass(datalist* l1, datalist* l2, const int len){
    // i 是 l1 的指针
    int i = 0, j, n = l1->length();
    // 对每两个相邻的 len 进行 merge
    while(i + 2 * len <= n - 1){
        merge(l1, l2, i, i + len - 1, i + 2 * len - 1);
        i += 2 * len;
    }
    if(i + len <= n - 1){
        merge(l1, l2, i, i + len - 1, n - 1);
    }
    else{
        for (j = i; j <= n - 1; j++) {
            l2[j] = l1[j];
        }
    }
}

void mergeSort(datalist* l){
    int n = l->length();
    datalist temp[n];
    int len = 1;
    while(len < n){
        mergePass(l, temp, len);
        len *= 2;
        mergePass(temp, l, len);
        len *= 2;
    }
}