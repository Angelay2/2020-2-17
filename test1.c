#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

// 实现一个函数, 可以左旋字符串中的k个字符
// 例如: ABCD左旋一个字符得到BCDA
//       ABCD左旋两个字符得到CDBA
// 是字符串 不需要定义长度参数(但前提是有(strin.h),后面会出现strlen),如果不是字符串 必须给长度
// 转7次就回到原字符串了 转100次相当于转2次 100%7=2  7 = len => n %= len


// easy版:   左旋一个 循环
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


// 采用拼接 n是几 先从后面取出多少, 放在临时空间里 接回去 再赋回去

void leftRoundNORMAL(char* src, int n){

	int len = strlen(src);
	char tmp[256] = { 0 };// 辅助空间
	n %= len;

	strcpy(tmp, src + n);// 把CDEFG 给了tmp 
	strncat(tmp, src, n);// 只要src前两个 接到CDEFG后面
	strcpy(src, tmp);// 再赋回去
}

// 局部逆序
// ABCDEFG 分为两部分
// BA GFEDC 先把前一半逆序 再把后一半逆序
// CDEFGAB 最后再完成整体的逆序

// 逆序函数
void part_reverse(char* begin, char* end){

	char tmp;
	// 牵涉到遍历 就用for循环
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

	part_reverse(src, src + n - 1);// 前 n 个先逆序
	part_reverse(src + n, src + len - 1);// 剩下的逆序
	part_reverse(src, src + len - 1);// 整体逆序

}
int main(){
	char src[] = "ABCDEFG";
	leftRound(src, 100);

	puts(src);// CDEFGAB 转2次也一样 

	system("pause");
	return 0;
}











