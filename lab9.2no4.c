#include <stdio.h>
#include <string.h>
#include <ctype.h>
int checkLogin(char *login, char *passwd);
//accepted only if Length = 5 and a number 1 or more digits
int checkValidPass(char *ps);

int main() {
	char login[64], password[64];
	printf("Enter login : "); gets(login);
	printf("Enter password : "); gets(password);
	if( checkLogin(login, password) == 1) {
		printf("Welcome\n");
	}
	else {
		printf("Incorrect login or password\n");
	}
	if (checkValidPass(password)) {
		//if Password is valid
		printf("Accepted\n");
	}
	else{
		printf("Reject\n");
	}
}
int checkValidPass(char *ps) {
	int accepted=0;
	
	//4.1
	if(strlen(ps) == 5){
		for(int i=0; i<strlen(ps); i++){
			if(isdigit(ps[i])){
				accepted = 1;
			}
		}
	}
	
	//4.2 & 4.3
	if(strlen(ps) >= 5 && strlen(ps) <= 8){
		//4.2
		if(!isdigit(ps[0])){
			int upper = 0;
			for(int i=0; i<strlen(ps); i++){
				if(isupper(ps[i])){
					upper++;
				}
			}
			if(upper >= 2){
				int digit = 0;
				for(int i=0; i<strlen(ps); i++){
					if(isdigit(ps[i])){
						digit++;
					}
				}
				if(digit >= 2){
					accepted = 1;
				}
			}
		}
		
		//4.3
		int digit = 0;
		int upperrepeat = 0;
		int upper = 0;
		
		for(int i=0; i<strlen(ps); i++){
			if(isupper(ps[i])){
				upper++;
			}
		}
		
		if(upper >= 2){
			for(int i=0; i<strlen(ps)-1; i++){
				if(isupper(ps[i]) && isupper(ps[i+1])){
					upperrepeat = 1;
					break;
				}
			}
			if(upperrepeat == 0){
				for(int i=0; i<strlen(ps); i++){
					if(isdigit(ps[i])){
						digit++;
					}
				}
				if(digit >= 2){
					accepted = 1;
				}
			}
		}
	}
	
	return accepted;
}
int checkLogin(char *login, char *passwd) {
	if( !strcmp(login, "student1") && !strcmp(passwd, "mypass"))
		return 1;
	else
		return 0;
}