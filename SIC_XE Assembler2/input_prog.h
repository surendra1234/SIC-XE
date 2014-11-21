#ifndef INPUT_PROG_H
#define INPUT_PROG_H
#include <iostream>
#include <cstdio>
#include <fstream>
void fib()
{
    freopen("input.txt","w",stdout);
    cout<<"COPY   START  0\n";
    cout<<"FIRST  STL    RETADR\n";
    cout<<"       LDB    #LENGTH\n";
    cout<<"       BASE   LENGTH\n";
    cout<<"       +JSUB  RDREC\n";
    cout<<"       LDA    LENGTH\n";
    cout<<"       COMP   #0\n";
    cout<<"       JEQ    ENDFILL\n";
    cout<<"       +JSUB  WRREC\n";
    cout<<"ENDFIL LDA    EOF\n";
    cout<<"       STA    BUFFER\n";
    cout<<"       LDA    #3\n";
    cout<<"       STA    LENGTH\n";
    cout<<"       +JSUB  WRREC\n";
    cout<<"       J      @RETADR\n";
    cout<<"EOF    BYTE   C'EOF'\n";
    cout<<"RETADR RESW   1\n";
    cout<<"LENGTH RESW   1\n";
    cout<<"BUFFER RESB   4096\n";
    cout<<".\n";
    cout<<".      SUBROUTINE TO READ RECORD INTO BUFFER\n";
    cout<<".\n";
    cout<<"RDREC  TD      INPUT\n";
    cout<<"       JEQ     RDREC\n";
    cout<<"       RD      INPUT\n";
    cout<<"       STA     N\n";
    cout<<"       RSUB\n";
    cout<<"INPUT  BYTE    X'F1'\n";
    cout<<"N      RESB    1\n";

    cout<<"       LDX    #0\n";
    cout<<"       LDT    N\n";
    cout<<"       LDA    ZERO\n";
    cout<<"       STA    ALPHA\n";
    cout<<"       LDA    ONE\n";
    cout<<"       STA    BETA\n";
    cout<<"ADDLP  LDS    ALPHA\n";
    cout<<"       LDA    BETA\n";
    cout<<"       STA    GAMMA\n";
    cout<<"       ADDR   S,A\n";
    cout<<"       STA    BETA\n";
    cout<<"       LDA    GAMMA\n";
    cout<<"       STA    ALPHA\n";
    cout<<"       TIXR   T\n";
    cout<<"       JLT    ADDLP\n";
    cout<<"       LDA    BETA\n";
    cout<<"       STA    FIBN\n";
    cout<<"ONE    WORD   1\n";
    cout<<"ZERO   WORD   1\n";
    cout<<"ALPHA  RESW   1\n";
    cout<<"BETA   RESW   1\n";
    cout<<"GAMMA  RESW   1\n";
    cout<<"INPUT  RESW   1\n";
    cout<<"FIBN   RESW   1\n";
    cout<<"       END    FIRST\n";
    cout<<"...";
    fclose(stdout);
}
void palindrome()
{
    freopen("input.txt","w",stdout);
    cout<<"COPY   START  0\n";
    cout<<"FIRST  LDX    #0\n";
    cout<<"       LDS    MAXLEN/2\n";
    cout<<"RLOOP  COMPR  X,S\n";
    cout<<"       JEQ    EXIT\n";
    cout<<"       LDA    BUFFER,X\n";
    cout<<"       LDT    #1\n";
    cout<<"       ADDR   X,T\n";
    cout<<"       LDT    BUFFER,MAXLEN-X\n";
    cout<<"       COMPR  A,T\n";
    cout<<"       JEQ    RLOOP\n";
    cout<<"       LDA    #0\n";
    cout<<"       STA    RESULT\n";
    cout<<"       JSUB   FINAL\n";
    cout<<"EXIT   LDA    #1\n";
    cout<<"       STA    RESULT\n";
    cout<<"FINAL  LDA    #0\n";
    cout<<"BUFFER BYTE   C'F1'\n";
    cout<<"MAXLEN RESW   1\n";
    cout<<"RESULT RESW   1\n";
    cout<<"       END    FIRST\n";
    fclose(stdout);
}
#endif
