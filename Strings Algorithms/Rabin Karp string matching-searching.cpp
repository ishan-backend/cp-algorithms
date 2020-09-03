/*

The Rabin–Karp string search algorithm is often explained using a rolling hash function that only uses multiplications and additions:

H = c 1 a k − 1 + c 2 a k − 2 + c 3 a k − 3 + . . . + c k a 0 , 

where  a is a constant, and c 1 , . . . , c k  are the input characters (but this function is not a Rabin fingerprint, see below).

In order to avoid manipulating huge H { values, all math is done modulo n . The choice of a and n is critical to get good hashing; see linear congruential generator for more discussion.

Removing and adding characters simply involves adding or subtracting the first or last term. Shifting all characters by one position to the left
requires multiplying the entire sum H by a. Shifting all characters by one position to the right requires dividing the entire sum H by a. 
Note that in modulo arithmetic, a can be chosen to have a multiplicative inverse a − 1 {\displaystyle a^{-1}} a^{-1} by which H can be multiplied to get the result of the division without actually performing a division. 


Use Cases ::

1>  To count substrings in a string that differs by some content (predecided). Sort the hashes of all matched substrings -> then count unique hashes, use set / sort+count.
    But this method is unreliable, as hashes are unreliable in general.
    
    So, what's better ? 
    
    e.g. CF- Good substrings.
    For all order n^2 possible substrings, every index can be a starting point, then flow from start to last. if cnt1 > k, then break. if current substring isnt present in trie,
    Otherwise, make a string till here, move pointer ahead.Keep a count and ++.
    
2> 
*/
