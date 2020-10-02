#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int n;
    char buffer[20];
	scanf("%d", &n);
	bin_count(n, buffer);
	return 0;
}
void bin_count(int n, char*buffer) {
	int i;
	for(i = 0; i < pow(2,n); i++) {
		itoa(i,buffer,2);
    	printf("valor binario = %s\n", buffer);
	}
}
