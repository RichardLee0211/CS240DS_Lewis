# 1
answer: b

# 2
answer: O(N)

# 3 & 4
answer: the interface would be
templet<class Value, class Key>
Value hash(Key key)

# 5
answer:
way1: num%100
way2: (int)(num/100)%100 // ??

# 6
TODO:
a chained hash table, an open hash table "open addressing"

# 7
answer: an adjacency list
because it could be too many users for a matrix. Assuming a user could have 1000
friends at average, but total users could be over 10 million, which makes matrix
too loose, that's to say, too many unused space in that matrix. Simply waster of
memory.

# 8
answer:
step 1: D
step 1: D C
step 1: D C A
step 1: D C A B
step 1: D C A B E

# 9
## 9a
answer: b
## 9b
answer: c
## 9c
answer: Depth first traversal
because whatever pop from stack would be that lastest push one, which would
successor of successor. The successor will be visited earlier that siblings.

# 10
answer: b

# 11
answer:
if(d[v] > d[u] + w(u, v))
    d[v] = d[u] + w(u, v)
    p[] = // ??

# 12
answer: TODO: ??

# 13
answer: TODO: drawing

# 14
answer: d

# 15
answer: TODO: Kruskal's Algorithm

# 16
answer:
## 1 false
## 2 right // ??
## 3 false // ??
## 4 true
## 5 true
## 6 heapsort // ??
## 7 false
## // ?? false

# 17
answer: a, b

# 18
answer:
// ??

# 19
version 1:
in C++ array, array[0] is used to store the number of node, instead of node, then
if left child exists, index of left child would be 2*i = 2*37 = 74
if right child exists, index of right child would be 2*i+1 = 2*37+1 = 75
index of parent could be (int)(i/2) = (int) 37/2 = 18
version 2:
array[0] is used to store node, then
if left child exists, index of left child would be 2*i+1 = 2*37+1 = 75
if right child exists, index of right child would be 2*i+2 = 2*37+2 = 76
index of parent could be (int)((i-1)/2) = (int) (37-1)/2 = 18

# 20
TODO: ??, AVL tree, balancing factor
answer: a,

# 21 & 22
TODO: drawing, a single right rotation

# 23
TODO: ??

# 24
TODO: balancing factors

# 25 & 26
TODO: Activity Selection problem
