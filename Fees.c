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

int eligibleMeals(int depart, int arrival){
    if (validateTime(depart) == -1 || validateTime(arrival) == -1 ){
        return -1;
    }
    if (depart < 700){
        return 1;
    }
    if (depart >= 700 && depart < 1200){
        return 2;
    }
    if (depart >= 1200 && depart < 1800){
        return 3;
    }
    if (depart >= 1800){
        return 4;
    }
    if (arrival < 800){
        return 5;
    }
    if (arrival >= 800 && arrival < 1300){
        return 6;
    }
    if (arrival >= 1300 && arrival < 1900){
        return 7;
    }
    if (arrival >= 1900){
        return 8;
    }
}

int mealFees(int departMeal, int arriveMeal, double departFee, double arriveFee){
    if (validateTime(departMeal) == -1 || validateTime(arriveMeal) == -1 ){
        return -1;
    }
    if (validateTime(departMeal) == -1 || validateTime(arriveMeal) == -1 ){
        return -1;
    }
    //depart breakfast is elligible
    if (departMeal == 1){
        calculateExpenses(departFee, 9, 1);
    }
    //depart lunch is elligible
    if (departMeal == 2){
        calculateExpenses(departFee, 12, 1);
    }
    //depart dinner is elligible
    if (departMeal == 3){
        calculateExpenses(departFee, 16, 1);
    }
    //arrive breakfast is elligible
    if (arriveMeal == 6){
        calculateExpenses(arriveFee, 9, 1);
    }
    //arrive lunch is elligible
    if (arriveMeal == 7){
        calculateExpenses(arriveFee, 12, 1);
    }
    //arrive dinner is elligible
    if (arriveMeal == 8){
        calculateExpenses(arriveFee, 16, 1);
    }

    return 1;
}
