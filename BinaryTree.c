#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>


struct node {

	int data;
	struct node *left;
	struct node *right;




};

struct node* newNode(int data) {
	struct node *yeni = (struct node*)malloc(sizeof(struct node));
	yeni->left = yeni->right = NULL;
	yeni->data = data;
	return(yeni);
}

void inorder(struct node* t) {
	if (t == NULL)
		return;
	inorder(t->left);
	printf("%d\t", t->data);

	inorder(t->right);


}
void preorder(struct node* q) {
	if (q == NULL) {
		return;
	}
	printf("%d\t", q->data);
	preorder(q->left);
	preorder(q->right);
}
void postorder(struct node* q) {
	if (q == NULL) {
		return;
	}
	postorder(q->left);
	preorder(q->right);
	printf("%d\t",q->data);
}
bool compute(struct node* q, int d, int level) {

	if (q == NULL) {
		return true;
	}
	if (q->left == NULL && q->right == NULL) {
		return(d == level + 1);
	}
	if (q->left == NULL || q->right == NULL) {
		return false;
	}
	return compute(q->left, d, level + 1) && compute(q->right, d, level + 1);


}
int depth(struct node*q) {
	if (q == NULL) {
		return -1;
	}
	else {
		int ldepth = depth(q->left);
		int rdepth = depth(q->right);
		if (ldepth > rdepth)
			return(ldepth + 1);
		else
			return(rdepth + 1);
	}
}
bool isPerfect(struct node* q) {
	int d = depth(q);
	return compute(q, d, 0);
}
int findMax(struct node* q) {
	if (q == NULL)
		return INT_MIN;
	
	int max = q->data;
	int lmax = findMax(q->left);
	int rmax = findMax(q->right);

	if (lmax > max) {
		max = lmax;
	}
	if (rmax > max) {
		max = rmax;
	}
	return max;
}

int dugumSayi(struct node* q) {

	if (q == NULL) {
		return 0;
	}
	else {
		return(q->left + q->right + 1);
	}
	


}








int main() {

	struct node *tree = NULL;
	tree = newNode(1);
	tree->left = newNode(2);
	tree->right = newNode(3);
	tree->right->right = newNode(4);
	tree->left->right = newNode(5);
	tree->left->left = newNode(6);
	tree->right->left = newNode(9);
	tree->right->right->right = newNode(10);

	/*preorder(tree);
	printf("\n");
	postorder(tree);
	printf("\n");
	inorder(tree);
	printf("\n");
	printf("%d", depth(tree));
	printf("\n");*/
	int max = findMax(tree);
	printf("%d\n", max);
	int data = dugumSayi(tree);
	printf("%d", data);
	////inorder(tree);
	//printf("%d\n", tree->left->data);
	//printf("%d\n", tree->data);
	//printf("%d\n", tree->right->data);
	//printf("%d\n", tree->left->right->data);
	
	

	return 0;
}
 