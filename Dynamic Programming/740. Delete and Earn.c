//Time: O(n)
//Space: O(n)

//return maximum
int max(int x, int y){
    return (x > y)? x:y;
}
/*
This question is very similar to Q198. House Robber,
please have a look on that solution before doing this question
*/
int deleteAndEarn(int* nums, int numsSize){
    //store the total points received when removing the number
    //something like hashtable
    //use the removed number as index and store the total amount as entries
    int * sum = (int *)malloc(sizeof(int) * 10001);
    int prev;
    int prev2;
    int temp;

    for(int i = 0; i <= 10000; i++){
        sum[i] = 0;
    }

    //get the total points by choosing each number
    for(int i = 0; i < numsSize; i++){
        sum[nums[i]] += nums[i];
    }

    //base cases
    //the maximum points gained by choosing 0 and 1 and we start to loop from 2
    prev2 = sum[0];
    prev = sum[1];

    /*
    There are two ways to obtain the max score up to i:

    Case 1: if we choose i, we cannot choose i - 1
            we can add up the sum by choosing i and i - 2
    Case 2: if we don't choose i, we can choose i - 1

    We compare the two cases and take the maximum
    */
    for(int i = 2; i < 10001; i++){
        temp = max(sum[i] + prev2, prev);
        prev2 = prev;
        prev = temp;
    }
    return temp;
}
