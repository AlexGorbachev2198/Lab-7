#include <stdio.h>
#include <stdlib.h>
struct Student
{
	char FIO[64];
	char Group[32];
	char ID[32];
	int Marks[4];
};
struct List
{
	struct List *next;
	struct Student stdnt;
};
void push(struct List **head, struct Student p) {
	struct List *tmp = (List*)malloc(sizeof(List));
	tmp->stdnt = p;
	tmp->next = (*head);
	*head = tmp;
}
void clear(List *head) {
    while (head != NULL) {
		List * t = head->next;
		free(head);
		head = t;
	}
}
int main() {
	FILE *pF;
	struct List *head = NULL;
	int n(0);
	fopen_s(&pF, "Students.dat", "rb");
	if (pF == 0)
	{
		printf("Error, file not found");
		return 1;
	}
	fread(&n, sizeof(int), 1, pF);
	for (int i = 0; i < n; i++) {
		struct Student *p = (Student *)malloc(sizeof(Student));
		fread(p, sizeof(Student), 1, pF);
		push(&head, *p);
	}
	fclose(pF);
	for (List *pi = head; pi; pi = pi->next) {
		printf("%s. %s. %s, %d, %d, %d, %d \n",
			pi->stdnt.FIO, pi->stdnt.Group, pi->stdnt.ID,
			pi->stdnt.Marks[0], pi->stdnt.Marks[1], pi->stdnt.Marks[2], pi->stdnt.Marks[3]);
	}
	clear(head);
	system("pause");
	return 0;
}
