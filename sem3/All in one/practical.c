// Write a program to find minimum and maximum element from the array?

// #include <stdio.h>

// int main() {
//   int arr[] = {3, 8, 2, 5, 1, 4, 7, 6};
//   int size = sizeof(arr) / sizeof(arr[0]);
//   int min = arr[0];
//   int max = arr[0];
  
//   for (int i = 1; i < size; i++) {
//     if (arr[i] < min) {
//       min = arr[i];
//     }
//     if (arr[i] > max) {
//       max = arr[i];
//     }
//   }

//   printf("Minimum element is %d\n", min);
//   printf("Maximum element is %d\n", max);
  
//   return 0;
// }

// Write a program to search an element using Binary search?


// #include <stdio.h>

// int binarySearch(int arr[], int l, int r, int x) {
//   if (r >= l) {
//     int mid = (l + r) / 2;
    
//     if (arr[mid] == x) {
//       return mid;
//     }
    
//     if (arr[mid] > x) {
//       return binarySearch(arr, l, mid - 1, x);
//     }
    
//     return binarySearch(arr, mid + 1, r, x);
//   }
  
//   return -1;
// }

// int main() {
//   int arr[] = {2, 4, 6, 8, 10, 12, 14};
//   int n = sizeof(arr) / sizeof(arr[0]);
//   int x = 12;
  
//   int result = binarySearch(arr, 0, n - 1, x);
  
//   if (result == -1) {
//     printf("Element not found\n");
//   } else {
//     printf("Element found at index %d\n", result);
//   }
  
//   return 0;
// }


// Write a program to search an element using Linear search.

// #include <stdio.h>

// int linearSearch(int arr[], int n, int x) {
//   for (int i = 0; i < n; i++) {
//     if (arr[i] == x) {
//       return i;
//     }
//   }
//   return -1;
// }

// int main() {
//   int arr[] = {2, 4, 6, 8, 10, 12, 14};
//   int n = sizeof(arr) / sizeof(arr[0]);
//   int x = 8;
  
//   int result = linearSearch(arr, n, x);
  
//   if (result == -1) {
//     printf("Element not found\n");
//   } else {
//     printf("Element found at index %d\n", result);
//   }
  
//   return 0;
// }

// Write a program to accept n numbers in array and display the addition of all evennumbersandmultiplication of all odd numbers

// #include <stdio.h>

// int main() {
//   int arr[100];
//   int n, sum = 0, product = 1;
  
//   printf("Enter the number of elements in the array: ");
//   scanf("%d", &n);
  
//   printf("Enter the elements of the array:\n");
//   for (int i = 0; i < n; i++) {
//     scanf("%d", &arr[i]);
//   }
  
//   for (int i = 0; i < n; i++) {
//     if (arr[i] % 2 == 0) {
//       sum += arr[i];
//     } else {
//       product *= arr[i];
//     }
//   }
  
//   printf("Sum of all even numbers: %d\n", sum);
//   printf("Product of all odd numbers: %d\n", product);
  
//   return 0;
// }

// Write a program to find out whether a matrix is symmetric or not. A matrix is symmetric if transposeofthematrix is equal to the matrix

// #include <stdio.h>

// int main(){
//     int arr[10][10];
//     int transpose[10][10];
//     int row,col,i,j,flag = 0;

//     printf("Enter the no. of row: ");
//     scanf("%d",&row);
//     printf("Enter the no. of col: ");
//     scanf("%d",&col);

//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             printf("Enter the element: ");
//             scanf("%d",&arr[i][j]);
//         }
//     }

//     for(i = 0;i<row;i++){
//         for(j=0;j<col;j++){
//             transpose[j][i] = arr[i][j];
//         }
//     }

//     for(i=0;i<row;i++){
//         for(j=0;j<col;j++){
//             if(arr[i][j] != transpose[i][j]){
//                 flag = 1;
//                 break;
//             }
            
//         }
//     }

//     if(flag == 1){
//         printf("Matrix is not symmetric");
//     }else{
//         printf("Matrix is symmetric");
//     }
// }

// Write a program to accept n numbers in an array and display the sum of the highest and lowest numbers

// #include <stdio.h>

