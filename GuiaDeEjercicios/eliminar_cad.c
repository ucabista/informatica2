#include<stdio.h>
#include<string.h>

int main()
{
    int i, j = 0, k = 0,n = 0;
    int flag = 0;
 
    char str[100], neww[100], word[100];

    printf("Escribe una cadena \n");
    gets(str);

    printf("Escribe la palabra que quieres eliminar en: %s \n\n",str);
    gets(word);

    for(i = 0 ; str[i] != '\0' ; i++)
    {
        k = i;
     
        while(str[i] == word[j])
        {
            i++,j++;
            if(j == strlen(word))
            {
                flag = 1;
                break;
            }
        }
    j = 0;

    if(flag == 0)
        i = k;      
    else
        flag = 0;

    neww[n++] = str[i];
    }

    neww[n] = '\0';
    
    printf("\n\n Cadena con la palabra eliminada: %s",neww);
}
