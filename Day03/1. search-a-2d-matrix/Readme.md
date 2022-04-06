<h1>:heavy_check_mark: 74. Search a 2D Matrix </h1>
<blockquote>Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
 </blockquote>

* **Example 1**:<br>

        Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
        Output: true

* **Example 2**:<br>

        Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
        Output: false

**➔ Your Task**

      You dont need to read input or print anything. 

<table align="center">
      <tr><td><em><b>Expected Time Complexity</td> <td><em><b>Expected Auxiliary Space</td></tr>
      <tr><td align="center">O(log(n))</td> <td align="center">O(1)</td></tr>
</table>

### **Constraints** 

        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 100
        -10^4 <= matrix[i][j], target <= 10^4