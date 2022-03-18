/* File: palindrome.c 
   Author: Zeen Wang
   
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //allows to use "bool" as a boolean type
#include <ctype.h>

/*Optional functions, uncomment the next two lines
 * if you want to create these functions after main: */
bool readLine(char** line, size_t* size, size_t* length);

/* 
  * NOTE that I used char** for the line above... this is a pointer to
  * a char pointer.  I used this because of the availability of
  * a newer function getline which takes 3 arguments (you should look it
  * up) and the first argument is a char**.  You can create a char*, say
  * called var, and to make it a char** just use &var when calling this
  * function.  If this is too confusing, you can use fgets instead.  Feel
  * free to change the function prototypes as you need them.
  * Also, note the use of size_t as a type.  You can look this up, but
  * essentially, this is just a special type of int to track sizes of
  * things like strings...
*/

bool isPalindrome(const char* line, size_t len);
char toUpperCase(char letter);

int main(int argc, char *argv[]){
    //your code here
    char* line;
    size_t size;
    size_t length;
    while(true) {
      printf("word> ");
      readLine(&line, &size, &length);
      line[length-1] = '\0';
      if(line[0] == '.' && line[1] == '\0') break;
      
      if(isPalindrome(line, length)){
        printf("\"%s\" is a palindrome\n", line);
      } else {
        printf("\"%s\" is not a palindrome\n", line);
      }
    }
    free(line);
}

bool isPalindrome(const char* line, size_t len){
  int i = 0;
  int j = len - 1;
  while(j > i) {
    while(!isalpha(line[i])) i++;
    while(!isalpha(line[j])) j--;

    if(toUpperCase(line[i]) != toUpperCase(line[j])) {
      return false;
    } else {
      i++;
      j--;
    }
  }
}

char toUpperCase(char letter) {
  if(letter >= 'a') return letter - 'a' + 'A';
  return letter;
}

bool readLine(char** line, size_t* size, size_t* length) {
  *length = getline(line, size, stdin);
  if(*length == -1) return false;
  return true;
}