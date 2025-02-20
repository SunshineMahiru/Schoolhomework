#include<stdio.h>
int main()
{
	int n, i, j, t;
	int a[11];
	scanf("%d", &n);
	
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
		
	for(i = 1;i < n;i++)
	{
		for(j = 0;j < n - i;j++)
		{
			if(a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for(i = 0;i < n;i++)
	{
		if(i < n - 1)
			printf("%d ", a[i]);
		else
			printf("%d\n", a[n - 1]);
	}
	return 0;
}
