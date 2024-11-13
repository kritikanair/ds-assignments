#include <stdio.h>

void merge(int a[], int low,int mid, int high){
	int i = low,j= mid+1 ,k=low, b[high+1];
	while(i<=mid && j<=high){
		if(a[i]< a[j]){
			b[k]= a[i];
			i++; k++;
		}
		else {
			b[k]= a[j];
			j++; k++;
		}
	}
	while(i<=mid){
		b[k]=a[i];
		i++; k++;
	}
	while(j<=high) {
		b[k]= a[j];
		j++; k++;
	}
	for(i=low; i<=high; i++) {
		a[i]= b[i];
	}
}

void ms(int a[], int low, int high) {
	if(low<high){
		int mid= (low+high)/2;
		ms(a, low, mid);
		ms(a, mid+1, high);
		merge(a,low,mid,high);
	}
}

void printArray(int arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n,i;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    ms(arr, 0, n - 1);
    printf("Array after sorting using merge sort (rec): ");
    printArray(arr, n);
    return 0;
}