// int main() {
//   int arr[100];
//   int n, i;
//   int highest, lowest;
  
//   printf("Enter the number of elements in the array: ");
//   scanf("%d", &n);
  
//   printf("Enter the elements of the array:\n");
//   for (i = 0; i < n; i++) {
//     scanf("%d", &arr[i]);
//   }
  
//   // Finding the highest and lowest numbers in the array
//   highest = lowest = arr[0];
//   for (i = 1; i < n; i++) {
//     if (arr[i] > highest) {
//       highest = arr[i];
//     }
//     if (arr[i] < lowest) {
//       lowest = arr[i];
//     }
//   }
  
//   printf("Sum of highest and lowest numbers = %d\n", highest + lowest);
  
//   return 0;
// }

// Write a program to find sum of elements of array using pointers. 

// #include <stdio.h>

// int main(){
//     int arr[100];
//     int n,i,sum = 0;
//     int *p;

//     printf("Enter the number of elements in the array: ");
//     scanf("%d",&n);

//     for(i = 0;i<n;i++){
//         printf("Enter the element: ");
//         scanf("%d",&arr[i]);
//     }

//     p = &arr[0];

//     for(i=0;i<n;i++){
//         sum = sum +*(p + i);
//     }

//     printf("Sum is %d",sum);
// }

