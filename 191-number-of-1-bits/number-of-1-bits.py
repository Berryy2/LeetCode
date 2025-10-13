class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Looping and increments counter each time an (n)'s bit is 1 checking by AND operation.
        # then at the end of the loop shift (n) bits to the right. 

        # Intialize counter by zero.
        counter = 0

        # Looping in the 32 bits. 
        for i in range (32):
            # If the bit is "1" increment counter. 
            if n & 1:
                counter += 1
            # Shift (n) to the right.
            n >>= 1
        # At the end return counter.
        return counter