#include<iostream>
#include<string>
#include<string.h>
using namespace std;

//Structure of Node
struct Node
{
	char data;
	Node* next;
};
class List
{
private:
	Node* head; //Address of Head Node.
	int length; //Get current size of list.
public:
	List(); //Initialize function
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	char ReadHead() const;
	void InsertAtHead(char value);
	char DeleteFromHead();
};

List::List() // Constructor of class
{
	length = 0;
	head = NULL;
}

//Check if there is enough system memory available;
bool List::IsFull() const
{
	Node* temp;
	try {
		temp = new Node;
		delete temp;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

bool List::IsEmpty() const
{
	return (length == 0 || head == NULL);
}

int List::GetLength() const
{
	return length;
}

//Function returns the data vaule at head of the list, use as helper function to implement top() of stack
char List::ReadHead() const
{
	char data = '`';
	if (head != NULL)
	{
		data = head->data;
	}
	return data;
}

//Insert a new node with value at the head of List
void List::InsertAtHead(char value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;

	head = newNode;
	length++;
}
//Delete node with value of a from List
char List::DeleteFromHead()
{
	char data = '`';
	if (head != NULL)
	{
		Node* temp = head;
		head = temp->next;
		data = temp->data;
		delete temp;
		length--;
	}
	return data;
}


class Stack
{
private:
	List list;
public:
	bool isFull() const;
	bool isEmpty() const;
	char top() const;
	void push(char value);
	char pop();
};

bool Stack::isFull() const
{
	return list.IsFull();
}
bool Stack::isEmpty() const
{
	return list.IsEmpty();
}
char Stack::top() const
{
	return list.ReadHead();
}
void Stack::push(char value)
{
	list.InsertAtHead(value);
}
char Stack::pop()
{
	return list.DeleteFromHead();
}

struct NodeStr
{
	string data;
	NodeStr* next;
};
class ListStr
{
private:
	NodeStr* head; //Address of Head Node.
	int length; //Get current size of list.
public:
	ListStr(); //Initialize function
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	string ReadHead() const;
	void InsertAtHead(string value);
	string DeleteFromHead();
};

ListStr::ListStr() // Constructor of class
{
	length = 0;
	head = NULL;
}

//Check if there is enough system memory available;
bool ListStr::IsFull() const
{
	Node* temp;
	try {
		temp = new Node;
		delete temp;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

bool ListStr::IsEmpty() const
{
	return (length == 0 || head == NULL);
}

int ListStr::GetLength() const
{
	return length;
}

//Function returns the data vaule at head of the list, use as helper function to implement top() of stack
string ListStr::ReadHead() const
{
	string data = "";
	if (head != NULL)
	{
		data = head->data;
	}
	return data;
}

//Insert a new node with value at the head of List
void ListStr::InsertAtHead(string value)
{
	NodeStr* newNode = new NodeStr;
	newNode->data = value;
	newNode->next = head;

	head = newNode;
	length++;
}
//Delete node with value of a from List
string ListStr::DeleteFromHead()
{
	string data = "";
	if (head != NULL)
	{
		NodeStr* temp = head;
		head = temp->next;
		data = temp->data;
		delete temp;
		length--;
	}
	return data;
}


class StackStr
{
private:
	ListStr list;
public:
	bool isFull() const;
	bool isEmpty() const;
	string top() const;
	void push(string value);
	string pop();
};

bool StackStr::isFull() const
{
	return list.IsFull();
}
bool StackStr::isEmpty() const
{
	return list.IsEmpty();
}
string StackStr::top() const
{
	return list.ReadHead();
}
void StackStr::push(string value)
{
	list.InsertAtHead(value);
}
string StackStr::pop()
{
	return list.DeleteFromHead();
}


struct NodeInt
{
	int data;
	NodeInt* next;
};
class ListInt
{
private:
	NodeInt* head; //Address of Head Node.
	int length; //Get current size of list.
public:
	ListInt(); //Initialize function
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	int ReadHead() const;
	void InsertAtHead(int value);
	int DeleteFromHead();
};

ListInt::ListInt() // Constructor of class
{
	length = 0;
	head = NULL;
}

//Check if there is enough system memory available;
bool ListInt::IsFull() const
{
	Node* temp;
	try {
		temp = new Node;
		delete temp;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

bool ListInt::IsEmpty() const
{
	return (length == 0 || head == NULL);
}

int ListInt::GetLength() const
{
	return length;
}

//Function returns the data vaule at head of the list, use as helper function to implement top() of stack
int ListInt::ReadHead() const
{
	int data = 0;
	if (head != NULL)
	{
		data = head->data;
	}
	return data;
}

//Insert a new node with value at the head of List
void ListInt::InsertAtHead(int value)
{
	NodeInt* newNode = new NodeInt;
	newNode->data = value;
	newNode->next = head;

	head = newNode;
	length++;
}
//Delete node with value of a from List
int ListInt::DeleteFromHead()
{
	int data = 0;
	if (head != NULL)
	{
		NodeInt* temp = head;
		head = temp->next;
		data = temp->data;
		delete temp;
		length--;
	}
	return data;
}


class StackInt
{
private:
	ListInt list;
public:
	bool isFull() const;
	bool isEmpty() const;
	int top() const;
	void push(int value);
	int pop();
};

bool StackInt::isFull() const
{
	return list.IsFull();
}
bool StackInt::isEmpty() const
{
	return list.IsEmpty();
}
int StackInt::top() const
{
	return list.ReadHead();
}
void StackInt::push(int value)
{
	list.InsertAtHead(value);
}
int StackInt::pop()
{
	return list.DeleteFromHead();
}

enum expressionType { postfix, infix, prefix };

class Expression
{
private:
	string expression;
	expressionType expression_type;

	int evaluatePrefix() const;
	int evaluateInfix() const;
	int evaluatePostfix() const;

	void prefixToInfix();
	void prefixToPostfix();
	void infixToPrefix();
	void infixToPostfix();
	void postfixToPrefix();
	void postfixToInfix();

	bool  isOperand(char ch) const
	{
		// If the scanned character is an operand, add it to output string. 
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			return true;
		else if (ch >= '0' && ch <= '9')
			return true;
		else
			return false;
	}
	int Precedence(char a)
	{
		if (a == '+' || a == '-')
			return 1;
		else if (a == '*' || a == '/')
			return 2;
		else
			return 0;
	}
	int ApplyOPerator(int var1, int var2, char a) const
	{
		switch (a)
		{
		case '+':
			return var1 + var2;
		case '-':
			return var1 - var2;
		case '*':
			return var1 * var2;
		case '/':
			return var1 / var2;
		}
	}
	int ConvertInt(char a)
	{
		if (a == '0')
			return 0;
		else if (a == '1')
			return 1;
		else if (a == '2')
			return 2;
		else if (a == '3')
			return 3;
		else if (a == '4')
			return 4;
		else if (a == '5')
			return 5;
		else if (a == '6')
			return 6;
		else if (a == '7')
			return 7;
		else if (a == '8')
			return 8;
		else if (a == '9')
			return 9;
	}
	// to check the precedence of operators.
	int precedence(char c) const
	{
		if (c == '^')
			return 3;
		else if (c == '*' || c == '/')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else
			return -1;
	}


public:
	Expression()
	{
		/*int i;
		for (i = 0; i < 30-1; i++)
		{
			expression[i] = '0';
		}*/
		this->expression = "00000000000000000000000";
		this->expression_type = infix;
	}
	void convertExpression(expressionType convertTo)
	{
		if (this->expression_type == prefix)
		{
			switch (convertTo)
			{
			case infix:
				//prefixToInfix();
				break;
			case postfix:
				//prefixToPostfix();
				break;
			}
		}
		else if (this->expression_type == infix)
		{
			switch (convertTo)
			{
			case prefix:
				infixToPrefix();
				break;
			case postfix:
				infixToPostfix();
				break;
			}
		}
		else if (this->expression_type == postfix)
		{
			switch (convertTo)
			{
			case prefix:
				//postfixToPrefix();
				break;
			case infix:
				//postfixToInfix();
				break;
			}
		}
	}
	int evaluateExpression()
	{
		switch (this->expression_type)
		{
		case prefix:
			evaluatePrefix();
			break;
		case infix:
			evaluateInfix();
			break;
		case postfix:
			evaluatePostfix();
			break;
		}
	}
	void Display()
	{
		switch (this->expression_type)
		{
		case prefix:
			cout << "Prefix ";
			break;
		case infix:
			cout << "Infix ";
			break;
		case postfix:
			cout << "Postfix ";
			break;
		}
		cout << "Notation: " << this->expression << endl;
	}
	void setExpression(string expression)
	{
		this->expression = expression;
	}
};

int Expression::evaluateInfix() const
{
	int val;
	Stack S1;
	StackInt S2;
	int n = this->expression.length();
	char ch;
	for (int i = 0; i <= n; i++)
	{
		ch = this->expression[i];
		if (ch == ' ')
			continue;
		else if (ch == '(')
			S1.push(ch);
		else if (isOperand(ch))
		{
			val = 0;
			while (i < n && isOperand(this->expression[i]))
			{
				val = (val * 10) + (this->expression[i] - '0');
				i++;
			}
			S2.push(val);
			i--;
		}
		else if (ch == ')')
		{
			while (!S1.isEmpty() && S1.top() != '(')
			{
				int val2 = S2.pop();
				int val1 = S2.pop();
				char op = S1.pop();
				S2.push(ApplyOPerator(val1, val2, op));
			}
			if (!S1.isEmpty())
				S1.pop();
		}
		else
		{
			while (!S1.isEmpty() && precedence(S1.top()) >= precedence(ch))
			{
				int val2 = S2.pop();
				int val1 = S2.pop();
				char op = S1.pop();
				S2.push(ApplyOPerator(val1, val2, op));
			}
			S1.push(this->expression[i]);
		}
	}
	while (!S1.isEmpty())
	{
		int val2 = S2.pop();
		int val1 = S2.pop();
		char op = S1.pop();
		S2.push(ApplyOPerator(val1, val2, op));
	}
	return S2.top();
}

int Expression::evaluatePrefix() const
{
	StackInt S;
	int val1, val2;
	int n = this->expression.length();
	char ch;
	int eval;
	for (int i = n-1; i >= 0; i--)
	{
		ch = this->expression[i];
		if (isOperand(ch))
		{
			ch = ch - '0';
			S.push(ch);
		}
		else
		{
			val1 = S.pop();
			val2 = S.pop();
			switch (ch)
			{
			case '+':
				eval = val1 + val2;
				S.push(eval);
				break;
			case '-':
				eval = val1 - val2;
				S.push(eval);
				break;
			case '*':
				eval = val1 * val2;
				S.push(eval);
				break;
			case '/':
				eval = val1 / val2;
				S.push(eval);
				break;
			}
		}
	}
	return S.pop();
}

int Expression::evaluatePostfix() const
{
	StackInt S;
	int val1, val2;
	int n = this->expression.length();
	char ch;
	int eval;
	for (int i = 0; i <= n; i++)
	{
		ch = this->expression[i];
		if (isOperand(ch))
		{
			ch = ch - '0';
			S.push(ch);
		}
		else
		{
			val1 = S.pop();
			val2 = S.pop();
			switch (ch)
			{
			case '+':
				eval = val1 + val2;
				S.push(eval);
				break;
			case '-':
				eval = val1 - val2;
				S.push(eval);
				break;
			case '*':
				eval = val1 * val2;
				S.push(eval);
				break;
			case '/':
				eval = val1 / val2;
				S.push(eval);
				break;
			}
		}
	}
	return S.pop();
}

void Expression::prefixToPostfix()
{
	StackStr S;
	string infixstr;
	int n = this->expression.length();
	char ch;
	string cha;
	string op1, op2, exp;
	for (int i = n-1; i >=0; i--)
	{
		ch = this->expression[i];
		if (isOperand(ch))
		{
			cha = ch;
			S.push(cha);
		}
		else
		{
			op1 = S.top();
			S.pop();
			op2 = S.top();
			S.pop();
			exp = op1 + op2 + ch ;
			S.push(exp);
		}
	}
	this->expression = S.top();
	this->expression_type = postfix;
}

void Expression::postfixToPrefix()
{
	StackStr S;
	string infixstr;
	int n = this->expression.length();
	char ch;
	string cha;
	string op1, op2, exp;
	for (int i = 0; i <= n; i++)
	{
		ch = this->expression[i];
		if (isOperand(ch))
		{
			cha = ch;
			S.push(cha);
		}
		else
		{
			op1 = S.top();
			S.pop();
			op2 = S.top();
			S.pop();
			exp =  ch + op2 + op1;
			S.push(exp);
		}
	}
	this->expression = S.top();
	this->expression_type = prefix;
}

void Expression::prefixToInfix()
{
	StackStr S;
	string infixstr;
	int n = this->expression.length();
	char ch;
	string cha;
	string op1, op2, exp;
	for (int i = n-1; i >= 0; i--)
	{
		ch = this->expression[i];
		if (isOperand(ch))
		{
			cha = ch;
			S.push(cha);
		}
		else
		{
			op1 = S.top();
			S.pop();
			op2 = S.top();
			S.pop();
			exp = '(' + op1 + ch + op2 + ')';
			S.push(exp);
		}
	}
	this->expression = S.top();
	this->expression_type = infix;
}

void Expression::postfixToInfix()
{
	StackStr S;
	string infixstr;
	int n = this->expression.length();
	char ch;
	string cha;
	string op1, op2, exp;
	for (int i = 0; i <= n; i++)
	{
		ch = this->expression[i];
		if (isOperand(ch))
		{
			cha = ch;
			S.push(cha);
		}
		else
		{
			op1 = S.top();
			S.pop();
			op2 = S.top();
			S.pop();
			exp = '(' + op2 + ch + op1 + ')';
			S.push(exp);
		}
	}
	this->expression = S.top();
	this->expression_type = infix;
}

void Expression::infixToPostfix()
{
	Stack stack;
	string postfixStr;
	//Check weather it is an infix expression or not.
	if (this->expression_type == infix)
	{
		for (int i = 0; i < this->expression.length(); i++)
		{
			// If the scanned character is an operand, add it to output string. 
			char ch = this->expression[i];
			if (isOperand(ch))
			{
				postfixStr += ch;
			}
			// If the scanned character is an ‘(‘, push it to the stack. 
			else if (ch == '(')
			{
				stack.push(ch);
			}

			// If the scanned character is an ‘)’, pop and to output string from the stack 
			// until an ‘(‘ is encountered. 
			else if (ch == ')')
			{
				while (stack.top() != '(' && !stack.isEmpty())
				{
					char op = stack.pop();
					postfixStr += op;
				}
				if (stack.top() == '(')
				{
					stack.pop();
				}
			}
			//If an operator is scanned 
			else {
				while (!stack.isEmpty() && precedence(ch) <= precedence(stack.top()))
				{
					char op = stack.pop();
					postfixStr += op;
				}
				stack.push(ch);
			}
		}
		//Pop all the remaining elements from the stack 
		while (!stack.isEmpty())
		{
			char op = stack.pop();
			postfixStr += op;
		}

		this->expression = postfixStr;
		this->expression_type = postfix;
	}
	else
	{
		cout << "Sorry given expression is not in Infix notation." << endl;
	}
}

void Expression::infixToPrefix()
{
	Stack stack;
	string prefixStr;
	int size;
	size = this->expression.length();
	for (int i = size - 1; i >= 0; i--)
	{
		char ch = this->expression[i];
		if (isOperand(ch))
		{
			prefixStr += ch;
		}
		else if (ch == ')')
		{
			stack.push(ch);
		}
		else if (ch == '(')
		{
			while (stack.top() != ')' && !stack.isEmpty())
			{
				char op = stack.pop();
				prefixStr += op;
			}
			if (stack.top() == ')')
			{
				stack.pop();
			}
		}
		else
		{
			if (stack.isEmpty())
				stack.push(ch);
			else
			{
				if (precedence(ch) > precedence(stack.top()))
				{
					stack.push(ch);
				}
				else if (precedence(ch) == precedence(stack.top()) && ch == '^')
				{
					while (precedence(ch) == precedence(stack.top()) && ch == '^')
					{
						prefixStr += stack.top();
						stack.pop();
					}
					stack.push(ch);
				}
				else if (precedence(ch) == precedence(stack.top()))
				{
					stack.push(ch);
				}
				else
				{
					while ((!stack.isEmpty()) && (precedence(ch) < precedence(stack.top())))
					{
						prefixStr += stack.top();
						stack.pop();
					}
					stack.push(ch);
				}
			}
		}
	}
	this->expression = "";
	while (!stack.isEmpty())
	{
		this->expression += stack.pop();
	}
	for (int i = prefixStr.length() - 1; i >= 0; i--)
	{
		this->expression += prefixStr[i];
	}
	this->expression_type = prefix;
}
int main()
{
	Expression E1;
	string expression = "a+b*(c+d)*e/f";
	E1.setExpression(expression);
	E1.Display();
	E1.convertExpression(prefix);
	E1.Display();
	return 0;
}