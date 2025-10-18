import heapq

# Define Manhattan Distance Heuristic
def manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

# Best-First Search Algorithm
def best_first_search(grid, start, treasure):
    rows, cols = len(grid), len(grid[0])
    start_x, start_y = start
    treasure_x, treasure_y = treasure

    # Priority queue to store cells with their heuristic values
    priority_queue = []
    heapq.heappush(priority_queue, (0, start_x, start_y))  # (Heuristic, x, y)

    visited = set()
    visited.add((start_x, start_y))

    # Path to store the steps taken
    path = []

    while priority_queue:
        # Pop the cell with the smallest heuristic value
        _, current_x, current_y = heapq.heappop(priority_queue)
        path.append((current_x, current_y))

        # If the treasure is found
        if (current_x, current_y) == (treasure_x, treasure_y):
            print(f"Treasure found at {current_x, current_y}!")
            return path

        # Check neighbors (up, down, left, right)
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            neighbor_x, neighbor_y = current_x + dx, current_y + dy

            # Ensure the neighbor is within bounds and not visited
            if 0 <= neighbor_x < rows and 0 <= neighbor_y < cols and (neighbor_x, neighbor_y) not in visited:
                visited.add((neighbor_x, neighbor_y))
                heuristic = manhattan_distance(neighbor_x, neighbor_y, treasure_x, treasure_y)
                heapq.heappush(priority_queue, (heuristic, neighbor_x, neighbor_y))

    print("Treasure not found.")
    return path

# Example Usage
# Define a 5x5 grid (0 for empty cells, 1 for obstacles)
grid = [
    [0, 0, 0, 0, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 0, 0, 0, 0],
]

# Start position and treasure position
start = (0, 0)       # Top-left corner
treasure = (4, 4)    # Bottom-right corner

# Run the Best-First Search
path = best_first_search(grid, start, treasure)
print("Path taken:", path)
