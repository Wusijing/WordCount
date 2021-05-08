#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *argv[])
{
    int x, count = 1;
    FILE *f;    //文件指针

    // 判断是否输入文件
    if (argc != 3){
        printf("文件名有误！请检查文件名");
        exit(1);    //非正常退出
    }

    // 判断能否成功打开文件
    if ((f = fopen(argv[2],"r")) == NULL){  //将argv[1]赋值给指针pt
        printf("打开文件 %s 失败,请检查文件是否有误",argv[2]);
        exit(1);
    }

    if (strcmp(argv[1], "-c") == 0) {
        count = 0;
        while((x = getc(f)) != EOF) {  //EOF 表示文件结束
            count++;
        }
        printf("字符数：%d\n", count);
    } else {
        while((x = getc(f)) != EOF) {
            if ((x == ' ') || (x == ',')) 
			count++;
        }
        printf("单词数：%d\n", count);
    }
    fclose(f);
    return 0;
}
