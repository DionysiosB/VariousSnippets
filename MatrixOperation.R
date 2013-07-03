matrixOperationB = function(n,k){
    A = matrix(0 , nrow = n, ncol =n)
    A = A + k*(row(A) == col(A)) + (abs(row(A)-col(A)) == 1);
    return(A)
}