# Iterative DFS function with path reconstruction
def dfs(tree, start, goal):
    visited = set()
    stack = [start]
    parent = {start: None}   # Store parent to reconstruct path

    print("DFS Traversal:", end=" ")

    while stack:
        node = stack.pop()

        if node not in visited:
            visited.add(node)
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

            # Add children to stack (reverse for left-to-right traversal)
            for neighbor in reversed(tree[node]):
                if neighbor not in visited:
                    parent[neighbor] = node
                    stack.append(neighbor)

    print("\nGoal not found.")

tree = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H', 'I'],
    'E': ['J', 'K'],
    'F': ['L', 'M'],
    'G': ['N', 'O'],
    'H': [], 'I': [], 'J': [], 'K': [],
    'L': [], 'M': [], 'N': [], 'O': []
}

dfs(tree, 'A', 'H')