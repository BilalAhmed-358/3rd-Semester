import math
import time

print()
print("Following are given equations which have to be converted into Echleon Form")
print("x1 + x2 + 2 x3= 8")
print("-x1 - 2 x2 + 3 x3= 1")
print("3 x1 - 7 x2 + 4 x3= 10")
print()

print("The matrix comprised of the coefficients is")
matrixA=[[1,1,2],[-1,-2,3],[3,-7,4]]
for i in range(len(matrixA)):
    print(matrixA[i])  
print()
time.sleep(2)
matrixB=[8,1,10]
print("The matrix comprised of the answers of the respective equations is")
for i in range (len(matrixB)):
    print(matrixB[i])
print()
time.sleep(2)
print("The augmented matrix becomes")
print(" 1    1    2    8")
print("-1   -2    3    1")
print(" 3   -7    4    10")
print()
print("Now converting the matrix into Reduced Echleon Form")
print()
time.sleep(2)
print("R2-> R2+R1")
for i in range (3):
    matrixA[1][i]=matrixA[1][i]+matrixA[0][i]
for i in range(len(matrixA)):
    print(matrixA[i]) 
print()
time.sleep(2)
print("R3-> R3-3R1")
for i in range (3):
    matrixA[2][i]=matrixA[2][i]-(3*matrixA[0][i])
for i in range(len(matrixA)):
    print(matrixA[i])
print()
time.sleep(2)
print("R2-> 9*R2")
for i in range (3):
    matrixA[1][i]=9*matrixA[1][i]
for i in range(len(matrixA)):
    print(matrixA[i])
print()
time.sleep(2)
print("R2-> R2-R3")
for i in range (3):
    matrixA[1][i]=matrixA[1][i]-matrixA[2][i]
for i in range(len(matrixA)):
    print(matrixA[i])
print()
time.sleep(2)
print("R3-> R3+10R2")
for i in range (3):
    matrixA[2][i]=matrixA[2][i]+10*matrixA[1][i]
for i in range(len(matrixA)):
    print(matrixA[i])
print()
time.sleep(2)
print("R3-> R3/468")
for i in range (3):
    matrixA[2][i]=matrixA[2][i]/468
    matrixA[2][i]=math.trunc(matrixA[2][i])
for i in range(len(matrixA)):
    print(matrixA[i])
print()
time.sleep(2)
print("R1-> R2-R1")
for i in range (3):
    matrixA[0][i]=matrixA[0][i]-matrixA[1][i]
for i in range(len(matrixA)):
    print(matrixA[i]) 
print()
time.sleep(2)
print("R1-> R1+(45*R3)")
for i in range (3):
    matrixA[0][i]=matrixA[0][i]+45*matrixA[2][i]
for i in range(len(matrixA)):
    print(matrixA[i])   
print()
time.sleep(2)
print("R2-> R2-(47*R3)")
for i in range (3):
    matrixA[1][i]=matrixA[1][i]-47*matrixA[2][i]
for i in range(len(matrixA)):
    print(matrixA[i])   

print()
time.sleep(2)
print("After performing the above operations on the matrix the Reduced Echleon form of the above matrix is ")
for i in range(len(matrixA)):
    print(matrixA[i])


