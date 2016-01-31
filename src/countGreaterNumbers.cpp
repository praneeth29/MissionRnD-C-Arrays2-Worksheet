/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
    int d,m,y,i,c=0;
    int dt,mt,yt;
    int daysinmonth[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int flag=0;
    d=((int)date[0]-'0')*10+(int)date[1]-'0';
    m=((int)date[3]-'0')*10+(int)date[4]-'0';
    y=((int)date[6]-'0')*1000+((int)date[7]-'0')*100+((int)date[8]-'0')*10+((int)date[9]-'0');
    if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        daysinmonth[1]=29;
    if (m<13 && m>0)
   {
    if( d <= daysinmonth[m-1] && d > 0)
        flag=1;
   }
    if(flag==0)
        return NULL;
    //printf("%s",date);
    for(i=0;i<len;i++)
    {
        flag=0;
        dt=((int)Arr[i].date[0]-'0')*10+((int)Arr[i].date[1]-'0');
        mt=((int)Arr[i].date[3]-'0')*10+((int)Arr[i].date[4]-'0');
        yt=((int)Arr[i].date[6]-'0')*1000+((int)Arr[i].date[7]-'0')*100+((int)Arr[i].date[8]-'0')*10+((int)Arr[i].date[9]-'0');
        if(yt % 400 == 0 || (yt % 100 != 0 && yt % 4 == 0))
        daysinmonth[1]=29;
         if (mt<13 && mt>0)
        {
            if( dt <= daysinmonth[m-1] && dt > 0)
            flag=1;
        }
        if(flag==0)
            return NULL;
        if(yt<y)
            continue;
        else if(yt==y)
        {
            if(mt<m)
                continue;
            else if(mt==m)
            {
                if(dt<=d)
                    continue;
                else c++;
            }
            else c++;
        }
        else c++;
    }
    printf("%d",c);
	return c;
}
