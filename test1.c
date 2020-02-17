#include <stdio.h>
#include <stdlib.h>


// 实现一个函数, 可以左旋字符串中的k个字符
// 例如: ABCD左旋一个字符得到BCDA
//       ABCD左旋两个字符得到CDBA
// easy版:   左旋一个 循环
// common版:

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











