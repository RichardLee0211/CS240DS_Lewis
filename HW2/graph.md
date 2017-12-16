## graph
G=<V, E>

### minimum spanning tree
kruskal's algorithm
    maintain a set of E' of edges(initially empty)
    for i= 1 to |V|-1
        find an edge e in E of least cost such that
            adding e to E' creates no cycles in G=<V, E'>
        add e to E'

consider edges in sorted order by weight, use a priority queue
vertices must be in separate graph "components"
kruskal:
    E' = {}
    components = |G|
    Edges = PriorityQueue(/* edges of G */)
    for each vertex u in G make a new component
    while components > 1 do
        {u, w} = extractMin from the priority queue
        U = Find(u) // returns the component of u
        W = Find(w)
        if(U != W)
            Union(U, W) // join two components
            insert {u, w} into E'
            components = components - 1
    return E'

prim's algorithm
    maintain two sets
    E' (initially empty)
    N (initially contains any one vertex)
    repeat |V|-1 times
        find an edge e in E of samllest weight, that join
            vertex u in N to a vertex v that is not in N
        add e to E'

difference and similarity:
- Kruska's builds a minimum spanning tree by adding one edge at a time. The next line is always the shortest (minimum weight) ONLY if it does NOT create a cycle.
- Prims builds a mimimum spanning tree by adding one vertex at a time. The next vertex to be added is always the one nearest to a vertex already on the graph.
- Prim always joins a "new" vertex to an "old" vertex, so that every stage is a tree. Kruskal's allows both "new" to "new" and "old" to "old" to get connected, so it risks creating a circuit and must check for them every time. So Kruskal's has a larger complexity than Prim.

### BFS, DFS
BFS(G, s):
Q = FIFO queue
while(Q != NULL)
    u = Dequeue(Q)
    for each v in adj[u]
        if(v.color == white)
            v.color = gray
            v.d = u.d + 1 // v.d holds distance from s
            v.u = u  // make u the predecessor of v in BFS
            enqueue(Q, v)
        u.color = black
worst case time of BFS is O(|V|+|E|)

DFS(G)
    for each u belong to G.V
        u.color = WHITE
        u.u = NULL
    time = 0
    for each u belong to G.V
        if u.color == WHITE
            DFS-VISIT(G, u)
DFS(G, u)
    time = time+1
    u.d = time
    u.color = GRAY
    for each v belong to G.Adj[u]
        if v.color == WHITE
            v.u = u // create an edge for the current DF tree
            DFS-VISITE(G, v)
        u.color = BLACK
        time = time - 1
        u.f = time
worst case ruuning time is O(|v|+|E|)

### Single source min path
Dijkstra(G, w, s)
    inint_single_source(G, s)
    S = NULL
    Q = G.V
    while Q != NULL
        u = extra_min(Q)
        S = S + u
        for each vertex v belong to G.adj[u]
            relax(u, v, w)  // essentially decrease-key()
initialization part: O(|V|)
while loop: O(|V|)
each extract-min(); O(lg|V|)
for loop(total number of iterations for entire while loop): O(|E|)
each relax(decrease-key): lg|V|
the total for the For loop: O(|E|lg|V|)
Running time: O(|E|lg|V|)
