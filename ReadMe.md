LeetCode Source Codes
=====================
##LeetCode1 Tow Sum
如果数组是有序的，O(n)的时间复杂度就可以解决了，现在是无序的，一开始要排一下序

##LeetCode2 Median of Two Sorted Arrays
让用logn的时间复杂度，用了两个二分，原来对这种题目都是用O(n)的算法的

##LeetCode3 Longest Substring Without Repeating Characters
很简单的一道题目，O(n)时间复杂度就可以解决

##LeetCode4 Add Two Numbers
简单题，注意空指针的情况和进位

##LeetCode5 Longest Palindromic Substring
O(N^2)的时间复杂度，不知道有没有更快的

##LeetCode6 ZigZag Conversion
边界条件一定要想完全了！！！

##LeetCode7 Reverse Integer
注意数字反正后可能超出Int32范围，此时应当抛异常

##LeetCode8 String to Integer(atoi)
注意一个地方是Overflow，如果插入了Int的范围，返回Int的最大值

##LeetCode9 Palindrome Number
三个地方注意：1、负数不是对称的；2、注意不要Overflow；3、不要使用额外空间，即使用常数项空间，所以不能把整数转化为字符串

##LeetCode10 Regular Expression Matching
**好题！！！** 看了测试样例，即使是大数据s子串的长度也是很小的，比较暴力的递归对大长度子串很不适合，但在Disscus里面有个讨论很好，尤其是给出的链接，值得思考。<http://swtch.com/~rsc/regexp/regexp1.html>

##LeetCode11 Container With Most Water
**好题！！！** 利用贪心的思想，数组两边各一个指针，指针向中间移动，如果height[left]<=height[right]，则left++，否则right++。因为我们都希望得到       
最大的容量，而较小的height就是瓶颈！

##LeetCode12 Integer to Roman
只要知道罗马数字的转换方法即可

##LeetCode13 Roman to Integer
同上

##LeetCode14 Longest Common Prefix
暴力解的，看看Discuss上有没有更好的解答

**后面这三题可以归为一类，就是是否有更好的算法呢？**
##LeetCode15 3Sum
用了N^2logN的算法，不知道还有没有更好的算法，发现此算法也可以跟2Sum一样两头一个指针，达到N^2的时间复杂度

##LeetCode16 3Sum with clostest
2N^2logN的算法,用了一个NlogN的算法，但无法证明其正确性，可能样例太简单了，N^2的算法是可以解决的

##LeetCode17 4Sum
用了N^3的算法

##LeetCode18 Letter Combinations of the Phone Numbers
递归实现，测试案例中没有数字1

##LeetCode19 Remove Nth Node From End of List
递归实现

##LeetCode20 Valid Parentheses
利用了栈

##LeetCode21 Generate Parentheses
又是递归实现

##LeetCode22 Merge K Sorted Lists
时间复杂度为O(N*K) N为K个List的节点数总和

##LeetCode23 Swap Node in Pairs
递归实现，发现很多关于List的题目可以往递归方面考虑

##LeetCode24 Reverse Nodes in K-Group
上面一题的扩展

##LeetCode25 Remove Duplicated Elements
这题就不说了

##LeetCode26 Remove Element
这题也就不说

##LeetCode27 Implement strStr()
KMP算法，可以练练这个算法

##LeetCode28 Next Permutation
要仔细想想的题目，但很容易想出来的，找到当前值较大的一个

##LeetCode29 Search in Rotated Array
先找到最小值的下标，然后两次二分，Array的数字都是不同的，如果存在相同值，则很难办

##LeetCode30 Search for a range
两次二分就好了

##LeetCode31 Search an inserted position
二分，不多说了

##LeetCode32 Combination Sum
**FIXME**用了暴力来解的，是不是会有更好的解决方法呢？

##LeetCode33 Combination Sum II
同上

##LeetCode34 First Missing Positive
算法是想的到的，证明复杂度是O(N)，有些复杂，我们可以想对于每个slot我们都只操作一次。

##LeetCode35 Trapping Rain Water
一维的方法很容易想，二维的要用到heap，也是先找最小的

##LeetCode36 Multiply Strings
O(NM)的时间复杂度实现的算法。

##LeetCode37 Permutations
简单题

##LeetCode38 Permutations II
先排序，然后就同上了

##LeetCode39 Rotate Image
x,y坐标变换搞好就行

##LeetCode40 Pow(x,n)
注意n可能为负数,且负数可能为(1<<31)!

##LeetCode41 N-Queens
dfs解决

##LeetCode42 N-Queens II
同上，不罗嗦了

##LeetCode43 Spiral Matrix
好绕的一道题目

##LeetCode44 Jump Game
O(n) time complexity

##LeetCode45 Merge Intervals
O(nlogn) 先排序

##LeetCode46 Insert Interval
O(n)

##LeetCode47 Length of Last word
这题太简单，就不说了

##LeetCode48 Spiral Matrix II
比I简单多了

##LeetCode49 Permutation Sequences
**好题**，暴力会超时，然后很多小细节

##LeetCode50 Rotate List
还算简单题，不过是链表，要多练练

##LeetCode51 Minimum Path Sum
dp了，O(NM)

##LeetCode52 Unique Path
简单的DP

##LeetCode53 Unique Path II
简单的DP

##LeetCode54 Merge Two Sorted List
简单的链表操作

##LeetCode55 Add Binary
简单的题目

##LeetCode56 Plus One
简单题目

##LeetCode57 Sqrt(x)
注意溢出，结果项下取整

##LeetCode58 Climbing Stairs
简单的DP

