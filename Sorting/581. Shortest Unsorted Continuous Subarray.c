//Time: O(n)
//Space: O(1)

int findUnsortedSubarray(int* nums, int numsSize){
    int start = 0;
    //we find the first inversion position and the last inversion position
    while(start <= numsSize - 2 && nums[start] <= nums[start + 1]){
        start++;
    }
    int end = numsSize - 1;
    while(end >= 1 && nums[end] >= nums[end - 1]){
        end--;
    }
    //if the array have no inversions
    if(end == 0 && start == numsSize - 1){
        return 0;
    }
    //we find the minimum and maximum in the range of index
    int min = nums[start];
    int max = nums[start];
    
    for(int i = start; i <= end; i++){
        if(nums[i] > max){
            max = nums[i];
        }
        if(nums[i] < min){
            min = nums[i];
        }
    }
    
    //check if there are some integers in the range of min and max of the subarray, if yes, we include them in
    for(int i = 0; i < start; i++){
        if(min < nums[i]){
            start = i;
        }
    }
    for(int i = end; i < numsSize; i++){
        if(max > nums[i]){
            end = i;
        }
    }
    return end - start + 1;
}
