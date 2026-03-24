# Iterative Deepening Depth First Search with Path

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H'],
    'E': ['I'],
    'F': [],
    'G': []
}

def dls(node, goal, limit, path):
    print(node, end=" ")        # show traversal
    path.append(node)           # add node to current path

    if node == goal:
        return True

    if limit <= 0:
        path.pop()              # backtrack
        return False

    for child in graph[node]:
        if dls(child, goal, limit - 1, path):
            return True

    path.pop()                  # backtrack if not found
    return False


def iddfs(start, goal, max_depth):

    for depth in range(max_depth + 1):
        print("\nDepth Limit =", depth)
        path = []

        if dls(start, goal, depth, path):
            return path

    return None


start = 'A'
goal = 'I'
max_depth = 3

final_path = iddfs(start, goal, max_depth)

print("\n")

if final_path:
    print("Goal Found")
    print("Final Path:", " → ".join(final_path))
else:
    print("Goal Not Found")