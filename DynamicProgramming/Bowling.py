"""
RULES:
- Each pin has an integer value (positive or negative)
- You have infinite bowling balls
- You can hit each pin by itself (and get that pins number of points) or
    with a neighboring pin (and get the product of the points)
- You do not have to hit each pin
"""
    
def bowlingProblem():
    def computeBestScores(pins):
        n:int = len(pins)
        S:list[int] = [0] * (n + 1) 

        for i in range(1, n + 1):
            #skip current pin
            skip = S[i - 1]

            #take current pin alone
            single = S[i - 1] + pins[i - 1]

            #take current and previous as a double throw
            if i >= 2:
                double = S[i - 2] + pins[i - 2] * pins[i - 1]
            else:
                double = float('-inf')  # invalid value if double is not possible (start of list)

            S[i] = max(skip, single, double)

        return S

    pins:list[int] = list(map(int, input("Enter values of pins space seperated: ").split()))
    table:list[int] = computeBestScores(pins)
    print(" ".join(list(map(str, table))))

bowlingProblem()