import heapq
from collections import deque

class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, start, end, cost):
        if start not in self.graph: 
        self.graph[start].append((end, cost))
        if end not in self.graph:
            self.graph[end] = []
        self.graph[end].append((start, cost))  # Assuming undirected graph

    def uniform_cost_search(self, start, goal):
        priority_queue = []
        heapq.heappush(priority_queue, (0, start, []))  # (Cost, Node, Path)
        visited = set()

        while priority_queue:
            current_cost, current_node, path = heapq.heappop(priority_queue)
            
            if current_node in visited:
                continue

            visited.add(current_node)
            path = path + [current_node]

            if current_node == goal:
                return current_cost, path

            for neighbor, cost in self.graph.get(current_node, []):
                if neighbor not in visited:
                    heapq.heappush(priority_queue, (current_cost + cost, neighbor, path))

        return float('inf'), []  # No path found

    def bfs_unweighted(self, start, goal):
        queue = deque([(start, [start])])  # (Node, Path)
        visited = set()

        while queue:
            current_node, path = queue.popleft()

            if current_node == goal:
                return len(path) - 1, path  # Path length is equivalent to cost in unweighted

            if current_node in visited:
                continue

            visited.add(current_node)

            for neighbor, _ in self.graph.get(current_node, []):
                if neighbor not in visited:
                    queue.append((neighbor, path + [neighbor]))

        return float('inf'), []  # No path found


# Example Usage
graph = Graph()

# Add edges (start, end, cost)
edges = [
    ('A', 'B', 1), ('A', 'C', 4), ('B', 'D', 2), 
    ('C', 'D', 1), ('B', 'E', 7), ('D', 'E', 3)
]

for edge in edges:
    graph.add_edge(*edge)

# Find optimal path using UCS
ucs_cost, ucs_path = graph.uniform_cost_search('A', 'E')
print(f"Uniform Cost Search: Cost = {ucs_cost}, Path = {ucs_path}")

# Find path using BFS for unweighted graph
bfs_cost, bfs_path = graph.bfs_unweighted('A', 'E')
print(f"Breadth-First Search (Unweighted): Cost = {bfs_cost}, Path = {bfs_path}")
