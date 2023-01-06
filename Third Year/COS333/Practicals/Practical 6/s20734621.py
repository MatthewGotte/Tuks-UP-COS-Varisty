# u20734621 - Matthew Gotte
# run:
# python s20734621.py

import sys

def convertInput(input):
    #remove non-alphanumeric characters
    input = ''.join(filter(str.isalnum, input))
    # convert to lowercase
    return input.lower()

def isPalindrome(input):
    # check if input is a palindrome
    if input == input[::-1]:
        return True
    else:
        return False

# check if the string is a palindrome
input = sys.argv[1]

if isPalindrome(convertInput(input)):
    print("Palindrome")
else:
    print("Not a Palindrome")