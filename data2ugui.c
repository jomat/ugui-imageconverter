#include <stdio.h>
/* Example how to convert a image to display data
 * - gimp set black/white image (image->mode->indexed->1 bit)
 * - export as data
 * - compile this: gcc data2ugui.c -o data2ugui
 * - run this
 */

#define width 85
#define height 48
unsigned char bo[width*height];
char b[(width*height)/8];

int main() {
  FILE *fp;
  char c;
  unsigned int bc;
  int i=0;
  int j=0;
  fp = fopen("/tmp/Untitled.data", "r");
  if(fp==NULL)
  {
    printf("Some problem in opening the file");
    return(0);
  }
  while((c=fgetc(fp))!=EOF)
  {
    bo[i]=c;
    printf("%c",bo[i] ? 'X' : ' ');
    if((i++%width)==0)
      printf("\n");
  }
  printf("\n");
  for(i=0;i<(width*height)/8;i++)
  {
    if((i%16)==0)
      printf("\n");
    bc=0;
    for(j=0;j<8;j++)
    {
      bc|=(bo[i%width+(width*8*(i/width))+(j*width)])<<j;
    }
    printf("0x%02x, ",bc);
  }

  fclose(fp);
  return 0;
 }
