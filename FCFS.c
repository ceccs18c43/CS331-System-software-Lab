#include<stdio.h>
int main()
{ int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
  int n,i=0,j=0,k=0,sum=0;
  float totalTAT=0,totalWT=0;
  printf("Enter the number of processes ");
  scanf("%d",&n);
  printf("Enter the arrival time and brust time for each process \n\n");
  for(i=0;i<n;i++)
  { printf("Arrival time P%d ",i+1);
    scanf("%d",&at[i]);
    printf("Brust time P%d ",i+1);
    scanf("%d",&bt[i]);
    printf("\n");
  }
  for(j=0;j<n;j++)
  {   sum+=bt[j];
      ct[j]+=sum;
  }
  for(k=0;k<n;k++)
  {  tat[k]=ct[k]-at[k];
     totalTAT+=tat[k];
  }
  for(k=0;k<n;k++)
  {  wt[k]=tat[k]-bt[k];
     totalWT+=wt[k];
  }
  printf("Solution :\n\n");
  printf("P#\t AT\t\tBT\t\tCT\t\tTAT\t\tWT\t\n\n");
  for(i=0;i<n;i++)
  {printf("P%d\t %d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
  }
  printf("\n\nAverage Turnaround Time =%f\n",totalTAT/n);
  printf("Average WT = %f\n\n",totalWT/n);
  return 0;
} 
    
