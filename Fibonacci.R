fibonacci = function(n){
    output = c();
    if(n<1){return;}
    if(n >= 1){output = c(1)}
    if(n >= 2){output = c(output,1);summary(output)}
    if(n >= 3){for(k in seq(3,n) ){output = c(output, output[k-1]+output[k-2]);}};
    output;
}
