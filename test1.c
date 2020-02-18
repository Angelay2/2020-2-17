#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

// ʵ��һ������, ���������ַ����е�k���ַ�
// ����: ABCD����һ���ַ��õ�BCDA
//       ABCD���������ַ��õ�CDBA
// ���ַ��� ����Ҫ���峤�Ȳ���(��ǰ������(strin.h),��������strlen),��������ַ��� ���������
// ת7�ξͻص�ԭ�ַ����� ת100���൱��ת2�� 100%7=2  7 = len => n %= len


// easy��:   ����һ�� ѭ��
void leftRoundEASY(char* src, int n){
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


// ����ƴ�� n�Ǽ� �ȴӺ���ȡ������, ������ʱ�ռ��� �ӻ�ȥ �ٸ���ȥ

void leftRoundNORMAL(char* src, int n){

	int len = strlen(src);
	char tmp[256] = { 0 };// �����ռ�
	n %= len;

	strcpy(tmp, src + n);// ��CDEFG ����tmp 
	strncat(tmp, src, n);// ֻҪsrcǰ���� �ӵ�CDEFG����
	strcpy(src, tmp);// �ٸ���ȥ
}

// �ֲ�����
// ABCDEFG ��Ϊ������
// BA GFEDC �Ȱ�ǰһ������ �ٰѺ�һ������
// CDEFGAB �����������������

// ������
void part_reverse(char* begin, char* end){

	char tmp;
	// ǣ�浽���� ����forѭ��
	for (; begin < end; begin++, end--){
	//while (begin < end{
		tmp = *begin;
		*begin = *end;
		*end = tmp;

	}
}
void leftRound(char* src, int n){
	int len = strlen(src);
	n %= len;

	part_reverse(src, src + n - 1);// ǰ n ��������
	part_reverse(src + n, src + len - 1);// ʣ�µ�����
	part_reverse(src, src + len - 1);// ��������

}
int main(){
	char src[] = "ABCDEFG";
	leftRound(src, 100);

	puts(src);// CDEFGAB ת2��Ҳһ�� 

	system("pause");
	return 0;
}











