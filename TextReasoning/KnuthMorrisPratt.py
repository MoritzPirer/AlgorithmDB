from itertools import product

def precomputation(pattern:str) -> list[int]:
    S = [0] * (len(pattern) + 1)
    S[0] = -1
    S[1] = 0
    for i in range(2, len(pattern) + 1):
        h = S[i - 1]
        print(f"At i = {i}: Set h to {h}")
        while h >= 0:
            if pattern[i - 1] == pattern[h]:
                print(f"At i = {i}: pattern matches at {i-1} and {h}, therefore S[{i}] is {h + 1}\n")
                S[i] = h + 1
                break
            
            print(f"At i = {i}: pattern didn't match at {i-1} and {h}, therefore h is set to {S[h]}")
            h = S[h]
            if h == -1:
                S[i] = 0
                print(f"At i = {i}: h was -1, so S[{i}] is set to 0\n")
    return S

def knuthMorrisPratt(text:str, pattern:str) -> list[int]:
    S = precomputation(pattern)
    print(f"precomputation is {S}\n")

    result = []
    # position in text & pattern
    t = 0
    p = 0
    while t < len(text):
        if text[t] == pattern[p]:
            print(f"At t = {t}: letter match found")
            if p == len(pattern) - 1: # pattern found starting at t - len(pattern) + 1
                print(f"At t = {t}, a full match was found (that started at {t - len(pattern) + 1})")
                result.append(t - len(pattern) + 1)
                p = S[len(pattern)]
            else:
                p += 1
            
            t += 1
        else: # mismatch
            if p == 0: # mismatch at first character
                print(f"At t = {t}, a missmatch was found at the start of the pattern")
                t += 1
            else: # mismatch further in the word
                print(f"At t = {t}, a missmatch was found in the middle of the pattern. Continuing search at p=S[p] = {S[p]}")
                p = S[p]
        print("")
    
    return result

def main() -> None:
    text = input("Enter your text: ")
    pattern = input("Enter your patten: ")

    print(f"The precomputation for this pattern is {precomputation(pattern)}")
    matches = knuthMorrisPratt(text, pattern)
    print(f"Knuth-Morris-Pratt found matches at the indices:")
    for i in matches:
        print(str(i) + " (" + text[i:i+len(pattern)] + ")")


main()