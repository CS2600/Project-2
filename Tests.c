/* 
* Documentation: https://github.com/ThrowTheSwitch/Unity
                 https://www.throwtheswitch.org/unity
* Additional Resource: https://www.feabhas.com/sites/default/files/2016-06/Unity.pdf
* To run: gcc Tests.c Fees.c FeesCalculator.c ./unity/src/unity.c -o Test
*         ./Test
*/
//#define UNITY_DOUBLE_TYPE long double
//#define UNITY_INCLUDE_DOUBLE
//#include "Unity/src/unity_config.h"
//#include "Unity/src/unity_internals.h"
#include "Unity/src/unity.h"
#include "Fees.h"
#include "FeesCalculator.h"

//Required to compile properly
void setUp(void) {

}

//Required to compile properly
void tearDown(void) {

}

void reset() {
    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

//INDIVIDUAL ADD TESTS
void Should_add_Private_car_expenses(void)
{
    double mile = 10;
    double totalExpenses = mile * 0.27;

    privateCar(mile);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Parking_fee_expenses(void)
{
    double fees = 20;
    int days = 5;
    double excess = 0;
    double saved = 0;
    
    if(days * 6 > fees) {
        saved = days * 6 - fees;
    }
    else {
        excess = fees - days * 6;
    }

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), fees);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), days * 6);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), excess);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), saved);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Rental_car_expenses(void)
{
    int days = 4;
    double pricePerDay = 29.99;

    rentalCar(days, pricePerDay);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), days * pricePerDay);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), days * pricePerDay);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Taxi_fee_expenses(void)
{
    int days = 6;
    double fees = 90;
    double excess = 0;
    double saved = 0;

    if(days * 10 > fees) {
        saved = days * 10 - fees;
    }
    else {
        excess = fees - days * 10;
    }

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), fees);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), days * 10);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), excess);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), saved);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Registration_fee_expenses(void)
{
    double fees = 100;
    
    registrationFees(fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), fees);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), fees);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Hotel_fee_expenses(void)
{
    int days = 2;
    double totalFees = 150;
    double excess = 0;
    double saved = 0;
    int nights = days - 1;

    if(nights * 10 > totalFees) {
        saved = nights * 90 - totalFees;
    }
    else {
        excess = totalFees - nights * 90;
    }

    hotelFees(days, totalFees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalFees);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), nights * 90);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), excess);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), saved);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Airfare_expenses(void) {
    double fee = 1023.13;

    airfare(fee);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), fee);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), fee);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

// INCOMPLETE
void Should_add_Meal_Fee_expenses(void)
{
    int time = 1000; // 1000 = 10:00
    double fee = 10;

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

//INDIVIDUAL INVALID TESTS
void Should_reject_Private_car_expenses_Invalid_mile() {
    double mile = -1;
    privateCar(mile);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}

void Should_reject_Parking_fee_expenses_Invalid_fee() {
    double fees = -10;
    int days = 5;

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}
void Should_reject_Parking_fee_expenses_Invalid_day() {
    double fees = 10;
    int days = -5;

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}

void Should_reject_Rental_car_expenses_Invalid_day() {
    int days = -4;
    double pricePerDay = 29.99;

    rentalCar(days, pricePerDay);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}

void Should_reject_Taxi_fee_expenses_Invalid_day() {
    int days = -6;
    double fees = 90;

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}
void Should_reject_Taxi_fee_expenses_Invalid_fee() {
    int days = 6;
    double fees = -90;

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}

void Should_reject_Registration_fee_expenses_Invalid_fee() {
    double fees = -100;
    
    registrationFees(fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_reject_Hotel_fee_expenses_Invalid_day() {
    int days = 0;
    double totalFees = 150;

    hotelFees(days, totalFees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}
void Should_reject_Hotel_fee_expenses_Invalid_fee() {
    int days = 2;
    double totalFees = -150;

    hotelFees(days, totalFees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}

void Should_reject_Airfare_expenses(void) {
    double fee = -1;

    airfare(fee);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getExcessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getAmountSaved(), 0);
}

//INCOMPLETE
void Should_reject_Meal_Fee_expenses() {

}

void Should_add_all_fees() {
    int days = 5;
    double miles = 29;
    double rentalCarFee = 30.15;
    double parkingFee = 14.98;
    double taxiFee = 98.76;
    double registrationFee = 39.75;
    double hotelFee = 100;
    double airfareFee = 1000;
    double total = (miles * .27) + (rentalCarFee * days) + parkingFee + taxiFee + registrationFee + (hotelFee * (days - 1)) + airfareFee;
    double totalAllowable = (days * (6 + 10)) + ((days - 1) * 90);
    //meal??

    double excess = 0;
    double saved = 0;

    excess += (miles * .27) + (rentalCarFee * days) + registrationFee + airfareFee;

    //Parking
    if(days * 6 > parkingFee) {
        saved += days * 6 - parkingFee;
    }
    else {
        excess += parkingFee - days * 6;
    }

    //Taxi
    if(days * 10 > taxiFee) {
        saved += days * 10 - taxiFee;
    }
    else {
        excess += taxiFee - days * 10;
    }

    //Hotel
    if((days - 1) * 90 > hotelFee) {
        saved += (days - 1) * 90 - hotelFee;
    }
    else {
        excess += hotelFee - (days - 1) * 90;
    }

     airfare( airfareFee);
     privateCar( miles);
     rentalCar( days, rentalCarFee);
     parkingFees( days, parkingFee);
     taxiFees( days, taxiFee);
     registrationFees(registrationFee);
     hotelFees( days, hotelFee);

    printf("%f\n", total);
    printf("%f\n", totalAllowable);
    printf("%f\n", excess);
    printf("%f\n", saved);

    TEST_ASSERT_EQUAL_DOUBLE(total, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(totalAllowable, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(Should_add_Private_car_expenses);
    reset();
    RUN_TEST(Should_add_Parking_fee_expenses);
    reset();
    RUN_TEST(Should_add_Rental_car_expenses);
    reset();
    RUN_TEST(Should_add_Taxi_fee_expenses);
    reset();
    RUN_TEST(Should_add_Registration_fee_expenses);
    reset();
    RUN_TEST(Should_add_Hotel_fee_expenses);
    reset();
    RUN_TEST(Should_add_Airfare_expenses);
    reset();
    //RUN_TEST(Should_add_Meal_Fee_expenses);

    RUN_TEST(Should_reject_Private_car_expenses_Invalid_mile);
    reset();
    RUN_TEST(Should_reject_Parking_fee_expenses_Invalid_day);
    reset();
    RUN_TEST(Should_reject_Parking_fee_expenses_Invalid_fee);
    reset();
    RUN_TEST(Should_reject_Rental_car_expenses_Invalid_day);
    reset();
    RUN_TEST(Should_reject_Taxi_fee_expenses_Invalid_day);
    reset();
    RUN_TEST(Should_reject_Taxi_fee_expenses_Invalid_fee);
    reset();
    RUN_TEST(Should_reject_Registration_fee_expenses_Invalid_fee);
    reset();
    RUN_TEST(Should_reject_Hotel_fee_expenses_Invalid_day);
    reset();
    RUN_TEST(Should_reject_Hotel_fee_expenses_Invalid_fee);
    reset();
    RUN_TEST(Should_reject_Airfare_expenses);
    reset();
    //RUN_TEST(Should_reject_Meal_Fee_expenses);

    RUN_TEST(Should_add_all_fees);

    return UNITY_END();
}