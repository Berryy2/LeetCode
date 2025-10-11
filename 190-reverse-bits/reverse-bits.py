class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        rev = 0
        for i in range(32):
            rev <<= 1
            if n & 1:
                rev |= 1
            n >>= 1
        return rev