#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include <iomanip>

#define S 0
#define X 1
#define Y 2
#define Z 3
#define LeftP 0
#define RightP 1
#define  a 2
#define  b 3
#define MULT 4
#define SUB 5
#define SUM 6


using namespace std;
string M[4][7];
stack<char> MyStack;
list<string> TreeList;
list<string>::iterator iter;
string userinput,input;
int NumberOfLine,NumberOfColumn;
bool completed=false;

string myReverse(string tempString)
{
    int length=tempString.length();

    for (int i = 0; i < length / 2; i++)
        swap(tempString[i], tempString[length - i - 1]);

    string reversed=tempString;

    return reversed;
}

void M_Initialize(){
    for (int i=0; i<=3 ; i++){
        for( int j=0; j<=7; j++){
            M[i][j]="0";
        }
    }

    M[S][LeftP]="(X)";
    M[X][LeftP]="YZ";
    M[X][a]="YZ";
    M[X][b]="YZ";
    M[Y][LeftP]="S";
    M[Y][a]="a";
    M[Y][b]="b";
    M[Z][RightP]="E";
    M[Z][MULT]="*X";
    M[Z][SUB]="-X";
    M[Z][SUM]="+X";

}
void FindLineColumn(char L,char C){
    NumberOfLine=0;
    NumberOfColumn=0;


    if (L=='S'){NumberOfLine=S;
    }else if (L=='X'){NumberOfLine=X;
    }else if(L=='Y'){NumberOfLine=Y;
    }else if (L=='Z'){NumberOfLine=Z;}

    if (C=='('){NumberOfColumn=LeftP;
    }else if(C==')'){NumberOfColumn=RightP;
    }else if (C=='a'){NumberOfColumn=a;
    }else if (C=='b'){NumberOfColumn=b;
    }else if (C=='*'){NumberOfColumn=MULT;
    }else if(C=='-'){NumberOfColumn=SUB;
    }else if (C=='+'){NumberOfColumn=SUM;
    }

}
void PrintStack(stack<char> s)
{
    // If stack is empty then return
    if (s.empty())

        return;


    char x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x ;

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
void PrintCharExceptInt(int A,int B){
    char K,L;
    string SymbolAndArrow;
    if (A==0){
        K='S';
        SymbolAndArrow="S-->";
    }else if (A==1){
        K='X';
        SymbolAndArrow="X-->";
    }else if (A==2){
        K='Y';
        SymbolAndArrow="Y-->";
    }else if (A==3){
        K='Z';
        SymbolAndArrow="Z-->";
    }

    if (B==0){L='(';
    }else if (B==1){L=')';
    }else if (B==2){L='a';
    }else if (B==3) {L = 'b';
    }else if (B==4){L='*';
    }else if (B==5){L='-';
    }else if (B==6){L='+';}

    cout<<string(30-input.length(),' ')<<"M("<<K<<","<<L<<")";

    cout<<string(15,' ')<<SymbolAndArrow<<M[A][B]<<endl;
}



int main() {

TreeList.push_back("S");


  char FirstInputChar,TopStackChar;
M_Initialize();
MyStack.push('$');
MyStack.push('S');


cout<<"Please insert the input"<<endl;

cin>>userinput;
input=userinput+'$';


cout<<"Stack"<<string(15,' ')<<"Input"<<string(25,' ')<<"Rule"<<string(18,' ')<<"Production"<<endl;


while (true){
PrintStack(MyStack);
cout<<string(20-MyStack.size(),' ')<<input;




    FirstInputChar=input[0];
    TopStackChar=MyStack.top();

    if(MyStack.top()=='$' ) {
        if (FirstInputChar == '$') {
            cout <<endl<< "Recognised";
            completed=true;
            break;
        }else{
            cout<<endl<<"Not Recognised";
            break;
        }
    }

    if (FirstInputChar!='(' && FirstInputChar!=')' && FirstInputChar!='a'&& FirstInputChar!='b'&& FirstInputChar!='*' && FirstInputChar!='+' && FirstInputChar!='-'){
        cout<<endl<<"There was an unrecognized character"<<endl<<"Process finished.";
        break;
    }

if (FirstInputChar!=MyStack.top()){


    FindLineColumn(TopStackChar,FirstInputChar);

    if (M[NumberOfLine][NumberOfColumn]!= "0") {

        //cout<<"M["<<NumberOfLine<<"]["<<NumberOfColumn<<"]"<<"          ";
        PrintCharExceptInt(NumberOfLine,NumberOfColumn);
        //cout<<M[NumberOfLine][NumberOfColumn]<<endl;

        TreeList.push_back(M[NumberOfLine][NumberOfColumn]);

        if (M[NumberOfLine][NumberOfColumn]=="E"){
            MyStack.pop();
        }else {
            MyStack.pop();
            string temp = myReverse(M[NumberOfLine][NumberOfColumn]);
            for (char i:temp) {
                MyStack.push(i);
            }
        }
    }else{
        cout<<endl<<"There was not such rule as ";
        PrintCharExceptInt(NumberOfLine,NumberOfColumn);
        //cout<<endl<<"There was not such rule as "<<"M["<<NumberOfLine<<"]["<<NumberOfColumn<<"]"<<endl;
        break;
    }

}else if(FirstInputChar==MyStack.top()){

    MyStack.pop();
    input.erase(input.begin());
    cout<<endl;
}


}





if (completed) {


    cout << endl;
    int count = 0;
    char space = ' ';
    for (iter = TreeList.begin(); iter != TreeList.end(); iter++) {
        /*for (char Ch:*iter){
            cout<<Ch<<"   ";
        }*/
        string s = *iter;


        if (s == "S") {
            //cout <<endl<< "                " << s<<endl;
            cout << string((count * 4) + 14, space) << s << endl;
            // cout <<string((count*4)+14,space) <<endl;
        } else if (s == "(X)") {
            cout << string(count + 12, space) << s[0] << space << s[1] << space << s[2] << endl;
        } else if (s == "YZ") {

            cout << string((4 * count) + 12, space) << s[0] << string(3, space) << s[1] << endl;
            //cout<<"             "<<s[0]<<"      "<<s[1]<<endl;
        } else if (s == "a" || s == "b") {
            cout << string((count * 4) + 10, space) << s;
        } else if (s == "+X" || s == "-X" || s == "*X") {

            cout << string(4, space) << s[0] << string(2, space) << s[1] << endl;
            count++;
        } else if (s == "E") {
            cout << string(4, space) << s;
        }

    }

}



    return 0;
}


