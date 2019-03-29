// Using Hash Table
// Time Complexity O(n)
// Space Complexity O(n)
void RemoveDuplicates(){
    unordered_set<int> Seen ; 
    Node* Current = Head ; 
    Node* Previous = nullptr ;
    
    while(Current != nullptr){
        if(Seen.find(Current->GetData()) != Seen.end()){
            Previous->SetNext(Current->GetNext()) ; 
            delete Current ; 
        }
        else{
            Seen.insert(Current->GetData()) ; 
            Previous = Current ; 
        }
        Current = Previous->GetNext() ;
    }
}

// Using 2 Loops
// Time Complexity O(n^2)
// Space Complexity O(1)
void RemoveDuplicates()
{
	Node* Current = Head;
	Node* Previous = Head;
	Node* CheckNext = Head->getNext();

	while (Current->getNext() != nullptr) 
	{
		while (CheckNext != nullptr)
		{
			if (CheckNext->getItem() == Current->getItem())
			{
				Previous->setNext(CheckNext->getNext());
				delete CheckNext;
				CheckNext = Previous->getNext();
				count--;
			}
			else
			{
				CheckNext = CheckNext->getNext();
			}
			Previous = Previous->getNext();
		}
		Current = Current->getNext();
		Previous = Current;
		CheckNext = Current->getNext();
	}
}
