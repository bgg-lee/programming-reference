class GNode:
    def __init__(self, id, color="W", p=None):
        self.id = id
        self.color = color
        self.parent = p
    def __str__(self):
        return self.id
    
    def __hash__(self):
        return hash(self.id)
    
def find_root_vertices(G):
    root_list = []
    for key in G.keys(): # for every node, test if is a root node.
        
        for tempkey in G.keys(): # convert to 'not visit' state.
            tempkey.color = 'W'
        
        # bfs algorithm start
        queue = []
        queue.append(key)
        while len(queue)!=0:
            curr = queue.pop()
            if curr.color=='W':
                curr.color = 'B'
                for v in G[curr]:
                    queue.append(v)
        
        # check if every color is black
        allblack = True
        for tempkey in G.keys():
            if tempkey.color!='B':
                allblack = False
                break
        
        if allblack:
            root_list.append(key)
    
    root_list = [r.id for r in root_list]
    return root_list
        
        
    
      

# A, B, C = GNode('A'), GNode('B'), GNode('C')
# D, E, F = GNode('D'), GNode('E'), GNode('F')
# G = dict()
# G[A], G[B], G[C] = [C, D], [A, E], [B, D]
# G[D], G[E], G[F] = [F], [F], []
# G[A], G[B], G[C] = [D], [E], [B, D]
# G[D], G[E], G[F] = [F], [F], []

# print(find_root_vertices(G))