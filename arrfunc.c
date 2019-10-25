#include<stdio.h>
int i = 0, j = 0, k, a, b;
void addArray(int arr[],int size);
void delArray(int arr[], int size);
void delDuplicate(int arr[], int size);
void arrArray(int arr[], int size);
void ascendWhole(int arr[], int size);
void descendWhole (int arr[], int size);
void ascendPart (int arr[], int size);
void descendPart (int arr[], int size);
void findArr(int arr[], int size);
int main(){
	int size, i;
	char choice;
	printf("Enter array size:\n");
	scanf("%d", &size);
	
	int arr[size];
	
	printf("Enter array elements:\n");
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	main_switch:
	do
	{
		printf("Choose one of the following:\n a)Enter additional array elements\n b)Delete an array element\n c)Delete duplicate elements\n d)Arrange an array\n e)Find specified highest or lowest number\n f)EXIT\n");
		scanf(" %c", &choice);
		
		switch (choice)
		{
			case 'a':
				addArray(arr,size);
			goto main_switch;
				
			case 'b':
				delArray(arr,size);
			goto main_switch;
			
			case 'c':
				delDuplicate(arr,size);
			goto main_switch;
			
			case 'd':
				arrArray(arr,size);
			goto main_switch;
			
			case 'e':
				findArr(arr, size);
			goto main_switch;
			case 'f':
			break;
			default:
				printf("Invalid.\n");
		}
		
	} while (choice!='f');
	
}

void addArray(int arr[],int size){
	int addSize;
	printf("Enter additional array size:\n");
	scanf("%d", &addSize);
	
	size += addSize;
	
	printf("Enter additional array elements:\n");
	for(i=size-addSize; i<size; i++){
		scanf("%d", &arr[i]);
	}
	printf("Array elements:\n");
	for(i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void delArray(int arr[], int size){
	int index;
	printf("Enter array index:\n");
	scanf("%d", &index);

	for(i=index; i<size; i++){
		arr[i] = arr[i+1];
	}
	size = size-1;

	printf("Remaining numbers:\n");
	for(i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void delDuplicate(int arr[], int size){
	for(i=0; i<size; i++){
		for(j=i+1; j<size; j++){
			if(arr[i] == arr[j]){
				for(k=j; k<size; k++){
					arr[k]= arr[k+1];
				}
				size--;
				j--;
			}
		}
	}
	printf("Remaining numbers:\n");
	for(i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void arrArray(int arr[], int size){
	char sort, sort1, sort2;
	starting_case:
		do{
			printf("a.)SORT WHOLE ARRAY?\tb.)SORT PART OF ARRAY?\tc.)EXIT\n");
			scanf(" %c", &sort);
			if(sort=='c'){
				break;
			}
			switch (sort){
				case 'a':
					printf("a.)ASCENDING?\nb.)DESCENDING?\n");
					scanf(" %c",&sort1);

					switch (sort1){
						
						case 'a':
							ascendWhole (arr, size);
						goto starting_case;
						
						case 'b':
							descendWhole (arr, size);
						goto starting_case;
					}
				case 'b':
					printf("a.)ASCENDING?\nb.)DESCENDING?\n");
					scanf(" %c",&sort2);
					
					switch (sort2){
						
						case 'a':
							ascendPart(arr,size);
						goto starting_case;
						
						case 'b':
							descendPart(arr,size);
						goto starting_case;
					}
								
			}
			printf("Array elements:\n");
			for(int i=0; i<size; i++){
				printf("%d\t", arr[i]);
			}
		}while(sort!='c');
}

void ascendWhole(int arr[], int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(arr[i]<arr[j]){
				int temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("Arranged elements in ascending order:\n");
	for(int i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void descendWhole (int arr[], int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("Arranged elements in descending order:\n");
	for(i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void ascendPart (int arr[], int size){
	printf("Enter starting index:\n");
	scanf("%d",&a);

	printf("Enter ending index:\n");
	scanf("%d",&b);
		for(int i=a; i<b; i++){
			for(int j=a; j<b; j++){
				if(arr[i]<arr[j]){
					int temp = arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
	printf("Arranged elements in ascending order:\n");
	for(int i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
		printf("\n");
}

void descendPart (int arr[], int size){
	printf("Enter starting index:\n");
	scanf("%d",&a);

	printf("Enter ending index:\n");
	scanf("%d",&b);
	for(int i=a; i<b; i++){
		for(int j=a+1; j<b; j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("Arranged elements in descending order:\n");
	for(i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void findArr(int arr[], int size){
	int fbig, sbig, fSmall, sSmall;
	char arrPosition;
	printf("a)Largest\tb)2nd Largest\tc)Smallest\td)2nd Smallest\n");
	scanf(" %c", &arrPosition);
	fbig=arr[0];
	sbig=arr[1];

	if(sbig>fbig){
		int temp = sbig;
		sbig = fbig;
		fbig = temp;
	}

	for(int i=2; i<size; i++){
		if(arr[i]>sbig){
			if(arr[i]>fbig){
				sbig=fbig;
				fbig=arr[i];
			}else{
				sbig=arr[i];
			}
		}
	}

	fSmall=arr[0];
	sSmall=arr[1];
	
	if(sSmall<fSmall){
		int temp=sSmall;
		sSmall=fSmall;
		fSmall=temp;
	}
	
	for(int i=2; i<size; i++){
		if(arr[i]<sSmall){
			if(arr[i]<fSmall){
				sSmall=fSmall;
				fSmall=arr[i];
			}else{
				sSmall=arr[i];
			}
		}
	}
	switch (arrPosition){
		case 'a':
			printf("The largest number is %d.\n", fbig);
		break;
		case 'b':
			printf("The second largest number is %d.\n", sbig);
		break;
		case 'c':
			printf("The smallest number is %d.\n", fSmall);
		break;
		case 'd':
			printf("The second smallest number is %d.\n", sSmall);
		break;
	
	}
}
