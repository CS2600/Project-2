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

//INDIVIDUAL ADD TESTS
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
    double excess = 0;
    double saved = 0;
    
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
    int days = 6;
    double fees = 90;
    double excess = 0;
    double saved = 0;

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
    int days = 2;
    double totalFees = 150;
    double excess = 0;
    double saved = 0;

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
    int time = 1000; // 1000 = 10:00
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

//INDIVIDUAL INVALID TESTS
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
    int days = -6;
    double fees = 90;

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}
void Should_reject_Taxi_fee_expenses_Invalid_fee() {
    int days = 6;
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
    int days = 0;
    double totalFees = 150;

    hotelFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}
void Should_reject_Hotel_fee_expenses_Invalid_fee() {
    int days = 2;
    double totalFees = -150;

    hotelFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);
}

void Should_reject_Meal_Fee_expenses() {

}

void Should_add_all_fees() {
    int days = 5;
    double miles = 29;
    double rentalCarFee = 30.15;
    double parkingFee = 14.98;
    double taxiFee = 98.76;
    double registrationFee = 39.75;
    double hotelFees = 1234.56;
    double total = (miles * days) + ()
    //meal??

    double excess = 0;
    double saved = 0;

    //Parking
    if(days * 6 > parkingFee) {
        excess = days * 6 - parkingFee;
    }
    else {
        saved = parkingFee - days * 6
    }

    //Taxi
    if(days * 10 > taxiFee) {
        excess = days * 10 - taxiFee;
    }
    else {
        saved = taxiFee - days * 10
    }

    //Hotel
    if(days * 90 > hotelFees) {
        excess = days * 90 - hotelFees;
    }
    else {
        saved = hotelFees - days * 90
    }



    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalAllowableExpenses(), totalExpenses);
    TEST_ASSERT_EQUAL_DOUBLE(excessExpenses(), 0);
    TEST_ASSERT_EQUAL_DOUBLE(amountSaved(), 0);

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
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

RUN_TEST(Should_reject_Private_car_expenses_Invalid_mile);
RUN_TEST(Should_reject_Parking_fee_expenses_Invalid_day);
RUN_TEST(Should_reject_Parking_fee_expenses_Invalid_fee);
RUN_TEST(Should_reject_Rental_car_expenses_Invalid_day);
RUN_TEST(Should_reject_Taxi_fee_expenses_Invalid_day);
RUN_TEST(Should_reject_Taxi_fee_expenses_Invalid_fee);
RUN_TEST(Should_reject_Registration_fee_expenses_Invalid_fee);
RUN_TEST(Should_reject_Hotel_fee_expenses_Invalid_day);
RUN_TEST(Should_reject_Hotel_fee_expenses_Invalid_fee);
RUN_TEST(Should_reject_Meal_Fee_expenses);

return UNITY_END();
}