class GNode:
    def __init__(self, id):
        self.id = id
        self.parent = None
        self.color = 'W'
    def __str__(self):
        return self.id
    
def paths(G, s, t):
    result_list = []
    if s == t:
        result_list.append([s])
        return result_list

    def __pathHelp(G, s, t, lst = [s], biglist = []):
        for n in G[s]:
            __pathHelp(G, n, t, lst + [n], biglist)
        if s == t:
            biglist.append(lst)
        return biglist
    
    result_list = __pathHelp(G, s, t)
    return result_list

a, b, c, d = GNode("a"), GNode("b"),GNode("c"),GNode("d")
G = dict()
G[a],G[b],G[c],G[d] = [b, c], [d], [], [c]
p = paths(G, a, c)
for path in p:
    for v in path:
        print(v, end = ' ')
    print()