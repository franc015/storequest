#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int d_index;
	char department_name[256];
}department;

typedef struct{
	int p_index;
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

int main(void)
{
	char* filename = "department.in";
	int department_count = file_length(filename);
	char search_d[9];	//d = deprartment
	int num_d = 0;		//num = number, d = department
	int j;
	int foundIndex;

	instructions();

	department departments[department_count];
	scan_department(departments, filename);

                
	printf("We scanned %d departments", department_count);
	getchar();

	printf("The departments are:\n");

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
	}
	else
	{
		printf("The department you entered is not found.\n\n");
	}


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

	for(i = 0; i < num_d; i++)
	{
		if(strcmp(search_d, departments[i].department_name) == 0)
		{
			printf("\nyour in a department\n");
			break;
		}
	}

	return (departments[i].d_index);
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

