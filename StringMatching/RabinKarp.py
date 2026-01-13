
def testPosition(text:str, pattern:str, index:int) -> bool:
    i = 0
    while i < len(pattern) and text[index + i] == pattern[i]:
        i += 1

    return i == len(pattern)

def rabinKarp(text:str, pattern:str, M:int, base:int = 10) -> list[int]:
    h = (base**(len(pattern)-1)) % M # precomputed for later use
    
    result = []
    
    # compute hash of pattern and first window
    window_hash = 0
    pattern_hash = 0
    for i in range(0, len(pattern)):
        window_hash = (base * window_hash + int(text[i])) % M
        pattern_hash = (base * pattern_hash + int(pattern[i])) % M
    
    for i in range(0, len(text) - len(pattern) + 1):
        if pattern_hash == window_hash:
            if testPosition(text, pattern, i): # Exact check
                result.append(i)

        # update window hash
        if i < len(text) - len(pattern):
            window_hash = (base * (window_hash - int(text[i]) * h) + int(text[i + len(pattern)])) % M
                  
            if window_hash < 0: # make sure hash is in range 
                window_hash += M

    return result

def main():
    text = input("Enter your text: ")
    pattern = input("Enter your patten: ")

    base = int(input("Enter your base (10 for only numbers, 256 for Ascii): "))
    modulo = int(input("Enter your modulo: "))
    matches = rabinKarp(text, pattern, modulo, base)
    print(f"Rabin-Karp found matches at the indices:")
    for i in matches:
        print(str(i) + " (" + text[i:i+len(pattern)] + ")")

main()