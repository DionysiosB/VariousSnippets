function(N){
    if(N < 1){return(NULL)}
    output = rep(0,N)
    phi = (1 + sqrt(5))/2
    for(k in 1:N){output[k] = (phi^k - (1 - phi)^k) / sqrt(5) }
    return(output)
}