
//We can consider all substrings one by one and check for each substring whether it contains all unique characters or not.
//Time complexity: O(N^3)
//Space complexity: O(1)

// This functionr eturns true if all characters in str[i..j]
// are distinct, otherwise returns false
bool areDistinct(string str, int i, int j)
{
 
    // Note : Default values in visited are false
    vector<bool> visited(26);
 
    for (int k = i; k <= j; k++) {
        if (visited[str[k] - 'a'] == true)
            return false;
        visited[str[k] - 'a'] = true;
    }
    return true;
}
 
// Returns length of the longest substring
// with all distinct characters.
int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int res = 0; // result
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
}
 

//The idea is to use window sliding. Whenever we see repetition, we remove the previous occurrence and slide the window.
//Time complexity: O(N^2)
//Space complexity: O(1)

int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int res = 0; // result
 
    for (int i = 0; i < n; i++) {
         
        // Note : Default values in visited are false
        vector<bool> visited(256);  
 
        for (int j = i; j < n; j++) {
 
            // If current character is visited
            // Break the loop
            if (visited[str[j]] == true)
                break;
 
            // Else update the result if
            // this window is larger, and mark
            // current character as visited.
            else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
 
        // Remove the first character of previous
        // window
        visited[str[i]] = false;
    }
    return res;
}

//The idea is to use hashmap
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int mx=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            int j=i;
            while(!mp.count(s[j]) and j<n){
                mp[s[j]]++;
                j++;
            }
            if(mx<(j-i)){
                mx=j-i;
            }
        }
        return mx;
    }
};