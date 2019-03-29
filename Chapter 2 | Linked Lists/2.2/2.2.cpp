// Time Complexity : O(n)
// Space Complexity : O(1)
// Using the Length of the List to Find Kth Element
int FindKthFromLast(int k){
	Node* Find = Head ; 
	for(int i=0 ;i<GetLength()-k ; i++){
		Find = Find->GetNext() ;
	}
	return Find->GetData() ; 
}

// Time Complexity : O(2n) ==> O(n)
// Space Complexity : O(1)
// Find the length then use it to find the Kth Element
int FindKthFromLast(int k){
	Node* Find = Head ; 
	int Length = 0 ;

	while(Find != nullptr){
		Find = Find->GetNext() ;
		Length++ ;
	}

	Find = Head ; 
	for(int i=0 ; i < Length-k ; i++){
		Find = Find->GetNext() ;
	}
	return Find->GetData() ; 
}

// Time Complexity : O(n)
// Space Complexity : O(n) due to the recursion
// Using recursion to find the Kth Element then Print it 
void FindKthFromLast(Node* Head, int k)  { 
	// Use static counter
	static int i = 0;  
    if (Head == NULL) 
       return; 
    
    printNthFromLast(Head->next, k); 
    if (++i == k) {
       cout << Head->data << endl; 
    }
} 

// Time Complexity : O(n)
// Space Complexity : O(n) due to the recursion
// Using recursion to find the Kth Element then Print it and return K
int FindKthFromLast(Node* Head, int k)  { 
    if (Head == NULL) {
       return 0 ; 
    }
    
    int Index = printNthFromLast(Head->GetNext(), k) + 1 ;
    if (Index == k) {
       cout << Head->GetData() << endl; 
    }
    return Index ;
} 

// Iterative
// Time Complexity : O(n)
// Space Complexity : O(1)
// Find the Kth Element from the end using two Pointers
Node* FindKthFromLast(Node *Head, int k){
    Node* First = Head ; 
    Node* Second = Head ;

    for(int i=0 ;i<k ; i++){
    	if(First = nullptr){
    		return nullptr ;
    	}
    	First = First->GetNext();
    }
    while(First != nullptr){
    	First = First->GetNext() ;
    	Second = Second->GetNext() ;
    }
    return Second ; 
}
