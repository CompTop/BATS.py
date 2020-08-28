import plotly
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import bats

class ScatterVisualization(go.Figure):
    """
    2D visualizations of simplicial complexes
    """
    def __init__(self, cpx, pos=None, **kwargs):
        super().__init__(**kwargs)
        self._cpx = cpx # complex
        if pos is None:
            raise NotImplementedError("pos must be specified")
        self._pos = pos # positions of points

        self.reset()

    def reset(self):
        self.data = ()
        self.add_points()
        self.add_edges()

    def add_points(self):
        # add scatter of points
        self.add_trace(go.Scatter(
            x = self._pos[:,0], y = self._pos[:,1],
            mode='markers',
        ))

    def add_edges(self):
        # add edges in complex
        edge_x = []
        edge_y = []
        for i, j in self._cpx.get_simplices(1):
            edge_x.extend([self._pos[i,0], self._pos[j,0], None])
            edge_y.extend([self._pos[i,1], self._pos[j,1], None])

        self.add_trace(go.Scatter(
            x=edge_x, y=edge_y,
            line=dict(width=0.5, color='#888'),
            hoverinfo='none',
            mode='lines')
         )

    def reduce(self, field=bats.F2):
        if not hasattr(self, '_RC'):
            self._RC = bats.ReducedChainComplex(self._cpx, field())

    def show_chain(self, c, dim=1, color="red"):
        if dim != 1:
            raise NotImplementedError("Only 1-chains are supported")

        edge_x = []
        edge_y = []
        nzind = c.nzinds()
        for k in nzind:
            [i, j] = self._cpx.get_simplex(1, k)
            edge_x.extend([self._pos[i,0], self._pos[j,0], None])
            edge_y.extend([self._pos[i,1], self._pos[j,1], None])
        self.add_trace(go.Scatter(
            x=edge_x, y=edge_y,
            line=dict(width=2, color=color),
            hoverinfo='none',
            mode='lines')
         )

    def show_generator(self, i, hdim=1, color="red"):
        if hdim != 1:
            raise NotImplementedError("Only H1 generators are supported")

        self.reduce()
        r = self._RC.get_preferred_representative(i, hdim)

        self.show_chain(r, dim=hdim, color=color)

    def show_generators(self, hdim):
        self.reduce()

        for i in range(self._RC.hdim(hdim)):
            self.show_generator(i, hdim, color=None)


def SimplicialTower(cpx=None, maps=None):
    if len(cpx) != len(maps) + 1:
        raise ValueError("number of maps must be one less than number of spaces")

    nspaces = len(cpx)
    D = bats.SimplicialComplexDiagram(nspaces, nspaces-1)

    for i in range(nspaces):
        D.set_node(i, cpx[i])

    for i in range(nspaces-1):
        D.set_edge(i, i, i+1, maps[i])

    return D


