#include <stdio.h>
int main(){
float dividend;
float divisor;
int res = 0;
do{
  printf("Hola, ingrese el dividendo: \n");
  scanf("%f",&dividend);
  printf("Ingrese el divisor: \n");
  scanf("%f",&divisor);
}while(divisor==0);
float temp, temp2;
temp = dividend;
if((temp < 0) ^ (divisor < 0)){
  if(temp<0){
    temp2 = temp+divisor;
    while(temp2<=0){
    temp= temp + divisor;
    res-- ;
    temp2 = temp+divisor;
    }
  }
  else{
  temp2 = temp+divisor;
  while(temp2>=0){
    temp= temp + divisor;
    res-- ;
    temp2 = temp+divisor;
    }
  }
}else if(temp>0 && divisor > 0){
  while(temp>=divisor){
    temp= temp - divisor;
    res++;
  }
}
else{
  if(dividend == 0){
    res = 0;
  }
else{
  while(temp<=divisor){
    temp= temp - divisor;
    res++;
  }
}
}
printf("residuo: %.2f\n", temp);
printf("resultado: %d\n", res);
return 0;
}
