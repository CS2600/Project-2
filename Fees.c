#include<stdio.h>

int validateFee(double fee){
    if (fee >= 0){
        return 1;
    }
    else{
        return -1;
    }
}

int validateMiles(double miles){
    if (miles >= 0){
        return 1;
    }
    else{
        return -1;
    }
}

int validateDays(int days){
    if (days >= 1){
        return 1;
    }
    else{
        return -1;
    }
}

int validateTime(int time){
    if (time >= 0 && time <= 2359){
        return 1;
    }
    else{
        return -1;
    }
}