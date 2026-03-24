from queue import PriorityQueue

# Graph (Adjacency List)
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': [],
    'E': [],
    'F': [],
    'G': []
}

# Heuristic values (Estimated distance to Goal F)
heuristic = {
    'A': 4,
    'B': 3,
    'C': 1,
    'D': 6,
    'E': 5,
    'F': 2,
    'G': 0
}

def greedy_best_first_search(start, goal):
    visited = set()
    pq = PriorityQueue()

    pq.put((heuristic[start], start))
    parent = {start: None}

    print("Traversal:")

    while not pq.empty():
        h, node = pq.get()

        if node in visited:
            continue

        print(node, end=" ")
        visited.add(node)

        if node == goal:
            break

        for child in graph[node]:
            if child not in visited:
                pq.put((heuristic[child], child))
                parent[child] = node

    # Reconstruct final path
    path = []
    current = goal
    total_hn = 0
    while current is not None:
        path.append(current)
        total_hn += heuristic[current]  # sum heuristic along the path
        current = parent.get(current)
    path.reverse()

    return path, total_hn

# Driver Code
start = 'A'
goal = 'G'

path, total_hn = greedy_best_first_search(start, goal)

print("\nFinal Path:", " → ".join(path))
print("Total h(n) along path:", total_hn)