class MapVisualization(go.Figure):
    def __init__(self, pos=None, cpx=None, maps=None):
        super().__init__()

        # compute number of spaces
        nspaces = len(cpx)
        if len(pos) != len(cpx):
            raise ValueError("number of spaces must be equal to number of positions")
        if len(maps) != len(cpx) - 1:
            raise ValueError("number of maps must be one less than number of spaces")

        self._pos = pos

        template_fig = make_subplots(rows=1, cols=nspaces,
                    specs=[[{"type": "scene"} if self.vis_dim(i) == 3 else {"type": "xy"} for i in range(nspaces)]],
                    subplot_titles=tuple("Space {}".format(i) for i in range(nspaces)))
        self.layout = template_fig.layout
        # copy subplot grid ref
        self.__dict__["_grid_ref"] = template_fig._grid_ref
        self.__dict__["_grid_str"] = template_fig._grid_str

        self._dgm = SimplicialTower(cpx, maps)

        self.reset()

    def reset(self):
        self.data = ()
        self.draw_points()
        self.draw_edges()

    def size(self):
        return self._dgm.nnode()

    def vis_dim(self, k):
        return self._pos[k].shape[1]

    def draw_points(self):

        for i in range(self.size()):
            if self.vis_dim(i) == 3:
                self.append_trace(
                    go.Scatter3d(x=self._pos[i][:,0], y=self._pos[i][:,1], z=self._pos[i][:,2],
                                 mode='markers',
                                 marker={'color':'#888', 'size':4},
                                 name="nodes",
                                 legendgroup="nodes"
                                ),
                         row=1, col=i+1)
            elif self.vis_dim(i) == 2:
                self.append_trace(
                    go.Scatter(x=self._pos[i][:,0], y=self._pos[i][:,1],
                                 mode='markers',
                                 marker={'color':'#888', 'size':4},
                                 name="nodes",
                                 legendgroup="nodes"
                                ),
                         row=1, col=i+1)


        return self


    def draw_edges(self):
        for k in range(self.size()):
            if self.vis_dim(k) == 3:
                # add edges in complex
                edge_x = []
                edge_y = []
                edge_z = []
                for i, j in self._dgm.node_data(k).get_simplices(1):
                    edge_x.extend([self._pos[k][i,0], self._pos[k][j,0], None])
                    edge_y.extend([self._pos[k][i,1], self._pos[k][j,1], None])
                    edge_z.extend([self._pos[k][i,2], self._pos[k][j,2], None])

                self.add_trace(go.Scatter3d(x=edge_x, y=edge_y, z=edge_z,
                                            line=dict(width=0.5, color='#888'),
                                            hoverinfo='none',
                                            mode='lines',
                                            name="edges",
                                            legendgroup="edges"
                                           ),
                    row=1, col=k+1
                 )
            elif self.vis_dim(k) == 2:
                # add edges in complex
                edge_x = []
                edge_y = []
                for i, j in self._dgm.node_data(k).get_simplices(1):
                    edge_x.extend([self._pos[k][i,0], self._pos[k][j,0], None])
                    edge_y.extend([self._pos[k][i,1], self._pos[k][j,1], None])

                self.add_trace(go.Scatter(x=edge_x, y=edge_y,
                                            line=dict(width=0.5, color='#888'),
                                            hoverinfo='none',
                                            mode='lines',
                                            name="edges",
                                            legendgroup="edges"
                                           ),
                    row=1, col=k+1
                 )


    def complex_diagram(self):
        return self._dgm

    def get_complex(self, i):
        return self._dgm.node_data(i)

    def compute_chain(self, field=bats.F2):
        """
        compute chain functor
        """
        if not hasattr(self, '_chain'):
            self._chain = bats.Chain(self._dgm, field())

    def chain_diagram(self):
        """
        return internal chain diagram
        """
        self.compute_chain()
        return self._chain

    def show_chain(self, c, dim=1, color='red', hcolor='blue', show_rep=True, group_suffix=None):
        """
        visualize chain in first space

        visualize image of chain in subsequent spaces

        options:
        color : chain color (default 'red')
        show_rep : show homology representative (default True)
        hcolor : homology representative color (default 'blue')
        group_suffix : use suffix for legend group (default None)
        """
        if dim != 1:
            raise NotImplementedError("Only 1-chains are supported")

        self._render_chain(0, c, dim=dim, color=color,
                           legendgroup="chain{}".format(group_suffix),
                           name="chain0")

        for i in range(self.size()-1):
            #rc = self._chain.edge_data(i)[dim] * c
            c = self._chain.edge_data(i)[dim] * c
            self._render_chain(i+1, c, dim=dim, color=color,
                               legendgroup="chain{}".format(group_suffix),
                               name="chain{}".format(i+1))
            if show_rep:
                R = self._hom.node_data(i+1)
                rc = R.chain_preferred_representative(c, dim)
                self._render_chain(i+1, rc, dim=dim, color=hcolor,
                                   legendgroup="hom{}".format(group_suffix),
                                   name="rep{}".format(i+1))

    def _render_chain(self, cpxind, c, dim=1, color='red', **kwargs):
        """
        render chain c at space cpxind
        """
        if dim != 1:
            raise NotImplementedError("Only 1-chains are supported")

        if self.vis_dim(cpxind) == 3:
            edge_x = []
            edge_y = []
            edge_z = []
            nzind = c.nzinds()
            for k in nzind:
                [i, j] = self.get_complex(cpxind).get_simplex(1, k)
                edge_x.extend([self._pos[cpxind][i,0], self._pos[cpxind][j,0], None])
                edge_y.extend([self._pos[cpxind][i,1], self._pos[cpxind][j,1], None])
                edge_z.extend([self._pos[cpxind][i,2], self._pos[cpxind][j,2], None])

            self.add_trace(go.Scatter3d(
                x=edge_x, y=edge_y, z=edge_z,
                line=dict(width=2, color=color),
                hoverinfo='none',
                mode='lines',
                **kwargs
            ),
                row=1, col=cpxind+1
             )
        elif self.vis_dim(cpxind) == 2:
            edge_x = []
            edge_y = []
            nzind = c.nzinds()
            for k in nzind:
                [i, j] = self.get_complex(cpxind).get_simplex(1, k)
                edge_x.extend([self._pos[cpxind][i,0], self._pos[cpxind][j,0], None])
                edge_y.extend([self._pos[cpxind][i,1], self._pos[cpxind][j,1], None])

            self.add_trace(go.Scatter(
                x=edge_x, y=edge_y,
                line=dict(width=2, color=color),
                hoverinfo='none',
                mode='lines',
                **kwargs
            ),
                row=1, col=cpxind+1
             )


    def compute_hom(self, dim=1, field=bats.F2):
        """
        compute hom functor
        """
        if dim != 1:
            raise AssertionError("dimension must be 1")
        if not hasattr(self, '_hom'):
            self.compute_chain(field)
            self._hom = bats.Hom(self._chain, dim)

    def hom_diagram(self):
        self.compute_hom()
        return self._hom

    def show_generator(self, i, **kwargs):
        self.compute_hom()
        R0 = self._hom.node_data(0)
        c = R0.get_preferred_representative(i,1)
        self.show_chain(c, **kwargs)
