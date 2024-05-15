#include <iostream>
#include <queue>
#include <iostream>
#include <queue>
#include<climits>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node* right;
	Node()
	{
		left = NULL;
		right = NULL;
	}

	Node(int n) {
		data = n;
		left = NULL;
		right = NULL;
	}
	// friend ostream& operator<<(ostream& writer, Node * root);
};

// Node* takeInput() {
// 	//take input to construct a Binary Tree --depth wise
// 	int data;
// 	cin >> data;

// 	if (data == -1) {
// 		return NULL;
// 	}

// 	Node * root = new Node(data);
// 	root->left = takeInput();	//take input for left SUBTREE
// 	root->right = takeInput();
// 	return root;
// }

Node * takeInputLevel() {
	//function to take Input as a tree --levelwise
	int data;
	cin >> data;
	if (data == -1) return NULL;

	Node * root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		//there is a node with potential to become parent
		Node *curParent = q.front();
		q.pop();

		int leftData;	cin >> leftData;
		//left child exists, hence create and attach to the parent
		//Also, this child can become Parent in the near future ;)
		if (leftData != -1) {
			Node * tmp = new Node(leftData);
			curParent->left = tmp;
			q.push(tmp);
		}

		//similarly for right child
		int rightData; 	cin >> rightData;
		if (rightData != -1) {
			Node * tmp = new Node(rightData);
			curParent->right = tmp;
			q.push(tmp);
		}
	}
	return root;
}
// void printLevel(Node * root) {
// 	queue<Node * > q;
// 	q.push(root);
// 	q.push(NULL);

// 	while (q.empty() == false) {
// 		//I have atleast one node to print
// 		Node* cur = q.front();
// 		q.pop();

// 		//delimiter case
// 		if (cur == NULL) {
// 			cout << endl;
// 			if (!q.empty()) {
// 				q.push(NULL);
// 			}
// 			continue;
// 		}


// 		cout << cur->data << " ";
// 		if (cur->left) q.push(cur->left);
// 		if (cur->right) q.push(cur->right);
// 	}
// }
void printAltLevel( Node *root)
{
	queue<Node*> q;

	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if ( temp == NULL )
		{
			if (q.empty()) break;

			q.push(NULL);
			cout << "\n";
			continue;
		}

		cout << temp -> data << " ";

		if ( temp -> left ) q.push(temp -> left);

		if ( temp -> right ) q.push(temp -> right);
	}
}

//Function to construct the BST from its given level order traversal.
Node* constructBst1(int arr[], int n)
{
	queue<pair<Node*, pair<int, int>>> q;

	Node * temp = new Node(arr[0]);

	q.push({temp, {INT_MIN, INT_MAX}});
	int index = 1;

	while (index < n) {

		Node * curr = q.front().first;
		pair<int, int> up = q.front().second;
		int upperbound = up.second;
		int lowerbound = up.first;

		q.pop();
		if (curr->data > arr[index] && arr[index] > lowerbound) {
			Node * temp1 = new Node(arr[index]);
			curr->left = temp1;
			q.push({temp1, {lowerbound, curr->data}});
			index++;
		}
		if (index < n && curr->data < arr[index] && arr[index] < upperbound) {
			Node * temp2 = new Node(arr[index]);
			curr->right = temp2;
			q.push({temp2, {curr->data, upperbound}});
			index++;
		}
	}

	return temp;
}


//User function Template for C++
void insert(Node* &root, int val) {
	if (!root) {
		Node* newNode = new Node(val);
		root = newNode;
	}
	else if (root->data < val) {
		insert(root->right, val);
	}
	else {
		insert(root->left, val);
	}
}
Node* constructBst2(int arr[], int n)
{
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, arr[i]);
	}

	return root;
}

int main() {
	Node *root = takeInputLevel();
	printAltLevel(root);
}

