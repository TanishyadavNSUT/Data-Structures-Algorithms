#include <bits/stdc++.h> 
void insert(stack<int> &stack, int n){
	if(stack.empty() || stack.top() < n){
		stack.push(n);
		return;
	}

	int num=stack.top();
	stack.pop();
	insert(stack,n);
	stack.push(num);

}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	int num=stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack,num);
}