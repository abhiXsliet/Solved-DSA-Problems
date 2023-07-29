#include<bits/stdc++.h>
using namespace std;


void deleteMiddle(stack<int>& s, int index) {    
    if(index == 1) {
        s.pop();
        return ;
    }
    int temp = s.top();
    s.pop();
    deleteMiddle(s, index-1);
    s.push(temp);
    return;
}

int main() {
    initializer_list<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    stack<int> myStack;

    for(auto& i : values) {
        myStack.push(i);
    }

    // for(int i=myStack.size()-1; i>=0; i--) {
    //     cout << myStack.top() << " ";
    //     myStack.pop();
    // } 

    while(!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    int index = myStack.size()/2;
    deleteMiddle(myStack, index);

    
    while(!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;
    return 0;
}