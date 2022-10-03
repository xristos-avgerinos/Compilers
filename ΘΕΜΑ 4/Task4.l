/*εναρξη δηλωσεων*/
NUMBER [0-9] 
VAR [A-Za-z][A-Za-z0-9]*
PRIMARY {VAR}|{NUMBER}
TERM ({PRIMARY}[*/%])*{PRIMARY}
EXPRESSION ({TERM}[+-])*{TERM}
ASSIGNMENT {VAR}[ ]?"="[ ]?{EXPRESSION}";"[ ]*      
/*πριν και μετα το "=" μπορει να υπαρχει το πολυ ενα κενο στην δηλωση ASSIGNMENT.Ενω πριν και μετα τη δηλωση ASSIGNMENT μπορουν να υπαρχουν απειρα κενα*/
/*τελος δηλωσεων*/

/*εναρξη κανονων*/
%%
{ASSIGNMENT} {
printf( "VALID ASSIGNMENT EXPRESSION: %s \n\n", yytext);
}
[ \t\n]+ /* απαλοιφη των κενων και των νεων γραμμων*/
.+ printf( "INVALID ASSIGNMENT EXPRESSION: %s\n\n", yytext );
%%
/*τελος κανονων*/
int main() {
   printf( "GIVE AN ASSIGNMENT EXPRESSION \n");
   yylex();
}
