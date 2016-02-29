def is_palindrome(x):
    return x == x[::-1]

if __name__ == "__main__":
    palindromes = []
    for num in range(1, 1000001):
        if is_palindrome(str(num)) == True and is_palindrome(bin(num)[2:]) == True:
            print num
            palindromes.append(num)
    print sum(palindromes)
            
