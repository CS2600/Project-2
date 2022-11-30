#include<stdio.h>
#include "FeesCalculator.h"

//validates fee input
int validateFee(double fee){
    if (fee >= 0){
        return 1;
    }
    else{
        return -1;
    }
}

//validates miles input
int validateMiles(double miles){
    if (miles >= 0){
        return 1;
    }
    else{
        return -1;
    }
}

//validates days input
int validateDays(int days){
    if (days >= 1){
        return 1;
    }
    else{
        return -1;
    }
}

//validates time input
int validateTime(int time){
    int minutes = time % 100;
    double hours = time / 100;

    if (minutes > 59 || hours > 23.59){
        return -1;
    }
    if (time < 0){
        return -1;
    }
    else{
        return 1;
    }
}

//calculates round trip airfare
int airfare(double fee){
    if (validateFee(fee) == -1){
        return -1;
    }
    calculateExpenses(fee, 0, 0);
    return 1;
}

//calculates private car expenses
int privateCar(double miles){
    double price;

    if (validateMiles(miles) == -1){
        return -1;
    }

    price = 0.27 * miles;

    calculateExpenses(price, 0, 0);
    return 1;
}

//calculates rental car expenses
int rentalCar(int days, double pricePerDay){
    double price;

    if (validateDays(days) == -1 || validateFee(pricePerDay) == -1){
        return -1;
    }

    price = pricePerDay * days;

    calculateExpenses(price, 0, 0);
    return 1;
}

//calculates parking expenses
int parkingFees(int days, double fee){

    if (validateDays(days) == -1 || validateFee(fee) == -1){
        return -1;
    }

    calculateExpenses(fee, 6, days);
    return 1;
}

//calculates taxi expenses
int taxiFees(int days, double fee){

    if (validateDays(days) == -1 || validateFee(fee) == -1){
        return -1;
    }

    calculateExpenses(fee, 10, days);
    return 1;
}

//calculates registration expenses
int registrationFees(double fee){
    if (validateFee(fee) == -1){
        return -1;
    }
    calculateExpenses(fee, 0, 0);
    return 1;
}

//calculates hotel expenses
int hotelFees(int days, double fee){
    double price;

    days = days -1;

    if (validateDays(days) == -1 || validateFee(fee) == -1){
        return -1;
    }

    price = fee * days;

    calculateExpenses(price, 90, days);
    return 1;
}

//determines what meals are eligible for departure.
int eligibleDepartMeals(int depart){
    if (validateTime(depart) == -1){
        return -1;
    }
    //breakfast is eligible
    if (depart < 700){
        return 1;
    }
    //lunch is eligible
    if (depart >= 700 && depart < 1200){
        return 2;
    }
    //dinner is eligible
    if (depart >= 1200 && depart < 1800){
        return 3;
    }
    //none are eligible
    if (depart >= 1800){
        return 4;
    }
}

//determines what meals are eligible for arrival.
int eligibleArrivalMeals(int arrival){
    if (validateTime(arrival) == -1){
        return -1;
    }
    //none are eligible
    if (arrival < 800){
        return 5;
    }
    //breakfast is eligible
    if (arrival >= 800 && arrival < 1300){
        return 6;
    }
    //lunch is eligible
    if (arrival >= 1300 && arrival < 1900){
        return 7;
    }
    //dinner is eligible
    if (arrival >= 1900){
        return 8;
    }
}

int mealFees(int departMeal, int arriveMeal, double departFee, double arriveFee){
    if (validateTime(departMeal) == -1 || validateTime(arriveMeal) == -1 ){
        return -1;
    }
    if (validateFee(departFee) == -1 || validateFee(arriveFee) == -1 ){
        return -1;
    }
    //depart breakfast is eligible
    if (departMeal == 1){
        calculateExpenses(departFee, 9, 1);
    }
    //depart lunch is eligible
    if (departMeal == 2){
        calculateExpenses(departFee, 12, 1);
    }
    //depart dinner is eligible
    if (departMeal == 3){
        calculateExpenses(departFee, 16, 1);
    }
    //arrive breakfast is eligible
    if (arriveMeal == 6){
        calculateExpenses(arriveFee, 9, 1);
    }
    //arrive lunch is eligible
    if (arriveMeal == 7){
        calculateExpenses(arriveFee, 12, 1);
    }
    //arrive dinner is eligible
    if (arriveMeal == 8){
        calculateExpenses(arriveFee, 16, 1);
    }

    return 1;
}
