bison -d compilersintactic.y
flex compilerlematic.l
gcc compilersintactic.tab.c lex.yy.c -lfl -o compiler.exe
./compiler.exe pruebas.txt
