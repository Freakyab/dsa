#include <stdio.h>
#include <stdlib.h>


// typedef struct nd
// {
//     int data;
//     struct nd *next;
// } node;

// node *create()
// {
//     node *head, *p;
//     int n, i;
//     printf("Enter the total length of node : ");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         if (i == 0)
//         {
//             head = (node *)malloc(sizeof(node));
//             p = head;
//         }
//         else
//         {
//             p->next = (node *)malloc(sizeof(node));
//             p = p->next;
//         }
//         printf("Enter the data: ");
//         scanf("%d", &p->data);
//     }
//     p->next = NULL;
//     return head;
// }

// node *display(node *head)
// {
//     node *temp;
//     int count = 1;
//     temp = head;
//     while (temp != NULL)
//     {
//         printf("The data of %d node : %d\n", count, temp->data);
//         count++;
//         temp = temp->next;
//     }
// }

// node *insert(node *head)
// {
//     node *temp, *newNode;
//     node *p, *head1;
//     head1 = head;
//     int i, n, k;

//     printf("Enter how many you want to insert: ");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         if (i == 0)
//         {
//             newNode = (node *)malloc(sizeof(node));
//             temp = newNode;
//         }
//         else
//         {
//             temp->next = (node *)malloc(sizeof(node));
//             temp = temp->next;
//         }
//         printf("Enter the data: ");
//         scanf("%d", &temp->data);
//     }
//     temp->next = NULL;

//     printf("Enter where you want to insert\n1.Beginning\n2.Middle\n3.Last\nEnter: ");
//     scanf("%d", &k);
//     if (k == 1)
//     {
//         temp->next = head;
//         return newNode;
//     }
//     if (k == 2)
//     {
//         int loc;
//         printf("Enter after whom you want to insert: ");
//         scanf("%d", &loc);
//         while (head1->next != NULL)
//         {
//             if (loc == head1->data)
//             {
//                 p = head1->next;
//                 head1->next = newNode;
//                 temp->next = p;
//                 break;
//             }
//             head1 = head1->next;
//         }
//         return head;
//     }
//     if (k == 3)
//     {
//         while (head1->next != NULL)
//         {
//             head1 = head1->next;
//         }
//         head1->next = newNode;
//         return head;
//     }
// }
// node *delete(node *head)
// {
//     node *temp, *i;
//     temp = head;
//     int n;
//     printf("Enter the data which you want to delete: ");
//     scanf("%d", &n);
//     if (head->data == n)
//     {
//         head = head->next;
//         free(temp);
//     }
//     else
//     {
//         while (temp->next != NULL)
//         {
//             i = temp->next;
//             if (temp->next->data == n)
//             {
//                 temp->next = temp->next->next;
//                 break;
//             }
//             temp = temp->next;
//         }
//         free(i);
//     }
//     return head;
// }
// void main()
// {
//     node *head;
//     int count = 1;
//     head = create();
//     display(head);
//     // head = insert(head);
//     head = delete (head);
//     display(head);
// }

// #define Max 5
// int stack[Max];
// int top = -1;

// void insert (int x){
//     if(top>=Max-1){
//         printf("Stack overflow\n");
//     }
//     else{
//         top++;
//         stack[top] = x;
//     }
// }

// void display(){
//     // printf("%d\n",top);
//     for(int i= 0;i<=top;i++)
//     {
//         printf("The stack data at %d is : %d \n",i+1,stack[i]);
//     }
// }

// void pop(){
//     if(top<=-1){
//         printf("stack underflow\n");
//     }
//     else{
//         top--;
//     }
// }

// void main(){
//     insert(5);
//     insert(5);
//     display();
//     pop();
//     pop();
//     display();
// }

// Linear search

int linear_search(int arr[], int n)
{
    int i;
    printf("Enter the no You want to search: ");
    scanf("%d", &i);
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == i)
        {
            return j;
            break;
        }
    }

    return -1;
}

// binear
int binear_search(int arr[], int low, int high, int key)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            binear_search(arr, low, mid - 1, key);
        }
        else
        {
            binear_search(arr, mid + 1, high, key);
        }
    }
    else
    {
        return -1;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d", arr[i]);
    }
}

// bubbleSort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printArr(arr, n);
}

// SelectionSort
void selectionSort(int arr[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            swap(&arr[i], &arr[min]);
        }
    }
    printArr(arr, n);
}

// insertion
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printArr(arr, n);
}

// quickSort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// mergeSort
void merge(int arr[],int l,int r,int m)
{
    int i,j,k = l;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    i =0,j =0;
    while(i<n1&&j<n2){
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort (int arr[],int l,int r)
{
    if(l<r){
        int mid = (l+r)/2;
        mergeSort (arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,r,mid);
    }
}

// queue
#define Max 5
int q[Max];
int r = -1,f = -1;

void Enqueue(int x)
{
    if(r == Max-1){
        printf("Queue Overflow\n");
    }
    else{
        if(f == -1)
        {
            f = 0;
            r++;
        }
        else{
            r++;
            q[r] = x;
        }
    }
}

void Dequeue(){
    if(f == r )
    {
        printf("Queue underflow\n");
    }
    else{
        f++;
    }
}

void display(){
    for(int i = f;i<=r;i++)
    {
        printf("The data : %d\n",q[i]);
    }
}

typedef struct node{
    int data;
    struct node *next;
}node;

struct Queue{
    node *front;
    node *rear;
};

node *top = NULL;
node *push(int data){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
node *pop(){
    node *temp = top;
    if(temp == NULL){
        printf("Stack underflow");
    }
    else{
        top = temp->next;
        free(temp);
    }
}
node *peek()
{
    node *item = top;
    printf("The peek data is : %d\n",item->data);
}

void enqueue(struct Queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    struct node* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* current = q->front;

    printf("Queue: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int found;
    // int i;
    // printf("Enter the no You want to search: ");
    // scanf("%d", &i);

    // found = linear_search(arr,n);

    // found = binear_search(arr, 0, n - 1, i);

    // if (found == -1)
    // {
    //     printf("not Found");
    // }
    // else
    // {
    //     printf("found at index %d", found);
    // }

    // bubbleSort(arr,n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // quickSort(arr, 0, n - 1);
    // mergeSort(arr, 0, n - 1);
    // printArr(arr, n);

    // Enqueue(5);
    // Enqueue(6);
    // Enqueue(7);
    // Enqueue(8);
    // Dequeue();
    // display();
    push(5);
    push(6);
    pop();
    peek();
}

