from queue import PriorityQueue

# Graph with edge costs
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 3), ('E', 1)],
    'C': [('F', 5)],
    'D': [],
    'E': [('F', 2)],
    'F': []
}

# Heuristic values (estimate to goal F)
h = {
    'A': 7,
    'B': 6,
    'C': 2,
    'D': 3,
    'E': 1,
    'F': 0
}

def astar(start, goal):

    open_list = PriorityQueue()
    open_list.put((h[start], start))

    parent = {start: None}
    g_cost = {start: 0}

    visited = set()

    print("Traversal:")

    while not open_list.empty():

        f, node = open_list.get()

        if node in visited:
            continue

        print(node, end=" ")
        visited.add(node)

        if node == goal:
            break

        for child, cost in graph[node]:

            new_g = g_cost[node] + cost
            new_f = new_g + h[child]

            if child not in g_cost or new_g < g_cost[child]:
                g_cost[child] = new_g
                parent[child] = node
                open_list.put((new_f, child))

    # Construct Final Path
    path = []
    current = goal

    while current is not None:
        path.append(current)
        current = parent[current]

    path.reverse()

    return path, g_cost[goal]


start = 'A'
goal = 'F'

path, cost = astar(start, goal)

print("\nFinal Path:", " → ".join(path))
print("Total Cost:", cost)