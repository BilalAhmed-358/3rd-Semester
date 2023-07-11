
import numpy as np
def row_echelon(M):
    """ Return MATRIX M into reduce echelon form"""




#if matrix M has no column and rowa,
# it is already in REF, so we return itself
    r, c =M.shape
    if r == 0 or c == 0:
        return M



    # search for non-zero element in the first column
    for i in range(len(M)):
        if M[i,0] != 0:
            break
    else:
        # if all elements in the first column is zero,
        # we perform REF on matrix from second column
        B = row_echelon(M[:,1:])
        # and then add the first zero-column back
        return np.hstack([M[:,:1], B])


    # if non-zero element happens not in the first row,
    # we switch rows
    if i > 0:
        ith_row = M[i].copy()
        M[i] = M[0]
        M[0] = ith_row

    
    # divide first row by first element in it
    M[0] = M[0] / M[0,0]
    
    # subtract all subsequent rows with first row (it has 1 now as first element)
    # multiplied by the corresponding element in the first column
    M[1:] -= M[0] * M[1:,0:1]

    # we perform REF on matrix from second row, from second column
    B = row_echelon(M[1:,1:])

    # we add first row and first (zero) column, and return
    return np.vstack([M[:1], np.hstack([M[1:,:1], B]) ])

M = np.array([[1, 1, 2, 8],
              [-1, -2, 3, 1],
              [3, -7, 4, 10]], dtype='float')

row_echelon(M)