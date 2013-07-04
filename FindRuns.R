findRuns = function(x , n){
	output = c();
	for(k in 1:(length(x)-n+1) ){if( all(x[k:(k+n-1)] == 1) ){output = c(output,k);}}
	return(output)
}