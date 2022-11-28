double allowedExpenses;
double static totalExpenses;
double static totalAllowableExpenses;
double static excessExpenses;
double static amountSaved;

void calculateExpenses(double fee, double dailyAllowedExpenses, int numberOfDays){

    //Calculates allowed expenses
    allowedExpenses = dailyAllowedExpenses * numberOfDays;
    totalAllowableExpenses += allowedExpenses;

    //Calculates total expenses
    totalExpenses +=fee;

    
    if(fee-allowedExpenses > 0)
    {
        //Calculates excess expenses
        excessExpenses += (fee - allowedExpenses);
    }
    else
    {
        //Calculates amount saved
        amountSaved += (allowedExpenses - fee);
    }
}


double getTotalExpenses(){
    return totalExpenses;
}
double getTotalAllowableExpenses(){
    return totalAllowableExpenses;
}
double getExcessExpenses(){
    return excessExpenses;
}
double getAmountSaved(){
    return amountSaved;
}