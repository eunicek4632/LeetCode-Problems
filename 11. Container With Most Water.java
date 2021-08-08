class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int max = 0;
        int area = 0;
        
        while(right > left){
//             Move the pointer that have smaller height
//             We should find the ones with larger height to obtain larger 
//             area since the width is constantly decreasing
            if(height[left] < height[right]){
                area = height[left] * (right - left);
                left++;
            }
            else{
                area = height[right] * (right - left);
                right--;
            }
            if(max < area){
                max = area;
            }
        }
        return max;
    }
}