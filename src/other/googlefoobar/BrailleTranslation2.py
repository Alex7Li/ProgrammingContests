#https://www.google.com/foobar/?eid=hWxkW9CDJIiCjwSRrYSYAQ&usg=AG3vBD1gNtwOhHU9VNBQBxViJalsYdRo4A
def answer(plaintext):
    incodestr = "the quick brown fox jumps over the lazy dog"
    outcodestr = "011110110010100010000000111110101001010100100100101000000000110000111010101010010111101110000000110100101010101101000000010110101001101100111100011100000000101010111001100010111010000000011110110010100010000000111000100000101011101111000000100110101010110110"
    toBraille = {}
    ans = ""
    for i, letter in enumerate(list(incodestr)):
        toBraille[letter] = outcodestr[i * 6:(i + 1) * 6]

    for i in plaintext.strip():
        if i.isupper():
            ans = ans + "000001"
        ans = ans + toBraille[i.lower()]
    return ans


print(answer("aa"))
