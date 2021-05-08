#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *argv[])
{
    int x, count = 1;
    FILE *f;    //�ļ�ָ��

    // �ж��Ƿ������ļ�
    if (argc != 3){
        printf("�ļ������������ļ���");
        exit(1);    //�������˳�
    }

    // �ж��ܷ�ɹ����ļ�
    if ((f = fopen(argv[2],"r")) == NULL){  //��argv[1]��ֵ��ָ��pt
        printf("���ļ� %s ʧ��,�����ļ��Ƿ�����",argv[2]);
        exit(1);
    }

    if (strcmp(argv[1], "-c") == 0) {
        count = 0;
        while((x = getc(f)) != EOF) {  //EOF ��ʾ�ļ�����
            count++;
        }
        printf("�ַ�����%d\n", count);
    } else {
        while((x = getc(f)) != EOF) {
            if ((x == ' ') || (x == ',')) 
			count++;
        }
        printf("��������%d\n", count);
    }
    fclose(f);
    return 0;
}
