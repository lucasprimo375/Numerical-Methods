import numpy as np

A, B, C, D, E, F = 3, 7, 7, 7, 3, 9

matrix_A = np.array([[30+A+F, A, B, C, D],
					 [A, 10+B+E, E, F, A+B],
					 [B, E, 50+C+D, B+C, C+D],
					 [C, F, B+C, 40-A, D+E],
					 [D, A+B, C+D, D+E, 60-B]])

matrix_AAt = np.matmul(matrix_A, np.transpose(matrix_A))

matrix_AtA = np.matmul(np.transpose(matrix_A), matrix_A)

print("QUESTÃO 01 E 02\n")

print(f"Matrix A: \n{matrix_A}")
print()
print(f"Matrix A': \n{np.transpose(matrix_A)}")
print()
print(f"Matrix AA': \n{matrix_AAt}")
print()
print(f"Matrix A'A: \n{matrix_AtA}")

print("QUESTÃO 03\n")

matrix_A = np.array([[30+A+F, A, B, C, D],
					 [A, 10+B+E, E, F, A+B],
					 [B, E, 50+C+D, B+C, C+D]])

matrix_AAt = np.matmul(matrix_A, np.transpose(matrix_A))

matrix_AtA = np.matmul(np.transpose(matrix_A), matrix_A)

print(f"Matrix A: \n{matrix_A}")
print()
print(f"Matrix A': \n{np.transpose(matrix_A)}")
print()
print(f"Matrix AA': \n{matrix_AAt}")
print()
print(f"Matrix A'A: \n{matrix_AtA}")