%{
#include <algorithm>  // for std::unique
#include <iostream>   // for std::cout
#include <string>     // for std::string
#include <stdio.h>


void  isUnique(std::string str,int length);

%}


line        e(y|u)thia
triangle    trig(w|o)no
square      tetrag(w|o)no
corner      g(w|o)nia
pentagon    pentag(w|o)no
hexagon     eksag(w|o)no
heptagon    eftag(w|o)no
octagon     oktag(w|o)no
letters     [A-H]
%%
({triangle})" "({letters}{3})$ {
    
    isUnique(yytext,3);
    
}

({corner})" "({letters}{1})$ {
    
    isUnique(yytext,1);
}

{line}" "({letters}{2})$ {
    
    isUnique(yytext,2);
}

{square}" "({letters}{4})$ {
    
    isUnique(yytext,4);
}

{pentagon}" "({letters}{5})$ {
    
    isUnique(yytext,5);
}
{hexagon}" "({letters}{6})$ {
    
    isUnique(yytext,6);
}
{heptagon}" "({letters}{7})$ {
    
    isUnique(yytext,7);
}
{octagon}" "({letters}{8})$ {
    
    isUnique(yytext,8);
}

.+ printf( "INVALID" );

%%
void  isUnique(std::string str,int length ){
    std::string str1=str.substr(str.size() - length);
    
    std::sort(str1.begin(), str1.end());
    bool u = std::unique(str1.begin(), str1.end()) == str1.end();
    if (u) { std::cout << "The expression "<<yytext<<" is valid\n"; }
    else   { std::cout << "The expression "<<yytext<<" is not  valid\n"; }
}


int main() {
    std::cout<< "Give expression(example: tetragwno ABCD)"<<std::endl;
    yylex();
    return 0;
}
