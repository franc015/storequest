/*Store Quest App */


#include <stdio.h>
#include <string.h>

void instructions();
int create_case(char search);
void search_op(int set);

int main (void){

	char search[50];
	int set;
	FILE *in;

	instructions();

	in = fopen("produc.in", "r");

	do{
		printf("Input an item> ");
		scanf("%s", &search);

		set = create_case(search);
		search_op(set);

	}while(search != 'q');

	fclose(in);

	return 0;
}

void instructions(){
	printf("Welcome to Store Quest. Search an item. If you need help enter (H). If you wish to quit enter (Q).\n");
}




int create_case(char search){
	int set;
	//if(search == "Soda") set = 0;
	if(strcmp(search, "Soda") == 0) set = 0;
	else if(search == "Cereal") set = 1;
	else if(search == "Soap") set = 2;
	else if(search == "Shampoo") set = 3;
	else if(search == "Toys") set = 4;
	else if(search == "Games") set = 5;
	else if(search == "Paper") set = 6;
	else if(search == "Bags") set = 7;
	else if(search == "Candy") set = 8;
	else if(search == "Bread") set = 9;
	else if(search == "H") set = 10;
	else set = 11;

	return (set);
}




void search_op(int set){
printf("This is set: %d\n", set);
	switch(set){

		case 0:
			printf("Soda is on ilse aisle 8. There are 30 bottles left. They are $1.99 per bottle.");
			break;
/*
		case 1:
			printf("Cereal is on ilse aisle 7. There are 10 boxes left. They are $2.33 per box.");
			break;

		case 2:
			printf("Soap is on ilse aisle 6. There are 22 boxes left. They are $2.98 per box.");
			break;

		case 3:
			printf("Shampoo is on ilse aisle 5. There are 8 bottles left. They are $.98 per bottle.");
			break;

		case 4:
			printf("Toys are on ilse aisles 9 and 10 . There are 300 different types left. They are between $.99 and $500 per toy.");
			break;
		case 5:
			printf("Games are on ilse aisle 9. There are 10 different types left. They are between $14.98 and $59.95 per game.");
			break;

		case 6:
			printf("Paper is on ilse aisle 3. There are 25 boxes left. They are $3.98 per box.");
			break;

		case 7:
			printf("Bags are on ilse aisle 12. There are 10 boxes left. They are $4.28 per box.");
			break;

		case 8:
			printf("Candy is on ilse aisle 2. There are 10 boxes left. They are $2.98 per box.");
			break;

		case 9:
			printf("Bread is on ilse aisle 1. There are 50 loaves left. They are $1.98 per loaf.");
			break;
		case 10:
			printf("A store associate has been notified of your location and will be assisting you shortly");
			break;
*/
		default:
			printf("Item is not in stock.\n");
			break;

	}
}

