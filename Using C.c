#include <stdio.h>
#define str 1900

void prnt();
void cal();


int leap(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
     return 1;
    return 0;
}


int getTotalLeap(int year)
{
    int dif = year - 1900;
    int leap = dif/4;

    if (dif >= 200)
    {
        leap += 1; //for 2000 which is leap
        leap -= dif/100; //every 100 years 1 leap less
    }

    if (dif-100 >= 400)//#100 for 2000 which is leap
    {
        leap += (dif-100)/400; //every 400 years 1 leap more
    }

    return leap;
}


int mondays(int mon,int y)
{
   int cnt = leap(y);
   if(cnt == 1 && mon == 2)
       return 29;
   else if (mon == 2)
       return 28;
   else if (mon == 4 ||mon == 6||mon == 9||mon == 11)     
       return 30;
   else
     return 31;
}


int days(int y,int mon)
{
    int leapYears = getTotalLeap(y);
    int ordinaryYears = (y - 1900) - leapYears;
    int totalDays =  ordinaryYears * 365;
    totalDays +=  leapYears * 366;

    for(int i=1; i<mon; i++)
    {
        totalDays += mondays(i,y);
    }
    return totalDays;
}


void main ()
{
    int y = 0,m = 0;
    printf("Enter the year and month ==> ");
    scanf("%d %d",&y, &m);
    
   lbl:
   cal(y,m);
    
    char c;
    printf("\nEnter your choice\n(S) Previous year\n(W) Next year\n(A) Previous month\n(D) Next month\n==> ");
    scanf(" %c", &c);
     if(c == 'W')
     {
        y += 1;
        goto lbl;
     }

    else if (c == 'S')
    {
        y -= 1; 
        goto lbl;
    }
        
    else if (c == 'A')
    {
        m -= 1;
        goto lbl;
    }
       
    else if (c == 'D')
    { 
        m += 1; 
        goto lbl;
    } 
}

void cal(int y,int m)
{
    int monday, Total_day,*ptr, cnt = 1;
    int arr[6][7] = {0};
    monday = mondays(m,y);
    Total_day = days(y,m);
    ptr = &arr[0][0];
    

    for (int i = Total_day % 7 + 1; i <= (monday + Total_day % 7); i++)
     {
        ptr[i] = cnt;
        cnt++;
     }
     prnt(arr,y,m);
}

void prnt(int arr[6][7],int y,int m)
{
    char arr2[12][5] = 
    {
        "Jan","Feb","Mar","Apl","May","Jun","Jul",
        "Aug","Sep","Oct","Nov","Dec"
    };

    printf("\n\n\t%s  %d\n\n",arr2[m - 1],y);
    printf("S    M    T    W    T    F    S\n");
    printf("----------------------------------\n");
     for (int i = 0; i < 6; i++)
     {
        for (int j = 0; j < 7; j++)
        {
            if(arr[i][j] == 0)
              printf("     ");
            
            else
             printf("%-4d ",arr[i][j]);
        }
         printf("\n");
     }
}