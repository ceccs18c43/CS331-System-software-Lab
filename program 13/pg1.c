#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;string.h&gt;
#include&lt;stdlib.h&gt;
void main()
{
    FILE *f1,*f2,*f3,*f4,*f5,*f6;
    char mne[20],opnd[20],la[20],ch;
    f1=fopen(&quot;input.txt&quot;,&quot;r&quot;);
    f2=fopen(&quot;ntab2.txt&quot;,&quot;w+&quot;);
    f3=fopen(&quot;dtab2.txt&quot;,&quot;w+&quot;);
    fscanf(f1,&quot;%s%s%s&quot;,la,mne,opnd);
    while(strcmp(mne,&quot;MEND&quot;)!=0)
    {
        if(strcmp(mne,&quot;MACRO&quot;)==0)
        {
            fprintf(f2,&quot;%s\n&quot;,la);
            fprintf(f3,&quot;%s\t%s\n&quot;,la,opnd);
        }
        else
            fprintf(f3,&quot;%s\t%s\n&quot;,mne,opnd);
        fscanf(f1,&quot;%s%s%s&quot;,la,mne,opnd);
    }
    fprintf(f3,&quot;%s&quot;,mne);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf(&quot;PASS 1 is successful&quot;);
    
    printf(&quot;\n\nInput Text:\n\n&quot;);
    f4 = fopen(&quot;input.txt&quot;, &quot;r&quot;);
    ch = fgetc(f4);
    while (ch != EOF)
    {
        printf(&quot;%c&quot;, ch);
        ch = fgetc(f4);
    }
    fclose(f4);

    printf(&quot;\n\nOutput Text:\n\n&quot;);
    printf(&quot;dtab2.txt\n&quot;);
    f6 = fopen(&quot;dtab2.txt&quot;, &quot;r&quot;);
    ch = fgetc(f6);
    while (ch != EOF)
    {
        printf(&quot;%c&quot;, ch);
        ch = fgetc(f6);
    }
    fclose(f6);
    printf(&quot;\n\n&quot;);
    printf(&quot;\nntab2.txt\n&quot;);
    f5 = fopen(&quot;ntab2.txt&quot;, &quot;r&quot;);
    ch = fgetc(f5);
    while (ch != EOF)
    {
        printf(&quot;%c&quot;, ch);
        ch = fgetc(f5);
    }
    fclose(f5);
    getch();
}
