def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()  # Initialize the visited set if it's not passed
        
    # Mark the current node as visited and process it (e.g., print it)
    visited.add(start)
    print(start, end=" ")

    # Visit all the unvisited neighbors of the current node
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)  # Recursively call DFS on the neighbor

# Example graph (adjacency list representation)
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'G'],
    'F': ['C'],
    'G': ['E']
}

start = 'A'
dfs(graph, start)
