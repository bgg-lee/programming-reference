from typing import List
def P2(n: int, edges: List[tuple]) -> int:
    ##### Write your Code Here #####
    
    class AdjNode:
        def __init__(self, data):
            self.vertex = data
            self.next = None

    class Graph:
        def __init__(self, vertices:int): # 그래프 요소 수
            self.V = vertices
            self.graph = [None] * self.V

        def add_edge(self, src, dest):
            node = AdjNode(dest)
            node.next = self.graph[src-1]
#             self.graph[src-1] = node
            self.graph[src-1] = node

            node = AdjNode(src)
            node.next = self.graph[dest-1]
#             self.graph[dest-1] = node
            self.graph[dest-1] = node

#         def print_graph(self):
#             for i in range(self.V):
#                 print("Adjacency list of vertex {}\n head".format(i+1), end="")
#                 temp = self.graph[i]
#                 while temp:
#                     print(" -> {}".format(temp.vertex), end="")
#                     temp = temp.next
#                 print(" \n")
                
        def cluster_withone(self):
            final = []
            for i in range(self.V):
                lst = []
                lst.append(i+1)
                temp = self.graph[i]
                while temp:
                    lst.append(temp.vertex)
                    temp = temp.next
                if 1 in lst:
                    final += lst
            return final      
    
    graph = Graph(n)
    for x,y in edges:
        graph.add_edge(x,y)
           
#     graph.print_graph()

    ans = list(set(graph.cluster_withone()))
#     print(ans)
    return len(ans)
     
    ##### End of your code #####