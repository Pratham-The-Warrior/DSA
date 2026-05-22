class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        max_len = 0
        l = 0  # Left pointer starts at 0
        
        # 1. EXPAND: Right pointer moves forward one element at a time
        for r in range(len(nums)):
            
            # 2. UPDATE STATE & SHRINK (Condition A: Threshold Violation)
            # If the new element is too big, the entire window is ruined.
            # We must shrink/reset the left pointer past this invalid element.
            if nums[r] > threshold:
                l = r + 1
                continue
            
            # 2. UPDATE STATE & SHRINK (Condition B: Parity Violation)
            # If two adjacent elements have the same odd/even parity, 
            # the current window is broken. Reset 'l' to the current 'r'.
            if r > l and (nums[r] % 2 == nums[r - 1] % 2):
                l = r
            
            # 2. UPDATE STATE & SHRINK (Condition C: Even Start Violation)
            # The problem dictates the subarray MUST start with an even number.
            # We shrink the left pointer until 'nums[l]' is even.
            while l <= r and nums[l] % 2 != 0:
                l += 1
                
            # 3. RECORD: The window is now 100% valid. Record the max length.
            if l <= r:
                max_len = max(max_len, r - l + 1)
                
        return max_len
