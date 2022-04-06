//Using extra space
//Time complexity: O(N)
//Space complexity: O(N)


//Two pointer
//Time complexity: O(N)
//Space complexity: O(1)

class Solution{
public:
    int remove_duplicate(int a[],int n){
        int i=0;
        int j=0;
        while(j<n){
            while(j<n-1 and a[j]==a[j+1]){
                j++;
            }
            i++;
            j++;
            a[i]=a[j];
        }
        return i;
    }
};

