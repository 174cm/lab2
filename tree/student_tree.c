#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>

struct student
{
	char *name;
	int mid;
	int final;
};

char nametable[100];
struct student *root = NULL;
struct student *stu_table;

int compare(const void *cp1, const void *cp2)
{
	return strcmp(((struct student *)cp1)->name, ((struct student *)cp2)->name);
}
void node_print(const void *, VISIT, int);

void main(int argc, char *argv[])
{
	int stu_num;
	int sum;
	float avg;

	printf("INPUT NUMBER OF STUDENT: ");
	scanf("%d", &stu_num);

	stu_table = (struct student *)malloc(stu_num * sizeof(struct student));
	if (stu_table == NULL)
	{
		printf("error");
		exit(-1);
	}
	fflush(stdin);

	char *nameptr = nametable;
	struct student *studentptr = stu_table;
	struct student **ret;
	int i = 0;

	while (scanf("%s%d%d", nameptr, &studentptr->mid, &studentptr->final) != EOF && i++ < stu_num)
	{
		studentptr->name = nameptr;
		ret = (struct student **)tsearch((void *)studentptr, (void **)&root, compare);
		nameptr += strlen(nameptr)+1;
		studentptr++;
	}
	twalk((void *)root, node_print);
	free((struct studen *)stu_table);
}

void node_print(const void *studentptr, VISIT order, int level)
{
	if (order == preorder || order == leaf)
		printf("name : %s mid : %d final %d\n", (*(struct student **)studentptr)->name, (*(struct student **)studentptr)->mid, (*(struct student **)studentptr)->final);
}
