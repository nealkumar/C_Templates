/*
 * test.c
 *
 *  Created on: Mar 30, 2020
 *      Author: nealk
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* fun1(char* str);
void start();

int main(void){
	start();
}

void start(void){
	printf("started...\n");
		pthread_t func1, func2, func3;
//		void* raw = (void*)malloc(0*sizeof(void));
//		char* str = (char*)&raw;
//		str[0] = 'N';
//		str[1] = 'E';
//		str[2] = 'A';
//		str[3] = 'L';
//		str[4] = 'L';
//		str[5] = 'L';
//		str[6] = 'L';
//		str[7] = 'L';
		char* str = (char*)malloc(0);
		*(str+0) = 'N';
		int err1 = pthread_create(&func1, NULL, (void*)&fun1, "hellloooo\n");

		//getchar();	//blocks until char is entered in console

		pthread_create(&func3, NULL, (void*)&fun1, str);
		int err2 = pthread_create(&func2, NULL, (void*)&fun1, "message toooooo\n");

		pthread_join(func2, NULL);	//forcing at least 1 method to join makes all functions activate...

		free(str);

		printf("%s%d\n", "Error status 1 = " , err1);
		printf("%s%d\n", "Error status 2 = " , err2);
		//free(raw);
		//free(str);
}

void* fun1(char* str){
	pthread_detach(pthread_self());
	printf("Inside the thread\n");
	printf("%s\n", str);
	pthread_exit(NULL);
	return NULL;
}
