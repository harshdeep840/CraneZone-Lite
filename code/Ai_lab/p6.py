from collections import deque

def bfs_shortest_path(maze, start, end):
    rows, cols = len(maze), len(maze[0])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right
    queue = deque([(start, [start])])  # (current position, path)
    visited = set()
    visited.add(start)
    nodes_explored = 0

    while queue:
        current, path = queue.popleft()
        nodes_explored += 1

        if current == end:
            return path, nodes_explored  # Found the shortest path

        for d in directions:
            new_row, new_col = current[0] + d[0], current[1] + d[1]
            new_pos = (new_row, new_col)

            if 0 <= new_row < rows and 0 <= new_col < cols and maze[new_row][new_col] == 1 and new_pos not in visited:
                visited.add(new_pos)
                queue.append((new_pos, path + [new_pos]))

    return None, nodes_explored  # No path found


def dfs_one_valid_path(maze, start, end):
    rows, cols = len(maze), len(maze[0])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right
    visited = set()
    nodes_explored = 0

    def dfs(current, path):
        nonlocal nodes_explored
        nodes_explored += 1

        if current == end:
            return path  # Found one valid path

        visited.add(current)

        for d in directions:
            new_row, new_col = current[0] + d[0], current[1] + d[1]
            new_pos = (new_row, new_col)

            if 0 <= new_row < rows and 0 <= new_col < cols and maze[new_row][new_col] == 1 and new_pos not in visited:
                result = dfs(new_pos, path + [new_pos])
                if result:
                    return result

        visited.remove(current)  # Backtrack
        return None

    result = dfs(start, [start])
    return result, nodes_explored


# 8x8 Maze Example (1: Walkable, 0: Wall)
maze = [
    [1, 0, 1, 1, 1, 0, 1, 1],
    [1, 0, 1, 0, 1, 0, 1, 0],
    [1, 1, 1, 0, 1, 1, 1, 0],
    [0, 0, 1, 1, 0, 0, 1, 1],
    [1, 1, 0, 1, 1, 1, 0, 1],
    [1, 0, 0, 0, 0, 1, 0, 1],
    [1, 1, 1, 1, 0, 1, 1, 1],
    [0, 0, 0, 1, 1, 1, 0, 1]
]

start = (0, 0)  # Top-left corner
end = (7, 7)    # Bottom-right corner

# Solve using BFS
bfs_path, bfs_nodes_explored = bfs_shortest_path(maze, start, end)

# Solve using DFS
dfs_path, dfs_nodes_explored = dfs_one_valid_path(maze, start, end)

# Results
print("Breadth-First Search (BFS):")
print(f"Shortest Path: {bfs_path}")
print(f"Nodes Explored: {bfs_nodes_explored}")

print("\nDepth-First Search (DFS):")
print(f"One Valid Path: {dfs_path}")
print(f"Nodes Explored: {dfs_nodes_explored}")

# Comparison
if bfs_path:
    print("\nComparison:")
    print(f"BFS explored {bfs_nodes_explored} nodes.")
    print(f"DFS explored {dfs_nodes_explored} nodes.")
else:
    print("No path found in the maze.")
