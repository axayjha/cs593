#include <iostream>
#include <string>

typedef struct 
{
	char name[20];
	long ssn;
	int grades[5];
	float avg;
}Student;

void getData(Student *st)
{
	printf("Enter the name of the student: ");
	scanf("%s", st->name);
	printf("Enter the ssn for %s: ", st->name);
	scanf("%ld", &(st->ssn));
	printf("Enter the grades in respective subjects: \n");
	st->avg=0;
	for(int i=0; i<5; i++)
	{
		scanf(" %d", &(st->grades[i]));
		st->avg += (st->grades[i]);
	}
	st->avg = (st->avg)/5;
}

void writeData(Student st)
{
	printf("\n\nStudent data for %s: \n", st.name);
	printf("--------------------------------------\n");
	printf("SSN = %d\n", st.ssn);
	printf("Grades in respective subjects: \n");
	for(int i=0; i<5; i++)
		printf("\tSubject %d : %d\n", i+1, st.grades[i]);
	printf("Average score: %.2f\n", st.avg);	
}

int main()
{
	Student s1;
	getData(&s1);
	writeData(s1);

}
