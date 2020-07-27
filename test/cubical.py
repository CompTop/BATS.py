import unittest
import bats
from bats import CubicalComplex

class TestCubicalComplex(unittest.TestCase):

	def setUp(self):
		pass

	def test_add(self):
		X = CubicalComplex(2)
		X.add([0,0,0,0])
		X.add([1,1,0,0])
		X.add([0,1,0,0])
		self.assertEqual(X.ncells(0), 2)
		self.assertEqual(X.ncells(1), 1)
		self.assertEqual(X.ncells(),  3)

	def test_add_recursive(self):
		X = CubicalComplex(3)
		X.add_recursive([0,1,0,1,0,1])
		self.assertEqual(X.ncells(0), 8)
		self.assertEqual(X.ncells(1), 12)
		self.assertEqual(X.ncells(2),  6)
		self.assertEqual(X.ncells(3), 1)


if __name__ == '__main__':
    unittest.main()
