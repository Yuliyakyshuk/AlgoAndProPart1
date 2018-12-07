#include <conio.h>
#include <stdio.h>
#include <math.h>
int dv_intrit (int x)
{
    int c,count=0,st=1,r=0;
    while(x>0){ 
               c=x%10;
               r+=c*st;
               count++;
               st=int(pow(2,count));
               x/=10 ;
             }
    x=r;
    c=0;st=1;r=0;
    while(x>0){     // переведення з десяткової у трійкову                  
              int c=x%3;
              r+=c*st;
              x/=3 ;
              st*=10;  
             }
return r;
}

// printt - функція зі змінною кількістю параметрів
void printt(int k,...){
    int *p = &k; //налаштували вказівник на параметр k - кількість для кожного різна

    for ( ; k!=0;k--)// цикл, в якому зменшується К
    {       *p++; // переводимо вказівник на наступне після к число
            // викликаємо функцію dv_intrit
           printf ("x(2)=%d \t x(3)=%d\n",*p,dv_intrit(*p)); 
    }
}


int main( ) 
{
printf("Perevedennya z dvijkovoi d nhsqrjde cbcntve \n\n");
printf ("1 grupa - 3 parametry\n");
printt(3,101,111,1111); 
printf("\n");
printf("2 grupa  6 parametriv \n");
printt(6,111,100,10011,1111100,101010,1111110);
printf("\n");
printf ("3 grupa 7 parametriv\n");
printt(7,111,100,10011,1111100,101010,1111110,1110011100); 
getch();

}
