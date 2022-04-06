#include<bits/stdc++.h>
//Using unordered map
//Time complexity: O(n)
//Space complexity: O(n)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp.count(i)){
                if(mp[i]>1){
                    arr[0]=i;
                }
            }
            else{
                arr[1]=i;
            }
        }
        return arr;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int repeating;
        int missing;
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
            else{
                repeating=abs(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                missing=i+1;
                break;
            }
        }
        arr[0]=repeating;
        arr[1]=missing;
        return arr;
    }
};
//Another approaches you can try are 

//1 Sorting the array and then find mising and repeating element
//Time complexity: O(nlog(n))
//Space complexity: O(1)

//2 Using an count array in which we will count the element occurences
//Time complexity: O(n)
//Space complexity: O(n)