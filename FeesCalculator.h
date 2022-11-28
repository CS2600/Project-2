double allowedExpenses;
double static totalExpenses;
double static totalAllowableExpenses;
double static excessExpenses;
double static amountSaved;

//Calculates allowed expenses
void calculateExpenses(double fee, double dailyAllowedExpenses, int numberOfDays){
    allowedExpenses = dailyAllowedExpenses * numberOfDays;
    totalAllowableExpenses += allowedExpenses;;
 
//Calculates total expenses
    totalExpenses +=fee;
    
    if(fee-allowedExpenses > 0)
    {
        //Calculates excess expenses
        excessExpenses += (fee - allowedExpenses);
    }

    if(fee-allowedExpenses < 0)
    {
        //Calculates amount saved
        amountSaved += (allowedExpenses - fee);
    }
}

void setTotalExpenses(double fee){
    totalExpenses = fee;
}
void setTotalAllowableExpenses(double fee){
    totalAllowableExpenses = fee;
}
void setExcessExpenses(double fee){
    excessExpenses = fee;
}
void setAmountSaved(double fee){
    amountSaved = fee;
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