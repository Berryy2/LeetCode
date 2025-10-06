class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        sizeA = len(a) - 1
        sizeB = len(b) - 1
        carry = 0
        res = []
        while sizeA >= 0 or sizeB >= 0 or carry > 0:
            if sizeA >= 0: 
                carry += int(a[sizeA])
                sizeA -= 1
            if sizeB >= 0:
                carry += int(b[sizeB])
                sizeB -= 1
            res.append(str(carry % 2))
            carry = carry // 2

        return "".join(res[::-1])

        