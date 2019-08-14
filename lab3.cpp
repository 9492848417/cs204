#include <iostream> 
#include <stack>
using namespace std;

void balance_parentheses();

int main()
{
    int t;
    cout << "Enter number of test cases:";
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        balance_parentheses();
    }

    return 0;
}

void balance_parentheses()
{
    stack<char> a;
    string s;
    cout << "Enter string :";
    cin >> s;
	int i;

    int flag = 0; 

    for (int i = 0; i < s.length(); i++)
    
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(' || s[i] == '<' ) {
            
            a.push(s[i]);
            flag = 1;
        }
        if (!a.empty()) {
            if (s[i] == '}') {
                if (a.top() == '{')
                
                {
                    a.pop();
                    
                    continue;
                }
	
            }
	}
	if (!a.empty()) {
	     if (s[i] == '>') {
		if (a.top() == '<')

		{
			a.pop();

			continue;
		}
	
	    }
	    
	    }
	if (!a.empty()) {
            if (s[i] == ']') {
                if (a.top() == '[') {
                    a.pop();
                    continue;
                }
         
            }
	}
	if (!a.empty()) {
             if (s[i] == ')') {
                if (a.top() == '(') {
                    a.pop();
                    continue;
                }
        
		
            }
        }
	}
        
 for (int i=0;i < s.length();i++) {
	{	
	if (s[i]=='|')
	a.push(s[i]);
	flag = 1;
			}

	if (!a.empty())
	{
	if (s[i] == '|') {
		if (a.top() == '|')
		{
			a.pop();
			continue;
		}
		
	}
	}
}

    if ((a.empty()) && (flag == 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
