class GNode:
    def __init__(self, id, color='W', d = 0, p = None):
        self.id = id
        self.color = color
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id
    
    
def bfs(G, s):
    queue = []
    queue.append(s)
    visit_list = []
    for key in G.keys():
        key.distance = len(G) + 100
    
    s.distance = 0
    while len(queue)!=0:
        curr = queue.pop(0)
        if curr.color == 'W':
            visit_list.append(curr) ## it is a Visit Action!
            curr.color = 'B'
            for n in G[curr]:
                if n.color == 'W' and n.distance > curr.distance + 1:
                    n.parent = curr
                    n.distance = curr.distance + 1
                queue.append(n)
                    
    return visit_list
            
def level_partition(G, s):
    visit_list = bfs(G, s)
    level_dict = {}
    result_list = []
    
    for v in visit_list:
        if v.distance not in level_dict:
            level_dict[v.distance] = []
        level_dict[v.distance].append(v)
    
    keys = level_dict.keys()
    keys = sorted(keys)
    for k in keys:
        result_list.append(level_dict[k])
        print(f"level_dict[k] = {[n.id for n in level_dict[k]]}")
    return result_list


r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
G = dict()
G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

level_partition(G, s)