#include<stdio.h>

int main(){
	int a, b, i, j, k, size, index, addSize, fbig, sbig, fSmall, sSmall;
	char choice, arrPosition, sort, sort1, sort2;
	printf("Enter array size:\n");
	scanf("%d", &size);
	
	int arr[size];
	
	printf("Enter array elements:\n");
	
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	main_switch:
	do{
		printf("Choose one of the following:\n a)Enter additional array elements\n b)Delete an array element\n c)Delete duplicate elements\n d)Arrange an array\n e)Find specified highest or lowest number\n f)EXIT\n");
		scanf(" %c", &choice);
	
		
		switch (choice){
			
			case 'a':
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
					
			break;
				
			case 'b':
		
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
			break;
			
			case 'c':
				
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
				break;
			
			case 'd':
			starting_case:
				do{
					printf("a.)SORT WHOLE ARRAY?\tb.)SORT PART OF ARRAY?\tc.)EXIT\n");
					scanf(" %c", &sort);
					if(sort=='c'){
						goto main_switch;
					}
					switch (sort){
						case 'a':
							printf("a.)ASCENDING?\nb.)DESCENDING?\n");
							scanf(" %c",&sort1);
							
							switch (sort1){
								case 'a':
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
								goto starting_case;
								case'b':
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
								goto starting_case;
							}
						case 'b':
							printf("a.)ASCENDING?\nb.)DESCENDING?\n");
							scanf(" %c",&sort2);
							
							switch (sort2){
								case 'a':
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
								goto starting_case;
								case 'b':
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
								goto starting_case;
							}
								
					}
					printf("Array elements:\n");
					for(int i=0; i<size; i++){
						printf("%d\t", arr[i]);
					}
				}while(sort!='0');
			
			case 'e':
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
	}while(choice!='f');
	
}
