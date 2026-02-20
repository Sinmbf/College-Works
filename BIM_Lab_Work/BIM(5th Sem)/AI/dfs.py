# Iterative DFS function
def dfs_iterative(tree, start,goal):
    visited = [] # Track visited nodes
    stack = [start]  # Stack for DFS
    print("DFS Traversal: ", end="")
    while stack:  # Continue until stack is empty
        node = stack.pop()  # Pop a node from the stack
        if node not in visited:
            visited.append(node)  # Mark node as visited
            print(node, end=" ")  # Print the current node (for illustration)
            if node==goal: return

            stack.extend(reversed(tree[node]))  # Add child nodes to stack

# Define the decision tree as a dictionary
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

# Run DFS starting from node 'A'
dfs_iterative(tree, 'A','H')