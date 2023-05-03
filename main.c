#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
struct termios orig_termios;

void disable_raw_mode(void) {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode(void){
     tcgetattr(STDIN_FILENO, &orig_termios);
     atexit(disable_raw_mode);
     struct termios raw=orig_termios;
     raw.c_lflag &= ~(ECHO);
     tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}
int main(void){
      
    uint8_t c;
    uint8_t d='¶';
    char y;
    while(read(STDIN_FILENO, &c, 4) == 1 &&  c!=d);
    // enable_raw_mode();
    scanf("%c",&y);
    printf("%c",y);
    return 0;
}
