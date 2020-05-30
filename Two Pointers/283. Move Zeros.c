//Time: O(n)
//Space: O(1)

void moveZeroes(int* nums, int numsSize){
    //now traverse the whole array
    //head saves the position when the next non-zero element should be swapped to
    int head = 0, now = 0;
    int temp;

    while(now < numsSize){
        //we ignore the 0 when we encounter one
        if(nums[now] == 0){
            now++;
            continue;
        }
        else{
            //if the element is in the right position
            if(head == now){

            }
            //if the element is not in the right position, we swap it to the head position
            else{
                temp = nums[head];
                nums[head] = nums[now];
                nums[now] = temp;
            }
            head++;
        }
        now++;
    }
}
