#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;string.h&gt;
#define MAX 11
char l[10];
struct symb
{
    int add;
    char label[10];
}sy[11];
void search();
void main()
{
    int a[MAX],num,key,i,ch,ans;
    int create(int);
    void lprob(int [],int,int);
    void display(int []);
    for(i=0;i&lt;MAX;i++)
    a[i]=0;
    printf(&quot;\n1.Create a symbol table \n2.Search in the symbol table\n&quot;);
    do
    {
        printf(&quot;\nEnter your choice:&quot;);
        scanf(&quot;%d&quot;,&amp;ch);
        switch(ch)
        {
            case 1:
                    do
                    {
                        printf(&quot;\nEnter the address:&quot;);
                        scanf(&quot;%d&quot;,&amp;num);
                        key=create(num);
                        printf(&quot;\nEnter the label:&quot;);
                        scanf(&quot;%s&quot;,l);
                        lprob(a,key,num);
                        printf(&quot;\nContinue(1/0)?&quot;);
                        scanf(&quot;%d&quot;,&amp;ans);
                    }

                    while(ans==1);
                    display(a);
                    break;
            case 2:
                    search();
                    break;
        }
    }while(ch&lt;=2);
    getch();
}
int create(int num)
{
    int key;
    key=num%11;
    return key;
}
void lprob(int a[MAX],int key,int num)
    {
    int flag,i,count=0;
    void display(int a[]);
    flag=0;
    if(a[key]==0)
    {
        a[key]=num;
        sy[key].add=num;
        strcpy(sy[key].label,l);
    }
    else
    {
        i=0;
        while(i&lt;MAX)
        {
            if(a[i]!=0)
            count++;
            i++;
        }
        if(count==MAX)
        {
            printf(&quot;\nHash table is full&quot;);
            display(a);
            getch();
            exit(1);
        }
        for(i=key+1;i&lt;MAX;i++)
            if(a[i]==0)
            {
                a[i]=num;
                flag=1;

                sy[key].add=num;
                strcpy(sy[key].label,l);
                break;
            }
        for(i=0;i&lt;key &amp;&amp; flag==0;i++)
            if(a[i]==0)
            {
                a[i]=num;
                flag=1;
                sy[key].add=num;
                strcpy(sy[key].label,l);
                break;
            }
    }
}
void display(int a[MAX])
{
    FILE *fp;
    int i;
    fp=fopen(&quot;symbol.txt&quot;,&quot;w&quot;);
    printf(&quot;\nThe Symbol Table is&quot;);
    printf(&quot;\nhashvalues address label&quot;);
    for(i=0;i&lt;MAX;i++)
    {
        printf(&quot;\n%d\t %d\t %s&quot;,i,sy[i].add,sy[i].label);
        fprintf(fp,&quot;\n%d %d %s&quot;,i,sy[i].add,sy[i].label);
    }
    fclose(fp);
}
 
void search()
{
    FILE *fp1;
    char la[10];
    int set=0,s;
    int j,i;
    printf(&quot;enter the label: &quot;);
    scanf(&quot;%s&quot;,la);
    fp1=fopen(&quot;symbol.txt&quot;,&quot;r&quot;);
    for(i=0;i&lt;MAX;i++)
    {
        fscanf(fp1,&quot;%d%d&quot;,&amp;j,&amp;sy[i].add);
        if(sy[i].add!=0)
        fscanf(fp1,&quot;%s&quot;,sy[i].label);
    }
    for(i=0;i&lt;MAX;i++)
    {
        if(sy[i].add!=0)
        {

            if(strcmp(sy[i].label,la)==0)
            {
                set=1;
                s=sy[i].add;
            }
        }
    }
    if(set==1)
        printf(&quot;\nThe label --%s--
 is present in the symbol table at address:%d\n&quot;,la,s);
    else
        printf(&quot;\nThe label is not present in the symbol table\n&quot;);
}
