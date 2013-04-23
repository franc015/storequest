#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int d_index;
	char department_name[256];
}department;

void instructions(void);
//int d_cmp(char *search_d, char *department[], int num_d);	//d = department, cmp = compare
int d_cmp(char *search_d, department* departments, int num_d);

int main(void)
{
	char search_d[9];		//d = deprartment
	//	char department[256][256];
	//	char *departments[256];
	FILE *in;
	int i=0;
	int j;
	int foundIndex;
	instructions();

	department* departments = malloc(sizeof(department *) * 17);

	in = fopen("department.in", "r");

	int temp_index;
	char temp_department_name[256];	
	char buffer[256];
char* status;

	//for(status = fgets(buffer, 256, in); status != 0; status = fgets(buffer, 256, in))
	while(fgets(buffer, 256, in) != NULL)
	{
	//	status != EOF;
	//	status = fgets(buffer, 256, in);
		printf("start");
printf("This is buffer: %s\n\n", buffer);
		sscanf(buffer, "%d %s", &temp_index, temp_department_name);
		department *a_department = (department *) malloc(sizeof(department));
		a_department->d_index = temp_index;
		strcpy(a_department->department_name, temp_department_name);
		departments[i] = *a_department;
		i++;
		printf("end");
	}

	printf("We scanned %d departments", i);
	getchar();

	printf("The departments are:\n");
	for (j = 0; j < i; j++)
	{
		printf("\t%s - index: %d\n",departments[j].department_name, j);
	}


	printf("Enter Department: ");
	scanf("%s", search_d);


	foundIndex = d_cmp(search_d, departments, i);
	if (foundIndex != 17)
	{
		printf("The index number found is %d\n\n",foundIndex);
	}
	else
	{
		printf("The department you entered is not found.\n\n");
	}

	fclose(in);

	return(0);
}
void instructions(void)
{
	printf("\nWelcome to Store Quest. \nSearch a department. If you need help enter (H). If you wish to quit enter (Q).\n");
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
		/*		else
				{
				printf("\ndepartment does not exisit\n");
				}*/
	}

	return departments[i].d_index;
}
