#include <stdio.h>
#include <math.h>

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
struct Investment createInvestment();

int main(){
  Investment mydata = createInvestment();
  printf("Amount of Money after 5 years: %f \n", getAmountOfMoney(mydata,5));
  printf("Number of years needed to reach $100: %f \n", getAmountOfTime(mydata,100));

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
  printf("\nWhat is your intrest rate on your investment: ");
  scanf( "%f",&d.intrestrate);
  printf("\nHow many times a year is your intrest compounded: ");
  scanf("%i",&d.timescompoundedayear);
  return d;
}
struct Date convertToDate(float startingyears){
  Date date;
  date.years = floor(startingyears);
  date.months = floor((startingyears - date.years) * 12);
  
  return date;
}
