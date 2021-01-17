#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
#include &lt;stdlib.h&gt;
void main()
{
char opcode[10], operand[10], label[10], a[10], ad[10],
symbol[10], ch;
char code[10][10], code1[10][10] = {&quot;33&quot;, &quot;44&quot;, &quot;53&quot;,
&quot;57&quot;};
char mnemonic[10][10] = {&quot;START&quot;, &quot;LDA&quot;, &quot;STA&quot;, &quot;LDCH&quot;,
&quot;STCH&quot;, &quot;END&quot;};
char mnemonic1[10][10] = {&quot;LDA&quot;, &quot;STA&quot;, &quot;LDCH&quot;, &quot;STCH&quot;};
int locctr, start, length, i = 0, j = 0, k, l = 0;
int st, diff, address, add, len, actual_len, finaddr,
prevaddr;
FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7;
fp1 = fopen(&quot;input.txt&quot;, &quot;r&quot;);
fp2 = fopen(&quot;symtab.txt&quot;, &quot;w&quot;);
fp3 = fopen(&quot;intermediate.txt&quot;, &quot;w&quot;);
fscanf(fp1, &quot;%s%s%s&quot;, label, opcode, operand);
if (strcmp(opcode, &quot;START&quot;) == 0)
{
start = atoi(operand);
locctr = start;
fprintf(fp3, &quot;%s\t%s\t%s\n&quot;, label, opcode, operand);
fscanf(fp1, &quot;%s%s%s&quot;, label, opcode, operand);
}
else
locctr = 0;
while (strcmp(opcode, &quot;END&quot;) != 0)
{
fprintf(fp3, &quot;%d&quot;, locctr);
if (strcmp(label, &quot;**&quot;) != 0)
fprintf(fp2, &quot;%s\t%d\n&quot;, label, locctr);
strcpy(code[i], mnemonic[j]);
while (strcmp(mnemonic[j], &quot;END&quot;) != 0)
{
if (strcmp(opcode, mnemonic[j]) == 0)
{

locctr += 3;
break;
}
strcpy(code[i], mnemonic[j]);
j++;
}
if (strcmp(opcode, &quot;WORD&quot;) == 0)
locctr += 3;
else if (strcmp(opcode, &quot;RESW&quot;) == 0)
locctr += (3 * (atoi(operand)));
else if (strcmp(opcode, &quot;RESB&quot;) == 0)
locctr += (atoi(operand));
else if (strcmp(opcode, &quot;BYTE&quot;) == 0)
++locctr;
fprintf(fp3, &quot;\t%s\t%s\t%s\n&quot;, label, opcode,
operand);
fscanf(fp1, &quot;%s%s%s&quot;, label, opcode, operand);
}
fprintf(fp3, &quot;%d\t%s\t%s\t%s\n&quot;, locctr, label, opcode,
operand);
length = locctr - start;
fclose(fp3);
fclose(fp2);
fclose(fp1);
printf(&quot;\n\nThe contents of Input file:\n\n&quot;);
fp1 = fopen(&quot;input.txt&quot;, &quot;r&quot;);
ch = fgetc(fp1);
while (ch != EOF)
{
printf(&quot;%c&quot;, ch);
ch = fgetc(fp1);
}
printf(&quot;\n\nLength of the input program is %d.&quot;, length);
printf(&quot;\n\nThe contents of Symbol Table:\n\n&quot;);
fp2 = fopen(&quot;symtab.txt&quot;, &quot;r&quot;);
ch = fgetc(fp2);
while (ch != EOF)
{
printf(&quot;%c&quot;, ch);
ch = fgetc(fp2);
}
fclose(fp2);
fclose(fp1);
fp4 = fopen(&quot;output.txt&quot;, &quot;w&quot;);
fp5 = fopen(&quot;symtab.txt&quot;, &quot;r&quot;);
fp6 = fopen(&quot;intermediate.txt&quot;, &quot;r&quot;);
fp7 = fopen(&quot;objcode.txt&quot;, &quot;w&quot;);
fscanf(fp6, &quot;%s%s%s&quot;, label, opcode, operand);

while (strcmp(opcode, &quot;END&quot;) != 0)
{
prevaddr = address;
fscanf(fp6, &quot;%d%s%s%s&quot;, &amp;address, label, opcode,
operand);
}
finaddr = address;
fclose(fp6);
fp6 = fopen(&quot;intermediate.txt&quot;, &quot;r&quot;);
fscanf(fp6, &quot;%s%s%s&quot;, label, opcode, operand);
if (strcmp(opcode, &quot;START&quot;) == 0)
{
fprintf(fp4, &quot;\t%s\t%s\t%s\n&quot;, label, opcode,
operand);
fprintf(fp7, &quot;H^%s^00%s^00%d\n&quot;, label, operand,
finaddr);
fscanf(fp6, &quot;%d%s%s%s&quot;, &amp;address, label, opcode,
operand);
st = address;
diff = prevaddr - st;
fprintf(fp7, &quot;T^00%d^%d&quot;, address, diff);
}
while (strcmp(opcode, &quot;END&quot;) != 0)
{
if (strcmp(opcode, &quot;BYTE&quot;) == 0)
{
fprintf(fp4, &quot;%d\t%s\t%s\t%s\t&quot;, address, label,
opcode, operand);
len = strlen(operand);
actual_len = len - 3;
fprintf(fp7, &quot;^&quot;);
for (k = 2; k &lt; (actual_len + 2); k++)
{
itoa(operand[k], ad, 16);
fprintf(fp4, &quot;%s&quot;, ad);
fprintf(fp7, &quot;%s&quot;, ad);
}
fprintf(fp4, &quot;\n&quot;);
}
else if (strcmp(opcode, &quot;WORD&quot;) == 0)
{
len = strlen(operand);
itoa(atoi(operand), a, 10);
fprintf(fp4, &quot;%d\t%s\t%s\t%s\t00000%s\n&quot;, address,
label, opcode, operand, a);
fprintf(fp7, &quot;^00000%s&quot;, a);
}
else if ((strcmp(opcode, &quot;RESB&quot;) == 0) ||
(strcmp(opcode, &quot;RESW&quot;) == 0))
fprintf(fp4, &quot;%d\t%s\t%s\t%s\n&quot;, address, label,
opcode, operand);
else

{
while (strcmp(opcode, mnemonic1[l]) != 0)
l++;
if (strcmp(operand, &quot;COPY&quot;) == 0)
fprintf(fp4, &quot;%d\t%s\t%s\t%s\t%s0000\n&quot;,
address, label, opcode, operand, code1[l]);
else
{
rewind(fp5);
fscanf(fp5, &quot;%s%d&quot;, symbol, &amp;add);
while (strcmp(operand, symbol) != 0)
fscanf(fp5, &quot;%s%d&quot;, symbol, &amp;add);
fprintf(fp4, &quot;%d\t%s\t%s\t%s\t%s%d\n&quot;,
address, label, opcode, operand, code1[l], add);
fprintf(fp7, &quot;^%s%d&quot;, code1[l], add);
}
}
fscanf(fp6, &quot;%d%s%s%s&quot;, &amp;address, label, opcode,
operand);
}
fprintf(fp4, &quot;%d\t%s\t%s\t%s\n&quot;, address, label, opcode,
operand);
fprintf(fp7, &quot;\nE^00%d&quot;, st);
printf(&quot;\nObject Program has been generated.&quot;);
fclose(fp7);
fclose(fp6);
fclose(fp5);
fclose(fp4);
printf(&quot;\n\nObject Program:\n\n&quot;);
fp7 = fopen(&quot;objcode.txt&quot;, &quot;r&quot;);
ch = fgetc(fp7);
while (ch != EOF)
{
printf(&quot;%c&quot;, ch);
ch = fgetc(fp7);
}
fclose(fp7);
}
