//Use two loops: The outer loop picks all the elements one by one. 
//The inner loop looks for the first greater element for the element picked by the outer loop. 
//If a greater element is found then that element is printed as next, otherwise, -1 is printed.
//Time complexity: O(N^2)
//Space complexity: O(N)
void nextLargerElement(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " -- "
             << next << endl;
    }
}

//Time complexity: O(N)
//Space complexity: O(N)
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> v;
        stack<long long> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(-1);
            }
            else if(s.size()>0 and arr[i]<s.top()){
                v.push_back(s.top());
            }
            else if(s.size()>0 and arr[i]>=s.top()){
                while(s.size()>0 and arr[i]>=s.top()){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};