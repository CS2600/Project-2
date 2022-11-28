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

int privateCar(double miles){
    double price;

    if (validateMiles(miles) == -1){
        return -1;
    }

    price = 0.27 * miles;

    calculateExpenses(price, price, 1); //flat fee, so allowedExpenses is same as fee
    return 1;
}

int rentalCar(int days, double pricePerDay){
    double price;

    if (validateDays(days) == -1 || validateFee(pricePerDay) == -1){
        return -1;
    }

    price = pricePerDay * days;

    calculateExpenses(price, price, 1); //flat fee, so allowedExpenses is same as fee
    return 1;
}

int parkingFees(int days, double fee){

    if (validateDays(days) == -1 || validateFee(fee) == -1){
        return -1;
    }

    calculateExpenses(fee, 6, days);
    return 1;
}

int taxiFees(int days, double fee){

    if (validateDays(days) == -1 || validateFee(fee) == -1){
        return -1;
    }

    calculateExpenses(fee, 10, days);
    return 1;
}

int registrationFees(double fee){
    if (validateFee(fee) == -1){
        return -1;
    }
    calculateExpenses(fee, fee, 1); //flat fee, so allowedExpenses is same as fee
    return 1;
}

int hotelFees(int days, double fee){
    double price;

    if (validateDays(days) == -1 || validateFee(fee) == -1){
        return -1;
    }

    price = fee * days;

    calculateExpenses(price, 90, days);
    return 1;
}