# we start from x = 0 and apply each operation in order.
# Each "++X" or "X++" increases x by 1,
# and each "--X" or "X--" decreases x by 1.
#
# The goal is to return the final value of x.

class Solution(object):
    def finalValueAfterOperations(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """
        # Initialize x to 0
        x = 0
        
        # Loop through every operation in the list
        for op in operations:
            # If the operation contains '+' → increment x
            if '+' in op:
                x += 1
            # Otherwise (it contains '-') → decrement x
            else:
                x -= 1
        
        # Return the final value after all operations
        return x