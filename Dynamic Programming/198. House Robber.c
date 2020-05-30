//Time O(n)
//Space O(n)
//You can make a small change to reduce the Space to O(1), I will demonstrate this in another similar question

int max(int x, int y){
    return (x > y)? x:y;
}

int rob(int* nums, int numsSize){
    //boundary case when there are no house
    if(numsSize == 0){
        return 0;
    }
    //This array stores the maximum amount gained up to each house index
    int * dp = (int *)malloc(sizeof(int) * (numsSize + 1));

    //base case
    //if we don't rob any house and rob the first house only
    dp[0] = 0;
    dp[1] = nums[0];

    /*
    We have two cases:
    Case 1: if we choose the i th house, we cannot choose i - 1
            we can add up the sum by choosing both i th and i - 2 th house

    Case 2: if we don't choose the i th house, we can choose the i - 1 th house
    */
    for(int i = 1; i < numsSize; i++){
        dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
    }

    //the maximum gained at the end to the house list (the whole list)
    return dp[numsSize];
}
