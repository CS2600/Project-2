//#include "Fees.h"
//#include "FeesCalculator.h"
#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    int choice = 0; 
    int totalNumOfDays = 0; 
    int departureTime = 0;
    int arrivalTime = 0;
    bool carRented = false; 
    double priceCarRent = 0.0; 
    bool privCarUsed = false;
    double milesDriven = 0.0;
    double privateCarCost = 0.0;
    bool taxiWasUsed = false;
    int taxiDays = 0;
    double taxiCost = 0.0; 
    double hotelCost = 0.0;
    double totalHotelCost = 0.0;
    double hotelCostByCompany = 0.0;    //might not need
    int daysParked = 0; 
    double parkingCost = 0.0;
    double totalParkingCost = 0.0;
    double parkingCostComp = 0.0;       //might not need
    double airfareCost = 0.0; 
    double conferenceCost = 0.0; 
    double breakfast = 0.0;
    double lunch = 0.0;
    double dinner = 0.0;
    double totalFoodCost = 0.0; 
    int numOfBreakfast = 0;
    int numOfLunch = 0;
    int numOfDinner = 0; 
    double companyCovFood = 0;      //might not need
    double totalExpenses = 0;
    double companyCovExpenses = 0;  //might not need
    double taxi = 0;
    double companyCovTaxi  = 0;     //might not need
    double totalRentPrice = 0;
    double reimbursement = 0.0;
    double moneySaved = 0.0; 

    printf("Welcome! This program calculates and displays the total expenses during a trip.");
    
    do
    {
        fflush(stdin);
        printf("\nWould you like to use this program:\nPress 1 if yes\nPress 2 to quit the program\n");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            //Gets user's total number of days on trip 
            printf("How many days was your trip?");
            scanf("%d", &totalNumOfDays);
            while(totalNumOfDays < 1)
            {
                printf("Invalid input! Please enter at least 1 for total number of days: ");
                scanf("%d", &totalNumOfDays);
            }

            //Gets user's departure time
            printf("Enter your departure time on the first day in 24-hour format (ex. 0059 for 12:59am and 1500 for 3:00pm): ");
            scanf("%d", &departureTime);
            while(departureTime < 0 || departureTime > 1759)    //Validates departure time is before 6:00pm
            {
                printf("Invalid time! Please enter a valid time format: ");
                scanf("%d", &departureTime);
            }

            //Gets user's arrival time
            printf("Enter your arrival time on the last day in 24-hour format (ex. 0801 for 8:01am and 2200 for 10:00pm): ");
            scanf("%d", &arrivalTime);
            while(arrivalTime < 801)    //Validates arrival time is after 8:00am
            {
                printf("Invalid time! Please enter a valid time format: ");
                scanf("%d", &arrivalTime);
            }    

            //Asks user if rented car was used
            printf("\nDid you rent a car during your trip? Enter 1 for true and 0 for false: ");
            scanf("%d", &carRented);
            while(carRented < 0 || carRented > 1)
            {
                printf("Invalid input! Please enter 1 for true and 0 for false: ");     //Validates user's input
                scanf("%d", &carRented);
            }
            //If rental car was used
            if(carRented == 1)
            {
                printf("Enter your rental price per day: ");
                scanf("%f", &priceCarRent);
                totalRentPrice = rentalCar(totalNumOfDays, priceCarRent);   //Calculates rental car fees
            }
            
            //Asks user if private car was used
            printf("\nDid you use a private car during your trip? Enter 1 for true and 0 for false: ");
            scanf("%d", &privCarUsed);
            while(privCarUsed < 0 || privCarUsed > 1)       //Validates user's input
            {
                printf("Invalid input! Please enter 1 for true and 0 for false: ");
                scanf("%d", &privCarUsed);
            }
            //If private car was used
            if(privCarUsed == 1)
            {
                printf("Enter the total miles driven: ");
                scanf("%f", milesDriven);
                while(milesDriven < 0)      //Validates user's input
                {
                    printf("Invalid input! Please enter total miles drive: ");
                    scanf("%f", milesDriven);
                    privateCarCost = privateCar(milesDriven);   //Calculates private car fees
                }
            } 
            fflush(stdin);
            
            //Asks user if taxi was used 
            printf("\nDid you use taxi during your trip? Enter 1 for true and 0 for false: ");
            scanf("%d", &taxiWasUsed); 
            while(taxiWasUsed < 0 || taxiWasUsed > 1)   //Validates user's input
            {   
                printf("Invalid input! Please enter 1 for true and 0 for false: ");
                 scanf("%d", &taxiWasUsed);
            }
            //If taxi was used 
            if(taxiWasUsed == 1)
            { 
                printf("Enter the number of days you took a taxi: ");
                scanf("%d", &taxiDays);
                while(taxiDays < 0 || taxiDays > totalNumOfDays)    //Validates user's input
                {
                    printf("\nInvalid input!\nPlease enter the number of days you took a taxi: ");
                    scanf("%d", &taxiDays);
                }

                printf("Enter total taxi cost during your trip: ");
                scanf("%f", &taxiCost);
                //companyCovTaxi(taxiDays);   //Calculates taxi fee covered by company
            }
            
            //Asks user for hotel cost 
            printf("\nEnter hotel cost per night: ");
            scanf("&lf", &hotelCost);
            totalHotelCost = hotelFees(totalNumOfDays, hotelCost);  //Calculates hotel fees

            //Asks user for parking cost
            printf("\nEnter number of days for parking: "); 
            scanf("%d", &daysParked); 
            while(daysParked <0 || daysParked > totalNumOfDays)     //Validates user's input
            {
                printf("Invalid input! Please enter number of days for parking: ");
                scanf("%d", &daysParked); 
            }
            printf("Enter parking cost per day: ");
            scanf("%lf", &parkingCost);
            totalParkingCost = parkingFees(daysParked, parkingCost);    //Calculates parking fees

            //Asks user for airfare fees
            printf("\nEnter the amount of any round-trip airfare: ");
            scanf("%lf", &airfareCost);
            while(airfareCost < 0)
            {
                printf("Invalid input! Please enter amount of any round-trip airfare: ");
                scanf("%lf", &airfareCost);
            }

            //Asks user for conference fees
            printf("\nEnter the total amount of any conference or seminar fees: ");
            scanf("%lf", &conferenceCost);
            while(conferenceCost < 0)       //Validates user's input
            {
                printf("Invalid input! Enter the total amount of any conference or seminar fees: ");
                scanf("%lf", &conferenceCost);
            }
            fflush(stdin);

            //Asks user for meal fees
            printf("Enter total breakfast cost for your trip: ");       //Breakfast
            scanf("%lf", &breakfast);
            while(breakfast < 0)
            {
                printf("Invalid input! Please enter total breakfast cost for your trip: ");
                scanf("%lf", &breakfast);
            }
            fflush(stdin);
            printf("Enter total lunch cost for your trip: ");       //Lunch
            scanf("%lf", &lunch);
            while(lunch < 0)
            {
                printf("Invalid input! Please enter total lunch cost for your trip: ");
                scanf("%lf", &lunch);
            }
            fflush(stdin);
            printf("Enter total dinner cost for your trip: ");      //Dinner
            scanf("%lf", &dinner);
            while(breakfast < 0)
            {
                printf("Invalid input! Please enter total dinner cost for your trip: ");
                scanf("%lf", &dinner);
            }
            totalFoodCost = breakfast + lunch + dinner; 
            
            //Number of meals covered by company
            
            
            //TOTAL EXPENSES 
            totalExpenses = totalFoodCost + airfareCost + conferenceCost + parkingCost + hotelCost + taxi + privateCarCost + totalRentPrice;
            companyCovExpenses = companyCovFood + parkingCostComp + hotelCostByCompany + companyCovTaxi;
            
            //DISPLAY INFORMATION
            printf("\nThe total expenses incurred by the businessperson: %.2lf", getTotalExpenses());
            printf("The total allowable expenses for the trip, %.2lf", getTotalAllowableExpenses()); 
            printf("\nTotal money saved is: %.2lf", getAmountSaved());
            printf("Total reimbursement is: %.2lf", getExcessExpenses());
        }
        else if(choice == 2)
        {
            printf("\nThank you for choosing our program."); 
        }
        else
        {
            printf("Invalid input!"); 
        }
    } while(choice != 2);
}