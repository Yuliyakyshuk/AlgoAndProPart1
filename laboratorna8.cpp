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
// ��������� ��������� ����� ����� �� �����
void printInfo(EMPLOYEE info) {
    	printf("%s\t%s\t%d\t%s\n", info.name, info.adres,info.number,info.sport); 
}

// �������� ������
int main ()
{
 int nn=3;
 FILE *f;	// �������� ���'������ � ������
 EMPLOYEE e;	// �����
 EMPLOYEE mas[nn];	//�����
 int i;

  
 if ((f = fopen("f.dat", "wb")) == NULL)//��������� ����
  {
    printf("Error opening file ");// ���� ��� ������� ����� ������ �������, �� �������� � �������
    getchar();
    return 0;
  }

for(i=1; i<=nn;i++)
{//������� ����� �
   printf("name of stadion="); scanf("%39s",&e.name);
   printf("adres of stadion="); scanf("%39s",&e.adres);
   printf("number of place="); scanf("%d",&e.number);
   printf("sport="); scanf("%39s",&e.sport);
   // �������� ����� � � ����
   fwrite(&e, sizeof(EMPLOYEE),1,f);
   if (ferror(f)!=NULL) printf ("exit\n");
}
fclose(f);

  if ((f = fopen("f.dat", "rb")) == NULL)//������� ���� ��� ������� ������ � �����
  {
    printf("Error opening file ");// ���� ��� ������� ����� ������ �������, �� �������� � �������
    getchar();
    return 0;
  }
  char nameSeach[40];
  printf ("Get name\n");scanf("%s",nameSeach); // ������ �����, ���� ����� ��������
  printf ("resultat\n"); 
  i=0;
  while (fscanf (f, "%s%s%d%s", &(mas[i].name), &(mas[i].adres), &(mas[i].number), &(mas[i].sport)) != EOF || i<nn) {
  if (strcmp(nameSeach, mas[i].name) > 0 || strcmp(nameSeach, mas[i].name) < 0)// ���� ����� �� ���������  � � ����
	   {printInfo(mas[i]);}	
  	i++;        
	}
  fclose(f);
system ("PAUSE");
}
