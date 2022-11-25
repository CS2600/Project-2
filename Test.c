/* 
* Documentation: https://github.com/ThrowTheSwitch/Unity
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

void Total_expenses_with_private_car(void)
{
    double mile = 10;
    double totalExpenses = mile * 0.27;
    privateCar(mile);
    TEST_ASSERT_EQUAL_DOUBLE(getTotalExpenses(), totalExpenses);
}

int main(void)
{
UNITY_BEGIN();

//TOTAL EXPENSES
RUN_TEST(Total_expenses_with_private_car);

//ALLOWABLE EXPENSES

//EXCESS EXPENSES

//AMOUNT SAVED

return UNITY_END();
}