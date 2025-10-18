import heapq
import matplotlib.pyplot as plt
import time

def manhattan_distance(node, goal):
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])

def euclidean_distance(node, goal):
    return ((node[0] - goal[0]) ** 2 + (node[1] - goal[1]) ** 2) ** 0.5

def get_neighbors(grid, node, allow_diagonal=False):
    x, y = node
    rows, cols = len(grid), len(grid[0])
    neighbors = []
    moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    if allow_diagonal:
        moves += [(1, 1), (1, -1), (-1, 1), (-1, -1)]
    for dx, dy in moves:
        nx, ny = x + dx, y + dy
        if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == 0:
            neighbors.append((nx, ny))
    return neighbors

def astar(grid, start, goal, heuristic=manhattan_distance, allow_diagonal=False):
    open_set = [(0, start, [])]  # (f_score, node, path)
    closed_set = set()
    nodes_visited = 0

    while open_set:
        f_score, current_node, path = heapq.heappop(open_set)
        nodes_visited += 1

        if current_node == goal:
            return path + [current_node], nodes_visited

        if current_node in closed_set:
            continue
        closed_set.add(current_node)

        for neighbor in get_neighbors(grid, current_node, allow_diagonal):
            if neighbor in closed_set:
                continue
            new_path = path + [current_node]
            g_score = len(new_path)  # Cost is just the path length
            h_score = heuristic(neighbor, goal)
            f_score = g_score + h_score
            heapq.heappush(open_set, (f_score, neighbor, new_path))

    return None, nodes_visited

def bfs(grid, start, goal):
    queue = [(start, [start])]
    visited = set()
    nodes_visited = 0

    while queue:
        node, path = queue.pop(0)
        nodes_visited += 1

        if node == goal:
            return path, nodes_visited

        visited.add(node)

        for neighbor in get_neighbors(grid, node):
            if neighbor not in visited:
                queue.append((neighbor, path + [neighbor]))

    return None, nodes_visited

def uniform_cost_search(grid, start, goal):
    queue = [(0, start, [start])]  # (cost, node, path)
    visited = set()
    nodes_visited = 0

    while queue:
        cost, node, path = heapq.heappop(queue)
        nodes_visited += 1

        if node == goal:
            return path, nodes_visited

        if node in visited:
            continue
        visited.add(node)

        for neighbor in get_neighbors(grid, node):
            new_cost = cost + 1
            heapq.heappush(queue, (new_cost, neighbor, path + [neighbor]))

    return None, nodes_visited

def plot_grid_and_path(grid, path=None, start=None, goal=None, algorithm_name="A*"):
    plt.imshow(grid, cmap='gray_r', origin='upper')
    plt.title(f"Path found by {algorithm_name}")
    if start:
        plt.scatter(start[1], start[0], color='green', marker='o', s=200, label='Start')
    if goal:
        plt.scatter(goal[1], goal[0], color='red', marker='x', s=200, label='Goal')
    if path:
        path_x, path_y = zip(*path)
        plt.plot(path_y, path_x, color='blue', linewidth=2, marker='o', markersize=5, label='Path')
    plt.legend()
    plt.show()

if __name__ == '__main__':
    grid = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]

    start = (0, 0)
    goal = (9, 9)

    # A* with Manhattan
    start_time = time.time()
    path_astar_manhattan, nodes_visited_astar_manhattan = astar(grid, start, goal, heuristic=manhattan_distance)
    end_time = time.time()
    execution_time_astar_manhattan = end_time - start_time

    print("A* with Manhattan:")
    if path_astar_manhattan:
        print("Path:", path_astar_manhattan)
        print("Nodes visited:", nodes_visited_astar_manhattan)
        print(f"Execution time: {execution_time_astar_manhattan:.4f} seconds")
        plot_grid_and_path(grid, path_astar_manhattan, start, goal, algorithm_name="A* Manhattan")
    else:
        print("No path found.")

    # A* with Euclidean (diagonal)
    start_time = time.time()
    path_astar_euclidean, nodes_visited_astar_euclidean = astar(grid, start, goal, heuristic=euclidean_distance, allow_diagonal=True)
    end_time = time.time()
    execution_time_astar_euclidean = end_time - start_time

    print("\nA* with Euclidean (diagonal):")
    if path_astar_euclidean:
        print("Path:", path_astar_euclidean)
        print("Nodes visited:", nodes_visited_astar_euclidean)
        print(f"Execution time: {execution_time_astar_euclidean:.4f} seconds")
        plot_grid_and_path(grid, path_astar_euclidean, start, goal, algorithm_name="A* Euclidean")
    else:
        print("No path found.")

    # BFS
    start_time = time.time()
    path_bfs, nodes_visited_bfs = bfs(grid, start, goal)
    end_time = time.time()
    execution_time_bfs = end_time - start_time

    print("\nBFS:")
    if path_bfs:
        print("Path:", path_bfs)
        print("Nodes visited:", nodes_visited_bfs)
        print(f"Execution time: {execution_time_bfs:.4f} seconds")
        plot_grid_and_path(grid, path_bfs, start, goal, algorithm_name="BFS")
    else:
        print("No path found.")

    # Uniform Cost Search
    start_time = time.time()
    path_ucs, nodes_visited_ucs = uniform_cost_search(grid, start, goal)
    end_time = time.time()
    execution_time_ucs = end_time - start_time

    print("\nUniform Cost Search:")
    if path_ucs:
        print("Path:", path_ucs)
        print("Nodes visited:", nodes_visited_ucs)
        print(f"Execution time: {execution_time_ucs:.4f} seconds")
        plot_grid_and_path(grid, path_ucs, start, goal, algorithm_name="Uniform Cost Search")
    else:
        print("No path found.")
