#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int a = -10, b = 3;
  
  for (a;a<11;a++){
    printf("\n Division von %d und %d = %d",a,b,(a/b));
    printf("\n Modulo (Rest) von %d durch %d = %d",a,b,abs(a%b));
  }
    b = 4;
    a = -10;
  for (a;a<11;a++){
    printf("\n Division von %d und %d = %d",a,b,(a/b));
    printf("\n Modulo (Rest) von %d durch %d = %d",a,b,abs(a%b));
  }
  scanf("%d",&a);  
}
