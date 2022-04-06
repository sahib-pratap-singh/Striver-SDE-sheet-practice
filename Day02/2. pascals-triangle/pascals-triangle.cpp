//A simple method is to run two loops and calculate the value of Binomial Coefficient in inner loop. 
// C(line, i)   = line! / ( (line-i)! * i! ) 
//Time complexity : O(n*n*n)
//Space complexity: O(1)
class Solution {
public:
    int binomialCoeff(int n, int k)
    {
        int res = 1;
        if (k > n - k)
        k = n - k;
        for (int i = 0; i < k; ++i)
        {
            res *= (n - i);
            res /= (i + 1);
        }

        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j <= i; j++)
                v.push_back(binomialCoeff(i, j));
            ans.push_back(v);
        }
        return ans;
    }
};

//Time complexity : O(n*n)
//Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> v;
        vector<vector<int>> ans;
        v.push_back(1);
        ans.push_back(v);
        for(int i=2;i<=n;i++){
            v.resize(i);
            v[0]=1;
            v[i-1]=1;
            for(int j=1;j<i-1;j++){
                v[j]=ans[i-2][j-1]+ans[i-2][j];
            }
            ans.push_back(v);
        }
        return ans;
    }
};

//Time complexity : O(n)
//Space complexity: O(1)
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int line = 1; line <= n; line++)
        {
            int binomialCoeff = 1;
            vector<int> v;
            for (int i = 1; i <= line; i++)
            {
                v.push_back(binomialCoeff);
                binomialCoeff = binomialCoeff * (line - i) / i;
            }
            ans.push_back(v);
        }
        return ans;
    }
};