//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
// Function to insert an element into a sorted stack
void sortedInsert(stack<int>& s, int num) {
    // Base case: if the stack is empty or the top element is smaller than the current number
    if (s.empty() || s.top() < num) {
        s.push(num);
        return;
    }

    // Otherwise, pop the top element and recur
    int temp = s.top();
    s.pop();
    sortedInsert(s, num);

    // Push the popped element back
    s.push(temp);
}

// Function to sort the stack
void SortedStack::sort() {
    // Base case: if the stack is empty, return
    if (s.empty()) {
        return;
    }

    // Pop the top element
    int num = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sort();

    // Insert the popped element into the sorted stack
    sortedInsert(s, num);
}
