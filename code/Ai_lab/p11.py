import heapq
import numpy as np

class PuzzleState:
    def __init__(self, board, parent=None, move=None, depth=0, cost=0):
        self.board = board
        self.parent = parent
        self.move = move
        self.depth = depth
        self.cost = cost
    
    def __lt__(self, other):
        return self.cost < other.cost

def misplaced_tiles(state, goal):
    return np.sum(state.board != goal) - 1  # Exclude the blank tile

def manhattan_distance(state, goal):
    distance = 0
    for num in range(1, 9):  # Exclude the blank tile (0)
        x1, y1 = np.argwhere(state.board == num)[0]
        x2, y2 = np.argwhere(goal == num)[0]
        distance += abs(x1 - x2) + abs(y1 - y2)
    return distance

def get_neighbors(state):
    x, y = np.argwhere(state.board == 0)[0]  # Locate the blank tile
    moves = {"Up": (-1, 0), "Down": (1, 0), "Left": (0, -1), "Right": (0, 1)}
    
    neighbors = []
    for move, (dx, dy) in moves.items():
        nx, ny = x + dx, y + dy
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_board = state.board.copy()
            new_board[x, y], new_board[nx, ny] = new_board[nx, ny], new_board[x, y]
            neighbors.append(PuzzleState(new_board, state, move, state.depth + 1))
    return neighbors

def a_star(initial, goal, heuristic):
    open_list = [(0, initial)]
    visited = set()
    nodes_explored = 0
    
    while open_list:
        _, current = heapq.heappop(open_list)
        nodes_explored += 1
        
        if np.array_equal(current.board, goal):
            return current, nodes_explored
        
        visited.add(tuple(current.board.flatten()))
        for neighbor in get_neighbors(current):
            if tuple(neighbor.board.flatten()) in visited:
                continue
            neighbor.cost = neighbor.depth + heuristic(neighbor, goal)
            heapq.heappush(open_list, (neighbor.cost, neighbor))
    
    return None, nodes_explored

def print_solution(solution):
    path = []
    while solution:
        path.append(solution.board)
        solution = solution.parent
    
    for step in reversed(path):
        print(step, "\n")

# Define goal and initial states
goal_state = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 0]])
initial_state = np.array([[1, 2, 3], [4, 0, 6], [7, 5, 8]])

initial_puzzle = PuzzleState(initial_state)

# Solve using misplaced tiles heuristic
sol1, nodes1 = a_star(initial_puzzle, goal_state, misplaced_tiles)
print("Solution using misplaced tiles heuristic:")
print_solution(sol1)
print("Nodes explored:", nodes1)

# Solve using Manhattan distance heuristic
sol2, nodes2 = a_star(initial_puzzle, goal_state, manhattan_distance)
print("\nSolution using Manhattan distance heuristic:")
print_solution(sol2)
print("Nodes explored:", nodes2)