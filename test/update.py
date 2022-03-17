import bats
import numpy as np
import scipy.spatial.distance as distance

# first, generate a noisy circle
np.random.seed(0)

n = 50
X = np.random.normal(size=(n,2))
X = X / np.linalg.norm(X, axis=1).reshape(-1,1)
X = X + np.random.normal(size=(n,2), scale = 0.1 )

# add some noise to the original datasets
# to create a similar datasets to show the performance of update persistence
X2 = X + np.random.normal(size=(n,2), scale = 0.001)

# get original reduced complex
D = distance.squareform(distance.pdist(X))
# r_enc = bats.enclosing_radius(bats.Matrix(D))
r_enc = np.inf
F_X = bats.LightRipsFiltration(bats.Matrix(D), r_enc, 2)
RC = bats.FilteredF2DGVectorSpace(F_X, +1)
R_enc = bats.ReducedFilteredF2DGVectorSpace(RC)

D2 = distance.squareform(distance.pdist(X2))
# r_enc2 = bats.enclosing_radius(bats.Matrix(D2))
r_enc2 = np.inf
F_Y = bats.LightRipsFiltration(bats.Matrix(D2), r_enc2, 2) # generate a RipsFiltration
UI = bats.UpdateInfoLightFiltration(F_X, F_Y) # find updating information
R_enc.update_filtration_general(UI)

ps = R_enc.persistence_pairs(0) + R_enc.persistence_pairs(1)
for p in ps:
    if p.length() > 0.5:
        print(p)

R2 = bats.reduce(F_Y, bats.F2())
ps2 = R2.persistence_pairs(0) + R2.persistence_pairs(1)
for p in ps2:
    if p.length() > 0.5:
        print(p)
