#include <stdio.h>
#include <stdlib.h>

int number = 0;
int flag = 0;

/*---------------------------------------Function for Printing Stars----------------------------------------------*/
void print_star(int array[])
{
    int first_count1,second_count2;
    printf("\n");
    first_count1 = 0;

    while(first_count1 < number)
    {
        printf("Array Value - %d : ",array[first_count1]);
        second_count2 = 0;

        while (second_count2<array[first_count1])
        {
            printf("*");                                       //Printing stars
            second_count2++;
        }

        first_count1++;
        printf("\n");
    }
}
/*----------------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------Swapping Function--------------------------------------------------*/
void swapping(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}
/*----------------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------Insertion Sort-----------------------------------------------------*/
void insertion_sort(int array[],int number)
{
    int i,j;
    i = 0;

    while(i < number)
    {
        j = i;
		while(j > 0 && array[j] < array[j-1])
		{
			swapping(&array[j],&array[j-1]);                    //main swapping based on values
			j--;
			if (number <= 20){                                  //if array size is less than 20 then print stars
                print_star(array);
			}
		}
		i++;
    }

    printf("\nThe Sorted Numbers are: - ");
    j = 0;
    while(j < number)
    {
        printf("%d ",array[j]);                                //printing sorted numbers
        j++;
    }
    printf("\n");
}
/*---------------------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------Merge Sort--------------------------------------------------------*/
void msort(int array[],int lower,int middle,int higher)        //function for main sorting elements
{
    int j,n,p,x,other[1000];
    x=lower;
    j=lower;
    n=middle+1;

    while((n<=higher) && (x<=middle))
    {
        if(array[n] >= array[x]){
            other[j] = array[x];
            x++;
        }
        else{
            other[j] = array[n];
            n++;
        }
        j++;
    }

    if(x > middle){
        p=n;
        while(p<=higher){
            other[j] = array[p];
            j++;
            p++;
        }
    }
    else{
        p=x;
        while(p<=middle){
            other[j] = array[p];
            j++;
            p++;
        }
    }

    p = lower;
    while(p <= higher){
        array[p] = other[p];
        p++;
    }

    if ( number <= 20){
        print_star(array);
    }
}

void merge_sort(int array[],int lower,int higher)
{
    int middle;
    if(higher > lower){
        middle = (lower+higher)/2;
        merge_sort(array,lower,middle);
        merge_sort(array,middle+1,higher);
        msort(array,lower,middle,higher);
    }
}
/*--------------------------------------------------------------------------------------------------------------*/



/*------------------------------------------Counting Sort -----------------------------------------------------*/
void counting_sort(int array[], int number)
{
	int i;
	int maximum = -1;
	i = 0;
    while(i < number){
        if(array[i] > maximum){
            maximum = array[i];
        }
        i++;
    }

	int second_array[maximum+1];
    i = 0;
    while(i <= maximum){
        second_array[i] = 0;
        i++;
    }
    i = 0;
    while(i < number){
        int second = array[i];
	    second_array[second] = second_array[second] + 1;
	    i++;
    }

    printf("\nMiddle Array : ");

    i = 0;
    while(i <= maximum){
        printf("%d ", second_array[i]);                                         //printing middle array
        i++;
    }

    printf("\n");
    i = 1;
    while(i <= maximum){
        second_array[i] = second_array[i] + second_array[i-1];
        i++;
    }

	int result[number];
    i = 0;
    while(i < number){
        int second = array[i];
	    int location = second_array[second] - 1;
	    result[location] = second;
	    second_array[second] = second_array[second] - 1;
	    i++;
    }

    i = 0;
    while(i < number){
        array[i] = result[i];
        i++;
    }
}
/*-----------------------------------------------------------------------------------------------------------*/



/*----------------------------------------------Randomized Quick Sort-----------------------------------------*/
int partition(int array[], int number)
{
    int i, pivot=0;
    swapping(array+(rand() % number), array+(number-1));
    i = 0;
    while(i < number)
    {
        if (array[i] < array[number-1])
        swapping(array + i, array + pivot++);
        ++i;
    }
    swapping(array+pivot, array+(number-1));
    return pivot;
}

void randomize_quick_sort(int array[], int number)
{
    if (number < 2)
        return;

    int pivot = partition(array, number);
    randomize_quick_sort(array, pivot++);
    randomize_quick_sort(array+pivot, number-pivot);
}
/*----------------------------------------------------------------------------------------------------------*/




int main()
{
	int selection,count,i;
	int array[1000],sorted_array[1000];
	int max_element;
	printf("Select the Sorting Algorithm:: \n");
    printf("1. Insertion Sort\n");
    printf("2. Counting Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Randomize Quick Sort \n");

    printf("\nEnter your choice::");
	scanf("%d",&selection);

    if(selection==2){
        flag=1;
    }

	while(number < 1 || number > 1001){
        printf("\nEnter the value of Numbers between 1 and 1000::");
        scanf ("%d",&number);
	}

	if (number <= 20){
        srand(time(NULL));
        count = 0;
        while(count < number){
            array[count]= rand() % 15 + 1;                                    //if value is under 20 then randomized numbers within 15
            count++;
        }
    }
    else{
        srand(time(NULL));
        count = 0;
        while(count < number){
            if (flag == 1){
                array[count]= rand() % 98 + 1;                                //for counting sort, randomized number between 99
            }
            else{
                array[count]= rand() % 1000 + 1;                             //for value exceeding 20, randomized numbers within 1000
            }
            count++;
        }
    }
    printf("\nThe Random Numbers are:- ");

    count = 0;
    while(count < number){
        printf("%d ",array[count]);
        count++;
    }
    printf("\n\n");

   	switch(selection)
	{
        case 1:                                                              //Case 1 for Insertion Sort
            if (number<=20){
                print_star(array);
            }
			insertion_sort(array,number);
            break;

        case 2:                                                              //Case 2 for Counting Sort
            if ( number <= 20){
                print_star(array);
			}
            counting_sort(array, number);
            if ( number <= 20){
               print_star(array);
			}
            printf("\nThe sorted array is:: ");
            i = 0;
			while(i < number)
            {
                printf("%d ",array[i]);
                i++;
            }
            printf("\n");
			break;

        case 3:                                                             //Case 3 for Merge Sort
            if (number <=20){
                print_star(array);
			}
            merge_sort(array,0,number);
			printf("\nThe sorted array is:: ");
			i = 0;
			while(i < number)
            {
                printf("%d ",array[i]);
                i++;
            }
           	printf("\n");
			break;

        case 4:                                                            //Case 4 for Randomized Quick sort
            if ( number <= 20){
               print_star(array);
			}
			randomize_quick_sort(array,number);
			if ( number <= 20){
                print_star(array);
			}
			printf("\nThe sorted array is:: ");
			i = 0;
			while(i < number)
            {
                printf("%d ",array[i]);
                i++;
            }
            printf("\n");
			break;

        default:
			printf("You Entered a Wrong Choice\n");
			break;
	}

   return 0;
}
