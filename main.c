#include "Fees.h"
#include "FeesCalculator.h"
#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    int choice = 0; 
    int totalNumOfDays = 0; 
    int departureTime = 0;
    double departMeal = 0.0;
    int arrivalTime = 0;
    double arriveMeal = 0.0;
    bool carRented = false; 
    double priceCarRent = 0.0;
    double totalRentPrice = 0.0; 
    bool privCarUsed = false;
    double milesDriven = 0.0;
    double privateCarCost = 0.0;
    bool taxiWasUsed = false;
    int taxiDays = 0;
    double taxiCost = 0.0; 
    double hotelCost = 0.0;
    double totalHotelCost = 0.0;
    int daysParked = 0; 
    double parkingCost = 0.0;
    double totalParkingCost = 0.0;
    double airfareCost = 0.0; 
    double conferenceCost = 0.0;
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
            printf("How many days was your trip? ");
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
            //Validates and asks for eligible meal fee based on departure time
            if (eligibleDepartMeals(departureTime) == 1)
            {
                printf("You're eligible for a covered breakfast! Enter the cost of your breakfast: ");
                scanf("%f", &departMeal);
            }
            else if (eligibleDepartMeals(departureTime) == 2)
            {
                printf("You're eligible for a covered lunch! Enter the cost of your breakfast: ");
                scanf("%f", &departMeal);
            }
            else if (eligibleDepartMeals(departureTime) == 3)
            {
                printf("You're eligible for a covered dinner! Enter the cost of your breakfast: ");
                scanf("%f", &departMeal);
            }
            else
            {
                printf("Sorry, you are not eligible for a covered meal.");
            }

            //Gets user's arrival time
            printf("Enter your arrival time on the last day in 24-hour format (ex. 0801 for 8:01am and 2200 for 10:00pm): ");
            scanf("%d", &arrivalTime);
            while(arrivalTime < 801)    //Validates arrival time is after 8:00am
            {
                printf("Invalid time! Please enter a valid time format: ");
                scanf("%d", &arrivalTime);
            }
            //Validates and asks for eligible meal fee based on arrival time
            if (eligibleArrivalMeals(arrivalTime) == 6)
            {
                printf("You're eligible for a covered breakfast! Enter the cost of your breakfast: ");
                scanf("%f", &arriveMeal);
            }
            else if (eligibleArrivalMeals(arrivalTime) == 7)
            {
                printf("You're eligible for a covered lunch! Enter the cost of your breakfast: ");
                scanf("%f", &arriveMeal);
            }
            else if (eligibleArrivalMeals(arrivalTime) == 8)
            {
                printf("You're eligible for a covered dinner! Enter the cost of your breakfast: ");
                scanf("%f", &arriveMeal);
            }
            else
            {
                printf("Sorry, you are not eligible for a covered meal.");
            }    

            //Calculates covered meal costs for first and last day
            mealFees(eligibleDepartMeals(departureTime), eligibleArrivalMeals(arrivalTime), departMeal, arriveMeal);   //double check if can pass function in function

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
                scanf("%f", &milesDriven);
                while(milesDriven < 0)      //Validates user's input
                {
                    printf("Invalid input! Please enter total miles drive: ");
                    scanf("%f", &milesDriven);
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
                    printf("\nInvalid input! Please enter the number of days you took a taxi: ");
                    scanf("%d", &taxiDays);
                }

                printf("Enter total taxi cost during your trip: ");
                scanf("%f", &taxiCost);
                taxiFees(taxiDays, taxiCost);   //Calculates taxi fee covered by company
            }
            
            //Asks user for hotel cost 
            printf("\nEnter hotel cost per night: ");
            scanf("%lf", &hotelCost);
            totalHotelCost = hotelFees(totalNumOfDays-1, hotelCost);  //Calculates hotel fees

            //Asks user for parking cost
            printf("\nEnter number of days for parking: "); 
            scanf("%d", &daysParked); 
            while(daysParked < 0 || daysParked > totalNumOfDays)     //Validates user's input
            {
                printf("Invalid input! Please enter number of days for parking: ");
                scanf("%d", &daysParked); 
            }
            printf("Enter total parking cost: ");
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
            airfareCost = airfare(airfareCost);     //Calculates airfare fees

            //Asks user for conference fees
            printf("\nEnter the total amount of any conference or seminar fees: ");
            scanf("%lf", &conferenceCost);
            while(conferenceCost < 0)       //Validates user's input
            {
                printf("Invalid input! Enter the total amount of any conference or seminar fees: ");
                scanf("%lf", &conferenceCost);
            }
            conferenceCost = registrationFees(conferenceCost);   //Calculates registration fees
            fflush(stdin);

            //DISPLAY INFORMATION
            printf("\nThe total expenses incurred by the businessperson: $%.2lf", getTotalExpenses());
            printf("The total allowable expenses for the trip: $%.2lf", getTotalAllowableExpenses()); 
            printf("\nTotal money saved is: $%.2lf", getAmountSaved());
            printf("Total reimbursement is: $%.2lf", getExcessExpenses());
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