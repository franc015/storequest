#include <stdio.h>
#include <string.h>

void instructions(void);
int d_cmp(char *search_d, char *department[], int num_d);	//d = department, cmp = compare

int main(void)
{
	char search_d[9];		//d = deprartment
	char department[256][256];
	char *departments[256];
	FILE *in;
	int i=0;
	int j;
	int foundIndex;

	in = fopen("product.in", "r");

	while(fscanf(in, "%s", department[i]) != EOF)
	{
		departments[i] = department[i];		
		i++;
	}

	printf("We scanned %d departments", i);
	getchar();

	printf("The departments are:\n");
	for (j = 0; j < i; j++)
	{
		printf("\t%s - index: %d\n",department[j], j);
	}

	instructions();

	printf("Enter Department: ");
	scanf("%s", search_d);

printf("before d_cmp");

	foundIndex = d_cmp(search_d, departments, i);

	printf("The index number found is %d\n\n",foundIndex);

	fclose(in);

	return(0);
}
void instructions(void)
{
	printf("\nWelcome to Store Quest. \nSearch a department. If you need help enter (H). If you wish to quit enter (Q).\n");
}
int d_cmp(char *search_d, char *department[], int num_d)
{
	int i;
	for(i = 0; i < num_d; i++)
	{
		if(strcmp(search_d, department[i]) == 0)
		{
			printf("\nyour in a department\n");
			break;
		}
		else
		{
			printf("\ndepartment does not exisit\n");
		}
	}

	return i;
}
