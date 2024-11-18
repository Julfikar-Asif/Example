//abbbbba

#include<stdio.h>
#include<string.h>

void  main()
{
    int state=0,i,length;
    char input[100];
    gets(input);
    length=strlen(input);

    if(input[0]=='a' && input[length-1]=='a')
    {
        state=1;
        for(i=1; i<length-1; i++)
        {
            if(input[i]!='b')
            {
                state=2;
                break;
            }
        }
    }

    else
    {
        state=2;
    }


    if(state==1)
        printf("String is under ab+a ");
    else
        printf("Wrong input ");

}


