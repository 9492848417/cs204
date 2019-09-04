#include<bits/stdc++.h>
using namespace std;


struct et 
{ 
    string value; 
    et* left, *right; 
}; 

int prec(string c) 
{ 
    if(c == "+" || c == "-") 
    return 1; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "^") 
    return 3; 

    else
    return -1; 
} 

string removeSpaces(string str) 
{ 
    int i = 0, j = 0; 
    while (str[i]) 
    { 
        if (str[i] != ' ') 
           str[j++] = str[i]; 
        i++; 
    } 
    str[j] = '\0'; 
    return str; 
} 
bool isOperator(string c) 
{ 
    if (c == "+" || c == "-" || 
            c == "*" || c == "/" || 
            c == "^") 
        return true; 
    return false; 
} 

et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  

vector<string> infixToPostfix(vector<string> s) 
{ 
    std::stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
        
        if(s[i]!="(" && s[i]!=")" && s[i]!="+" && s[i]!="*" && s[i]!="-" && s[i]!="/" && s[i]!="") 
         ns.push_back(s[i]); 

  
       
        else if(s[i] == "(")   
        st.push("("); 
          
        
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 

              if(c!="")ns.push_back(c);
               
            } 
            if(st.top() == "(") 
            { 
                string c = st.top(); 
                st.pop();  
            } 
        } 
          
        
        else{ 
            while(st.top() != "N" && prec(s[i]) <= prec(st.top())) 
            { 
                string c = st.top(); 
                st.pop(); 
                if(c!="")ns.push_back(c); 
                
            } 
            st.push(s[i]); 
        } 
  
    } 
    
    while(st.top() != "N") 
    { 
                string c = st.top(); 
                st.pop(); 
              if(c!="") ns.push_back(c); 
    } 
      
    return ns;
  
} 


et* constructTree(vector<string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    
    for (int i=0; i<postfix.size(); i++) 
    { 
        
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(postfix[i]); 
  
            
            t1 = st.top();
            st.pop();      
            t2 = st.top(); 
            st.pop(); 
  
            
            t->right = t1; 
            t->left = t2; 
  
           
            st.push(t); 
        } 
    } 
  
    
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
int evaluate(et * root){
    if(root==NULL) return 0;
    if(root->left==NULL&&root->right==NULL){
        return stoi(root->value);
    }
    int l=evaluate(root->left);
    int r=evaluate(root->right);
    if(root->value=="+") return l+r;
    else if(root->value=="-") return l-r;
    else if(root->value=="*") return l*r;
    else if(root->value=="/") return l/r;
    else return pow(l,r);
}

int main()
{
    string s;
	cin>>s;
	vector<string> str;
	string temp="";
    
	for(int i=0; i<s.length();i++)
	{
        
		if(s[i]>=48 && s[i]<=57)
		{
          temp=temp + s[i];
		}
		else
		{
             str.push_back(temp);
            temp=""; temp=temp + s[i];  
              str.push_back(temp);
            temp="";
		}

	}
    
    str.push_back(temp);
    
     vector<string> postexp=infixToPostfix(str);
   
    struct et* root=constructTree(postexp);
    int ans = evaluate(root);
    cout<<ans<<endl;
    return 0;	
}
