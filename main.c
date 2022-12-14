#include "Fees.h"
#include "FeesCalculator.h"
#include<stdio.h>
#include <ctype.h>
#include<stdbool.h>

int main(void)
{
    int choice = 0; 
    int totalNumOfDays = 0;
    int departureTime = 0;
    double departMeal = 0.0;
    int arrivalTime = 0;
    double arriveMeal = 0.0;
    int carRented = 0; 
    double priceCarRent = 0.0;
    double totalRentPrice = 0.0; 
    int privCarUsed = 0;
    double milesDriven = 0.0;
    double privateCarCost = 0.0;
    int taxiWasUsed = 0;
    int taxiDays = 0;
    double taxiCost = 0.0; 
    double hotelCost = 0.0;
    double totalHotelCost = 0.0;
    int daysParked = 0; 
    double parkingCost = 0.0;
    double totalParkingCost = 0.0;
    double airfareCost = 0.0; 
    double conferenceCost = 0.0;

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
            fflush(stdin);
            scanf("%d", &totalNumOfDays);
            while(totalNumOfDays < 1)
            {
                printf("Invalid input! Please enter at least 1 for total number of days: ");
                fflush(stdin);
                scanf("%d", &totalNumOfDays);
            }

            //Gets user's departure time
            printf("Enter your departure time on the first day in 24-hour format (ex. 0059 for 12:59am and 1500 for 3:00pm): ");
            fflush(stdin);
            scanf("%d", &departureTime);
            while(departureTime < 0 || departureTime > 2359 || departureTime%100 > 59)    //Validates departure time is before 6:00pm
            {
                printf("Invalid time! Please enter a valid time format: ");
                fflush(stdin);
                scanf("%d", &departureTime);
            }
            //Validates and asks for eligible meal fee based on departure time
            if (eligibleDepartMeals(departureTime) == 1)
            {
                printf("You're eligible for a covered breakfast! Enter the cost of your breakfast: ");
                fflush(stdin);
                scanf("%f", &departMeal);
            }
            else if (eligibleDepartMeals(departureTime) == 2)
            {
                printf("You're eligible for a covered lunch! Enter the cost of your lunch: ");
                fflush(stdin);
                scanf("%f", &departMeal);
            }
            else if (eligibleDepartMeals(departureTime) == 3)
            {
                printf("You're eligible for a covered dinner! Enter the cost of your dinner: ");
                fflush(stdin);
                scanf("%f", &departMeal);
            }
            else
            {
                printf("Sorry, you are not eligible for a covered meal.\n");
            }

            //Gets user's arrival time
            printf("Enter your arrival time on the last day in 24-hour format (ex. 0801 for 8:01am and 2200 for 10:00pm): ");
            fflush(stdin);
            scanf("%d", &arrivalTime);
            while(arrivalTime < 0 || arrivalTime > 2359 || arrivalTime%100 > 59)    //Validates arrival time is after 8:00am
            {
                printf("Invalid time! Please enter a valid time format: ");
                fflush(stdin);
                scanf("%d", &arrivalTime);
            }
            //Validates and asks for eligible meal fee based on arrival time
            if (eligibleArrivalMeals(arrivalTime) == 6)
            {
                printf("You're eligible for a covered breakfast! Enter the cost of your breakfast: ");
                fflush(stdin);
                scanf("%f", &arriveMeal);
            }
            else if (eligibleArrivalMeals(arrivalTime) == 7)
            {
                printf("You're eligible for a covered lunch! Enter the cost of your lunch: ");
                fflush(stdin);
                scanf("%f", &arriveMeal);
            }
            else if (eligibleArrivalMeals(arrivalTime) == 8)
            {
                printf("You're eligible for a covered dinner! Enter the cost of your dinner: ");
                fflush(stdin);
                scanf("%f", &arriveMeal);
            }
            else
            {
                printf("Sorry, you are not eligible for a covered meal.\n");
            }    

            //Calculates covered meal costs for first and last day
            mealFees(eligibleDepartMeals(departureTime), eligibleArrivalMeals(arrivalTime), departMeal, arriveMeal);   //double check if can pass function in function

            //Asks user if rented car was used
            printf("\nDid you rent a car during your trip? Enter 1 for true and 0 for false: ");
            fflush(stdin);
            scanf("%d", &carRented);
            while(carRented != 0 && carRented != 1)
            {
                printf("Invalid input! Please enter 1 for true and 0 for false: ");     //Validates user's input
                fflush(stdin);
                scanf("%d", &carRented);
            }
            //If rental car was used
            if(carRented == 1)
            {
                printf("Enter your rental price per day: ");
                fflush(stdin);
                scanf("%f", &priceCarRent);
                totalRentPrice = rentalCar(totalNumOfDays, priceCarRent);   //Calculates rental car fees
            }
            
            //Asks user if private car was used
            printf("\nDid you use a private car during your trip? Enter 1 for true and 0 for false: ");
            fflush(stdin);
            scanf("%d", &privCarUsed);
            while(privCarUsed != 0 && privCarUsed != 1)       //Validates user's input
            {
                printf("Invalid input! Please enter 1 for true and 0 for false: ");
                fflush(stdin);
                scanf("%d", &privCarUsed);
            }
            //If private car was used
            if(privCarUsed == 1)
            {
                printf("Enter the total miles driven: ");
                fflush(stdin);
                scanf("%f", &milesDriven);
                while(milesDriven < 0)      //Validates user's input
                {
                    printf("Invalid input! Please enter total miles drive: ");
                    fflush(stdin);
                    scanf("%f", &milesDriven);
                    privateCarCost = privateCar(milesDriven);   //Calculates private car fees
                }
            } 
            fflush(stdin);
            
            //Asks user if taxi was used 
            printf("\nDid you use taxi during your trip? Enter 1 for true and 0 for false: ");
            fflush(stdin);
            scanf("%d", &taxiWasUsed); 
            while(taxiWasUsed != 0 && taxiWasUsed != 1)   //Validates user's input
            {   
                printf("Invalid input! Please enter 1 for true and 0 for false: ");
                fflush(stdin);
                scanf("%d", &taxiWasUsed);
            }
            //If taxi was used 
            if(taxiWasUsed == 1)
            { 
                printf("Enter the number of days you took a taxi: ");
                fflush(stdin);
                scanf("%d", &taxiDays);
                while(taxiDays < 0 || taxiDays > totalNumOfDays)    //Validates user's input
                {
                    printf("\nInvalid input! Please enter the number of days you took a taxi: ");
                    fflush(stdin);
                    scanf("%d", &taxiDays);
                }

                printf("Enter total taxi cost during your trip: ");
                fflush(stdin);
                scanf("%f", &taxiCost);
                taxiFees(taxiDays, taxiCost);   //Calculates taxi fee covered by company
            }
            
            //Asks user for hotel cost 
            printf("\nEnter hotel cost per night: ");
            fflush(stdin);
            scanf("%lf", &hotelCost);
            totalHotelCost = hotelFees(totalNumOfDays-1, hotelCost);  //Calculates hotel fees

            //Asks user for parking cost
            printf("\nEnter number of days for parking: "); 
            fflush(stdin);
            scanf("%d", &daysParked); 
            while(daysParked < 0 || daysParked > totalNumOfDays)     //Validates user's input
            {
                printf("Invalid input! Please enter number of days for parking: ");
                fflush(stdin);
                scanf("%d", &daysParked); 
            }
            printf("Enter total parking cost: ");
            fflush(stdin);
            scanf("%lf", &parkingCost);
            totalParkingCost = parkingFees(daysParked, parkingCost);    //Calculates parking fees

            //Asks user for airfare fees
            printf("\nEnter the amount of any round-trip airfare: ");
            fflush(stdin);
            scanf("%lf", &airfareCost);
            while(airfareCost < 0)
            {
                printf("Invalid input! Please enter amount of any round-trip airfare: ");
                fflush(stdin);
                scanf("%lf", &airfareCost);
            }
            airfareCost = airfare(airfareCost);     //Calculates airfare fees

            //Asks user for conference fees
            printf("\nEnter the total amount of any conference or seminar fees: ");
            fflush(stdin);
            scanf("%lf", &conferenceCost);
            while(conferenceCost < 0)       //Validates user's input
            {
                printf("Invalid input! Enter the total amount of any conference or seminar fees: ");
                fflush(stdin);
                scanf("%lf", &conferenceCost);
            }
            conferenceCost = registrationFees(conferenceCost);   //Calculates registration fees
            fflush(stdin);

            //DISPLAY INFORMATION
            printf("\nThe total expenses incurred by the businessperson: $%.2lf", getTotalExpenses());
            printf("\nThe total allowable expenses for the trip: $%.2lf", getTotalAllowableExpenses()); 
            printf("\nTotal money saved is: $%.2lf", getAmountSaved());
            printf("\nTotal reimbursement is: $%.2lf", getExcessExpenses());
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