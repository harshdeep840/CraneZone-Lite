import networkx as nx  
import matplotlib.pyplot as plt 
from collections import deque

# Bi-Directional BFS Implementation
def bidirectional_bfs(graph, start, goal):
    if start == goal:
        return [start]

    # Queues for BFS from start and goal
    queue_start = deque([start])
    queue_goal = deque([goal])

    # Visited dictionaries to track paths
    visited_start = {start: None}
    visited_goal = {goal: None}

    while queue_start and queue_goal:
        # Expand from the start side
        if queue_start:
            node = queue_start.popleft()
            for neighbor in graph[node]:
                if neighbor not in visited_start:
                    visited_start[neighbor] = node
                    queue_start.append(neighbor)
                    if neighbor in visited_goal:  # Intersection found
                        return reconstruct_path(visited_start, visited_goal, neighbor)

        # Expand from the goal side
        if queue_goal:
            node = queue_goal.popleft()
            for neighbor in graph[node]:
                if neighbor not in visited_goal:
                    visited_goal[neighbor] = node
                    queue_goal.append(neighbor)
                    if neighbor in visited_start:  # Intersection found
                        return reconstruct_path(visited_start, visited_goal, neighbor)

    return None  # No path exists


# Helper function to reconstruct the path
def reconstruct_path(visited_start, visited_goal, meeting_point):
    path = []

    # Trace back from the meeting point to the start
    current = meeting_point
    while current is not None:
        path.append(current)
        current = visited_start[current]
    path.reverse()

    # Trace forward from the meeting point to the goal
    current = visited_goal[meeting_point]
    while current is not None:
        path.append(current)
        current = visited_goal[current]

    return path


# Standard BFS for comparison
def bfs(graph, start, goal):
    queue = deque([(start, [start])])
    visited = set()

    while queue:
        node, path = queue.popleft()
        if node == goal:
            return path
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                queue.append((neighbor, path + [neighbor]))

    return None


# DFS for comparison
def dfs(graph, start, goal, visited=None, path=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []

    visited.add(start)
    path.append(start)

    if start == goal:
        return path

    for neighbor in graph[start]:
        if neighbor not in visited:
            result = dfs(graph, neighbor, goal, visited, path)
            if result:
                return result

    path.pop()
    return None


# Visualization using NetworkX
def visualize(graph, path, title):
    G = nx.Graph()
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            G.add_edge(node, neighbor)

    pos = nx.spring_layout(G)
    plt.figure(figsize=(8, 6))
    nx.draw(G, pos, with_labels=True, node_color="lightblue", node_size=500, edge_color="gray")
    if path:
        path_edges = [(path[i], path[i + 1]) for i in range(len(path) - 1)]
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color="red", width=2)
    plt.title(title)
    plt.show()


# Example usage
def main():
    # City map represented as a graph (adjacency list)
    city_map = {
        0: [1, 2],
        1: [0, 3, 4],
        2: [0, 5],
        3: [1, 6],
        4: [1, 6],
        5: [2, 6],
        6: [3, 4, 5],
    }

    start = 0
    goal = 6

    # Bi-Directional BFS
    path_bidirectional = bidirectional_bfs(city_map, start, goal)
    print("Bi-Directional BFS Path:", path_bidirectional)
    visualize(city_map, path_bidirectional, "Bi-Directional BFS")

    # Standard BFS
    path_bfs = bfs(city_map, start, goal)
    print("Standard BFS Path:", path_bfs)
    visualize(city_map, path_bfs, "Standard BFS")

    # DFS
    path_dfs = dfs(city_map, start, goal)
    print("DFS Path:", path_dfs)
    visualize(city_map, path_dfs, "DFS")


if __name__ == "__main__":
    main()
