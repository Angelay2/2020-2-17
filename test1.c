#include <stdio.h>
#include <stdlib.h>


// ʵ��һ������, ���������ַ����е�k���ַ�
// ����: ABCD����һ���ַ��õ�BCDA
//       ABCD���������ַ��õ�CDBA
// easy��:   ����һ�� ѭ��
// common��:

int leftRound(char* src, int n){

	int i, j;
	char tmp;
	int len = strlen(src);
	n %= len;

	for (i = 0; i < n; i++){
		tmp = src[0];
		for (j = 0; j < len - 1; j++){
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}
int main(){
	char src[] = "ABCDEFG";
	leftRound(src, 100);

	puts(src);

	system("pause");
	return 0;
}











