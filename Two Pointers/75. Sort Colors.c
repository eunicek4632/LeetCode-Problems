//Time: O(n)
//Space: O(1)

void sortColors(int* nums, int numsSize){
    int head = 0, tail = numsSize - 1;
    int ptr = 0;
    int temp;

    //going throught the array
    //head strat from beginning and find 0
    //tail start from the end and find 2
    //if 0 and 2 are sorted, 1 will be automatically sorted
    while(ptr <= tail){
        if(nums[ptr] == 0){
            temp = nums[ptr];
            nums[ptr] = nums[head];
            nums[head] = temp;
            head++;
            ptr++;
        }
        else{
            //not increasing ptr because we have to check the element after swapping
            if(nums[ptr] == 2){
                temp = nums[ptr];
                nums[ptr] = nums[tail];
                nums[tail] = temp;
                tail--;
            }
            else{
                ptr++;
            }
        }
    }
}
