double allowedExpenses;
double static totalExpenses;
double static totalAllowableExpenses;
double static excessExpenses;
double static amountSaved;

//Calculates allowed expenses
void setTotalAllowedExpenses(double allowedExpenses, double dailyAllowedExpenses, int numberOfDays){
    allowedExpenses = dailyAllowedExpenses * numberOfDays;
    totalAllowableExpenses += allowedExpenses;;
 }

//Calculates total expenses
void setTotalExpenses(double totalExpenses, double fee){
    totalExpenses +=fee;
}
    
void setExcessExpenses(double allowedExpenses, double fee, double excessExpenses){
    if(fee-allowedExpenses > 0)
    {
        //Calculates excess expenses
        excessExpenses += (fee - allowedExpenses);
    }
}

void setSavedAmount(double allowedExpenses, double fee, double amountSaved){
    if(fee-allowedExpenses < 0)
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