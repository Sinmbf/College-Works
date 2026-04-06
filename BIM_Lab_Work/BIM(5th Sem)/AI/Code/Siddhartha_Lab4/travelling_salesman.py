from itertools import permutations

def tsp_simple(graph):
    n = len(graph)
    cities = list(range(1, n))  # exclude starting city 0

    min_cost = float('inf')
    best_path = []

    for perm in permutations(cities):
        cost = 0
        current = 0

        # calculate cost of this path
        for city in perm:
            cost += graph[current][city]
            current = city

        cost += graph[current][0]  # return to start

        # update minimum
        if cost < min_cost:
            min_cost = cost
            best_path = [0] + list(perm) + [0]

    return min_cost, best_path


# Graph
graph = [
    [0, 35, 10, 50],
    [35, 0, 50, 20],
    [10, 50, 0, 15],
    [50, 20, 15, 0]
]

# Map indices to city names
city_names = ['A', 'B', 'C', 'D']

cost, path = tsp_simple(graph)

# Convert numeric path to names
named_path = " -> ".join(city_names[i] for i in path)

print("Minimum cost:", cost)
print("Path:", named_path)