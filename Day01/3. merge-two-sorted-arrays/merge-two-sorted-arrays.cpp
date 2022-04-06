//Method 1:

//The idea is to begin from last element of ar2[] and search it in ar1[]. 
//If there is a greater element in ar1[], then we move last element of ar1[] to ar2[].To 
//keep ar1[] and ar2[] sorted, we need to place last element of ar2[] at correct place in ar1[]. 
//Time complexity: O(N^2)
//Space complexity: O(1)

// Merge ar1[] and ar2[] with O(1) extra space
void merge(int ar1[], int ar2[], int m, int n)
{
    // Iterate through all elements
    // of ar2[] starting from the last element
    for (int i = n - 1; i >= 0; i--)
    {
        /* Find the smallest element greater than ar2[i].
        Move all elements one position ahead till the
        smallest greater element is not found */
        int j, last = ar1[m - 1];
        for (j = m - 2; j >= 0
             && ar1[j] > ar2[i]; j--)
            ar1[j + 1] = ar1[j];
 
        // If there was a greater element
        if (j != m - 2 || last > ar2[i])
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
    }
}
 
//Method 2:

//The solution can be further optimized by observing that while traversing the two 
//sorted arrays parallelly, if we encounter the jth second array element is smaller 
//than ith first array element, then jth element is to be included and replace some 
//kth element in the first array. 
//Time complexity: O(O((n+m)log(n+m)))
//Space complexity: O(1)


void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
   
    // Until i less than equal to k
    // or j is less than m
    while (i <= k && j < m) {
        if (arr1[i] < arr2[j])
            i++;
        else {
            swap(arr2[j++], arr1[k--]);
        }
    }
   
    // Sort first array
    sort(arr1, arr1 + n);
   
    // Sort second array
    sort(arr2, arr2 + m);
}

//Method 3:

//only need to sort second array
//Time complexity: O(O(n+m*log(m)))
//Space complexity: O(1)

void merge(int arr1[], int arr2[], int n, int m) {
        int i=0;
        // while loop till last element of array 1(sorted) is greater than
          // first element of array 2(sorted)
        while(arr1[n-1]>arr2[0])
        {
            if(arr1[i]>arr2[0])
            {
                // swap arr1[i] with first element
                  // of arr2 and sorting the updated
                // arr2(arr1 is already sorted)
                swap(arr1[i],arr2[0]);
                sort(arr2,arr2+m);
            }
            i++;
        }
    }

//Method 4:

//Gap method
//Time complexity: O((n+m))
//Space complexity: O(1)
int nextgap(int gap){
        if(gap<=1){
            return 0;
        }
        return (gap/2)+(gap%2);
    }
    void merge(long long arr1[], long long arr2[], int n, int m) 
    { 
        int i,j,gap=n+m;
        for(gap=nextgap(gap);gap>0;gap=nextgap(gap)){
            for(i=0;i+gap<n;i++){
                if(arr1[i]>arr1[i+gap]){
                    swap(arr1[i],arr1[i+gap]);
                }
            }
            for(j= gap>n?gap-n:0;i<n&&j<m;i++,j++){
                if(arr1[i]>arr2[j]){
                    swap(arr1[i],arr2[j]);
                }
            }
            for(j=0;j+gap<m;j++){
                if(arr2[j]>arr2[j+gap]){
                    swap(arr2[j],arr2[j+gap]);
                }
            }
        }
    } 
};