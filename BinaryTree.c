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
	yeni->left = NULL;
	yeni->right = NULL;
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

int depth(struct node* q) {
	if (q == NULL) {
		return -1;
	}
	int ldepth = depth(q->left);
	int rdepth = depth(q->right);
	if (ldepth > rdepth)
		return(ldepth + 1);

	else
		return(rdepth + 1);

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
		return(dugumSayi(q->left) +dugumSayi(q->right) + 1);
	}
	
}
int icDugum(struct node* q) {

	if (q == NULL) 
		return 0;
	
	if ((q->left == NULL) && (q->right == NULL))
		return 0;

	else
		return icDugum(q->left) + icDugum(q->right) + 1;
}

int yaprakSayisi(struct node* q) {

	if (q == NULL)
		return 0;
	
	if ((q->left == NULL) && (q->right == NULL)) 
	return 1;
	

	else
		return yaprakSayisi(q->left) + yaprakSayisi(q->right);

}
//çarpmada etkisiz elemanýn 1 olduðunu kanýtlayan soruyu yap
//iç düðümün çarpýmý nedir ?

void postorderDelete(struct node* q) {
	if (q == NULL)
		return;
	postorderDelete(q->left);
	
	postorderDelete(q->right);

	free(q);

}
struct node* binaryInsert(struct node* q, int item) {

	if (q == NULL)
		return newNode(q);

	if (item < q->data)
		q->left = binaryInsert(q->left, item);
	else
		q->right = binaryInsert(q->right, item);

	return q;


}
struct node* ara(struct node* q, int k) {
	if ((q == NULL) || q->data == k) {
		return q;
	}
	if (k < q->data)
		return ara(q->left, k);

	return ara(q->right, k);

}


int main() {

	struct node* tree;
	tree = newNode(1);
	tree->left = newNode(2);
	tree->left->right = newNode(5);
	tree->right = newNode(3);
	tree->left->left = newNode(4);
	
	//printf("Derinlik = %d", depth(tree));
	printf("Dugum sayisi %d\n", dugumSayi(tree));
	printf("Ic dugum sayisi %d\n", icDugum(tree));
	printf("yaprak sayisi %d\n", yaprakSayisi(tree));
	//printf("En buyuk deger = %d", findMax(tree));
	/*printf("ic dugum sayisi = %d\n", icDugum(tree));
	printf("dugum sayisi = %d\n", dugumSayi(tree));*/

	/*preorder(tree);
	printf("\n");
	postorder(tree);
	printf("\n");
	inorder(tree);
	printf("\n");
	printf("%d", depth(tree));
	printf("\n");*/
	/*int max = findMax(tree);
	printf("%d\n", max);
	int dugum = dugumSayi(tree);
	printf("%d\n", dugum);
	int icData = icDugum(tree);
	printf("%d\n", icData);*/
	//postorderDelete(tree);
	////inorder(tree);
	//printf("%d\n", tree->left->data);
	//printf("%d\n", tree->data);
	//printf("%d\n", tree->right->data);
	//printf("%d\n", tree->left->right->data);
	
	

	return 0;
}
 