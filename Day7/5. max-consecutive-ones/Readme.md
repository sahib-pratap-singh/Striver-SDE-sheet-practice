<h1>:heavy_check_mark: 485. Max Consecutive Ones</h1>
<blockquote>Given a binary array nums, return the maximum number of consecutive 1's in the array.</blockquote>

* **Example 1**:<br>

        Input: nums = [1,1,0,1,1,1]
        Output: 3
        Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

* **Example 2**:<br>

        Input: nums = [1,0,1,1,0,1]
        Output: 2


<table align="center">
      <tr><td><em><b>Expected Time Complexity</td> <td><em><b>Expected Auxiliary Space</td></tr>
      <tr><td align="center">O(N)</td> <td align="center">O(1)</td></tr>
</table>

### **Constraints** 

        1 <= nums.length <= 10^5
        nums[i] is either 0 or 1.