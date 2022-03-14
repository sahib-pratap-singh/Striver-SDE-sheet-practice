//Approach 1
//solution is to keep dividing the number by two, i.e, do n = n/2 iteratively. 
//In any iteration, if n%2 becomes non-zero and n is not 1 then n is not a power of 2. 
//If n becomes 1 then it is a power of 2. 

//Time complexity: O(log(N))
//Space complexity: O(1)
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return 0;
    while (n != 1)
    {
        if (n%2 != 0)
            return 0;
        n = n/2;
    }
    return 1;
}

//Appraoch 2
// A simple method for this is to simply take the log of the number on base 2 and 
//if you get an integer then the number is the power of 2

//Time complexity: O(1)
//Space complexity: O(1)
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

//Appraoch 3
//Time complexity: O(1)
//Space complexity: O(1)
class Solution {
public:
    bool isPowerOfTwo(long n) {
        return n and !(n&(n-1));
    }
};