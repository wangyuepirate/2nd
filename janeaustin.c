#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"


int main(void)
{
   FILE *ifp1,*ifp2;
   set *sa,*sb,*same;
   arrtype tem;
   char book1[]="sense-and-sense.txt";
   char book2[]="pride-and-prej.txt";

   if((ifp1=fopen(book1,"r"))==NULL){
      printf("CANNOT OPEN FILE\n");
      exit(1);
    }
   if((ifp2=fopen(book2,"r"))==NULL){
      printf("CANNOT OPEN FILE\n");
      exit(1);
    }
    sa=set_init();
    sb=set_init();
    memset(&tem,0,sizeof(arrtype));

    while(fscanf(ifp1,"%s",tem.str)!=EOF){
       set_insert(sa,tem);
       memset(&tem,0,sizeof(arrtype));
    }
    printf("There are %d unique words in %s \n",sa->sz,book1);  
    
    while(fscanf(ifp2,"%s",tem.str)!=EOF){
       set_insert(sb,tem);
       memset(&tem,0,sizeof(arrtype));
    }
   printf("There are %d unique words in %s\n",sb->sz,book2); 
   same=set_intersection(sa,sb);
   printf("There are %d common words\n",same->sz);

   fclose(ifp1);
   fclose(ifp2);
   return 0;
}

