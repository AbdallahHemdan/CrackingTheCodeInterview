// Using Hash Table 
void RemoveDuplicated(){
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
