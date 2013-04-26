#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int d_index;
	char department_name[256];
}department;

typedef struct{
	char product_name[256];
	int d_index;
	int aisle;
	int shelf;
	int quantity;
	double price;
}product;

void instructions(void);
int d_cmp(char *search_d, department *departments, int num_d);	//d = department, cmp = compare
int file_length(char* filename);
void scan_department(department* departments, char* filename);
void scan_product(product* products, char* filename);
void show_products(int department_index, int product_count, product* products);
void show_individual_product(char *search_p, int product_count, product* products);

int main(void)
{
	char* d_filename = "department.in";
	int department_count = file_length(d_filename);
	char* p_filename = "product.in";
	int product_count = file_length(p_filename);
	char search_d[9];	//d = deprartment
	char search_p[9];	//p = product
	char command[9];	//p = product
	int j;
	int foundIndex;

	instructions();

	department departments[department_count];
	scan_department(departments, d_filename);
	product products[product_count];
	scan_product(products, p_filename);


	printf("We scanned %d departments", department_count);
	getchar();

	printf("The departments are:\n");

	while(strcmp(command, "Q") != 0){
		printf("Enter Command: ");
		scanf("%s", command);

		for (j = 0; j < department_count; j++)
		{
			printf("\t%s - index: %d\n",departments[j].department_name, departments[j].d_index);
		}

		printf("Enter Department: ");
		scanf("%s", search_d);


		foundIndex = d_cmp(search_d, departments, department_count);
		if (foundIndex != 17)
		{
			printf("The index number found is %d\n\n",foundIndex);
			printf("Products:\n");
			show_products(foundIndex, product_count, products);
			printf("Enter Product: ");
			scanf("%s", search_p);
			show_individual_product(search_p, product_count, products);

		}
		else
		{
			printf("The department you entered is not found.\n\n");
		}
	};

	return(0);
}
void instructions(void)
{
	printf("\nWELCOME TO STORE QUEST\n");
	printf("Search a department. If you need help enter (H). If you wish to quit enter (Q).\n");
}
int d_cmp(char *search_d, department* departments, int num_d)
{
	int i;
	int depart_v = 17;

	for(i = 0; i < num_d; i++)
	{
		if(strcmp(search_d, departments[i].department_name) == 0)
		{
			printf("\nyour in a department\n");
			depart_v = departments[i].d_index;
			break;
		}
	}

	return (depart_v);
}

int file_length(char* filename){

	FILE *in;
	in = fopen(filename, "r");
	int i = 0;
	char * buffer = malloc(256 * sizeof(char));
	while((fgets(buffer, 256, in)) != NULL){
		i++;
	}

	return i;
}

void scan_department(department* departments, char* filename){

	FILE *in;
	in = fopen(filename, "r");
	int i = 0;
	char * buffer = malloc(256 * sizeof(char));
	while((fgets(buffer, 256, in)) != NULL){
		department *current_department = malloc(sizeof(department));

		sscanf(buffer, "%d %s", &current_department->d_index, current_department->department_name);
		departments[i] = *current_department;
		i++;
	}
	fclose(in);
}

void scan_product(product* products, char* filename){

	FILE *in;
	in = fopen(filename, "r");
	int i = 0;
	char * buffer = malloc(256 * sizeof(char));
	while((fgets(buffer, 256, in)) != NULL){
		product *current_product = malloc(sizeof(product));

		sscanf(buffer, "%s %d %d %d %d %lf", current_product->product_name, &current_product->d_index, &current_product->aisle, &current_product->shelf, &current_product->quantity, &current_product->price);
		products[i] = *current_product;
		i++;
	}
	fclose(in);
}

void show_products(int department_index, int product_count, product* products){
	int i;
	for(i = 0; i < product_count; i++){

		if (products[i].d_index == department_index){
			printf("%s\n", products[i].product_name);

		}
	}
}

void show_individual_product(char *search_p, int product_count, product* products){
	int i;
	for(i = 0; i < product_count; i++){

		if (strcmp(search_p, products[i].product_name) == 0){
			printf("Product: %s, Aisle Number: %d, Shelf: %d, Quantity: %d, Price: $%.2lf\n", products[i].product_name, products[i].aisle, products[i].shelf, products[i].quantity, products[i].price);

		}
	}
}
