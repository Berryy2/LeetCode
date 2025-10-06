
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        # Initialize pointers to the last index of both binary strings.
        # We start from the least significant bit (rightmost digit).
        sizeA = len(a) - 1
        sizeB = len(b) - 1
        # Carry represents the overflow from adding two binary digits (either 0 or 1).
        carry = 0
        # This list will store the resulting bits in reverse order.
        res = []
        # Loop until both strings are fully processed AND no carry remains.
        while sizeA >= 0 or sizeB >= 0 or carry > 0:
            # If there are bits left in 'a', add its value (as integer) to carry.
            if sizeA >= 0: 
                carry += int(a[sizeA])
                sizeA -= 1  
            # If there are bits left in 'b', add its value (as integer) to carry.
            if sizeB >= 0:
                carry += int(b[sizeB])
                sizeB -= 1
            # Append the current bit result (carry % 2) to the result list.
            # carry % 2 gives the binary sum bit at the current position.
            res.append(str(carry % 2))
            # Update carry for the next iteration (carry // 2).
            # In binary addition, carry can only be 0 or 1.
            carry = carry // 2
        # Since we built the result in reverse (from least to most significant),
        # we reverse the list and join it into a single binary string.
        return "".join(res[::-1])

        