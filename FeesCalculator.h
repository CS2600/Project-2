double allowedExpenses;
double static totalExpenses;
double static totalAllowableExpenses;
double static excessExpenses;
double static amountSaved;

void calculateExpenses(double fee, double dailyAllowedExpenses, int numberOfDays);

void setTotalExpenses(double fee);
void setTotalAllowableExpenses(double fee);
void setExcessExpenses(double fee);
void setAmountSaved(double fee);

double getTotalExpenses();
double getTotalAllowableExpenses();
double getExcessExpenses();
double getAmountSaved();

