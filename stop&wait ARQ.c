#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
  
#define TRUE 1
#define FAlSE 0
int main()
{
     int total_frames;
     int current_frame=1;
     int is_lost;
     srand(time(NULL));
     printf("example cansole output:\n");
     printf("stop and wait ARQ\n");
     total_frames=(rand()%3)+3;
     while (current_frame<=total_frames)
     {
        printf("sending frame %d\n",current_frame);
        is_lost=rand()%2;
        if (is_lost)
        { 
            printF("frame %d lost!\n",current_frame);
            printf("retransmitting frame %d\n",current_frame);
        }
        else
        {
            printf("frame %d received sccessfully.\n",current_frame);
            printf("ACK received for frame %d.\n",current_frame);
            current_frame++;
        }
        sleep(1);
     }
     printf("\nALL frames transmitted successfully.\n");
     printf("stop and wait ARQ completed.\n");
    }
