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

double privateCar(double miles){
    double price;

    price = 0.27 * miles;

    calculateExpenses(price, price, 1); //flat fee, so allowedExpenses is same as fee
    return price;
}

double rentalCar(int days, double pricePerDay){
    double price;

    price = pricePerDay * days;

    calculateExpenses(price, price, 1); //flat fee, so allowedExpenses is same as fee
    return price;
}

double parkingFees(int days, double fee){
    double price;

    price = fee * days;

    calculateExpenses(price, 6, days);
    return price;
}

double taxiFees(int days, double fee){
    double price;

    price = fee * days;

    calculateExpenses(price, 10, days);
    return price;
}

double registrationFees(double fee){
    calculateExpenses(fee, fee, 1); //flat fee, so allowedExpenses is same as fee
    return fee;
}

double hotelFees(int days, double fee){
    double price;

    price = fee * days;

    calculateExpenses(price, 90, days);
    return price;
}