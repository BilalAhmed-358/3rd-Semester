# import sympy
from sympy import *

M = ([[1, 0, 1, 3], [2, 3, 4, 7], [-1, -3, -3, -4]])
print("Matrix : {} ".format(M))

# Use sympy.rref() method
M_rref = M.rref()
	
print("The Row echelon form of matrix M and the pivot columns : {}".format(M_rref))
