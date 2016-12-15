#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
typedef struct Investment{

  int startingcash;
  float intrestrate;
  int maxmoney;
  int timescompoundedayear;

} Investment;
typedef struct Portfolio{
  int cash;
  struct Investment investments[];
} Portfolio;

typedef struct Date {
  int years;
  int months;
  int days;
  char display[50];

} Date;


float getAmountOfMoney( struct Investment d, int lengthoftime);
float getAmountOfTime(struct Investment d, int amountofmoney);
struct Date convertToDate(float startingyears);
void printDate(struct Date d);
struct Investment createInvestment();
void dateMarginOfError(struct Date d, float startingyears);
struct Investment generateInvestment(int seed);

int main(){
/*  Investment mydata = createInvestment();
  printf("Amount of Money after 5 years: %f \n", getAmountOfMoney(mydata,5));
  Date date = convertToDate( getAmountOfTime(mydata,100));
  printf("Number of years needed to reach $100: ");
  printDate(date);
  dateMarginOfError(date, getAmountOfTime(mydata,100));
*/

  Investment i[50];
  for(int x = 0; x<50; x++){
    i[x] = generateInvestment(x);
    Date d = convertToDate(getAmountOfTime(i[x],10000));
    dateMarginOfError(d, getAmountOfTime(i[x],10000));
  }


  return 0;
}

float getAmountOfMoney(struct Investment d, int lengthoftime){
  float num = d.startingcash*powf(1 + (d.intrestrate/d.timescompoundedayear),
                                  (lengthoftime*d.timescompoundedayear));
  return num;
}
float getAmountOfTime(struct Investment d, int amountofmoney){
  float num = (log10(amountofmoney/d.startingcash))/(d.timescompoundedayear *
               log10(1 + d.intrestrate/d.timescompoundedayear));
  return num;
}
struct Investment createInvestment(){
  Investment d;
  printf("How much money are you starting with?: ");
  scanf("%d", &d.startingcash);
  printf("What is your intrest rate on your investment: ");
  scanf( "%f",&d.intrestrate);
  printf("How many times a year is your intrest compounded: ");
  scanf("%i",&d.timescompoundedayear);
  return d;
}
struct Date convertToDate(float startingyears){
  Date date;
  int raw_days = floor(startingyears*365);
  int raw_months = floor(raw_days/30.42);
  date.years = floor(raw_months/12);
  date.months = floor(raw_months - date.years*12);
  date.days = floor(raw_days - raw_months*30.42);
  return date;
}
void printDate(struct Date d){
  printf("%i years, %i months, and %i days\n", d.years, d.months, d.days);
  return;
}
void dateMarginOfError(struct Date d, float startingyears){
  float combined_date = (d.years) + (d.months/12) + (d.days/365);
  float error = startingyears/combined_date;
  printf("the date is %f percent off \n",error);
  return;
}
struct Investment generateInvestment(int seed){
  Investment i;
  srand(seed);
  i.startingcash = rand() % 1000;
  i.intrestrate = (((float)(rand() % 20))/1000)+.01;
  /*printf("startingcash : %i,intrest rate : %f\n",i.startingcash, i.intrestrate);*/
  i.timescompoundedayear = 12;
  return i;

}
