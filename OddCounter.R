oddCounter = function(x){
     output = 0;
     for( k in x){if( k %% 2 == 1){output = output + 1;}}  
     return(output);
}   