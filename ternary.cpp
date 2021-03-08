//Andrew Jones
//CS 315 - Project 2
//3/4/21
//Purpose: This project is designed to create a ternary tree from a random string of integers and output the tree to the user.
#include <iostream>

using namespace std;

//this struct is the data structure for each section of our tree
struct node{
	//the two ints are the data for each node
	int a;
	int b;

	//these point to the nodes three (possible) child nodes
	node* less;
	node* eq;
	node* more;
};

//this function creates a blank node and outputs a pointer to the node
node* makenode(){

	node* Newnode = new node;
	Newnode->a = -1;
	Newnode->b = -1;
	Newnode->less = NULL;
	Newnode->eq = NULL;
	Newnode->more = NULL;
	
	return Newnode;
}

//this function inserts a single int into our ternary tree
void insert(node &parent, int data){
	
	//-1 indicates that a or b is empty.
	if (parent.a == -1)
		parent.a = data;

	else if (parent.b == -1){
		parent.b = data;

		//if we insert our data into b, we need to make sure the two ints are in the proper order before we add any child nodes
		if (parent.b < parent.a){
			int temp = parent.a;
			parent.a = parent.b;
			parent.b = temp;
		}
	}
	//if our data is <= a, it will go into the less child
	else if (data <= parent.a){

		//we have to create a new child node if one does not already exi		st.
		if (parent.less == NULL)
			parent.less = makenode();
		
		//this function will recurse until we find a suitable placement 		for our data
		insert(*parent.less, data);
	}

	//the last else if is copied, but for data that is > a and <= b
	else if (data <= parent.b){
		if (parent.eq == NULL)
			parent.eq = makenode();
		insert(*parent.eq, data);
	}

	//all other data will fall into the more category
	else{
		if (parent.more == NULL)
			parent.more = makenode();
		insert(*parent.more, data);
	}
	
}
//this function recursively prints our ternary tree to the user
void print(node root){

	//if a 'less' child node exists, we run the print function with it as an 	argument
	if (root.less != NULL){
		cout << "(";
		print(*root.less);;
		cout << ") ";
	}
	//if this node has a value for a, we print it.
	if (root.a != -1){
		cout << root.a;
		if (root.b != -1)
		cout << " ";
	}
	//if we have a middle node, we run the print function wit hit as an 
	//argument
	if (root.eq != NULL){
		cout << "(";
		print(*root.eq);
		cout << ") ";
	}
	//we print our b value if it exists
	if (root.b != -1){
		cout << root.b;
		if (root.more != NULL)
			cout << " ";
	}
	//if we have a more node, we run the print function with it as an
	//argument
	if (root.more != NULL){
		cout << "(";
		print(*root.more);
		cout << ")";
	}
}

//out main function takes one argument, n
int main(int argc, char* argv[]){
	
	//assigns the command line argument to num_ints
	int num_ints = stoi(argv[1]);
	
	//The following lines create our root node with the first 2 ints from ra	ndGen
	node* root_pointer = makenode();
	node root = *root_pointer;	

	//this loop uses our insert function to insert all data into the tree
	for (int i = 0; i < num_ints; i++){
		int data;
		cin >> data;
		insert(root, data);
	}

	//the print function is invoked to output our data
	print(root);
	return 0;
}


