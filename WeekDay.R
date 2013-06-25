weekDay = function(day,month,year){
    k = day
    y = year %% 100
    c = year %/% 100
    m = (month - 2); if(m<0){m = m+12}

    f = ( as.integer(2.6*m -0.2) + k + y + as.integer(y/4) + as.integer(c/4) - 2*c) %% 7
    if(f == 0){f = 7};

    dayNames = c("Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday")
    return(dayNames[f])
}