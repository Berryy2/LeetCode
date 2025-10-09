'''
In this approach we wll use 2 pointers method shrinking until meeting each other
if the elemnet the the 2 pointers pointing 2 is equal until they meet then
the string is a palindrome (skipping all spaces and special charachters)
'''
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Intializing the 2 pointers to the start and end of the string.
        L = 0
        R = len(s) - 1
        
        # Loop while Left pointer hasn't met the right pointer
        while L < R:
            # Skipping all space and special character using isalnum() for left pointer.
            # then move it forward.
            while (L < R) and not (s[L].isalnum()):
                L += 1
            # Skipping all space and special character using isalnum() for right pointer. 
            # then move it backward.               
            while (L < R) and not (s[R].isalnum()):
                R -= 1
            # Compare the lowercase versions of the current characters.
            # If they are not equal, the string is not a palindrome.
            if s[L].lower() != s[R].lower():
                return False
            # If they are equal, continue shrinking until breaking the loop.
            L += 1
            R -= 1
        # Completing the loop means that the string is palindrome.
        return True

    
        