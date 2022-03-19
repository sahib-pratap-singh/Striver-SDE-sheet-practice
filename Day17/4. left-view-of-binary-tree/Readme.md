<h1>:heavy_check_mark: Left View of Binary Tree </h1>
<blockquote>Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

               1
            /     \
           2        3
         /   \     /  \
        4     5   6    7
         \
          8   
</blockquote>

* **Example 1**:<br>

      Input:
         1
       /  \
      3    2
      Output: 1 3

* **Example 2**:<br>
![Tree](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190221103723/leftview.jpg)

        Output: 10 20 40

**➔ Your Task**

      You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.

<table align="center">
      <tr><td><em><b>Expected Time Complexity</td> <td><em><b>Expected Auxiliary Space</td></tr>
      <tr><td align="center">O(N)</td> <td align="center">O(N)</td></tr>
</table>

### **Constraints** 

      0 <= Number of nodes <= 100
      1 <= Data of a node <= 1000