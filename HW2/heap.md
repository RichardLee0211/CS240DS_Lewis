## heap
sudo code
/*
 * A, array pointer
 * i, index of node that want to heapify
 * n, the number of heap nodes
 * O(lg(N))
 */
max_heapify(A, i, n)
    swap i and larger sub-node

/*
 * O(N)
 */
build_max_heap(A, n)
    for i=(int) n/2 downto 1
        max_heapify(A, i, n)

/*
 * O(N*lg(N))
 */
heapsort(A, n)
    build_max_heap(A, n)
    for i=n downto 2
        exchange A[1] with A[i]
        max_heapify(A, 1, i-1)

/*
 * O(lg(N))
 */
heap_extract_max(A, n)
    if n<1
        error "heap underflow"
    max=A[1]
    A[1] = A[n]
    n = n-1
    max_heapify(A, 1, n)
    return max

/*
 * O(lg(N))
 */
heap_increase_key(A, i, key)
    if key<A[i]
        error "new key is smaller than current key"
    A[i] = key
    while i>1 and A[parent(i)]<A[i]
        exchange A[i] with A[parent(i)]
        i = parent(i)

/*
 * O(lg(N))
 */
max_heap_insert(A, key, n)
    n = n+1
    A[n] = -infinate
    heap_increase_key(A, n, key)
