class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, start, end):
        """Add an edge from start to end."""
        if start not in self.graph:
            self.graph[start] = []
        self.graph[start].append(end)

    def depth_limited_search(self, start, goal, depth_limit):
        """Perform Depth-Limited Search."""
        def dls(node, depth):
            print(f"Visiting Node: {node}, Depth: {depth}")
            if node == goal:
                return True
            if depth == 0:
                return False
            for neighbor in self.graph.get(node, []):
                if dls(neighbor, depth - 1):
                    return True
            return False

        return dls(start, depth_limit)


# Example Usage
if __name__ == "__main__":
    g = Graph()
    g.add_edge('A', 'B')
    g.add_edge('A', 'C')
    g.add_edge('B', 'D')
    g.add_edge('B', 'E')
    g.add_edge('C', 'F')
    g.add_edge('C', 'G')

    start_node = 'A'
    goal_node = 'E'
    depth_limit = 2

    found = g.depth_limited_search(start_node, goal_node, depth_limit)
    if found:
        print(f"Goal node {goal_node} found within depth {depth_limit}.")
    else:
        print(f"Goal node {goal_node} not found within depth {depth_limit}.")
