#include <stdio.h>

int main(){
int c;                                      //Se crea como int debido a que necitamos una manera de poder detener el programa, EOF es un int
                                            //No podemos usar char tampoco debido a que no es lo suficientemente grande como para almacenar EOF
while ((c = getchar( )) != EOF) {           //Esto sigue leyende y escribiendo mientras el getchar no detectte EOF 
    putchar(c);                             //Imprime lo que detecte getchar   
    }
}

/* 

Standard input, by default, is line-buffered with an interactive device. This means that your program won't see any input at all until a complete line is ready, 
in your case when you hit Enter. One good reason for this is that if the user types her 8 character password, then hits backspace 8 times, and then types her username 
and hits Enter, then your program only gets her username, and never sees the correction, which is usually what you want when your shell gives the opportunity to edit 
your input before you send it anywhere.

So what happens is essentially this:

    You call getchar(). No input is available, so it waits.

    You press a. It's not the end of a line, so no input is sent to your program, getchar() has nothing to read, so it still waits.

    You press b. It's not the end of a line, so no input is sent to your program, getchar() has nothing to read, so it still waits.

    You press c. It's not the end of a line, so no input is sent to your program, getchar() has nothing to read, so it still waits.

    You press d. It's not the end of a line, so no input is sent to your program, getchar() has nothing to read, so it still waits.

    You press e. It's not the end of a line, so no input is sent to your program, getchar() has nothing to read, so it still waits.

    You press Enter. Now it is the end of a line, so the input "abcde\n" is sent to your program.

    getchar() now has input to read, so it returns 'a', increments nc, and loops back to wait for input.

    Immediately, getchar() has more input to read from the rest of the characters in that line, so it returns 'b', increments nc, and loops back to wait for input.

    Immediately, getchar() has more input to read from the rest of the characters in that line, so it returns 'c', increments nc, and loops back to wait for input.

    Immediately, getchar() has more input to read from the rest of the characters in that line, so it returns 'd', increments nc, and loops back to wait for input.

    Immediately, getchar() has more input to read from the rest of the characters in that line, so it returns 'e', increments nc, and loops back to wait for input.

    Immediately, getchar() has more input to read from the rest of the characters in that line, so it returns '\n', increments nc, and loops back to wait for input.

    If you signified end-of-input, perhaps by pressing Control-D, then getchar() has nothing to read and knows there will never be anything to read, so it returns EOF 
    and your loop ends. If it were not end-of-input, then getchar() would just again wait here for you to enter a new line of input.

So what actually happened here is that getchar() did nothing until you hit Enter. Then, probably before you even took your finger off the Enter key, it ran six times 
and consumed the six characters of input that you typed. But despite getchar() running six times, you were only prompted to enter something once (twice, if you 
include having to type Control-D), because getchar() will only wait for your input when it doesn't already have input available and waiting.

Back in the days where standalone terminals were common, the actual terminal device might not even transmit any characters to the computer 
until the end of a line, and could have a small amount of on-board memory to allow for this kind of local line-based editing, so the computer 
itself might literally never see it until end-of-line. On the kind of modern PC many people use, the operating system, down at the terminal driver 
level, will more probably be buffering these characters itself, and just presenting them and making them available to your program one line at a time
 (unless you specifically tell it that you want characters immediately, of course).
*/