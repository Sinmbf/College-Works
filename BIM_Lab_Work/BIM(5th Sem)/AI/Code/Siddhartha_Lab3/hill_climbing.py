# Hill Climbing Search using Graph

graph = {
    'S':['A', 'D'],
    'A':['B', 'D'],
    'B':['C', 'E'],
    'C':[],
    'D':['A','E'],
    'E':['B','F'],
    'F':['G'],
    'G':[]
     
}

# Heuristic values (lower value = closer to goal F)
h = {
    'S': 10,
    'A': 7.5,
    'B': 6,
    'C': 3,
    'D': 7,
    'E': 6,
    'F': 3,
    'G': 0,
}

def hill_climbing(start, goal):

    current = start
    path = [current]

    print("Traversal:")

    while True:
        print(current, end=" ")

        if current == goal:
            return path

        neighbors = graph[current]

        if not neighbors:
            return path   # local maxima or dead end

        # choose neighbor with minimum heuristic
        next_node = min(neighbors, key=lambda x: h[x])

        # if no improvement, stop
        if h[next_node] >= h[current]:
            return path

        current = next_node
        path.append(current)


start = 'S'
goal = 'G'

path = hill_climbing(start, goal)

print("\nFinal Path:", " → ".join(path))