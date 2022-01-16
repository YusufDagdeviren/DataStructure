#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#include<stdbool.h>


struct node {

	int data;
	struct node* left;
	struct node* right;

};

struct node* newNode(int data) {
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->left = NULL;
	yeni->right = NULL;
	yeni->data = data;
	return(yeni);
}
int patalojik(struct node* q) {
	struct node* gecici = q;

	while (gecici != NULL) {
		if ((gecici->left != NULL) && (gecici->right != NULL))
			return 0;

		if ((gecici->left == NULL) || (gecici->right == NULL)) {
			if (gecici->left != NULL) {
				gecici = gecici->left;
			}
			else  if (gecici->right != NULL) {
				gecici = gecici->right;
			}
			else if (gecici == NULL) {
				return 1;
			}
		}
	}
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
	printf("%d\t", q->data);
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
		return 0;
	}
	int ldepth = depth(q->left);
	int rdepth = depth(q->right);
	if (ldepth > rdepth)
		return(ldepth + 1);

	else
		return(rdepth + 1);

}
bool isPerfect(struct node* q) {
	return compute(q, depth(q), 0);
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
		return(dugumSayi(q->left) + dugumSayi(q->right) + 1);
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
	struct node* tree = newNode(5);
	tree->left = newNode(8);
	tree->left->left = newNode(1);
	tree->left->right = newNode(4);
	tree->right = newNode(6);
	tree->right->left = newNode(7);
	tree->right->right = newNode(11);

	
	if (isPerfect(tree)) {
		printf("Agaciniz perfect binary treedir");
	}
	else {
		printf("Agaciniz perfect degildir");
	}
	//printf("%d", depth(tree));
	/*
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
	//printf("%d", findMax(tree));

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
 
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <time.h>
//
//struct node {
//	int data;
//	struct node* left;
//	struct node* right;
//};
//
//struct node* newnode(int data) {
//	struct node* node
//		= (struct node*)malloc(sizeof(struct node));
//
//	node->data = data;
//
//	node->left = null;
//	node->right = null;
//	return (node);
//}
//
////calculate depth
//int depth(struct node* q) {
//	if (q == NULL) {
//		return 0;
//	}
//
//	else {
//		int ldepth = depth(q->left);
//		int rdepth = depth(q->right);
//		if (ldepth > rdepth) {
//			return (ldepth + 1);
//		}
//		else {
//			return (rdepth + 1);
//		}
//	}
//}
//
//void preorder(struct node* q) {
//	if (q == null)return;
//	printf("%d \t", q->data);
//	preorder(q->left);
//	preorder(q->right);
//
//	// 10 20 40 50 25 60 30 90 72 65 77 17  55 82
//}
//
//void inorder(struct node* q) {
//	if (q == null)return;
//	inorder(q->left);
//	printf("%d \t", q->data);
//	inorder(q->right);
//}
//
//void pasorder(struct node* q) {
//	if (q == null) return;
//	pasorder(q->left);
//	pasorder(q->right);
//	printf("%d \t", q->left);
//}
//
//bool compute(struct node* q, int d, int level) {
//	if (q == NULL)
//		return true;
//
//	if (q->left == NULL && q->right == NULL)
//		return (d == level + 1);
//
//	if (q->left == NULL || q->right == NULL)
//		return false;
//
//	return compute(q->left, d, level + 1) && compute(q->right, d, level + 1);
//}
//
//int patalojik(struct node* q) {
//	struct node* gecici = q;
//
//	while (gecici != null) {
//		if ((gecici->left != null) && (gecici->right != null))
//			return 0;
//
//		if ((gecici->left == null) || (gecici->right == null)) {
//			if (gecici->left != null) {
//				gecici = gecici->left;
//			}
//			else  if (gecici->right != null) {
//				gecici = gecici->right;
//			}
//			else if (gecici == null) {
//				return 1;
//			}
//		}
//	}
//}
//
//bool isperfect(struct node* q) {
//	int d = depth(q);
//
//	return compute(q, d, 0);
//}
//
//struct node* ara(struct node* q, int k) {
//	if ((q == null) || (q->data == k))
//		return q;
//
//	if (q->data < k)
//		return ara(q->left, k);
//
//	return ara(q->right, k);
//}
//
///*
//int arama(struct node *q, int k) {
//	if (q == null)
//		return 0;
//
//	if(q -> data == k)
//		return q -> data;
//
//	if(q -> data < k )
//		return ara(q -> left, k);
//
//	else
//		return ara(q -> right, k);
//}
//*/
//
//int icdugum(struct node* q) {
//	if (q == null)
//		return 0;
//
//	if ((q->right == null) && (q->left == null))
//		return 0;
//
//	else
//		return (icdugum(q->left) + icdugum(q->right) + 1);
//}
//
//int dugumsayisi(struct node* q) {
//	if (q == null)
//		return 0;
//
//	else
//		return (icdugum(q->left) + icdugum(q->right) + 1);
//}
//
//int yapraksayi(struct node* q) {
//	if (q == null)
//		return 0;
//
//	if (q->left == null && q->right == null)
//		return 1;
//
//	else return (yapraksayi(q->left) + yapraksayi(q->right));
//}
//
//int dugumsayi(struct node* q) {
//	if (q == null)
//		return 0;
//
//	else return (dugumsayi(q->left) + dugumsayi(q->right)) + 1;
//}
//
//struct node* insert(struct node* q, int item) {
//	if (q == null)
//		return newnode(item);
//
//	if (item < q->data)
//		q->left = insert(q->left, item);
//
//	else if (item > q->data)
//		q->right = insert(q->right, item);
//
//	return q;
//}
//
//int main() {
//	/*
//	struct node* root = newnode(1);
//
//	root->left = newnode(2);
//	root->right = newnode(3);
//	root->right->left = newnode(7);
//	root->left->left = newnode(4);
//	root->left->right = newnode(6);
//	root->right->right = newnode(5);
//
//	printf("ic dugum sayisi = %d \n", icdugum(root));
//	printf("dugum sayisi = %d \n", dugumsayisi(root));
//
//	inorder(root);
//	printf("agacin derinligi = %d", depth(root));
//	*/
//
//	struct node* root = null;
//	struct node* root2 = null;
//	clock_t bas = clock();
//	int c = 0, c2 = 0;
//	while (c < 5000) {
//
//			root = insert(root, 7);
//			root = insert(root, 10);
//			root = insert(root, 11);
//			root = insert(root, 8);
//			root = insert(root, 15);
//
//		/*root2 = newnode(10);
//		root2->left = newnode(7);
//		root2->left->right = newnode(13);
//		root2->right = newnode(9);
//		root2->right->left = newnode(48);*/
//
//		c = c + 1;
//	}
//
//	//inorder(root);	// küçükten büyüðe sýralar
//	//printf("dugum sayisi = %d \n", dugumsayisi(root));
//
//	//printf("yaprak sayisi = %d \n", yapraksayi(root));
//	//printf("dugum sayisi = %d \n", dugumsayi(root));
//
//	clock_t son = clock();
//
//	double gecenzaman = (double)(son - bas) / clocks_per_sec;
//	printf("gecen zaman = %f \n", gecenzaman);
//
//	printf("yaprak sayisi = %d", yapraksayi(root2));
//
//	// if(ara(root, 7) != null)
//
//	//printf("bulundu %d \n", ara(root -> data, 8));
//
//
//	return 0;
//}

