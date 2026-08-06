import random

# Initial population
population = ["1010", "1100", "1001", "0111"]

# Fitness function
def fitness(chromosome):
    return chromosome.count("1")

print("Initial Population:", population)

# Run for 3 generations
for generation in range(3):

    # Select the best two chromosomes
    population.sort(key=fitness, reverse=True)
    parent1 = population[0]
    parent2 = population[1]

    # Crossover
    child1 = parent1[:2] + parent2[2:]
    child2 = parent2[:2] + parent1[2:]

    # Mutation on Child 1
    child = list(child1)
    index = random.randint(0, 3)
    child[index] = '1' if child[index] == '0' else '0'
    child1 = "".join(child)

    # New population
    population = [parent1, parent2, child1, child2]

    print("\nGeneration", generation + 1)
    print("Parents :", parent1, ",", parent2)
    print("Children:", child1, ",", child2)
    print("Population:", population)

# Final result
best = max(population, key=fitness)

print("\nBest Chromosome:", best)
print("Fitness:", fitness(best))