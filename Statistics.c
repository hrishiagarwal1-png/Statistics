#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct {
	float var;
	float std;
}stats;

float fMean(int a[],int n);
float fMedian(int a[],int n);
int fMode(int a[],int n);
int fMax(int a[], int n);
float fmd(float M,int a[],int n,int i);
stats fstd(float m,int a[],int n, int i);



int main()
{
   int static a[]={13,15,17,19,21,13,24,13,13,29};
   int n=10,Max;
   float Mode,Mean,Median,Median_md,Mean_md,Mode_md,j=0;

     Mean=fMean(a,n);
	 Median=fMedian(a,n);
	 Mode=fMode(a,n);
	 Max=fMax(a,n);
     Mean_md=fmd(Mean,a,n,j);
     Median_md=fmd(Median,a,n,j);
     Mode_md=fmd(Mode,a,n,j);
	int static i;
	i=0;
	
	stats result=fstd(Mean,a,n,i);
	
	
		printf("Mean of the set is %f\n", Mean);
		printf("Median of the set is %f\n", Median);
		printf("Mode of the set is %f\n", Mode);
		printf("Max of the set is %d\n", Max);
        printf("Mean deviation from mean  %f\n",Mean_md);
        printf("Mean deviation from median %f\n", Median_md);
        printf("Mean deviation from mode %f\n", Mode_md);
        printf("Standard deviation %f\n", result.std);
	    printf("Variance %f\n", result.var);

return 0;
}


int fMax(int a[], int n)
{
int Max=a[0];
	for(int i=0;i<n;i++)
	{	if(a[i]>Max)
		{Max=a[i];
		}
	}
return Max;
}

float fMean(int a[],int n)
{
   int sum=0;
   float avg;
     for(int i=0;i<n;i++)
	{
  	   sum=sum+a[i];
	}
   avg=(float)sum/n;//return mean as a float 
   return (avg);
}



float fMedian(int a[],int n)
{  int b[n];
int t;

memcpy(b,a,n*sizeof(int)); //copy the array so that orignal array is preserved

for(int i=0;i<n;i++)
{	for(int j=0;j<n;j++)
	{	if(b[i]>b[j])//sort the copied array
		{	
			t=b[i];
			b[i]=b[j];
  			b[j]=t;
 		}
	}
}

if(n%2!=0)//if n is odd
{ return b[n/2];}

return ((float)b[n/2-1]+b[(n)/2])/2.0;//if n is even 
}


int fMode(int a[], int n)
{
    int f[n];
    int visited = -1;

   
    for (int i = 0; i < n; i++)
        f[i] = 0;

    
    for (int i = 0; i < n; i++)
    {
        if (f[i] == visited)
            continue;

        int count = 1; // count itself
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                f[j] = visited; // mark as counted
            }
        }
        f[i] = count; // save frequency for this element
    }

    // Find maximum frequency
    int maxFreq = fMax(f, n);

    // Find element corresponding to max frequency
    for (int i = 0; i < n; i++)
    {
        if (f[i] == maxFreq)
            return a[i]; 
    }

    return -1; // fallback
}


float fmd(float M,int a[],int n,int i)

{   float static sum=0;// Static variable to accumulate sum of absolute deviations Retains value across recursive calls
    if(i==0) sum=0;
if(i==n) 
{float result = sum/n;
    sum=0; //We have reset it ourself as the variable is static
          return result;
         
        }
    
	
	float md=fabs(a[i]-M);//calculate md use fabs to get absolute float values
	sum+=md;
	
	return fmd(M,a,n,i+1);
}




stats fstd(float m,int a[],int n, int i)
{  

    float static sum=0;//We use static variable to accumulate sum of squared differences as static  Keeps its value across recursive calls
	 stats result;
	
    if(i==0) sum =0;
	if(i==n) 
    {result.std=sqrt(sum/n);
              result.var=sum/n;
			    return result;}
	sum+=pow(a[i]-m,2);  // Add squared deviation of current element from mean
	
	return fstd(m,a,n,i+1);//use recursion 
}


