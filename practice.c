#include <stdio.h>

int main() 
{
   FILE *fptr;
   char ch;
   fptr=fopen("MyFile.txt","r");
   if(fptr==NULL){
       printf("Error : can not the file");
       return 0;
   }
   while((ch=getc(fptr)) !=EOF)
   {
       printf("%c",ch);
   }
   fclose(fptr);
    return 0;
}