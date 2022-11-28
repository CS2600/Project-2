/* 
* Documentation: https://github.com/ThrowTheSwitch/Unity
                 https://www.throwtheswitch.org/unity
* Additional Resource: https://www.feabhas.com/sites/default/files/2016-06/Unity.pdf
* To run: gcc Test.c Fees.c FeesCalculator.c ./unity/src/unity.c -o Test
*         ./Test
*/
#include "Unity/src/unity.h"
#include "Fees.h"
#include "FeesCalculator.h"

//Required to compile properly
void setUp(void) {

}

//Required to compile properly
void tearDown(void) {

}
//NOTE**** TESTS MIGHT NOT BE INDEPENDENT IF TOTAL EXPENSES IS STATIC
void Should_add_Private_car_expenses(void)
{
    double mile = 10;
    double totalExpenses = mile * 0.27;
    privateCar(mile);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Parking_fee_expenses(void)
{
    double fees = 10;
    int days = 5;
    int excess = 0;
    int saved = 0;
    
    if(days * 6 > fees) {
        excess = days * 6 - fees;
    }
    else {
        saved = fees - days * 6
    }

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), fees);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), days * 6);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), excess);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), saved);

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
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), days * pricePerDay);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Taxi_fee_expenses(void)
{
    double days = 6;
    double fees = 90;
    int excess = 0;
    int saved = 0;

    if(days * 10 > fees) {
        excess = days * 10 - fees;
    }
    else {
        saved = fees - days * 10;
    }

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), fees);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), days * 10);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), excess);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), saved);

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
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), fees);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_add_Hotel_fee_expenses(void)
{
    double days = 2;
    double totalFees = 150;
    int excess = 0;
    int saved = 0;

    if(days * 10 > fees) {
        excess = days * 90 - fees;
    }
    else {
        saved = fees - days * 90;
    }

    hotelFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalFees);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), days * 90);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), excess);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), saved);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

// INCOMPLETE
void Should_add_Meal_Fee_expenses(void)
{
    double time = 1000; // 1000 = 10:00
    double fee = ;
    

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_reject_Private_car_expenses_Invalid_mile() {
    double mile = -1;
    privateCar(mile);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}

void Should_reject_Parking_fee_expenses_Invalid_fee() {
    double fees = -10;
    int days = 5;

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}
void Should_reject_Parking_fee_expenses_Invalid_day() {
    double fees = 10;
    int days = -5;

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}

void Should_reject_Rental_car_expenses_Invalid_day() {
    int days = -4;
    double pricePerDay = 29.99;

    rentalCar(days, pricePerDay);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}

void Should_reject_Taxi_fee_expenses_Invalid_day() {
    double days = -6;
    double fees = 90;

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}
void Should_reject_Taxi_fee_expenses_Invalid_fee() {
    double days = 6;
    double fees = -90;

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}

void Should_reject_Registration_fee_expenses_Invalid_fee() {
    double fees = -100;
    
    registrationFees(fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

void Should_reject_Hotel_fee_expenses_Invalid_day() {
    double days = 0;
    double totalFees = 150;

    hotelFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}

void Should_reject_Hotel_fee_expenses_Negative_fee() {
    double days = 2;
    double totalFees = -150;

    hotelFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}
void Should_reject_Meal_Fee_expenses() {

}


int main(void)
{
UNITY_BEGIN();

RUN_TEST(Should_add_Private_car_expenses);
RUN_TEST(Should_add_Parking_fee_expenses);
RUN_TEST(Should_add_Rental_car_expenses);
RUN_TEST(Should_add_Taxi_fee_expenses);
RUN_TEST(Should_add_Registration_fee_expenses);
RUN_TEST(Should_add_Hotel_fee_expenses);
RUN_TEST(Should_add_Meal_Fee_expenses);

return UNITY_END();
}