from collections import deque

MAX_NODES = 100
graph = [[0] * MAX_NODES for _ in range(MAX_NODES)]

visited = [False] * MAX_NODES

def bfs(start_node, num_nodes):

    queue = deque([start_node])
    visited[start_node] = True

    while queue:
        node = queue.popleft()  
        print(node, end=" ")

        for i in range(num_nodes):
            if graph[node][i] == 1 and not visited[i]: 
                queue.append(i)
                visited[i] = True  


def main():

    num_nodes = int(input("Enter the number of nodes: "))
    
    num_edges = int(input("Enter the number of edges: "))
    
    for _ in range(num_edges):
        u, v = map(int, input("Enter an edge (node1 node2): ").split())
        if u < num_nodes and v < num_nodes:
            graph[u][v] = 1
            graph[v][u] = 1  
        else:
            print(f"Invalid edge: nodes should be between 0 and {num_nodes - 1}.")
    
    start_node = int(input(f"Enter the starting node for BFS (0 to {num_nodes - 1}): "))
    if start_node < 0 or start_node >= num_nodes:
        print("Invalid start node.")
        return
    
    global visited
    visited = [False] * num_nodes

    print("BFS traversal order: ", end="")
    bfs(start_node, num_nodes)
    print()

if __name__ == "__main__":
    main()
