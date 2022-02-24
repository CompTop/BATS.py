import unittest
import bats

class TestZigzagSimplicialComplex(unittest.TestCase):

	def setUp(self):
		pass

	def test_barcode(self):

		n = 3 # number of spaces

		D = bats.SimplicialComplexDiagram(n, n-1)

		# first, we add SimplicialComplexes to the diagram
		X = bats.SimplicialComplex()
		X.add_recursive([0,1])
		D.set_node(0, X) # left node
		D.set_node(2, X) # right node

		Y = bats.SimplicialComplex()
		Y.add([0])
		Y.add([1])
		D.set_node(1, Y)

		# now, we add SimplicialMaps
		f = bats.SimplicialMap(Y, X, [0, 1])
		D.set_edge(0, 1, 0, f) # edge 0 maps space at node 1 to space at node 0.  The map is f
		D.set_edge(1, 1, 2, f) # edge 1 maps space at node 1 to space at node 2.  The map is f

		CD = bats.Chain(D, bats.F3())

		HD = bats.Hom(CD, 0) # 0 is homology dimension
		HD.edge_data(0).tolist() # [[1, 1]]
		# self.assertEqual(HD.edge_data(0).tolist(),  [[bats.F3(1),bats.F3(1)]])

		ps = bats.barcode(HD, 0) # homology dimension is 0
		self.assertEqual(ps[0].birth(),  0)
		self.assertEqual(ps[0].death(),  2)
		self.assertEqual(ps[1].birth(),  1)
		self.assertEqual(ps[1].death(),  1)


if __name__ == '__main__':
    unittest.main()
