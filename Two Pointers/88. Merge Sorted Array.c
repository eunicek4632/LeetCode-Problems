//Time: O(n + m)
//Space: O(1)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //we start merging from the end
    //last index of nums1
    int ptr = m + n - 1;
    m--;
    n--;
    //Use this loop until we have finish one of the arrays
    while(m >= 0 && n >= 0){
        if(nums1[m] >= nums2[n]){
            nums1[ptr] = nums1[m];
            m--;
        }
        else{
            nums1[ptr] = nums2[n];
            n--;
        }
        printf("%d ", nums1[ptr]);
        ptr--;
    }

    //if we have not finish one of the arrays, we copy all the remaining elements in order
    while(m >= 0){
        nums1[ptr] = nums1[m];
        m--;
        ptr--;
    }
    while(n >= 0){
        nums1[ptr] = nums2[n];
        n--;
        ptr--;
    }
}