// Write a program to create a singly linked list and display the content of list.

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct nd{
//     int data;
//     struct nd *next;
// }node;

// node *create (){
//     node *head,*temp;
//     int i,n;
//     printf("Enter the total no. elements: ");
//     scanf("%d",&n);

//     for( i =0;i<n;i++){
//         if(i == 0){
//             head = (node*)malloc(sizeof(node));
//             temp = head;
//         }
//         else{
//             temp->next = (node*)malloc(sizeof(node));
//             temp = temp->next;
//         }
//         printf("Enter the element: ");
//         scanf("%d",&temp->data);
//     }
//     temp->next = NULL;
//     return head;
// }
// int main(){
//     node *head;
//     head = create();
//     while(head != NULL){
//         printf("%d ",head->data);
//         head = head->next;
//     }
// }

// Write a program to create a doubly linked list and display the content of list.
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct nd{
//     int data;
//     struct nd *next;
//     struct nd *prev;
// }node;

// node *create (){
//     node *head,*temp,*current;
//     int i,n;
//     printf("Enter the total no. elements: ");
//     scanf("%d",&n);

//     for( i =0;i<n;i++){
//         if(i == 0){
//             head = (node*)malloc(sizeof(node));
//             temp = head;
//             head->prev = NULL;
//             current = temp;
//         }
//         else{
//             temp->next = (node*)malloc(sizeof(node));
//             temp->prev = current;
//             current = current->next;
//             temp = temp->next;
//         }
//         printf("Enter the element: ");
//         scanf("%d",&temp->data);
//     }
//     temp->next = NULL;
//     return head;
// }
// int main(){

//     node *head;
//     head = create();
//     while(head != NULL){
//         printf("\n%d %d\n",head->prev,head->next);
//         printf("%d ",head->data);
//         head = head->next;
//     }
// }

// Write a program for stack having functions push(), pop(), peek(), display(). (Array Implementation)

// #include <stdio.h>
// #define max 100
// int arr[max];
// int top = -1;

// int push(int x){
//     if(top>=max-1){
//         printf("stack overflow");
//     }
//     else{
//         top++;
//         arr[top] = x;
//     }
// }

// int pop(){
//     if(top<=-1){
//         printf("stack underflow");
//     }
//     else{
//         top--;
//     }
// }

// int peek(){
//     if(top<=-1){
//         printf("stack underflow");
//     }
//     else{
//         return arr[top];
//     }
// }

// int display(){
//     if(top<=-1){
//         printf("stack underflow");
//     }
//     else{
//         for(int i = 0;i<=top;i++){
//             printf("%d ",arr[i]);
//         }
//     }
// }
// int main(){
//     int choice;
//     int done = 0;
//     while(done == 0)
//     {    
//         printf("1.push\n2.pop.\n3.peek.\n4.display\n");
//         printf("Enter the choice: ");
//         scanf("%d",&choice);
//         if(choice == 1)
//         {
//             int x;
//             printf("Enter the element: ");
//             scanf("%d",&x);
//             push(x);
//         }
//         else if(choice == 2){
//             pop();
//         }
//         else if(choice == 3){
//             printf("%d",peek());
//         }
//         else if(choice == 4){
//             display();
//         }
//         else{
//             done = 1;
//         }
//     }
// }

// Write a program for queue having functions insert(), delete(), display(). (Array Implementation)

// #include <stdio.h>
// #define max 100
// int arr[max];
// int front = -1;
// int rear = -1;

// int insert(int x){
//     if(rear>=max-1 ){
//         printf("queue overflow");
//     }
//     else{
//         if(front == -1){
//             front = 0;
//         }
//         rear++;
//         arr[rear] = x;
//     }
// }

// int delete(){
//     if(front>=rear || front == -1){
//         printf("queue underflow");
//     }
//     else{
//         front++;
//     }
// }

// int main(){
//     int choice;
//     int done = 0;
//     while(done == 0){
//         printf("1.insert\n2.delete\n3.display\n");
//         printf("Enter the choice: ");
//         scanf("%d",&choice);

//         if(choice==1){
//             int x;
//             printf("Enter the element: ");
//             scanf("%d",&x);
//             insert(x);
//         }
//         else if (choice == 2){
//             delete();
//         }
//         else if(choice == 3){
//             for(int i = front+1;i<=rear;i++){
//                 printf("%d ",arr[i]);
//             }
//             printf("\n");
//         }
//         else{
//             done = 1;
//         }
//     }

// }

// Write a program to implement Bubble Sort?

// #include <stdio.h>

// int main(){
//     int arr [] = {1,9,8,7,65,3,2,10};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int i,j;
//     for(i =0;i<n;i++){
//         for(j = 0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     for(i = 0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
// }

// Write a program to implement Selection Sort.

// #include <stdio.h>

// int bubblesort(int arr[],int n){
//     int min;
//     for(int i = 0;i<n-1;i++)
//     {
//         min = i;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]<arr[min]){
//                 min = j;
//             }
//         }
//         int temp = arr[i];
//         arr[i]=arr[min];
//         arr[min]=temp;
//     }
// } 

// int main(){
//     int arr[] = {0,9,8,7,6,5,4,3,2,1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     bubblesort(arr,n);

//     for(int i = 0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
// }

// Write a program to implement Quick Sort.

// #include <stdio.h>

// int swap(int *a,int *b){
//     int temp = *a;
    // *a =*b;
    // *b = temp;
// }

// int partition(int arr[],int low,int high){
//     int pivot = arr[high];
//     int i = low-1;
//     for(int j= low;j<=high-1;j++){
//         if(arr[j]<=pivot){All in one/practical.c
//             i++;
//             swap(&arr[i],&arr[j]);
//         }
//     } 
//     swap(&arr[i+1],&arr[high]);
//     return i+1;
// }

// int quicksort(int arr[],int low,int high){
//     if(low<high){
//         int pivot = partition(arr,low,high);
//         quicksort(arr,low,pivot-1);
//         quicksort(arr,pivot+1,high);
//     }
// }

// int main(){
//     int arr[] = {0,9,8,7,6,5,4,3,2,1};
//     int n =sizeof(arr)/sizeof(arr[0]);

//     quicksort(arr,0,n-1);

//     for(int i = 0;i<n;i++){
//         printf("%5d",arr[i]);
//     }
// }

// Write a program to implement Merge Sort

// #include <stdio.h>

// int merge(int arr[],int l,int m,int r){
//     int n1 = m-l+1;
//     int n2 = r-m;
//     int i,j,k;

//     int L[n1],R[n2];

//     for(i = 0;i<n1;i++){
//         L[i] = arr[l+i];
//     }
//     for(j=0;j<n2;j++){
//         R[j] = arr[m+1+j];
//     }
//     i = 0, j = 0 , k = l;
//     while(i<n1 && j<n2){
//         if(L[i]<=R[j]){
//             arr[k] = L[i];
//             i++;
//         }
//         else{
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while(i<n1){
//         arr[k]= L[i];
//         i++;
//         k++;
//     }

//     while(j<n2){
//         arr[k]= R[j];
//         j++;
//         k++;
//     }
// }

// int mergesort(int arr[],int l,int r){
//     if(l<r){
//         int mid = l + (r - l) / 2;
//         mergesort(arr,l,mid);
//         mergesort(arr,mid+1,r);

//         merge(arr,l,mid,r);
//     }
// }

// int main(){
//     int arr[] = {0,9,8,7,6,5,4,3,2,1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     for(int i =0;i<n;i++){
//         printf("%3d",arr[i]);
//     }
//     printf("\n");
//     mergesort(arr,0,n-1);
//      for(int i =0;i<n;i++){
//         printf("%3d",arr[i]);
//     }

// }
// Write a program to implement Insertion Sort.
// #include <stdio.h>

// int insertion(int arr[], int n){
//     int i,j,key;
//     for(i=1;i<n;i++){
//         key = arr[i];
//         j = i-1;

//         while(j>=0 && arr[j]>key){
//             arr[j+1]= arr[j];
//             j = j-1;
//         }
//         arr[j+1] = key;
//     }
// }

// int main(){
//     int arr[] = {0,9,8,7,6,5,4,3,2,1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     insertion(arr,n);
//     for(int i =0;i<n;i++){
//         printf("%3d",arr[i]);
//     }
// }

// Write a function to insert new element at the beginning of singly linked list, also display thecontentafterinsertion.

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct nd{
//     int data;
//     struct nd *next;
// }node;

// node *create(){
//     node *temp,*head;
//     int i,n;
//     printf("Enter :  ");
//     scanf("%d",&n);

//     for(i=0;i<n;i++){
//         if(i==0){
//             head = (node*)malloc(sizeof(node));
//             temp = head;
//         }
//         else{
//             temp->next = (node*)malloc(sizeof(node));
//             temp = temp->next;
//         }
//         printf("Enter the data: ");
//         scanf("%d",&temp->data);
//     }
//     temp->next = NULL;
//     return head;
// }

// int main(){
//     node *head,*newnode;
//     head = create();
//     printf("Enter the newData: ");
//     newnode = (node*)malloc(sizeof(node));
//     scanf("%d",&newnode->data);
//     newnode->next = head;
//     head = newnode;
//     while(head!=NULL){
//         printf("%3d",head->data);
//         head= head->next;
//     }
// }

// Write a function to insert new element at the beginning of doubly linked list, also display thecontentafterinsertion.

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* prev;
//     struct Node* next;
// };

// // function to insert a new element at the beginning of a doubly linked list
// void insertAtBeginning(struct Node** head, int data) {
//     // create a new node with the given data
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;

//     // update the links
//     newNode->prev = NULL;
//     newNode->next = *head;
//     if (*head != NULL) {
//         (*head)->prev = newNode;
//     }
    // *head = newNode;
// }

// // function to display the content of a doubly linked list
// void displayList(struct Node* head) {
//     struct Node* current = head;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// int main() {
//     // create an empty doubly linked list
//     struct Node* head = NULL;

//     // insert some elements at the beginning of the list
//     insertAtBeginning(&head, 10);
//     insertAtBeginning(&head, 20);
//     insertAtBeginning(&head, 30);
//     insertAtBeginning(&head, 40);

//     // display the content of the list
//     displayList(head);

//     return 0;
// }


// Write a program to implement Depth First Search in c?
// #include<stdio.h>
// #include<stdlib.h>
 
// int visited[7] = {0,0,0,0,0,0,0};
//     int A [7][7] = {
//         {0,1,1,1,0,0,0},
//         {1,0,1,0,0,0,0},
//         {1,1,0,1,1,0,0},
//         {1,0,1,0,1,0,0},
//         {0,0,1,1,0,1,1},
//         {0,0,0,0,1,0,0}, 
//         {0,0,0,0,1,0,0} 
//     };
 
// void DFS(int i){
//     printf("%d ", i);
//     visited[i] = 1;
//     for (int j = 0; j < 7; j++)
//     {
//         if(A[i][j]==1 && !visited[j]){
//             DFS(j);
//         }
//     }
// }
 
// int main(){ 
//     // DFS Implementation  
//     DFS(0); 
//     return 0;
// }