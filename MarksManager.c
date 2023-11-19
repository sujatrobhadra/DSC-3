#include <stdio.h>
#include <stdlib.h>

int size; //number of students

void add_marks(float **marks, int num); //function to add marks to the list
void print_marks(float **marks); //function to print the marks of each and every student
float get_average(float **marks); //function to get average of total marks
void change_marks(float **marks, int idx); //function to change marks according to index

int main()
{
	

	printf("\t\tStudent Marks Analyzer\n");
	int num=0 , idx=0; //for number of students and index number
	size=0;
	float* studentmarks=NULL; //setting initial array to NULL
	while(1)
	{
		int choice; //for taking choice from user
		printf("1.Enter student marks\n");
		printf("2.Print student marks\n");
		printf("3.Get Average marks\n");
		printf("4.Get number of entries made\n");
		printf("5.Change a given entry\n");
		printf("6. Exit\n");
		printf("Enter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter number of students whose marks you want to enter:");
				scanf("%d", &num);
				if(num>0)
				{
					add_marks(&studentmarks, num);
				}
				else
				{
					printf("\nError! Number of students must be greater than 0\n\n");
				}
				break;
			case 2:
				if(size<=0)
				{
					printf("\nNo student marks entered yet\n\n");
				}
				else
				{
					print_marks(&studentmarks);
				}
				break;
			case 3:
				if(size<=0)
				{
					printf("\nNo student marks entered yet\n\n");
				}
				else
				{
					printf("\nThe average marks of %d students is %.2f\n\n",size,get_average(&studentmarks));
				}
				break;
			case 4:
				printf("\nNumber of entries made: %d\n\n", size);
				break;
			case 5:
				
				if(size==0)
				{
					printf("\nNo students marks entered yet\n\n");
				}
				else
				{
					printf("\nEnter index of marks:");
					scanf("%d", &idx);
					if(idx>=1 && idx<=size) //check for index number
					{
						change_marks(&studentmarks, idx);
					}
					else
					{
						printf("\nError in index value entered\n\n");
					}
				}
				break;
			case 6:
				printf("\nExiting the program...\n");
				break;
			default:
				printf("\nError! Invalid option chosen. Please try again\n\n");
				
		}
		if(choice==6)
		{
			break;// breaking out of while loop
		}
	}
free(studentmarks); //freeing memory
return 0;
}
void add_marks(float **marks,int num)
{
	 if (*marks == NULL) {
        *marks = (float*)calloc(num, sizeof(float)); //allocating dynamic memory using calloc though malloc can also be used
        size = num;
    } else {
        *marks = (float*)realloc(*marks, (size + num) * sizeof(float)); //changing size of array using realloc
        size += num;
    }

   int i = size - num;
	
	while(i<size)
	{
		float score;
		printf("\nEnter marks of student %d:",i+1);
		scanf("%f",&score);
		if(score<0 || score>100) //check for valid marks between 0 or 100
		{
			printf("Error in marks value please try again\n");
			
		}
		else
		{
			*(*marks+i)=score;
			printf("Marks allocated successfully\n");
			i++;
		}
		
	}
	printf("\n");
	return;
} 
void print_marks(float **marks)
{
	printf("\nid\tMarks\n\n");
	
	for(int i=0;i<size;i++)
	{
		printf("%d\t%.2f\n",i+1,*(*marks+i));
		
	}
	printf("\n");
}
float get_average(float **marks)
{

	 
	float sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=*(*marks+i); //calculating sum of total marks
	}
	return sum/size; //returning average
}
void change_marks(float **marks, int idx )
{
	printf("\nThe marks at %dth index is:%.2f\n",idx,*(*marks+(idx-1)));
	printf("Would you like to change the value at ith index. Enter 1 for yes and anything else for no?");
	int inp;
	scanf("%d", &inp);
	if(inp==1)
	{
		
		float newmarks;
		printf("Enter new marks at %dth index:",idx);
		scanf("%f", &newmarks);
		if(newmarks>=0 && newmarks<=100) //again checking for valid marks
		{
			*(*marks+(idx-1))=newmarks;
			
		}
		else
		{
			printf("\nError in assigning values\n");
		}
	}
	printf("\n");

}