<h1>:heavy_check_mark: Top View of Binary Tree </h1>
<blockquote>
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree


            1
         /     \
        2       3
       /  \    /  \
      4   5  6    7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.
</blockquote>

* **Example 1**:<br>

      Input:
            1
         /    \
        2      3
      Output: 2 1 3

* **Example 2**:<br>

      Input:
              10
            /      \
           20        30
          /   \    /    \
         40   60  90    100
      Output: 40 20 10 30 100

**➔ Your Task**

      Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

<table align="center">
      <tr><td><em><b>Expected Time Complexity</td> <td><em><b>Expected Auxiliary Space</td></tr>
      <tr><td align="center">O(N)</td> <td align="center">O(N)</td></tr>
</table>

### **Constraints** 

      1 <= Number of nodes <= 10^5
      1 <= Data of a node <= 10^5