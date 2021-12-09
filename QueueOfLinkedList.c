#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {

	int data;
	struct node* next;
	
	
	};
	struct node* front = NULL;
	struct node* rear = NULL;



	
	void enqueue(int data) {

		struct node *newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = NULL;

		if (front == NULL && rear == NULL) {
			front = rear = newNode;
			return;
		}
		rear->next = newNode;
		rear = newNode;


		}

	int dequeue() {
		struct node* temp = front;
		int data = 0;
		if (front == NULL) {
			return INT_MIN;
		}
		if (front == rear) {
			data = rear->data;
			front = rear = NULL;
		}
		else {
			data = front->data;
			front = front->next;
		}
		
		free(temp);
		return data;
		
	}




int main() {
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);

	printf("Kuyruktan Cikan Eleman %d\n", dequeue());
	printf("Kuyruktan Cikan Eleman %d\n", dequeue());
	printf("Kuyruktan Cikan Eleman %d\n", dequeue());
	printf("Kuyruktan Cikan Eleman %d\n", dequeue());
	enqueue(9);
	enqueue(10);
	enqueue(11);
	enqueue(12);
	printf("Kuyruktan Cikan Eleman %d\n", dequeue());
	printf("Kuyruktan Cikan Eleman %d\n", dequeue());
	printf("Kuyruktan Cikan Eleman %d\n", dequeue());
	printf("Kuyruktan Cikan Eleman %d\n", dequeue());

	return 0;
}