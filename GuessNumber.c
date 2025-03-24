#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void AB(char* s, char* t){
	int countA = 0, countB = 0;
	int used[4] = {0};
	for(int i = 0; i < 4; i++){
		if(t[i] == s[i]){
			countA++;
			used[i] = 1;
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(t[j] == s[i] && used[j] == 0){
				countB++;
				used[j] = 1;
				break;
			}
		}
	}
	printf("%dA%dB\n", countA, countB);
}

int main(){
	char s[5];
	s[4] = '\0';
	srand(time(NULL));
	for(int i = 0; i < 4; i++){
		s[i] = '0'+rand()%10;
	}
	while(1){
		char t[5];
		printf("Please guess numbers\n");
		scanf("%4s", t);
		AB(s, t);
		if(t[0] == s[0] && t[1] == s[1] && t[2] == s[2] && t[3] == s[3]){
			printf("Bingo~!\n");
			break;
		}
	}
	return 0;
}
