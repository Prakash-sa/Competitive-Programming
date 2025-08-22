void modifiedLevelOrder(struct Node* node) 
{   
    if (node == NULL) 
        return; 
    if (node->left == NULL && node->right == NULL) { 
        cout << node->data; 
        return; 
    } 
    queue<Node*> myQueue; 
    stack<Node*> myStack; 
    struct Node* temp = NULL; 
    int sz; 
    int ct = 0; 
    bool rightToLeft = false;  
    myQueue.push(node); 
    while (!myQueue.empty()) { 
        ct++; 
        sz = myQueue.size(); 
        for (int i = 0; i < sz; i++) { 
            temp = myQueue.front(); 
            myQueue.pop(); 
            if (rightToLeft == false)  
                cout << temp->data << " ";             
            else 
                myStack.push(temp);              
            if (temp->left) 
                myQueue.push(temp->left); 
            if (temp->right) 
                myQueue.push(temp->right); 
        } 
        if (rightToLeft == true) { 
            while (!myStack.empty()) { 
                temp = myStack.top(); 
                myStack.pop(); 
                cout << temp->data << " "; 
            } 
        } 
        if (ct == 2) { 
            rightToLeft = !rightToLeft; 
            ct = 0; 
        } 
        cout << "\n"; 
    } 
} 