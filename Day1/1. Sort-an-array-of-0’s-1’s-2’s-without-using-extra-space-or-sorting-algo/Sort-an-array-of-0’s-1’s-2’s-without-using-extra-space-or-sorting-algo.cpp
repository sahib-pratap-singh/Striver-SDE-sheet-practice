//Using three variables
//Time complexity: O(N)
//Space complexity: O(1)
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int start=0;
        int mid=0;
        int last=n-1;
        while(mid<=last){
            if(a[mid]==0){
                swap(a[mid],a[start]);
                start++;
                mid++;
            }
            else if(a[mid]==1){
                mid++;
            }
            else if(a[mid]==2){
                swap(a[mid],a[last]);
                last--;
            }
        }
    }
};

//Using counter
//Time complexity: O(N)
//Space complexity: O(1)
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int one=0;
        int zero=0;
        int two=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zero++;
            }
            if(a[i]==1){
                one++;
            }
            if(a[i]==2){
                two++;
            }
        }
        int i=0;
        while(zero){
            a[i]=0;
            zero--;
            i++;
        }
        while(one){
            a[i]=1;
            one--;
            i++;
        }
        while(two){
            a[i]=2;
            two--;
            i++;
        }
    }
    
};