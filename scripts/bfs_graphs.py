import networkx as nx
import scipy.io as sp
import networkit as nk

## not working -3-
## .mtx files crash

NUM_NODES = 2**20                       
AVG_DEGREE = 16
NUM_EDGES = (NUM_NODES * AVG_DEGREE) // 2

G = nx.gnm_random_graph(NUM_NODES, NUM_EDGES, seed=42)
sparse_mat = nx.to_scipy_sparse_array(G, format='coo')
sp.mmwrite("erdos_renyi.mtx", sparse_mat)

rmat = nk.generators.RmatGenerator(scale = 20, edgeFactor=8, a=0.57, b=0.19, c=0.19, d=0.05)
graph = rmat.generate()
rmat_matrix = nk.algebraic.adjacencyMatrix(graph)
sp.mmwrite("rmat.mtx", rmat_matrix)
