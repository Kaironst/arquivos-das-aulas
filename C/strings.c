#include <stdio.h>

//tamanho USANDO VETORES
int mystrlen(const char str[])
{
    int i = 0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}

// tamanho USANDO PONTEIROS
int mystrlenptr(const char * str)
{
    char *p = (char *)str;
    while(*p!='\0'){p++;}
    return (int)(p-str);
}

//concatenação USANDO VETORES
void mystrcat(char str1[], const char str2[])
{
    int i=0;
    int ii=0;
    while(str1[i]){i++;} 
    while (str2[ii])
    {
        str1[i]=str2[ii];
        i++;ii++;
    }
    str1[i]='\0';
}

int mytoupper(char letter)
{
    if(letter>='a' && letter<='z'){return (char)letter-32;}
    else {return (char)letter;}
}

int mystrcmp(const char str1[], const char str2[])
{
    int i=0, result=0;
    while(str1[i] && str2[i])
    {
        if(mytoupper(str1[i])>mytoupper(str2[i])){result=1; break;}
        else if(mytoupper(str1[i])<mytoupper(str2[i])){result=-1; break;}
        i++;
    }
    return result;
}
//
//int mystrchr(const char str[], char simbol)
//{
//    int i=0;
//    char positions[100];
//    while(str[i])
//    {
//        if(str[i]==simbol){positions}
//        i++;
//    }
//    return (char)"X";
//}

int main ()
{
    char str1[100],str2[100];
    int i=0;
printf("insira o valor de 2 strings\n");
fgets(str1,100,stdin);
fgets(str2,100,stdin);
printf("o tamanho da string1 é: %d\n",mystrlen(str1));
printf("string 2, mas agora usando a função com ponteiros: %d\n",mystrlenptr(str2));
char strca[100];for(i=0;i<100;i++){strca[i]=str1[i];}
mystrcat(strca,str2);
printf("concatenando as duas: %s",strca);
printf("comparando as duas (sem diferença entre maiuscula e minuscula): %d\n",mystrcmp(str1,str2));
printf("presença de a na str1: %d, presença de a na str2: %d\n",mystrchr(str1,'a'),mystrchr(str2,'a'));
}