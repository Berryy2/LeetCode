class Solution(object):
    def isSameAfterReversals(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 0: 
            return True
        remainder = num % 10
        if remainder == 0: 
            return False
        return True
        