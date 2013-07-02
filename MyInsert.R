function(x, where, what){
    if(where < 1){return(c(what,x))}
    if(where > length(x)){return(c(x,what))}
    return( c(x[1:(where-1)],what,x[where:length(x)]) )
}