vectorOperation = function(x){
    output = (x<0)*(x^2+2*x+3) + (x >= 0  &  x < 2)*(x+3) + (x >= 2)*(x^2 + 4*x - 7)
    return(output)
}