# Alpha-Beta Pruning showing actual pruned subtree

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

pruned_branches = []

def collect_subtree(node):
    """Collect entire subtree rooted at node"""
    nodes = [node]
    for child in graph[node]:
        nodes += collect_subtree(child)
    return nodes


def alphabeta(node, alpha, beta, isMax):

    # Terminal node
    if len(graph[node]) == 0:
        return utility[node], [node]

    if isMax:
        best_val = float('-inf')
        best_path = []

        for i, child in enumerate(graph[node]):
            val, path = alphabeta(child, alpha, beta, False)

            if val > best_val:
                best_val = val
                best_path = [node] + path

            alpha = max(alpha, best_val)

            # PRUNING
            if beta <= alpha:
                # collect all remaining siblings' subtrees
                for rem in graph[node][i+1:]:
                    pruned_branches.append(collect_subtree(rem))
                break

        return best_val, best_path

    else:
        best_val = float('inf')
        best_path = []

        for i, child in enumerate(graph[node]):
            val, path = alphabeta(child, alpha, beta, True)

            if val < best_val:
                best_val = val
                best_path = [node] + path

            beta = min(beta, best_val)

            # PRUNING
            if beta <= alpha:
                for rem in graph[node][i+1:]:
                    pruned_branches.append(collect_subtree(rem))
                break

        return best_val, best_path


value, path = alphabeta('A', float('-inf'), float('inf'), True)

print("Optimal Value:", value)
print("Optimal Path:", " → ".join(path))

print("\nPruned Branch(es):",end="")
for branch in pruned_branches:
    print(" → ".join(branch))