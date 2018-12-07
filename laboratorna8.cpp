#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct EMPLOYEE
{
char name [40]; 
char adres [40];
int number;
char sport [40];
}EMPLOYEE;
// процедура виведення вмісту файла на екран
void printInfo(EMPLOYEE info) {
    	printf("%s\t%s\t%d\t%s\n", info.name, info.adres,info.number,info.sport); 
}

// основний модуль
int main ()
{
 int nn=3;
 FILE *f;	// вказівник пов'язаний з файлом
 EMPLOYEE e;	// змінна
 EMPLOYEE mas[nn];	//масив
 int i;

  
 if ((f = fopen("f.dat", "wb")) == NULL)//відкриваємо файл
  {
    printf("Error opening file ");// якщо при відкритті файлу виникає помилка, то виходимо з функції
    getchar();
    return 0;
  }

for(i=1; i<=nn;i++)
{//формуємо запис е
   printf("name of stadion="); scanf("%39s",&e.name);
   printf("adres of stadion="); scanf("%39s",&e.adres);
   printf("number of place="); scanf("%d",&e.number);
   printf("sport="); scanf("%39s",&e.sport);
   // записуємо запис е у файл
   fwrite(&e, sizeof(EMPLOYEE),1,f);
   if (ferror(f)!=NULL) printf ("exit\n");
}
fclose(f);

  if ((f = fopen("f.dat", "rb")) == NULL)//відкрили файл для читання записів з файлу
  {
    printf("Error opening file ");// якщо при відкритті файлу виникає помилка, то виходимо з функції
    getchar();
    return 0;
  }
  char nameSeach[40];
  printf ("Get name\n");scanf("%s",nameSeach); // задаємо запис, який треба вилучити
  printf ("resultat\n"); 
  i=0;
  while (fscanf (f, "%s%s%d%s", &(mas[i].name), &(mas[i].adres), &(mas[i].number), &(mas[i].sport)) != EOF || i<nn) {
  if (strcmp(nameSeach, mas[i].name) > 0 || strcmp(nameSeach, mas[i].name) < 0)// якщо запис на вилучення  є в файлі
	   {printInfo(mas[i]);}	
  	i++;        
	}
  fclose(f);
system ("PAUSE");
}
