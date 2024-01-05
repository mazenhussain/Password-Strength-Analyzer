#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hasLowercase(char password[]){
  int i;
  for (i=0;i<strlen(password);i++){
    if (islower(password[i])){
      return 1;
    }
  }
  return 0;
}

int hasUppercase(char password[]){
  int i;
  for (i=0;i<strlen(password);i++){
    if (isupper(password[i])){
      return 1;
    }
  }
  return 0;
}

int hasDigit(char password[]){
  int i;
  for (i=0;i<strlen(password);i++){
    if (isdigit(password[i])){
      return 1;
    }
  }
  return 0;
}

int hasSpecialChar(char password[]){
  int i;
  for (i=0;i<strlen(password);i++){
    if (!isalnum(password[i])){
      return 1;
    }
  }
  return 0;
}

int evaluateStrength(char password[]){
  int score;
  
  score = hasLowercase(password) + hasUppercase(password) + hasSpecialChar(password) + hasDigit(password);


  if (strlen(password) >= 12){
    score++;
  }

  return score;
}


int main() {
  int menu_input;
  char strength[200] = "\nError: No password has been tested yet";
  while (1>0){
    printf("\nPassword Resilience Analyzer\n");
    printf("1. Test a new password\n");
    printf("2. View strength of the last tested password\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &menu_input);

    if (menu_input == 1){
      char password[500];
      int score;
      int rightSize = 0;


      while (1>0){
      printf("Enter the password:");
      scanf("%499s", password);
      if (strlen(password) < 8){
        printf("Error: Password should be at least 8 characters long.\n");
        rightSize = 0;
        break;
      }else{
        rightSize = 1;
        break;
      }
      }

      score = evaluateStrength(password);

      if ((score > 0 && score <= 2) & rightSize == 1 ){
        strcpy(strength,"Weak");
      }else if((score >= 3  && score <= 4) & rightSize == 1){
        strcpy(strength,"Moderate");
      }else if((score == 5) & rightSize == 1){
        strcpy(strength,"Strong");
      }

      if (rightSize == 1){
        printf("Password strength: %s\n",strength);
      }
      
    }else if(menu_input == 2){
      printf("Last tested password strength: %s\n",strength);
    }else if(menu_input == 3){
      printf("Exiting...\n");
      return 0;
    }else{
      printf("Incorrect input, Please enter a number from the list\n");
    }
  }

  return 0;
}

