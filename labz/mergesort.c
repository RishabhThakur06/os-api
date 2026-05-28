#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int low, int mid, int high)
{
	int i,j,k,b[100];

	i=low;
	j=mid+1;
	k=low;

	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}

	while(i<=mid)
		b[k++]=a[i++];

	while(j<=high)
		b[k++]=a[j++];

	for(i=low;i<=high;i++)
		a[i]=b[i];
}

void mergesort(int a[], int low, int high)
{
	int mid;

	if(low<high)
	{
		mid=(low+high)/2;

		mergesort(a,low,mid);
		mergesort(a,mid+1,high);

		merge(a,low,mid,high);
	}
}

int main()
{
	int i,n,a[100];
	float tc,start,end;

	printf("enter the number of elements\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		a[i]=rand()%1000;
		printf("%d\t",a[i]);
	}

	start=clock();

	mergesort(a,0,n-1);

	end=clock();

	printf("\nthe sorted array is \n");

	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}

	tc=(difftime(end,start)/CLOCKS_PER_SEC);

	printf("\ntime taken is %f",tc);

	return 0;
}