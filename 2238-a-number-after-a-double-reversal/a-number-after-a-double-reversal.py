'''
I am training my python so i couldn't find easier problem to implement it on python
than this. :)
Approach:
    1. If num == 0, it stays the same after any number of reversals.
    2. Otherwise, check if the last digit is 0 (num % 10 == 0).
        - If yes → it will lose zeros when reversed → return false.
        - Otherwise → double reversal restores the same number → return true.
Time Complexity: O(1)
Space Complexity: O(1)
'''
class Solution(object):
    def isSameAfterReversals(self, num):
        """
        :type num: int
        :rtype: bool
        """
        # Edge case num = zero -> Zero stays zero after any number of reversals.
        if num == 0: 
            return True
        remainder = num % 10
        # If the number ends with zero, reversing will drop those zeros.
        if remainder == 0: 
            return False
        # Otherwise, reversing twice restores the same number.
        return True
        