'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
 Two-pointer approach:
  We check whether every character in string `s` appears in string `t` in the same order.
  1. Initialize two pointers at the start of each string.
  2. Traverse `t`. When characters at both pointers match, increment the `s` pointer.
  3. If `s` reaches its end, all its characters appeared in order → return true.
  4. If traversal of `t` finishes before `s` does, return false.
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # We assign the strings lengths to a variable.
        L_s = len(s)
        L_t = len(t)

        # Corner case that if s is an empty string then it's always a subsequent. 
        if L_s == 0: return True

        # Intializing the 2 ptrs at the start of each string.
        s_ptr = 0
        t_ptr = 0

        # Start looping in t.
        while(t_ptr < L_t):

            # Increment s_ptr only if its char matches a char in t.
            if s[s_ptr] ==t[t_ptr]:
                s_ptr += 1

            # If s_ptr reached the end of s string (all the characters matched), we return true.
            if s_ptr == L_s:
                return True

            # ptr_t keeps incrementing regardless the ptr_s conditions 
            t_ptr += 1

        # If the while loop completed without all s characters matched, we return false.
        return False
        