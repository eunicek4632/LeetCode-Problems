class Solution {
    List<List<Integer>> sol = new LinkedList<>();
    
    public void recur(LinkedList<Integer> list, int[] candidates, int target, int index){
        
        if(target == 0){
            this.sol.add(new LinkedList(list));
            return;
        }
        
        if(target < 0){
            return;
        }
        
        // the index prevents the pointer to go back to previous entries and produce duplicated results
        // We don't add 1 to index when we call the method again because the same number can be used more than once
        for(int i = index; i < candidates.length; i++){
            list.addLast(candidates[i]);
            this.recur(list, candidates, target - candidates[i], i);
            list.removeLast();
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        LinkedList<Integer> tmp = new LinkedList<Integer>();
        this.recur(tmp, candidates, target, 0);
        return this.sol;    
    }
    
}