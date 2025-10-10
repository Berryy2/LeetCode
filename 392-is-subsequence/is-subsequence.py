class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        L_s = len(s)
        L_t = len(t)
        if L_s == 0: return True
        s_ptr = 0
        t_ptr = 0
        while(t_ptr < L_t):
            if s[s_ptr] ==t[t_ptr]:
                s_ptr += 1
            if s_ptr == L_s:
                return True
            t_ptr += 1
        return False
        