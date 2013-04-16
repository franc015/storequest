#include <stdio.h>
#include <string.h>

void instructions(void);
void d_cmp(char *search_d, char *department[17][9]);	//d = department, cmp = compare

int main(void)
{
	char *search_d;		//d = deprartment
	char *department[17][9];
	FILE *in;

	in = fopen("product.in", "r");

	fscanf(in, "%s", department[17][9]);

	instructions();

	printf("Enter Department: ");
	scanf("%s", search_d);

	d_cmp(search_d, department);

	fclose(in);

	return(0);
}
void instructions(void)
{
	printf("\nWelcome to Store Quest. \nSearch a department. If you need help enter (H). If you wish to quit enter (Q).\n");
}
void d_cmp(char *search_d, char *department[17][9])
{
	if(*search_d == *department[17][9])
	{
		printf("your in a department");
	}
	else
	{
		printf("department does not exisit");
	}
}
