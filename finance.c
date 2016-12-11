#include <stdio.h>
#include <math.h>

typedef struct Data{

  int startingcash;
  float intrestrate;
  int timescompoundedayear;

} Data;


float getAmountOfMoney( struct Data d, int lengthoftime);
float getAmountOfTime(struct Data d, int amountofmoney);
struct Data createInvestment();

void main(){
  Data mydata = createInvestment();
  printf("Amount of Money after 5 years: %f \n", getAmountOfMoney(mydata,5));
  printf("Number of years needed to reach $100: %f \n", getAmountOfTime(mydata,100));
}

float getAmountOfMoney(struct Data d, int lengthoftime){
  float num = d.startingcash*powf(1 + (d.intrestrate/d.timescompoundedayear),
                                  (lengthoftime*d.timescompoundedayear));
  return num;
}
float getAmountOfTime(struct Data d, int amountofmoney){
  float num = (log10(amountofmoney/d.startingcash))/(d.timescompoundedayear *
               log10(1 + d.intrestrate/d.timescompoundedayear));
  return num;
}
struct Data createInvestment(){
  Data d;
  int a;
  printf("How much money are you starting with?: ");
  scanf("%d", &d.startingcash);
  printf("\nWhat is your intrest rate on your investment: ");
  scanf( "%f",&d.intrestrate);
  printf("\nHow many times a year is your intrest compounded: ");
  scanf("%i",&d.timescompoundedayear);
  return d;
}
