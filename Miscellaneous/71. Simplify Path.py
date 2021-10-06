class Solution:
    def simplifyPath(self, path: str) -> str:
        arr = path.split("/")
        
        ptr = 0
        while ptr < len(arr):
            if arr[ptr] == "..":
                arr.pop(ptr)
                if ptr > 0:
                    arr.pop(ptr - 1)
                    ptr -= 1       
                # need to move backward
            
            elif arr[ptr] == '' or arr[ptr] == '.':
                arr.pop(ptr)
                # No need to move forward
                
            else:
                ptr += 1
                
        return "/" + "/".join(arr)
