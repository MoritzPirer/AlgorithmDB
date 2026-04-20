# DESCRIPTION

This Repository serves as a collection of sample implementations of algorithms and data structures. While pseudo-code is great, an actual, working implementation is often easier to understand and transfer to other languages.

# ALGORITHMS BY TAGS

This Repository uses a tagging system to categorize its elements. A full list of tags can be found at the bottom of this file.

## BY DOMAIN:

> The type of problem the algorithm solves

### domain/sort
> Algorithms that sort data in a container
[BubbleSort](./Algorithms/Sorting/BubbleSort.py)
[MergeSort](./Algorithms/Sorting/MergeSort.py)
[QuickSort](./Algorithms/Sorting/QuickSort.py)

### domain/search
> Algorithms that search for entries in a container

[BinarySearch](./Algorithms/Searching/BinarySearch.py)
[InterpolationSearch](./Algorithms/Searching/InterpolationSearch.py)

### domain/text
> Algorithms that modify or process text / strings

[Knuth-Morris-Pratt](./Algorithms/Text/StringMatching/KnuthMorrisPratt.py)
[Rabin-Karp](./Algorithms/Text/StringMatching/Rabin-Karp.py)

### domain/math
> mathematical algorithms

[Fibonaci](./Algorithms/DynamicProgramming/Fibonacci.py)

### domain/graph
[Convex Polygon contains Point](./Algorithms/Graph/Polygon.py)
### domain/visual

### domain/crypt

### domain/stat

[Fisher-Yates Shuffle](./Algorithms/Random/FisherYatesShuffle.py)

### domain/toy
> Toy problems that are intended to explore concepts rather than have a practical application
[Bowling Problem](./Algorithms/DynamicProgramming/Bowling.py)
[Knapsack Problem](./Algorithms/DynamicProgramming/Knapsack.py)

### domain/data-structure

[BitSet](./Data%20Structures/BitSet%20&%20BloomFilter/BitSet.hpp)
[Bloom Filter](./Data%20Structures/BitSet%20&%20BloomFilter/BloomFilter.hpp)

### domain/joke
> Algorithms that are fun because they are stupid and / or impractical

[BogoBogoSort](./Joke/BogoBogoSort.py)
[BogoSort](./Joke/BogoSort.py)
[CommunismSort](./Joke/CommunismSort.py)
[HiroshimaSort](./Joke/HiroshimaSort.py)
[HumanSort](./Joke/HumanSort.py)
[IntelligentDesignSort](./Joke/IntelligentDesignSort.py)
[MiracleSort](./Joke/MiracleSort.py)
[RoundUpSort](./Joke/RoundUpSort.py)
[SleepSort](./Joke/SleepSort.py)
[StalinSort](./Joke/StalinSort.py)
[ThanosSort](./Joke/ThanosSort.py)
[RandomSearch](./Joke/Searching/RandomSearch.py)
[GaslightSearch](./Joke/Searching/GaslightSearch.p)

## BY PARADIGM
> Categorizes algorithm by design principles used

### paradigm/dynamic-programming

[Bowling Problem](./Algorithms/DynamicProgramming/Bowling.py)
[Fibonaci](./Algorithms/DynamicProgramming/Fibonacci.py)
[Knapsack Problem](./Algorithms/DynamicProgramming/Knapsack.py)
[SubarraySum](./Algorithms/DynamicProgramming/SubarraySum.py)

### paradigm/greedy
> choosing locally optimal options

### paradigm/divide-and-conquer
> recursivly split into smaller subproblems

### paradigm/bit-manipulation
> Work directly on the bits

[BitSet](./Data%20Structures/BitSet%20&%20BloomFilter/BitSet.hpp)

### paradigm/brute-force
> Exhaustive search over all possible choices

### paradigm/binary-search
> repeatedly exclude one half of a search space

[BinarySearch](./Algorithms/Searching/BinarySearch.py)
[Convex Polygon contains Point](./Algorithms/Graph/Polygon.py)

### paradigm/hashing
> computes a hash value for data

[Bloom Filter](./Data%20Structures/BitSet%20&%20BloomFilter/BloomFilter.hpp)
[Rabin-Karp](./Algorithms/Text/StringMatching/Rabin-Karp.py)

## BY PROPERTY
> categorize algorithms by attributes of their behavior

### prop/stable
> preserves relative ordering in a container

### prop/in-place
> Constant memory overhead 

[Fisher-Yates Shuffle](./Algorithms/Random/FisherYatesShuffle.py)

### prop/parallel
> Uses some form of multithreading / paralellization

### prop/approx
> Returns an approximation for a more expensive calculation

### prop/lossy
> loses some data in exchange for other benefits (e.g. reduced memory usage)

### prop/probabilistic
> some chance for incorrect result (usually in exchange for cheaper calculation or lower overhead)
[Bloom Filter](./Data%20Structures/BitSet%20&%20BloomFilter/BloomFilter.hpp)

# ALL TAGS

## DOMAIN: What the problem is about

- domain/sort                   sorting data in a container
- domain/search                 finding data in a container
- domain/text                   modifying or processing text / strings
- domain/math                   math (number theory, algebra, ...)
- domain/graph                  reasoning over graphs, networks paths, ...
- domain/visual                 displaying things and modifying pixel-like grids (e.g. shape drawing algorithms, shape processing)
- domain/crypt                  encryption and cryptography
- domain/stat                   probabilistic & (pseudo-)random algorithms, estimations
- domain/toy                    Toy problems that are intended to explore concepts rather than have a practical application
- domain/data-structure
- domain/joke

## PARADIGM: What design principles the algorithm uses
paradigm/dynamic-programming         dynamic programming (e.g. memoization)
paradigm/greedy                     choosing locally optimal options
paradigm/divide-and-conquer         recursivly split into smaller subproblems
paradigm/bit-manipulation           Work directly on the bits
paradigm/brute-force                Exhaustive search over all possible choices
paradigm/binary-search              repeatedly exclude one half of a search space
paradigm/hashing                    computes a hash value for data

## PROPERTIES: how the algorithm behaves
prop/stable                         preserves relative ordering in a container
prop/in-place                       Constant memory overhead 
prop/parallel                       Uses some form of multithreading / paralellization
prop/approx                         Returns an approximation for a more expensive calculation
prop/lossy                          loses some data in exchange for other benefits (e.g. reduced memory usage)
prop/probabilistic                  some chance for incorrect result (usually in exchange for cheaper calculation or lower overhead)
