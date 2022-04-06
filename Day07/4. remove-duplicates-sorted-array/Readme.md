<h1>:heavy_check_mark: Remove duplicate elements from sorted Array</h1>
<blockquote>Given a sorted array A[] of size N, delete all the duplicates elements from A[].</blockquote>

* **Example 1**:<br>

      Input:
      N = 5
      Array = {2, 2, 2, 2, 2}
      Output: 2
      Explanation: After removing all the duplicates 
      only one instance of 2 will remain.

* **Example 2**:<br>

      Input:
      N = 3
      Array = {1, 2, 2}
      Output: 1 2 

**➔ Your Task**

      You don't need to read input or print anything. Complete the function remove_duplicate() which takes the array A[] and its size N as input parameters and modifies it in place to delete all the duplicates. The function must return an integer X denoting the new modified size of the array. 
      Note: The generated output will print all the elements of the modified array from index 0 to X-1.

<table align="center">
      <tr><td><em><b>Expected Time Complexity</td> <td><em><b>Expected Auxiliary Space</td></tr>
      <tr><td align="center">O(N)</td> <td align="center">O(1)</td></tr>
</table>

### **Constraints** 
    1 ≤ N ≤ 10^4
    1 ≤ A[i] ≤ 10^6