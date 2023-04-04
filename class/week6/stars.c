#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<2*n;j++){
            if(j<=(n+i-1)&&j>=(n-i+1)){
                printf("*");
            }else{
                printf(" ");
            }
        } 
    printf("\n");


    }
    return 0;
}

/*
以下内容为课堂上老师的代码（上面是上课的时候自己写的）
#include <stdio.h>

int main() {
  int lines;
  scanf("%d", &lines);

  for (int i = 0; i < lines; i++) {
    // print lines - 1 - i spaces
    for (int j = 0; j < lines - 1 - i; j++) {
      printf(" ");
    }

    // print 2 * i + 1 stars
    for (int j = 0; j < 2 * i + 1; j++) {
      printf("*");
    }

    if (i < lines - 1) {
      printf("\n");
    }
  }

  return 0;
}
*/