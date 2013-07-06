autocorrelationLag = function(x,lag){
    N = length(x)
    xbar = mean(x);
    var = sum( (x - xbar)^2)

    first = x[1:(N-lag)] - xbar
    second = x[(1+lag):N] - xbar
    return( sum(first * second)/var)
}