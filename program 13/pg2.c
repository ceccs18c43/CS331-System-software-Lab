#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;string.h&gt;
#include&lt;stdlib.h&gt;
void main()
{
    FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8;
    int i,len;
    char mne[20],opnd[20],la[20],name[20],mne1[20],opnd1[20],arg[20],ch;
    f1=fopen(&quot;input.txt&quot;,&quot;r&quot;);
    f2=fopen(&quot;ntab2.txt&quot;,&quot;r&quot;);
    f3=fopen(&quot;dtab2.txt&quot;,&quot;r&quot;);
    f4=fopen(&quot;atab2.txt&quot;,&quot;w+&quot;);
    f5=fopen(&quot;op2.txt&quot;,&quot;w&quot;);
    fscanf(f1,&quot;%s%s%s&quot;,la,mne,opnd);
    while(strcmp(mne,&quot;END&quot;)!=0)
    {
        if(strcmp(mne,&quot;MACRO&quot;)==0)
        {
            fscanf(f1,&quot;%s%s%s&quot;,la,mne,opnd);
            while(strcmp(mne,&quot;MEND&quot;)!=0)
                fscanf(f1,&quot;%s%s%s&quot;,la,mne,opnd);
        }
        else
        {
            fscanf(f2,&quot;%s&quot;,name);
            if(strcmp(mne,name)==0)
            {
                len=strlen(opnd);
                for(i=0;i&lt;len;i++)
                {
                    if(opnd[i]!=&#39;,&#39;)
                    fprintf(f4,&quot;%c&quot;,opnd[i]);
                    else
                    fprintf(f4,&quot;\n&quot;);
                }
                fseek(f2,SEEK_SET,0);
                fseek(f4,SEEK_SET,0);
                fscanf(f3,&quot;%s%s&quot;,mne1,opnd1);
                fprintf(f5,&quot;.\t%s\t%s\n&quot;,mne1,opnd);
                fscanf(f3,&quot;%s%s&quot;,mne1,opnd1);
                while(strcmp(mne1,&quot;MEND&quot;)!=0)
                {
                    if((opnd1[0]==&#39;&amp;&#39;))
                    {
                        fscanf(f4,&quot;%s&quot;,arg);
                        fprintf(f5,&quot;-\t%s\t%s\n&quot;,mne1,arg);

                    
}
                    else
                        fprintf(f5,&quot;-\t%s\t%s\n&quot;,mne1,opnd1);
                    fscanf(f3,&quot;%s%s&quot;,mne1,opnd1);
                }
            }
            else
            fprintf(f5,&quot;%s\t%s\t%s\n&quot;,la,mne,opnd);
        }
        fscanf(f1,&quot;%s%s%s&quot;,la,mne,opnd);
    }
    fprintf(f5,&quot;%s\t%s\t%s\n&quot;,la,mne,opnd);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    printf(&quot;PASS 2 Complete&quot;);
    printf(&quot;\n\nInput Text:\n\n&quot;);
    f4 = fopen(&quot;input.txt&quot;, &quot;r&quot;);
    ch = fgetc(f4);
    while (ch != EOF)
    {
        printf(&quot;%c&quot;, ch);
        ch = fgetc(f4);
    }
    fclose(f4);
    printf(&quot;\n\ndtab2.txt\n&quot;);
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

    printf(&quot;\n\nOutput Text:\n\n&quot;);
    printf(&quot;ntab2.txt\n&quot;);
    f7 = fopen(&quot;atab2.txt&quot;, &quot;r&quot;);
    ch = fgetc(f7);
    while (ch != EOF)
    {
        printf(&quot;%c&quot;, ch);
        ch = fgetc(f7);
    }
    fclose(f7);
    printf(&quot;\n\nop2.txt\n&quot;);
    f8 = fopen(&quot;op2.txt&quot;, &quot;r&quot;);
    ch = fgetc(f8);
    while (ch != EOF)
    {
        printf(&quot;%c&quot;, ch);
        ch = fgetc(f8);
    }
    fclose(f8);
    getch();
}
