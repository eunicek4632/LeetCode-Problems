# Time Complexity: O(n!)
# Space Complexity: O(n!)

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        def recur(SelList, AnsList):
          # Base case
            if len(SelList) == 0:
                result.append(AnsList)
                return
            
            for i in range(len(SelList)):
              # Add the i-th element to AnsList and remove it from SelList
                recur(SelList[:i] + SelList[i+1:], AnsList + [SelList[i]])
            
        recur(nums, [])
        return result
