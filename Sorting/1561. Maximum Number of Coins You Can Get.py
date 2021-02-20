class Solution:
    
    '''The strategy is to get the two with largest amoutn and the one with lowest amount each turn'''
    '''
    Time Complexity: O(nlogn)
    Space: O(1)
    '''
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort(reverse=True)
        sum = 0
        i = 1
        while i < len(piles):
            sum += piles[i]
            piles.pop()
            i += 2      
        return sum