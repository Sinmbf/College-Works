# Depth Limited Search with Traversal

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H'],
    'E': ['I'],
    'F': [],
    'G': []
}

def depth_limited_search(node, goal, limit):
    print(node, end=" ")   # show traversal

    if node == goal:
        return True

    if limit <= 0:
        return False

    for child in graph[node]:
        if depth_limited_search(child, goal, limit - 1):
            return True

    return False


start = 'A'
goal = 'I'
limit = 2

print("Traversal:")
found = depth_limited_search(start, goal, limit)

print("\n")

if found:
    print("Goal found within depth limit")
else:
    print("Goal not found within depth limit")