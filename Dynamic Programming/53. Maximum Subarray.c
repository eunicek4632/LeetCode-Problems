//Time: O(n)
//Spce: O(1)

int max(int x, int y){
    return (x > y)? x:y;
}

int maxSubArray(int* nums, int numsSize){
    //we only need the previous value so we can use constant space
    //m is the max until now
    int m = nums[0];
    //base case
    //the max subarray at the first entry is the entry tself
    int temp = nums[0];
    /*
    We have two cases when the size of the subarray increase

    Case 1: Concatenate this entry to the original max subarray
    Case 2: The max subarray starts from this entry

    We take the maximum of the two cases
    */
    for(int i = 1; i < numsSize; i++){
        temp = max(temp + nums[i], nums[i]);
        m = max(temp, m);
    }

    return m;
}
