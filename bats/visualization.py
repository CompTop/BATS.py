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


def persistence_diagram(ps, remove_zeros=True, show_legend=True, **kwargs):
    fig, ax = plt.subplots(**kwargs)
    a = process_pairs(ps)
    dims = np.array(a[:,2], dtype=np.int) # homology dimension
    cs=plt.get_cmap('Set1')(dims) # set colors

    eps = essential_pair_filter(a)
    tmax = np.max(a[eps != True,:1])
    inf_to = tmax * 1.1

    # loop over dimensions
    maxdim = np.max(dims)
    for d in range(maxdim+1):
        dinds = dims == d
        ad = a[dinds]
        cd = cs[dinds]

        eps = essential_pair_filter(ad)
        neps = non_essential_pair_filter(ad, remove_zeros)
        # plot non-essential pairs
        ax.scatter(ad[neps, 0], ad[neps, 1], c=cd[neps], marker='o', label="H{}".format(d))

        # plot essential pairs
        eps = essential_pair_filter(ad)
        eb = ad[eps, 0]
        ed = [inf_to for _ in eb]
        ax.scatter(eb, ed, c=cd[eps], marker='*')

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

    if show_legend:
        ax.legend(loc='lower right')

    return fig, ax
