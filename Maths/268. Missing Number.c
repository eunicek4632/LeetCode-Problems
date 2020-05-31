//Time: O(n)
//Space: O(n)

int missingNumber(int* nums, int numsSize){
    int sum = 0, arr = 0;
    //arr stores the sum of numbers present in the array
    for(int i = 0; i < numsSize; i++){
        arr += nums[i];
    }

    //sum stores the total sum from 0 to n
    //by the closed for formula: n * (n + 1) / 2
    sum = (numsSize * (numsSize + 1)) / 2;

    //the difference between the total sum of the numbers assuming all of them are present and the sum of the elements in the array
    return sum - arr;
}
