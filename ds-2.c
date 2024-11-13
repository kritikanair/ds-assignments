#include <stdio.h>

void insertionsort(int arr[], int size) {
	int i,j, temp;
	for(i=1; i<size; i++) {
		temp = arr[i];
		j= i-1;
		
		while(j>=0 && arr[j]> temp) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void bubblesort(int arr[], int size) {
	int i,j;
	int swapped;
    for(i=0; i<size -1; i++){
    	swapped = 0;
        for(j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1] ) {
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
                swapped = 1;
            }
        }
        if(swapped == 0){
        	break;
		}
    }
}

void selectionsort(int arr[], int size) {
	int min,i,j,temp;
	for(i=0; i<size; i++) {
		min=i;
		int flag=0;
		for(j=i+1; j<size; j++) {
			if(arr[j] < arr[min]){
				min=j;	
			}
			if (arr[j - 1] > arr[j]) {
                flag=1;
            }
		}
		if(flag==0){
			break;
		}
	
		if(min != i) {
		temp= arr[i];
		arr[i]= arr[min];
		arr[min]= temp;
		}		
	}
}

void quicksort(int arr[], int low, int high){
	int i, j, pivot,temp,flag;
	if(low<high){
		pivot=low;
		i=low;
		j=high;
		flag=0;
		while(i<=j){
			while(arr[i]<= arr[pivot] && i<=high){
				i++;
				flag=1;
			}
			while(arr[j]> arr[pivot] && j>=low){
				j--;
				flag=1;
			}
			if(i<j) {
				temp= arr[i];
				arr[i]= arr[j];
				arr[j]= temp;
			}
		}
		temp= arr[pivot];
		arr[pivot]= arr[j];
		arr[j]= temp;
		if(flag==0) {
			return;
		}
		quicksort(arr,low, j-1);
		quicksort(arr, j+1, high);
	}	
}

void printArray(int arr[], int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int n,i;
	printf("enter size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("enter the array: ");
	for(i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	insertionsort(arr,n);
	printf("Array after sorting using insertion sort: ");
	printArray(arr,n);
	bubblesort(arr,n);
	printf("Array after sorting using bubble sort: ");
	printArray(arr,n);
	selectionsort(arr,n);
	printf("Array after sorting using selection sort: ");
	printArray(arr,n);
	quicksort(arr, 0, n-1);
	printf("Array after sorting using quick sort: ");
	printArray(arr,n);
	return 0;
}
