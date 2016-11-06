/* Caesar cipher - Implement a Caesar cipher */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 512


/* encode consumes a character and a integer, and mutates the character according to the caesar cipher*/
char *encode(char *msg, int key)
{
	int i = 0;
	char *temp_msg = msg;
	
	do {
		temp_msg[i] = toupper(temp_msg[i]);
		i++;
	} while (i < strlen(temp_msg));
	
	for (i = strlen(temp_msg) - 1; i >= 0; i--) {
		if (isalpha(temp_msg[i]))
			temp_msg[i] = ((temp_msg[i] + key) <= 'Z') ? (temp_msg[i] + key) : (temp_msg[i] + key - 26);
	}
	
	return temp_msg;
}

/*decode consumes a character and a key integer, then decodes the character according 
caesar cipher.*/
char *decode(char *msg, int key)
{
	int i = 0;
	char *temp_msg = msg;
	
	do {
		temp_msg[i] = toupper(temp_msg[i]);
		i++;
	} while (i < strlen(temp_msg));
	
	for (i = strlen(temp_msg) - 1; i >= 0; i--) {
		if (isalpha(temp_msg[i]))
			temp_msg[i] = ((temp_msg[i] - key) >= 'A') ? (temp_msg[i] - key) : (temp_msg[i] - key + 26);
	}
	
	return temp_msg;
}

int main()
{
	int choice;
	char str[BUF_SIZE];
	int key;
	
	printf("Caesar cipher\n1. encode\n2. decode\n");
	scanf(" %d", &choice);
	
	fflush(stdin);
		
	if (fgets(str, BUF_SIZE - 1, stdin) != NULL) {
		printf("Key? (1-25) ");
		scanf(" %d", &key);
		
		if (key >= 1 && key <= 25)
			if (choice == 1)
				printf("%s", encode(str, key));
			else if (choice == 2)
				printf("%s", decode(str, key));
			else
				printf("Invalid input.\n");
		else
			printf("Invalid input.\n");
	}
	
	return 0;
}