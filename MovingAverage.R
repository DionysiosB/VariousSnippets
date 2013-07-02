movingAverage = function(x,a){
    N = length(x)
    output = rep(0,N-a+1)
    for(k in 1:a ){output = output +x[k:(N-a+k)]}
    return(output/a)
}