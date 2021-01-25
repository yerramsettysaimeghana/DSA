//Time Complexity : O(n)  Auxiliary Space : O(1)
#include <iostream> 
using namespace std; 
 
struct Node { 
	int data; 
	struct Node* next;
	Node(int d){
	    data = d;
	    next = NULL;
	}
}; 


void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
	cout << endl; 
} 



Node* insert(Node* head, int val) 
{ 
	Node* temp = new Node(val); 
	temp->next = head; 
	head = temp; 
	return head; 
} 

void segregate(Node** head) 
{ 
	// Step 1: Segregate even and odd nodes 
	// Step 2: Split odd and even lists 
	// Step 3: Merge even list into odd list 
	Node* even; 
	Node *temp, *prev_temp; 
	Node *i, *j, *k, *l, *ptr; 

	// Step 1: Segregate Odd and Even Nodes 
	temp = (*head)->next; 
	prev_temp = *head; 

	while (temp != nullptr) { 

		// Backup next pointer of temp 
		Node* x = temp->next; 

		// If temp is odd move the node 
		// to beginning of list 
		if (temp->data % 2 != 0) { 
			prev_temp->next = x; 
			temp->next = (*head); 
			(*head) = temp; 
		} 
		else { 
			prev_temp = temp; 
		} 

		// Advance Temp Pointer 
		temp = x; 
	} 

	// Step 2 
	// Split the List into Odd and even 
	temp = (*head)->next; 
	prev_temp = (*head); 

	while (temp != nullptr && temp->data % 2 != 0) { 
		prev_temp = temp; 
		temp = temp->next; 
	} 

	even = temp; 

	// End the odd List (Make last node null) 
	prev_temp->next = nullptr; 

	// Step 3: 
	// Merge Even List into odd 
	i = *head; 
	j = even; 

	while (j != nullptr && i != nullptr) { 

		// While both lists are not 
		// exhausted Backup next 
		// pointers of i and j 
		k = i->next; 
		l = j->next; 

		i->next = j; 
		j->next = k; 

		// ptr points to the latest node added 
		ptr = j; 

		// Advance i and j pointers 
		i = k; 
		j = l; 
	} 

	if (i == nullptr) { 

		// Odd list exhausts before even, 
		// append remainder of even list to odd. 
		ptr->next = j; 
	} 

	// The case where even list exhausts before 
	// odd list is automatically handled since we 
	// merge the even list into the odd list 
} 


int main() 
{ 
    int n,t;
    
    cout<<"Enter element"<<endl;
    cin>>n;
	  Node* head = new Node(n); 
	

    do{
        cout<<"Enter \n1 -> insert\n2 ->Alternate Odd and Even Nodes \n3 -> printList\n0 -> Exit"<<endl;
        cin>>t;
        switch(t){
            case 1:cout<<"Enter element"<<endl;
                    cin>>n;
                    head = insert(head, n); //at beggining
                    break;
            case 2:	cout << "segregated List" << endl; 
	                segregate(&head);
                    break;
            case 3:cout << "Linked List:" << endl; 
	               printList(head);
            case 0: break;
        }
    }while(t != 0);

} 

