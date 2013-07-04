primeFinder = function(n){
    if(n<2){stop("Input should be more >=2");}

    sieve = rep(T , n);sieve[1]=F;

    for(k in 2:sqrt(n) ) {
        if(!sieve[k]) {next;}
        a = 2*k; while( a <= n ){sieve[a] = F; a = a+k}
    }
    primes = 1:n;primes = primes[sieve];primes;
}
