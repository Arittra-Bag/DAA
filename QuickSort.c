#include<stdio.h>

int Partition(int arr[], int beg, int end){
	int left,right,temp,loc,flag;
	loc=left=beg;
	right=end;
	flag=0;
	while(flag!=1){
		while ((arr[loc]<=arr[right]) && (loc!=right))
		right--;
		if(loc==right)
		flag=1;
		else if(arr[loc]>arr[right]){
			temp=arr[loc];
			arr[loc]=arr[right];
			arr[right]=temp;
			loc=right;
		}
		if(flag!=1){
			while((arr[loc]>=arr[left]) && (loc!=left))
			left++;
			if(loc==left)
			flag=1;
			else if(arr[loc]<arr[left]){
				temp=arr[loc];
				arr[loc]=arr[left];
				arr[left]=temp;
				loc=left;
			}
		}
	}
	return loc;
}

void QuickSort(int arr[], int beg, int end){
	int loc;
	if(beg<end){
		loc=Partition(arr,beg,end);
		QuickSort(arr,beg,loc-1);
		QuickSort(arr,loc+1,end);
	}
}

int main() {
	int i,n,ch;
	printf("Enter the Number of Elements you want in your Array: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Array[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++){
		printf("Array[%d]: %d\n",i+1,arr[i]);
	}	
	return 0;
}
