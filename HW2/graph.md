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
