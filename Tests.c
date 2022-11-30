/* 
* Documentation: https://github.com/ThrowTheSwitch/Unity
                 https://www.throwtheswitch.org/unity
* Additional Resource: https://www.feabhas.com/sites/default/files/2016-06/Unity.pdf
* To run: gcc Tests.c Fees.c FeesCalculator.c ./unity/src/unity.c -o Test
*         ./Test
*/
#include "Unity/src/unity.h"
#include "Fees.h"
#include "FeesCalculator.h"

//Required to compile properly
void setUp() {

}

//Required to compile properly
void tearDown() {

}

void reset() {
    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

//INDIVIDUAL ADD TESTS
void Should_add_Private_car_expenses()
{
    double mile = 10;
    double totalExpenses = mile * 0.27;

    privateCar(mile);

    TEST_ASSERT_EQUAL_DOUBLE(totalExpenses, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(totalExpenses, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_add_Parking_fee_expenses()
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

    TEST_ASSERT_EQUAL_DOUBLE(fees, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE((days * 6), getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());
}

void Should_add_Rental_car_expenses()
{
    int days = 4;
    double pricePerDay = 29.99;

    rentalCar(days, pricePerDay);

    TEST_ASSERT_EQUAL_DOUBLE(days * pricePerDay, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(days * pricePerDay, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_add_Taxi_fee_expenses()
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

    TEST_ASSERT_EQUAL_DOUBLE(fees, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(days * 10, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());
}

void Should_add_Registration_fee_expenses()
{
    double fees = 100;
    
    registrationFees(fees);

    TEST_ASSERT_EQUAL_DOUBLE(fees, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(fees, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_add_Hotel_fee_expenses()
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

    TEST_ASSERT_EQUAL_DOUBLE(totalFees, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(nights * 90, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());
}

void Should_add_Airfare_expenses() {
    double fee = 1023.13;

    airfare(fee);

    TEST_ASSERT_EQUAL_DOUBLE(fee, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(fee, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_add_Depart_Meal_Fee_Breakfast_expenses() {
    int time = 659;
    double mealFee = 15;
    double allowedExpenses = 9;
    int departMeal = eligibleDepartMeals(time);
    double excess = 0;
    double saved = 0;

    if(mealFee < allowedExpenses) {
        saved = allowedExpenses - mealFee;
    }
    else {
        excess = mealFee - allowedExpenses;
    }

    mealFees(departMeal, 0, mealFee, 0);

    TEST_ASSERT_EQUAL_DOUBLE(mealFee, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(allowedExpenses, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());
}
void Should_add_Depart_Meal_Fee_Lunch_expenses() {
    int time = 700;
    double mealFee = 15;
    double allowedExpenses = 12;
    int departMeal = eligibleDepartMeals(time);
    double excess = 0;
    double saved = 0;

    if(mealFee < allowedExpenses) {
        saved = allowedExpenses - mealFee;
    }
    else {
        excess = mealFee - allowedExpenses;
    }

    mealFees(departMeal, 0, mealFee, 0);

    TEST_ASSERT_EQUAL_DOUBLE(mealFee, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(allowedExpenses, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());
}
void Should_add_Depart_Meal_Fee_Dinner_expenses() {
    int time = 1200;
    double mealFee = 15;
    double allowedExpenses = 16;
    int departMeal = eligibleDepartMeals(time);
    double excess = 0;
    double saved = 0;

    if(mealFee < allowedExpenses) {
        saved = allowedExpenses - mealFee;
    }
    else {
        excess = mealFee - allowedExpenses;
    }

    mealFees(departMeal, 0, mealFee, 0);

    TEST_ASSERT_EQUAL_DOUBLE(mealFee, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(allowedExpenses, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());
}

void Should_add_Arrival_Meal_Fee_Breakfast_expenses() {
    int time = 1300;
    double mealFee = 15;
    double allowedExpenses = 9;
    int arrivalMeal = eligibleArrivalMeals(time);
    double excess = 0;
    double saved = 0;

    if(mealFee < allowedExpenses) {
        saved = allowedExpenses - mealFee;
    }
    else {
        excess = mealFee - allowedExpenses;
    }

    mealFees(0, arrivalMeal, 0, mealFee);

    TEST_ASSERT_EQUAL_DOUBLE(mealFee, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(allowedExpenses, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}
void Should_add_Arrival_Meal_Fee_Lunch_expenses() {
    int time = 1900;
    double mealFee = 15;
    double allowedExpenses = 12;
    int arrivalMeal = eligibleArrivalMeals(time);
    double excess = 0;
    double saved = 0;

    if(mealFee < allowedExpenses) {
        saved = allowedExpenses - mealFee;
    }
    else {
        excess = mealFee - allowedExpenses;
    }

    mealFees(0, arrivalMeal, 0, mealFee);

    TEST_ASSERT_EQUAL_DOUBLE(mealFee, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(allowedExpenses, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}
void Should_add_Arrival_Meal_Fee_Dinner_expenses() {
    int time = 2345;
    double mealFee = 15;
    double allowedExpenses = 16;
    int arrivalMeal = eligibleArrivalMeals(time);
    double excess = 0;
    double saved = 0;

    if(mealFee < allowedExpenses) {
        saved = allowedExpenses - mealFee;
    }
    else {
        excess = mealFee - allowedExpenses;
    }

    mealFees(0, arrivalMeal, 0, mealFee);

    TEST_ASSERT_EQUAL_DOUBLE(mealFee, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(allowedExpenses, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(excess, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(saved, getAmountSaved());

    setTotalExpenses(0);
    setTotalAllowableExpenses(0);
    setExcessExpenses(0);
    setAmountSaved(0);
}

//INDIVIDUAL INVALID TESTS
void Should_reject_Private_car_expenses_Invalid_mile() {
    double mile = -1;
    privateCar(mile);
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Parking_fee_expenses_Invalid_fee() {
    double fees = -10;
    int days = 5;

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}
void Should_reject_Parking_fee_expenses_Invalid_day() {
    double fees = 10;
    int days = -5;

    parkingFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Rental_car_expenses_Invalid_day() {
    int days = -4;
    double pricePerDay = 29.99;

    rentalCar(days, pricePerDay);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Taxi_fee_expenses_Invalid_day() {
    int days = -6;
    double fees = 90;

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}
void Should_reject_Taxi_fee_expenses_Invalid_fee() {
    int days = 6;
    double fees = -90;

    taxiFees(days, fees);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Registration_fee_expenses_Invalid_fee() {
    double fees = -100;
    
    registrationFees(fees);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Hotel_fee_expenses_Invalid_day() {
    int days = 0;
    double totalFees = 150;

    hotelFees(days, totalFees);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}
void Should_reject_Hotel_fee_expenses_Invalid_fee() {
    int days = 2;
    double totalFees = -150;

    hotelFees(days, totalFees);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Airfare_expenses() {
    double fee = -1;

    airfare(fee);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Depart_Meal_Fee_Invalid_time() {
    int time = 1260;
    double mealFee = 15;
    int departMeal = eligibleDepartMeals(time);

    mealFees(departMeal, 0, mealFee, 0);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}
void Should_reject_Depart_Meal_Fee_Invalid_fee() {
    int time = 1000;
    double mealFee = -1;
    int departMeal = eligibleDepartMeals(time);

    mealFees(departMeal, 0, mealFee, 0);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Arrival_Meal_Fee_Invalid_time() {
    int time = 2260;
    double mealFee = 15;
    int arrivalMeal = eligibleArrivalMeals(time);

    mealFees(0, arrivalMeal, 0, mealFee);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_reject_Arrival_Meal_Fee_Invalid_fee() {
    int time = 1200;
    double mealFee = -1;
    int arrivalMeal = eligibleArrivalMeals(time);

    mealFees(0, arrivalMeal, 0, mealFee);

    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getTotalAllowableExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getExcessExpenses());
    TEST_ASSERT_EQUAL_DOUBLE(0, getAmountSaved());
}

void Should_add_all_fees() {
    int days = 5;
    double miles = 29;
    double rentalCarFee = 30.15;
    double parkingFee = 14.98;
    double taxiFee = 98.76;
    double registrationFee = 39.75;
    double hotelFee = 2;
    double airfareFee = 1000;
    int departTime = 800;
    int arrivalTime = 1000;
    double allowedDepartMealFee = 12;
    double allowedArrivalMealFee = 9;
    double departMealFee = 10.59;
    double arrivalMealFee = 12.12;

    double total = (miles * .27) + (rentalCarFee * days) + parkingFee + taxiFee + registrationFee + (hotelFee * (days - 1)) + airfareFee + departMealFee + arrivalMealFee;
    double totalAllowable = (days * (6 + 10)) + ((days - 1) * 90) + allowedDepartMealFee + allowedArrivalMealFee;

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
    if(90 > hotelFee) {
        saved += (days - 1) * (90 - hotelFee);
    }
    else {
        excess += (days - 1) * (hotelFee - 90);
    }
    //Depart Meal
    if(allowedDepartMealFee > departMealFee) {
        saved += allowedDepartMealFee - departMealFee;
    }
    else {
        excess += departMealFee - allowedDepartMealFee;
    }

    //Arrival Meal
    if(allowedArrivalMealFee > arrivalMealFee) {
        saved += allowedArrivalMealFee - arrivalMealFee;
    }
    else {
        excess += arrivalMealFee - allowedArrivalMealFee;
    }

    airfare(airfareFee);
    privateCar(miles);
    rentalCar(days, rentalCarFee);
    parkingFees(days, parkingFee);
    taxiFees(days, taxiFee);
    registrationFees(registrationFee);
    hotelFees(days, hotelFee);
    int arrivalMeal = eligibleArrivalMeals(arrivalTime);
    int departMeal = eligibleDepartMeals(departTime);
    mealFees(departMeal, arrivalMeal, departMealFee, arrivalMealFee);

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

    printf("            *****Private Car Tests*****\n");
    RUN_TEST(Should_add_Private_car_expenses);
    reset();
    RUN_TEST(Should_reject_Private_car_expenses_Invalid_mile);
    reset();

    printf("\n          *****Parking Fee Tests*****\n");
    RUN_TEST(Should_add_Parking_fee_expenses);
    reset();
    RUN_TEST(Should_reject_Parking_fee_expenses_Invalid_day);
    reset();
    RUN_TEST(Should_reject_Parking_fee_expenses_Invalid_fee);
    reset();

    printf("\n          *****Rental Car Tests*****\n");
    RUN_TEST(Should_add_Rental_car_expenses);
    reset();
    RUN_TEST(Should_reject_Rental_car_expenses_Invalid_day);
    reset();

    printf("\n          *****Taxi Fee Tests*****\n");
    RUN_TEST(Should_add_Taxi_fee_expenses);
    reset();
    RUN_TEST(Should_reject_Taxi_fee_expenses_Invalid_day);
    reset();
    RUN_TEST(Should_reject_Taxi_fee_expenses_Invalid_fee);
    reset();

    printf("\n          *****Registration Fee Tests*****\n");
    RUN_TEST(Should_add_Registration_fee_expenses);
    reset();
    RUN_TEST(Should_reject_Registration_fee_expenses_Invalid_fee);
    reset();

    printf("\n          *****Hotel Fee Tests*****\n");
    RUN_TEST(Should_add_Hotel_fee_expenses);
    reset();
    RUN_TEST(Should_reject_Hotel_fee_expenses_Invalid_day);
    reset();
    RUN_TEST(Should_reject_Hotel_fee_expenses_Invalid_fee);
    reset();

    printf("\n          *****Airfare Tests*****\n");
    RUN_TEST(Should_add_Airfare_expenses);
    reset();
    RUN_TEST(Should_reject_Airfare_expenses);
    reset();

    printf("\n          *****Depart Meal Fee Tests*****\n");
    RUN_TEST(Should_add_Depart_Meal_Fee_Breakfast_expenses);
    reset();
    RUN_TEST(Should_add_Depart_Meal_Fee_Lunch_expenses);
    reset();
    RUN_TEST(Should_add_Depart_Meal_Fee_Dinner_expenses);
    reset();
    
    RUN_TEST(Should_reject_Depart_Meal_Fee_Invalid_time);
    reset();
    RUN_TEST(Should_reject_Depart_Meal_Fee_Invalid_fee);
    reset();

    printf("\n          *****Arrival Meal Fee Tests*****\n");
    RUN_TEST(Should_add_Arrival_Meal_Fee_Breakfast_expenses);
    reset();
    RUN_TEST(Should_add_Arrival_Meal_Fee_Lunch_expenses);
    reset();
    RUN_TEST(Should_add_Arrival_Meal_Fee_Dinner_expenses);
    reset();

    RUN_TEST(Should_reject_Arrival_Meal_Fee_Invalid_time);
    reset();
    RUN_TEST(Should_reject_Arrival_Meal_Fee_Invalid_fee);
    reset();

    printf("\n          *****All Fee Tests*****\n");
    RUN_TEST(Should_add_all_fees);

    return UNITY_END();
}