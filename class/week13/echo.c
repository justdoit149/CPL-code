

// main函数的两个参数：int argc, char *argv[];
// argc用于计数传进来的命令行参数个数，argv储存命令行参数
// argv[0],程序的名称
// argv[1 ---- n-1]储存命令行参数
// argv[n]:空指针NULL


#include <stdio.h>

/**
 * @brief program/command-line arguments
 * @param argc count the number of arguments
 * @param argv v: vector
 *  argv[0]: program name
 *  argv[1 .. argc - 1]: ant hengxin
 *  argv[argc]: NULL
 * @return
 */
int main(int argc, char *argv[]) {
  // for (int i = 1; i < argc; i++) {
  //   printf("%s\n", argv[i]);
  // }

  // for (char **ptr = argv + 1; *ptr != NULL; ptr++) {
  //   printf("%s\n", *ptr);
  // }

  char **ptr = argv;
  // ptr = ptr + 1; *ptr;
  // *++ptr vs. *ptr++
  // *--ptr vs. *ptr--
  while (*++ptr != NULL) {
    printf("%s\n", *ptr);
  }

  return 0;
}