//We can use brute force approach that will take O(N*N) time.

//We can also use Sorting
//Time complexity:O(Nlog(n))
//Space complexity: O(1)

//Using hashing
//Time complexity:O(N)
//Space complexity: O(N)

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      unordered_map<int,int> mp;
      for(int i=0;i<n;i++){
          mp[arr[i]]++;
      }
      int ans=0;
      for(int i=0;i<n;i++){
          int cnt=1;
          int val=arr[i]+1;
          if(mp.count(val-2)){
              continue;
          }
          while(mp.count(val)){
              cnt++;
              val++;
          }
          ans=max(ans,cnt);
      }
      return ans;
    }
};

//Using priority queue
//Time complexity:O(N)
//Space complexity: O(N)

int findLongestConseqSubseq(int arr[], int N)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++) {
       
        // adding element from
        // array to PriorityQueue
        pq.push(arr[i]);
    }
 
    // Storing the first element
    // of the Priority Queue
    // This first element is also
    // the smallest element
    int prev = pq.top();
    pq.pop();
 
    // Taking a counter variable with value 1
    int c = 1;
 
    // Storing value of max as 1
    // as there will always be
    // one element
    int max = 1;
    while (!pq.empty()) {
       
        // check if current peek
        // element minus previous
        // element is greater then
        // 1 This is done because
        // if it's greater than 1
        // then the sequence
        // doesn't start or is broken here
        if (pq.top() - prev > 1) {
           
            // Store the value of counter to 1
            // As new sequence may begin
            c = 1;
 
            // Update the previous position with the
            // current peek And remove it
            prev = pq.top();
            pq.pop();
        }
 
        // Check if the previous
        //  element and peek are same
        else if (pq.top() - prev == 0) {
           
            // Update the previous position with the
            // current peek And remove it
            prev = pq.top();
            pq.pop();
        }
       
        // If the difference
        // between previous element and peek is 1
        else {
           
            // Update the counter
            // These are consecutive elements
            c++;
 
            // Update the previous position
            //  with the current peek And remove it
            prev = pq.top();
            pq.pop();
        }
       
        // Check if current longest
        // subsequence is the greatest
        if (max < c) {
           
            // Store the current subsequence count as
            // max
            max = c;
        }
    }
    return max;
}