//Days Between Two Dates
int DaysInMonth(int month, int year);
/*
 * Complete the function below.
 */
int DaysBetween(int year1, int month1, int day1, int year2, int month2, int day2) 
{
    int total = 0;
    long int days1 = year1* 365 + day1;
    long int days2 = year2* 365 + day2;
    int leap = 0;
    for(int z = year1; z < year2 ; z++)
    {
        if(DaysInMonth(2,z) == 29)
        {
            leap++;
        }
    }
    for(int i = 1; i < month1; i++)
    {
        days1 += DaysInMonth(i, year1);
    }
    for(int u = 1; u < month2; u++)
    {
        days2 += DaysInMonth(u, year2);
    }
    total = days2 - days1 + leap;
    return total;
}