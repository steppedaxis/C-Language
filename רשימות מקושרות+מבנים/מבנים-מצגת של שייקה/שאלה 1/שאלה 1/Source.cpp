#include<stdio.h>
#include<stdlib.h>



typedef struct Hotel
{
	char name[30];
	char city[20];
	int rooms;
	int free;
	
	char getname(){
		return printf("%s", name);
}

	char getcity() {
		return printf("%s", city);
	}

	int getrooms() {
		return printf("%d", rooms);
	}

	int getfree() {
		return printf("%d", free);
	}
}Hotel;








void main()
{
	Hotel myhotel;
	printf("enter your hotel name:");
	scanf("%s", myhotel.name);
	printf("enter your city name:");
	scanf("%s", myhotel.city);
	printf("enter your rooms number:");
	scanf("%d", myhotel.rooms);
	myhotel.getname();
	myhotel.getcity();

	myhotel.getrooms();


}		

