import bats
import numpy as np
import matplotlib.pyplot as plt

# generate image
m = 100
n = 100
A = np.empty((m,n))
for i in range(m):
    for j in range(n):
        A[i,j] = np.sin(i/10) * np.cos(j/10)
plt.imshow(A)
plt.savefig('figures/cubical_image.png')


def to_toplexes(A):
    """
    Create list of toplexes from boolean array A

    assume 2-dimensional for now
    """
    dims = A.shape
    toplex_list = []
    for i in range(dims[0]-1):
        for j in range(dims[1]-1):
            if (A[i,j] and A[i+1,j] and A[i,j+1] and A[i+1,j+1]):
                toplex_list.append([i,i+1,j,j+1])

    return toplex_list

def image_to_complex(A):
    """
    Create cubical complex from boolean image A
    """
    toplex_list = to_toplexes(A)
    X = bats.CubicalComplex(2)
    for t in toplex_list:
        X.add_toplex(t)
    return X

lsets = [[x/10, (x+2)/10] for x in range(-10,9,1)]

# create diagram of cubical complexes
D = bats.CubicalComplexDiagram()
for i in range(len(lsets)):
    lb = lsets[i][0]
    ub = lsets[i][1]
    AL = np.logical_and(lb < A, A < ub)
    ii = D.add_node(image_to_complex(AL))

    if i != 0:
        # add edge to previous union
        D.add_edge(ii, ii-1, bats.CubicalMap(D.node_data(ii), D.node_data(ii-1)))

    if i != len(lsets)-1:
        # add node for union
        ub = lsets[i+1][1]
        AL = np.logical_and(lb < A, A < ub)
        D.add_node(image_to_complex(AL))

        # add edge to union
        D.add_edge(ii, ii+1, bats.CubicalMap(D.node_data(ii), D.node_data(ii+1)))

FD = bats.Chain(D, bats.F2())

ps = []
for hdim in range(2):
    RD = bats.Hom(FD, hdim)
    ps.extend(bats.barcode(RD, hdim))

fig, ax = bats.visualization.persistence_barcode(ps)
fig.savefig('figures/cubical_levelset_zz.png')