##LeetCode59 Set Matrix Zeros
**好题**，很多要注意的地方，常量空间复杂度

##LeetCode60 Search a 2D Matrix
两次二分即可

##LeetCode61 Sort Color
**好题**O(n) one pass algorithm

##LeetCode62 Minimum Window SubString
**好题**跟珍珠项链差不多

##LeetCode63 Combinations
简单题目

##LeetCode64 Subset
简单题目

##LeetCode65 Word Search
简单题目

##LeetCode66 Remove Duplicates from Sorted Array II
简单题目

##LeetCode67 Remove Duplicates from Sorted List
链表操作，简单题目

##LeetCode68 Remove Duplicates from Sorted List II
链表操作，注意边界

##LeetCode69 Largest Rectangle in Histogram
**好题** 但不知道自己的解法是不是最好的

##LeetCode70 Partition List
简单的链表题目

##LeetCode71 Merge Sorted Array
简单题，有没有可以不用额外空间的？

##LeetCode72 Decode Ways
**好题** dp，一开始暴力了。。。

##LeetCode73 Reverse Linked List II
链表题目，简单题目

##LeetCode74 Maximum Depth of Binary Tree
简单题目

##LeetCode75 Path Sum
**好题**意要明确什么是叶子节点，就是它的左右子节点都是NULL的时候

##LeetCode76 Minimum Depth of Binary Tree
仍然要注意上题的坑，简单题目

##LeetCode77 Pascal's Triangle
简单题目

##LeetCode78 Pascal's Triangle II
简单题目

##LeetCode79 Triangle
简单dp

##LeetCode80 Valid Palindrome
简单题目，要仔细，注意空字符串

##LeetCode81 Sum Root to Leaf Numbers
简单题目，注意root为NULL

##LeetCode82 Surrounded Regions
广度搜索

##LeetCode83 Palindrome Partitioning II
**好题**两次DP

##LeetCode84 Palindrome Partitioning
有了上面一道题的基础，这道题就好做很多了

##LeetCode85 Binary Tree Inorder Traversal
**好题** 非递归中序遍历， 那非递归前序和后序呢？

##LeetCode86 Unique Binary Search Trees
**好题** DP

##LeetCode87 Interleaving String
**好题** DP

##LeetCode88 Edit Distance
简单的DP

##LeetCode89 Binary Tree Maximum Path Sum
**好题** 注意有负数

##LeetCode90 Best Time to Buy and Sell Stock
注意有空数组，单个元素的数组，只递减的数据

##LeetCode91 Best Time to Buy and Sell Stock II
求每个上升区间段

##LeetCode92 Best Time to Buy and Sell Stock III
**好题** O(n)的算法

##LeetCode93 Path Sum II
简单题目

##LeetCode94 Populating Next Right Pointers in Each Node
还算简单题目吧，关键要求是用常数空间

##LeetCode95 Symmetric Tree
非递归就用队列好了

##LeetCode96 Same Tree
方法同上

##LeetCode97 Binary Tree Level Order Traversal
简单题目

##LeetCode98 Binary Tree Zigzag Level Order Traversal
简单题目

##LeetCode99 Flatten Binary Tree to Linked List
注意树的left指针要置为NULL

##LeetCode100 Balanced Binary Tree
简单题目

##LeetCode101 Convert Sorted List to Binary Search Tree
简单题目,是否可以不用数组呢

##LeetCode102 Convert Sorted Array to Binary Search Tree
简单题目

##LeetCode103 Binary Tree Level Order Traversal II
简单题目

##LeetCode104 Construct Binary Tree from Inorder and Postorder Traversal
递归来解还是蛮好写的

##LeetCode105 Construct Binary Tree from Preorder and Inorder Traversal
代码实现要仔细啊

##LeetCode106 Validate Binary Search Tree
利用中序遍历的性质

##LeetCode107 Divide Two Integers
**好题** 关键是时间复杂度怎么算的啊？

##LeetCode108 Longest Valid Parentheses
**好题** 贪心啊。。。

##LeetCode109 Jump Game II
**好题** 线段树

##LeetCode110 Anagrams
搞不懂为什么这样做

##LeetCode111 Gray Code
找规律即可得出

##LeetCode112 Longest Consecutive Sequence
**好题** 用 Hash Table 的时间复杂度将会为O(N)

##LeetCode113 Word Ladder
如果是构造图的话，要O(N^2)的时间复杂度，会TLE的

##LeetCode114 Subset II
dfs

##LeetCode115 Word Ladder II
终于改的不TLE了

##LeetCode116 Populating Next Right Pointers in Each Node II
**好题** 

##LeetCode117 Distinct Subsequences
**好题** dp

##LeetCode118 Recover Binary Search Tree
**好题** 节点的值都不相同吧

##LeetCode119 Text Justification
模拟题

##LeetCode120 Search in Rotated Sorted Array II
两次二分了

##LeetCode121 Maximal Rectangle
O(N*M^2)的时间复杂度

##LeetCode122 Restore IP Addresses
DFS

##LeetCode123 Simplify Path
简单题目，注意边界

##LeetCode124 Valid Number
各种坑啊，例如e3,+,+.,e前面必须有数字，e后面必须为整数

##LeetCode125 Valid Sudoku
只要现有的局面不违反数独规则，此数独就一定有解

##LeetCode126 Scramble String
三维DP

##LeetCode127 Count and Say
模拟题目

##LeetCode128 Substring with Concatenation of All Words
还是需要一下技巧的

##LeetCode129 Solve Sudoku
DFS

##LeetCode130 Wildcard Matching
**好题** 有一种用DP的方法，递归超时