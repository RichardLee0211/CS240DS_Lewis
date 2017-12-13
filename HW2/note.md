name: Wenchen Li
# 1
answer: b
in algorithm class, O(NlogN) always run faster than O(N^2)

# 2
answer: O(1)
hashfunction is designed to be O(1)

# 3 & 4
answer: the interface would be
templet<class Value, class Key>
key hashfunction(Value value)

# 5
answer:
way1: num%100
way2: (int)(num/100)%100

# 6
a chained hash table, just add a node after its linked list
an open hash table, resolved by linear probing

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
answer: d
that's the defination

# 11
answer:
if(d[v] > d[u] + w(u, v))
    d[v] = d[u] + w(u, v)
    p[v] = u

# 12
TODO: remain
answer: c

# 13
answer: see pic

# 14
answer: d

# 15
answer:
kruskal's algorithm
    maintain a set of E' of edges(initially empty)
    for i= 1 to |V|-1
        find an edge e in E of least cost such that
            adding e to E' creates no cycles in G=<V, E'>
        add e to E'
So the condiction would be:
        find an edge e in E of least cost such that
            adding e to E' creates no cycles in G=<V, E'>


# 16
answer:
## 1 false
## 2 true
## 3 false
## 4 true
## 5 true
## 6 false
## 7 false
## 8 false

# 17
answer: a, b

# 18 TODO: remain
answer:
O(lg(N))
because:
// i go throuh 1 to A[N/2]
i = 1
find(x, A, i)
    if x = A[i], return 1
    if x < A[i], return 0
    if x > A[i],
        find(x, A, leftchild(i))
        find(x, A, rightchild(i))

# 19
// version 1:
// in C++ array, array[0] is used to store the number of node, instead of node, then
// if left child exists, index of left child would be 2*i = 2*37 = 74
// if right child exists, index of right child would be 2*i+1 = 2*37+1 = 75
// index of parent could be (int)(i/2) = (int) 37/2 = 18
version 2:
array[0] is used to store node, then
if left child exists, index of left child would be 2*i+1 = 2*37+1 = 75
if right child exists, index of right child would be 2*i+2 = 2*37+2 = 76
index of parent could be (int)((i-1)/2) = (int) (37-1)/2 = 18

# 20
TODO: remain, AVL tree, balancing factor, a single right rotation
answer: a, c, d

# 21 & 22
see pic

# 23
see pic

# 24
this could be -1, 0, 1
according the fination of balance tree, for every node, its height of right-subtree
and height of left-subtree differ at most 1
so, balance fact could only be -1, 0, 1


# 25 & 26
TODO: Activity Selection problem
not required
