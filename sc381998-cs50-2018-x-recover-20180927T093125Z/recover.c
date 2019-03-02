#include<stdio.h>
#include<cs50.h>
#include"bmp.h"

int main(void)
{
       FILE* card_ptr=fopen("card.raw","r");
       if(card_ptr==NULL)
       {
           fprintf(stderr,"file not found!");
           return 1;
       }
       BYTE buffer[512];bool found_first_jpg=false;FILE* new_jpg_ptr; int file_counter=0;
       while(fread(buffer,1,512,card_ptr)!=0x00)
       {
           if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xf0)==0xe0)
        {
            if(!found_first_jpg)
            {
                found_first_jpg=true;
                char filename[8];
                sprintf(filename,"%03i.jpg",file_counter++);
                new_jpg_ptr=fopen(filename,"w");
                if(new_jpg_ptr==NULL)
                return 2;
                fwrite(buffer,1,512,new_jpg_ptr);
            }
            else
            {
            fclose(new_jpg_ptr);
            char filename[8];
                sprintf(filename,"%03i.jpg",file_counter++);
                new_jpg_ptr=fopen(filename,"w");
                if(new_jpg_ptr==NULL)
                return 2;
                 fwrite(buffer,1,512,new_jpg_ptr);
        }
       }
       else
       {
           if(found_first_jpg)
{
      fwrite(buffer,1,512,new_jpg_ptr);
}
      }
      }
      fclose(new_jpg_ptr);
      fclose(card_ptr);

}