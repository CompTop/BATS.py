import numpy as np
import matplotlib.pyplot as plt

def pair_to_arr(p):
    return p.birth(), p.death(), p.dim()


def process_pairs(ps, remove_zeros=True):
    a = []
    for p in ps:
        a.append([*pair_to_arr(p)])
    a = np.array(a)
    lens = a[:,1] - a[:,0]
    if remove_zeros:
        a = a[lens > 0]
    return a


def essential_pair_filter(a, tub=np.inf):
    """
    tub - upper bound on what will be displayed
    """
    return np.max(a, axis=1) >= tub


def non_essential_pair_filter(a, tub=np.inf):
    """
    tub - upper bound on what will be displayed
    """
    lens = np.abs(a[:,1] - a[:,0])
    f = lens < tub
    return f


def persistence_diagram(ps, remove_zeros=True, show_legend=True, tmax=0.0, tmin=0.0, **kwargs):
    fig, ax = plt.subplots(**kwargs)
    a = process_pairs(ps, remove_zeros)
    dims = np.array(a[:,2], dtype=np.int) # homology dimension
    cs=plt.get_cmap('Set1')(dims) # set colors

    eps = essential_pair_filter(a)
    tmax = np.max((tmax, np.max(a[eps != True,:2])))
    tmin = np.min((tmin, np.min(a[eps != True,:2])))
    inf_to = tmax * 1.1
    minf_to = tmin * 1.1

    # set axes
    xbnds = (minf_to*1.05, inf_to*1.05)
    ybnds = (minf_to*1.05, inf_to*1.05)
    ax.set_xlim(xbnds)
    ax.set_ylim(ybnds)
    ax.set_aspect('equal')

    # add visual lines
    ax.plot(xbnds, ybnds, '--k')
    ax.plot([minf_to*1.05,tmax], [tmax, tmax], '--r')

    # add labels
    ax.set_xlabel("Birth")
    ax.set_ylabel("Death")

    # loop over dimensions
    maxdim = np.max(dims)
    for d in range(maxdim+1):
        dinds = dims == d
        ad = a[dinds]
        cd = cs[dinds]

        eps = essential_pair_filter(ad, remove_zeros)
        neps = non_essential_pair_filter(ad)
        # plot non-essential pairs
        ax.scatter(ad[neps, 0], ad[neps, 1], c=cd[neps], marker='o', label="H{}".format(d))

        # plot essential pairs
        eps = essential_pair_filter(ad)
        eb = ad[eps, 0]
        ed = [inf_to for _ in eb]
        ax.scatter(eb, ed, c=cd[eps], marker='*')





    if show_legend:
        ax.legend(loc='lower right')

    return fig, ax


def persistence_barcode(ps, remove_zeros=True, tlb=0.0, tub=np.inf, essential_color=None, figargs={}, lineargs={"linewidth":1}):
    """
    plot a persistence barcode for pairs in ps.
    Each barcode is a pyplot axis.
    Barcodes are stacked horizontally in figure.

    Parameters:

        ps: List of PersistencePair

        remove_zeros: flag to remove zero-length bars (default: True)

        tlb: lower bound on filtration parameter to display.  (default: 0.0)

        tlb: upper bound on filtration parameter to display.  (default: inf)

        essential_color: color for essential pairs (defualt: 'r')

        figargs - passed onto pyplot subplots construction (default {})

        lineargs - passed onto hlines construction (default {"linewidth":1})

    Returns:
        fig, ax - pyplot figure and axes
    """
    a = process_pairs(ps, remove_zeros)
    dims = np.array(a[:,2], dtype=np.int) # homology dimension

    if tub==np.inf:
        tub = np.max(a[:,1] * 1.1)

    inf_to = tub * 1.1
    ar_to = tub

    # loop over dimensions
    maxdim = np.max(dims)
    fig, ax = plt.subplots(nrows=(maxdim+1), ncols=1, sharex=True, **figargs)
    if maxdim == 0:
        ax = [ax]

    for d in range(maxdim+1):
        dinds = dims == d
        ad = a[dinds]
        ys = np.array([i for i in reversed(range(len(ad)))])

        eps = essential_pair_filter(ad, tub)
        neps = non_essential_pair_filter(ad, tub)

        # plot non-essential pairs
        if 'colors' not in lineargs:
            lineargs['colors'] = 'b'
        ax[d].hlines(ys[neps], ad[neps, 0], ad[neps, 1], **lineargs)

        # plot essential pairs
        eb = ad[eps, 0]
        ed = [inf_to for _ in eb]
#         for y, b in zip(ys[eps], eb):
#             print("arrow")
#             ax[d].arrow(b, y, ar_to - b, 0, head_width=10, head_length=0.5, length_includes_head=True, fc='k', ec='k')
        if essential_color is None:
            lineargs['colors'] = 'r'
        else:
            lineargs['colors'] = essential_color
        ax[d].hlines(ys[eps], eb, ed, **lineargs)

        # remove labels from y axis
        ax[d].get_yaxis().set_ticks([])
        ax[d].set_ylabel(r"$H_{}$".format(d), rotation=45)

        ax[d].set_xlim((0, inf_to))

    fig.subplots_adjust(hspace=0)

    return fig, ax
