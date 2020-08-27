import plotly
import plotly.graph_objects as go
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
