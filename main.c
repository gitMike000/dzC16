#include <stdio.h>
#include <stdbool.h> // for use boolean type
#include <time.h>

#include "geek.h"

// Task 1
char* caesar(char* in, int key, boolean encrypt) {
    int i=0;
    int sign=(key>=0 ? 1 : -1);
    key=abs(key%((int)'z'-(int)'0'));
    sign=(encrypt ? sign : sign*(-1));
    do {
     if (in[i]<'\0' || in[i]>'z') {
      printf("Message contains invalid characters\n");
      return NULL;
     }
    } while (in[i++]!='\0');
   char* out=(char*) malloc(i*sizeof (char));
   i=0;
   int temp;
   do {
    if (in[i]>='0' && in[i]<='z') {
     temp=(int)in[i]+sign*key;
     if (temp>(int)'z') temp=temp-(int)'z'+(int)'0';
     if (temp<(int)'0') temp=(int)'z'+temp-(int)'0';
     out[i]=(char)temp;
    }
    else out[i]=in[i];
   } while (in[i++]!='\0');
   out[i]='\0';
   return out;
}

// Task 2

char* shuffle(char* in, int key, boolean encrypt) {
    int len=0;
    key=abs(key);
    do {
     if (in[len]<'\0' || in[len]>'z') {
      printf("Message contains invalid characters\n");
      return NULL;
     }
     len++;
    } while (in[len]!='\0');
   char* out=(char*) calloc(len,sizeof (char));
   int row=(int) len/key;
   int col_end=((len%key)>0 ? 1 :0);
   int x=0;
   for (int i=0;i<(row+col_end);i++) {
       x=i*key;
       for (int j=0;j<key;j++) {
           if ((x+key-1-j)>(len-1))
               out[x+j]=' ';//(char)(rand()%((int)'Z'-(int)'A')+(int)'A');
           else out[x+j]=in[x+key-1-j];
       }
   }
   out[x+key]='\0';
   return out;
}

int main()
{
// Task 1
   printf("Task 1\n");
   char* phrase="A ROZA UPALA NA LAPU AZORA\0";
   //char* phrase="Google is very best site!\0";
   char* phraseCr=caesar(phrase, -34, true);
   char* phraseDecr=caesar(phraseCr, -34, false);
   if (phraseCr!=NULL) printf("%s\n", phraseCr);
   if (phraseDecr!=NULL) printf("%s\n", phraseDecr);
   free(phraseCr);
   free(phraseDecr);

// Task 2
   printf("\nTask 2\n");
   srand(time(NULL));
   phraseCr=shuffle(phrase, 5, true);
   phraseDecr=shuffle(phraseCr, 5, false);
   if (phraseCr!=NULL) printf("%s\n", phraseCr);
   if (phraseDecr!=NULL) printf("%s\n", phraseDecr);
   free(phraseCr);
   free(phraseDecr);

   return 0;
}
