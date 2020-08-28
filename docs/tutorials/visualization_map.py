import numpy as np
import bats
from bats.visualization.plotly import MapVisualization
import scipy.spatial.distance as distance

np.random.seed(0)

def gen_cylinder(n, r=1.0, sigma=0.1):
    X = np.random.randn(n,2)
    X = r * X / np.linalg.norm(X, axis=1).reshape(-1,1)
    X = np.hstack((X, r*np.random.rand(n,1) - r/2))
    return X

X = gen_cylinder(500)

pdist = distance.squareform(distance.pdist(X, 'euclidean'))
R = bats.RipsComplex(bats.Matrix(pdist), 0.25, 2)

inds = np.where(X[:,2] < 0)[0]
Xi = X[inds]
pdisti = distance.squareform(distance.pdist(Xi, 'euclidean'))
Ri = bats.RipsComplex(bats.Matrix(pdisti), 0.25, 2)

M = bats.SimplicialMap(Ri, R, inds)

fig = MapVisualization(pos=(Xi,X), cpx=(Ri,R), maps=(M,))
fig.update_layout(scene_aspectmode='manual',
                  scene_aspectratio=dict(x=1, y=1, z=0.5))
fig.write_html('figures/map0.html')

fig.reset()
fig.show_generator(1)
fig.write_html('figures/map_gen.html')

fig.reset()
fig.show_generator(5, group_suffix=0)
fig.show_generator(3, color='orange', hcolor='black', group_suffix=1)
fig.write_html('figures/map_gen2.html')
