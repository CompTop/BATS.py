import unittest
import bats
from bats import SimplicialComplex

class TestSimplicialComplex(unittest.TestCase):

	def setUp(self):
		pass

	def test_add(self):
		X = SimplicialComplex()
		X.add([0])
		X.add([1])
		X.add([0,1])
		self.assertEqual(X.ncells(0), 2)
		self.assertEqual(X.ncells(1), 1)
		self.assertEqual(X.ncells(),  3)


if __name__ == '__main__':
    unittest.main()
