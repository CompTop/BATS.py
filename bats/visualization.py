import numpy as np
import matplotlib.pyplot as plt

def pair_to_arr(p):
    return p.birth(), p.death(), p.dim()


def process_pairs(ps, inf_to=None):
    a = []
    for p in ps:
        a.append([*pair_to_arr(p)])
    a = np.array(a)
    return a


def essential_pair_filter(a):
    return np.max(a, axis=1) == np.inf


def non_essential_pair_filter(a, remove_zeros=True):
    lens = a[:,1] - a[:,0]
    f = lens < np.inf
    if remove_zeros:
        return np.logical_and(f, lens > 0)
    else:
        return f


def persistence_diagram(ps, remove_zeros=True, **kwargs):
    fig, ax = plt.subplots(**kwargs)
    a = process_pairs(ps)
    d = np.array(a[:,2], dtype=np.int) # homology dimension
    cs=plt.get_cmap('Set1')(d) # set colors
    eps = essential_pair_filter(a)
    neps = non_essential_pair_filter(a, remove_zeros)
    # plot non-essential pairs
    ax.scatter(a[neps, 0], a[neps, 1], c=cs[neps], marker='o')

    # plot essential pairs
    tmax = np.max(a[eps != True,:1])
    inf_to = tmax * 1.1
    eb = a[eps, 0]
    ed = [inf_to for _ in eb]
    ax.scatter(eb, ed, c=cs[eps], marker='*')

    # set axes
    xbnds = [0, inf_to*1.05]
    ybnds = [0, inf_to*1.05]
    ax.set_xlim((*xbnds))
    ax.set_ylim((*ybnds))
    ax.set_aspect('equal')

    # add visual lines
    ax.plot(xbnds, ybnds, '--k')
    ax.plot([0,tmax], [tmax, tmax], '--r')

    # add labels
    ax.set_xlabel("Birth")
    ax.set_ylabel("Death")
    return fig, ax
