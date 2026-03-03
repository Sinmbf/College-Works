from collections import deque

def bfs(tree, start, goal):
    visited = set([start])
    queue = deque([start])
    parent = {start: None}   # To reconstruct path

    print("BFS Traversal:", end=" ")

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        if node == goal:
            # Reconstruct path
            path = []
            while node is not None:
                path.append(node)
                node = parent[node]
            path.reverse()
            print("\nFinal Path:", " -> ".join(path))
            return

        for neighbor in tree[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                parent[neighbor] = node   # Store parent
                queue.append(neighbor)

    print("\nGoal not found.")

tree = {
    'A': ['B', 'C'],  # Node A connects to B and C
    'B': ['D', 'E'],  # Node B connects to D and E
    'C': ['F', 'G'],  # Node C connects to F and G
    'D': ['H', 'I'],  # Node D connects to H and I
    'E': ['J', 'K'],  # Node E connects to J and K
    'F': ['L', 'M'],  # Node F connects to L and M
    'G': ['N', 'O'],  # Node G connects to N and O
    'H': [], 'I': [], 'J': [], 'K': [],  # Leaf nodes have no children
    'L': [], 'M': [], 'N': [], 'O': []   # Leaf nodes have no children
}
bfs(tree, 'A', 'H')