# Minimax with Path

graph = {
    'A': ['B', 'C'],     # MAX
    'B': ['D', 'E'],     # MIN
    'C': ['F', 'G'],     # MIN
    'D': [],
    'E': [],
    'F': [],
    'G': []
}

utility = {
    'D': 3,
    'E': 5,
    'F': 2,
    'G': 9
}

def minimax(node, isMax):

    # Terminal node
    if len(graph[node]) == 0:
        return utility[node], [node]

    if isMax:
        best_val = float('-inf')
        best_path = []

        for child in graph[node]:
            val, path = minimax(child, False)

            if val > best_val:
                best_val = val
                best_path = [node] + path

        return best_val, best_path

    else:
        best_val = float('inf')
        best_path = []

        for child in graph[node]:
            val, path = minimax(child, True)

            if val < best_val:
                best_val = val
                best_path = [node] + path

        return best_val, best_path


start = 'A'

value, path = minimax(start, True)

print("Optimal Value:", value)
print("Optimal Path:", " → ".join(path))