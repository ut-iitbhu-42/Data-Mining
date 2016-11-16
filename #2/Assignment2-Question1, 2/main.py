from GraphAlgo.GraphAlgo import *
from KSquareTree.KSquareTree import KSquareTree


graph = [[0, 1, 1, 1],
         [1, 0, 0, 1],
         [1, 0, 0, 0],
         [1, 1, 0, 0]]

k2tree = KSquareTree(2)
k2tree.create(graph)

print bfs(k2tree, 0, 3)
print bron_kerbosch(k2tree)
print mst(k2tree)
print shortest_path(k2tree, 0)
print betweeness_centrality(k2tree)
print global_cluster_coeff(k2tree)
