import numpy as np
import bats
from bats.visualization.plotly import ScatterVisualization
import scipy.spatial.distance as distance


def gen_circle(n, r=1.0, sigma=0.1):
    X = np.random.randn(n,2)
    X = r * X / np.linalg.norm(X, axis=1).reshape(-1,1)
    X += sigma*np.random.randn(n, 2)
    return X

np.random.seed(0)

X = gen_circle(200)

pdist = distance.squareform(distance.pdist(X, 'euclidean'))

R = bats.RipsComplex(bats.Matrix(pdist), 0.25, 2)
fig = ScatterVisualization(R, pos=X)
fig.update_layout(width=600, height=600, showlegend=False)
fig.write_image("figures/rips_circle.png")

f = bats.SimplicialMap(R, R)

R2 = bats.ReducedChainComplex(R, bats.F2())
F2 = bats.Chain(f, bats.F2())
Ftil = bats.InducedMap(F2, R2, R2, 1)
Ftil.tolist() # [[1]]


k = 40
inds, dists = bats.greedy_landmarks_hausdorff(bats.Matrix(pdist), 0)
inds = inds[:k]
eps = dists[k-1]
eps # hausdorff distance from subset to total data set

Xk = X[inds]
pdist_k = np.array(pdist[inds][:,inds], copy=True)
Rk = bats.RipsComplex(bats.Matrix(pdist_k), 0.25 + 2*eps, 2)
fig = ScatterVisualization(Rk, pos=Xk)
fig.update_layout(width=600, height=600, showlegend=False)
fig.write_image("figures/rips_circle_40.png")

from scipy.spatial import cKDTree
tree = cKDTree(Xk)
ds, f0 = tree.query(X, k=1)

f = bats.SimplicialMap(R, Rk, f0)

Rk2 = bats.ReducedChainComplex(Rk, bats.F2())
F2 = bats.Chain(f, bats.F2())
Ftil = bats.InducedMap(F2, R2, Rk2, 1)
Ftil.tolist() # [[0, 1]]

from bats.visualization.plotly import MapVisualization
fig = MapVisualization(pos=(X, Xk), cpx=(R, Rk), maps=(f,))
fig.show_generator(0, color='green', group_suffix=0)
fig.show_generator(1, color='red', group_suffix=1)
fig.write_html('figures/map_circle_vis.html')
