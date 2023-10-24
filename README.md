This is to compare the time used in sequential vs parallel computing.
I have written all programs using openMP. The sum of array code is in both the SPMD and using constructors, rest of them have used only constructors.
The first programme is about computing the sum of an array using both parallel and sequential one. The output is the sum of array followed by the time taken to execute the computation part.
The other 2 programmes are about evaluating the LU decomposition and inverse of a square matrix. The input for matrix is generated using rand(), which generates a random number.



