class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        # We will use Hashmap Approach Creating an empty dictionary (hash map)
        # This will store each character from magazine and how many times it appears.
        dictionary = {}

        # Then Counting frequency of each character in magazine
        for char in magazine:
            if char not in dictionary:
                # If it's the first time we see this char → initialize count = 1
                dictionary[char] = 1
            else:
                # Otherwise → increment its count
                dictionary[char] += 1

        # We Try to "use up" letters to build the ransom note
        for char in ransomNote:
            # Check if the char exists in the dictionary and still has a positive count
            if (char in dictionary) and (dictionary[char] > 0):
                # If yes → consume one letter
                dictionary[char] -= 1
            else:
                # If char doesn't exist or no remaining copies → cannot construct the note
                return False

        # Finally, If we managed to process all ransomNote letters successfully → return True
        return True
        '''

        Time: O(n + m) - Space: O(1) 
        
        '''
