#include <iostream>

using namespace std ;

/***** Pre-Data of the Hash table ***/

/**** when we talk about hashing , it means key value pairs ****/
int const MAX = 10001 ;

class Node 
{
	public :
	int key ;
	int val ;
	Node *next ;
} ;


class HashTable
{
	public :
		Node * listH ;
		int numberNode ;
	    HashTable() ;
};


class HashMap
{
	private:
		HashTable table[MAX] ; // object 
		int totalNode        ; 
		
	public :
	HashMap() ;
	
	int  hashFunction(int key) ;
	bool insert(int key , int val) ;
	bool insert(Node node) ;
	bool insert(Node *   ) ;
	bool search(int key  ) ;
	bool search(Node node) ;
	bool search(Node *   ) ;
	bool searchWithHash(int hash , int key) ;
	bool remove(int key)   ;
	bool remove(Node ) ;
	bool remove(Node *) ;
	Node* getAllPair() ;
	int   getValue(int key) ;
	int * getAllKeys() ;
	int * getAllValues() ;
	int getSize() ;
} ;


/**** Call MAX times , so that each list will empty and number of node is 0 ****/
HashTable::HashTable()
{
		listH = NULL   ;
		numberNode = 0 ;
}	

HashMap::HashMap() 
{
		totalNode = 0 ;
}
	

/*** hashFunction : implementation "Any quardetice function " ***/
int HashMap::hashFunction(int key)
{
	return (key * key + key + 1) % MAX ;
}

/*** intsert in HashMap ****/
/*** Inserting of the data will be saame as the Inserting of the data for list at beg  ****/
bool HashMap::insert(int key , int val)
{
	int hash = hashFunction(key)  ;
	
	/**** If key already already exsists in the table , key will not insert ****/
	if(searchWithHash(hash , key))
	{
		return false ;   /*** Key already exsists ****/
	}
	
	Node *newNode = new Node() ;
	newNode->key = key ;
	newNode->val = val ;
	
	newNode->next = table[hash].listH ;
	table[hash].listH = newNode ;
	totalNode++ ;
	return true ;	
}


bool HashMap::insert(Node node)
{
	int hash = hashFunction(node.key)  ;
	if(searchWithHash(hash , node.key))
	{
		return false ;   /*** Key already exsists ****/
	}
	
	Node *newNode = new Node() ;
	newNode->key = node.key ;
	newNode->val = node.val ;
	
	newNode->next = table[hash].listH ;
	table[hash].listH = newNode ;
	totalNode++ ;
	return true ;	
}

bool HashMap::insert(Node *ptr)
{
	if(ptr == NULL) return false ;
	
	int hash = hashFunction(ptr->key)  ;
	if(searchWithHash(hash , ptr->key))
	{
		return false ;   /*** Key already exsists ****/
	}
	
	
	ptr->next = table[hash].listH ;
	table[hash].listH = ptr ;
	totalNode++ ;
	return true ;	
}

/**** Searching weather key already exsit in the table ****/
bool HashMap::searchWithHash(int hash , int key)
{
	Node *itr = table[hash].listH ;
	
	/**** key does not exsists ****/
	if(itr == NULL)
		return false ;
		
	while(itr && itr->key != key)	
	{
		itr = itr->next ;
	}
	
	return itr == NULL ? false : true ;
}

/*** Searcning the value using key only ****/
bool HashMap::search(int key)
{
	int hash = hashFunction(key)  ;
	searchWithHash(hash ,key) ? true : false ;
}

/*** searching based on the Node ***/
bool HashMap::search(Node node)
{
	int hash = hashFunction(node.key)  ;
	
	Node *itr = table[hash].listH ;
	
	/**** key does not exsists ****/
	if(itr == NULL)
		return false ;
		
	while(itr && itr->key != node.key)	
	{
		itr = itr->next ;
	}
	
	if(itr)
	{
		if(itr->val == node.val)
			return true ;
	}
	
	return false ;
}

/**** search based on the Node * ****/
bool HashMap::search(Node *ptr)
{
	if(ptr == NULL ) return false ;
	
	int hash = hashFunction(ptr->key)  ;
	
	Node *itr = table[hash].listH ;
	
	/**** key does not exsists ****/
	if(itr == NULL)
		return false ;
		
	while(itr && itr->key != ptr->key)	
	{
		itr = itr->next ;
	}
	
	if(itr)
	{
		if(itr->val == ptr->val)
			return true ;
	}
	
	return false ;
}

/**** removing the node based on the key ****/
bool HashMap::remove(int key)   
{
	/*** key is not in the hash table ***/
	if(!search(key))
	{
		return false ;
	}
	
	int hash = hashFunction(key) ;
	
	Node *itr = table[hash].listH ;	
	Node *prev = NULL ;		
	while(itr && itr->key != key)	
	{
		prev = itr ;
		itr = itr->next ;
	}
	
	if(prev == NULL)
	{
		table[hash].listH = itr->next ;
		delete itr ;
		return true ;
	}
	
	prev->next = itr->next ;
	delete itr  ;
	return true ;	
}


/**** removing the node based on the node ***/
bool HashMap::remove(Node node ) 
{
	/*** key is not in the hash table ***/
	if(!search(node.key))
	{
		return false ;
	}
	
	int hash = hashFunction(node.key) ;
	
	Node *itr = table[hash].listH ;	
	Node *prev = NULL		;
	while(itr && itr->key != node.key)	
	{
		prev = itr ;
		itr = itr->next ;
	}
	
	if(prev == NULL)
	{
		table[hash].listH = itr->next ;
		delete itr ;
		return true ;
	}
	
	prev->next = itr->next ;
	delete itr  ;
	return true ;
	
}

/**** Removing the node ****/
bool HashMap::remove(Node * ptr) 
{
	/*** key is not in the hash table ***/
	if(!search(ptr->key))
	{
		return false ;
	}
	
	int hash = hashFunction(ptr->key) ;
	
	Node *itr = table[hash].listH ;	
	Node *prev = NULL ;		
	while(itr && itr->key != ptr->key)	
	{
		prev = itr ;
		itr = itr->next ;
	}
	
	if(prev == NULL)
	{
		table[hash].listH = itr->next ;
		delete itr ;
		return true ;
	}
	
	prev->next = itr->next ;
	delete itr  ;
	return true ;
	
}

/**** geting all pairs of hash ****/
Node* HashMap::getAllPair() 
{
	return NULL ;
}

/**** get value of the key *****/
int   HashMap::getValue(int key) 
{
	return 0 ;
}

/*** get all the keys ****/
int * HashMap::getAllKeys() 
{
	return NULL ;
}

/**** get all the values ****/
int * HashMap::getAllValues() 
{
	return NULL ;
}

int HashMap::getSize()
{
	return  totalNode ;
}


int main(){
	return 0 ;
}
