#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
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
	postorder(q->right);
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

int dugumSayi(struct node* q) { //yap

	if (q == NULL) {
		return 0;
	}
	else {
		return(dugumSayi(q->left) +dugumSayi(q->right) + 1);
	}
	
}
int icDugum(struct node* q) { //yap  

	if (q == NULL) 
		return 0;
	
	if ((q->left == NULL) && (q->right == NULL))
		return 0;

	else
		return icDugum(q->left) + icDugum(q->right) + 1;
}

int yaprakSayisi(struct node* q) { // yap

	if (q == NULL)
		return 0;
	
	if ((q->left == NULL) && (q->right == NULL)) 
	return 1;
	

	else
		return yaprakSayisi(q->left) + yaprakSayisi(q->right);

}

int yaprakSayisiTopla2(struct node* q) {

	if (q == NULL) {
		return 0;
	}
	else if (q->left == NULL && q->right == NULL) {
		return q->data;
	}
		

	else
		return yaprakSayisiTopla2(q->left) + yaprakSayisiTopla2(q->right);



}
int ortbul(struct node* q) {
	return yaprakSayisiTopla2(q) / yaprakSayisi(q);
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
struct node* binaryInsert(struct node* q, int item) {//yap

	if (q == NULL)
		return newNode(q);

	if (item < q->data)
		q->left = binaryInsert(q->left, item);
	else
		q->right = binaryInsert(q->right, item);

	return q;


}
struct node* ara(struct node* q, int k) {//yap
	if ((q == NULL) || q->data == k) {
		return q;
	}
	if (k < q->data)
		return ara(q->left, k);

	return ara(q->right, k);

}
bool arama(struct node* q, int k) {
	if ((q == NULL) || q->data == k) {
		return true;
	}
	else if (q->left == NULL && q->right == NULL) {
		return false;
	}
	if (k < q->data)
		return arama(q->left, k);

	return arama(q->right, k);



}
struct node* insert(struct node* q, int item) {
	if (q == NULL)
		return newNode(item);

	if (item < q->data)
		q->left = insert(q->left, item);

	else if (item > q->data)
		q->right = insert(q->right, item);

	return q;
}

int main() {

	struct node* tree=newNode(5);
	tree->left = newNode(8);
	tree->left->left = newNode(40);
	tree->right = newNode(11);
	tree->right->left = newNode(80);
	tree->right->right = newNode(60);
	/*tree = insert(tree,8);
	tree = insert(tree,3);
	tree = insert(tree,10);
	tree = insert(tree,1);
	tree = insert(tree,14);
	tree = insert(tree,13);
	tree = insert(tree,6);
	tree = insert(tree,4);
	tree = insert(tree,7);*/
	//postorder(tree);
	//printf("%d", yaprakSayisi(tree));
	printf("%d", findMax(tree));
	/*tree = newNode(5);
	tree->left = newNode(8);
	tree->right = newNode(4);
	tree->left->left = newNode(2);
	tree->left->right = newNode(6);
	tree->left->right->left = newNode(3);
	tree->left->right->right = newNode(2);
	tree->left->right->left->left = newNode(1);
	printf("%d", dugumSayi(tree));*/

	
	
	

	return 0;
}
//// 
////#include <stdio.h>
////#include <stdlib.h>
////#include <stdbool.h>
////#include <time.h>
////
////struct node {
////	int data;
////	struct node* left;
////	struct node* right;
////};
////
////struct node* newNode(int data) {
////	struct node* node
////		= (struct node*)malloc(sizeof(struct node));
////
////	node->data = data;
////
////	node->left = NULL;
////	node->right = NULL;
////	return (node);
////}
////
//////calculate depth
////int depth(struct node* q) {
////	if (q == NULL) {
////		return 0;
////	}
////
////	else {
////		int ldepth = depth(q->left);
////		int rdepth = depth(q->right);
////		if (ldepth > rdepth) {
////			return (ldepth + 1);
////		}
////		else {
////			return (rdepth + 1);
////		}
////	}
////}
////
////void preOrder(struct node* q) {
////	if (q == NULL)return;
////	printf("%d \t", q->data);
////	preOrder(q->left);
////	preOrder(q->right);
////
////	// 10 20 40 50 25 60 30 90 72 65 77 17  55 82
////}
////
////void inOrder(struct node* q) {
////	if (q == NULL)return;
////	inOrder(q->left);
////	printf("%d \t", q->data);
////	inOrder(q->right);
////}
////
////void pasOrder(struct node* q) {
////	if (q == NULL) return;
////	pasOrder(q->left);
////	pasOrder(q->right);
////	printf("%d \t", q->left);
////}
////
////bool compute(struct node* q, int d, int level) {
////	if (q == NULL)
////		return true;
////
////	if (q->left == NULL && q->right == NULL)
////		return (d == level + 1);
////
////	if (q->left == NULL || q->right == NULL)
////		return false;
////
////	return compute(q->left, d, level + 1) && compute(q->right, d, level + 1);
////}
////
////int patalojik(struct node* q) {
////	struct node* gecici = q;
////
////	while (gecici != NULL) {
////		if ((gecici->left != NULL) && (gecici->right != NULL))
////			return 0;
////
////		if ((gecici->left == NULL) || (gecici->right == NULL)) {
////			if (gecici->left != NULL) {
////				gecici = gecici->left;
////			}
////			else  if (gecici->right != NULL) {
////				gecici = gecici->right;
////			}
////			else if (gecici == NULL) {
////				return 1;
////			}
////		}
////	}
////}
////
////bool isPerfect(struct node* q) {
////	int d = depth(q);
////
////	return compute(q, d, 0);
////}
////
////struct node* ara(struct node* q, int k) {
////	if ((q == NULL) || (q->data == k))
////		return q;
////
////	if (q->data < k)
////		return ara(q->left, k);
////
////	return ara(q->right, k);
////}
////
/////*
////int arama(struct node *q, int k) {
////	if (q == NULL)
////		return 0;
////
////	if(q -> data == k)
////		return q -> data;
////
////	if(q -> data < k )
////		return ara(q -> left, k);
////
////	else
////		return ara(q -> right, k);
////}
////*/
////
////int icDugum(struct node* q) {
////	if (q == NULL)
////		return 0;
////
////	if ((q->right == NULL) && (q->left == NULL))
////		return 0;
////
////	else
////		return (icDugum(q->left) + icDugum(q->right) + 1);
////}
////
////int dugumSayisi(struct node* q) {
////	if (q == NULL)
////		return 0;
////
////	else
////		return (icDugum(q->left) + icDugum(q->right) + 1);
////}
////
////int yaprakSayi(struct node* q) {
////	if (q == NULL)
////		return 0;
////
////	if (q->left == NULL && q->right == NULL)
////		return 1;
////
////	else return (yaprakSayi(q->left) + yaprakSayi(q->right));
////}
////
////int dugumSayi(struct node* q) {
////	if (q == NULL)
////		return 0;
////
////	else return (dugumSayi(q->left) + dugumSayi(q->right)) + 1;
////}
////
////struct node* insert(struct node* q, int item) {
////	if (q == NULL)
////		return newNode(item);
////
////	if (item < q->data)
////		q->left = insert(q->left, item);
////
////	else if (item > q->data)
////		q->right = insert(q->right, item);
////
////	return q;
////}
////
////int main() {
////	/*
////	struct node* root = newNode(1);
////
////	root->left = newNode(2);
////	root->right = newNode(3);
////	root->right->left = newNode(7);
////	root->left->left = newNode(4);
////	root->left->right = newNode(6);
////	root->right->right = newNode(5);
////
////	printf("ic dugum sayisi = %d \n", icDugum(root));
////	printf("dugum sayisi = %d \n", dugumSayisi(root));
////
////	inOrder(root);
////	printf("agacin derinligi = %d", depth(root));
////	*/
////
////	struct node* root = NULL;
////	struct node* root2 = NULL;
////	clock_t bas = clock();
////	int c = 0, c2 = 0;
////	while (c < 5000) {
////
////			root = insert(root, 7);
////			root = insert(root, 10);
////			root = insert(root, 11);
////			root = insert(root, 8);
////			root = insert(root, 15);
////
////		/*root2 = newNode(10);
////		root2->left = newNode(7);
////		root2->left->right = newNode(13);
////		root2->right = newNode(9);
////		root2->right->left = newNode(48);*/
////
////		c = c + 1;
////	}
////
////	//inOrder(root);	// küçükten büyüðe sýralar
////	//printf("dugum sayisi = %d \n", dugumSayisi(root));
////
////	//printf("yaprak sayisi = %d \n", yaprakSayi(root));
////	//printf("dugum sayisi = %d \n", dugumSayi(root));
////
////	clock_t son = clock();
////
////	double gecenZaman = (double)(son - bas) / CLOCKS_PER_SEC;
////	printf("gecen zaman = %f \n", gecenZaman);
////
////	printf("yaprak sayisi = %d", yaprakSayi(root2));
////
////	// if(ara(root, 7) != NULL)
////
////	//printf("bulundu %d \n", ara(root -> data, 8));
////
////
////	return 0;
////}#include<stdio.h>
