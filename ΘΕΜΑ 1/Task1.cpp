#include <stack>
#include<iostream>
#include <algorithm>

using namespace std;


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
    cout << x;

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
void func(char Input, stack<char> s, const string& State){
    cout << "INPUT: " << Input << "\n";

    cout << "STACK: ";
    PrintStack(s);
    cout <<"\n";

    cout<< "STATE: " + State + "\n" + "\n";
}

bool balance(string expr)
{
    bool bigExpr=true;
    size_t sum_of_xy = count(expr.begin(), expr.end(), 'x') + count(expr.begin(), expr.end(), 'y') +
            count(expr.begin(), expr.end(), 'X') + count(expr.begin(), expr.end(), 'Y');

    if(sum_of_xy > 10){
        cout<<"The expression string seems big and it might take some time to be printed do you wish to continue?[Y/N]: ";
        string answer ;
        cin>>answer;
        if(!(answer == "Yes" ||answer=="Y" || answer=="yes" || answer == "y")){
            bigExpr = false;
        }
    }
    
    string State = "k1";
    char Input = 0;
    stack<char> s;
    s.push('$');
    func(Input, s, State);

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        Input = expr[i];
        //input = expr[i];

        if(i==(expr.length()-1) && !bigExpr){
            cout <<".\n";
            cout <<".\n";
            cout <<".\n";
            bigExpr = true;
            cout <<"\n";
            cout <<"\n";
        }
        
         if (Input == 'X' || Input == 'x')
         {
             // Push the element in the stack
             s.push(Input);
                
             if(bigExpr) {
                 func(Input, s, State);
             }

             continue;
         }else if ((Input == 'y' || Input=='Y') && (s.top() == 'x' || s.top() == 'X')) {

             s.pop();
             // Store the top element in a
             if (bigExpr) {
                 func(Input, s, State);
             }

         }else if(Input == 'Y'|| Input == 'y' && s.top()=='$'){
             
             if(bigExpr) {
                 func(Input, s, State);
             }
             return false;

            }

        }
    
    if(  State == "k1" && s.top()=='$'){

        Input = ' ' ;
        cout << "INPUT: " << Input << "\n";

        cout << "STACK: ";
        PrintStack(s);
        cout << "\n";

        State = "k2";
        cout << "STATE: " + State + "\n" + "\n";
        s.pop();
        return true;

    }

    return (s.empty());
}

// Driver code
int main()
{
    string expr ;
    cout<<"Insert expression:";
    cin >> expr;
    cout << "\n";

    // Function call
    if (balance(expr))
        cout << "Valid";
    else
        cout << "Not Valid";
    return 0;
}