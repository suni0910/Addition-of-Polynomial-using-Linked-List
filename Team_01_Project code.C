//Addition of polynomial using linked list
//Group-1(PROJECT)
#include<stdio.h>   //Preproccessor Directive
#include<stdlib.h>   //library function

//define the structure of the node
struct node 
{
int coef,expo;   //coefficient and exponent
struct node* next;
};
// Insertion of polynomial node
struct node* insertpoly(struct node* thead,int c,int e);
struct node* append(struct node* thead,int c,int e);
struct node* polyaddition(struct node* p1thead,struct node* p2thead);
void display(struct node* thead);

void main()
{
int a,b,n,i;
struct node* p1head,* p2head,* p3head;
p1head=p2head=NULL;

// Inputing the first polynomial

printf("Enter the no of terms of polynomial 1..");
scanf("%d",&n);
printf("\nEnter the polynomial..");
for(i=0;i<n;i++){
printf("\nEnter the coefficient and exponent of the term..");
scanf("%d%d",&a,&b);
p1head=insertpoly(p1head,a,b);
}

// Inputing the second polynomial

printf("\nEnter the no of terms of polynomial 2..");
scanf("%d",&n);
printf("\nEnter the polynomial..");
for(i=0;i<n;i++){
printf("\nEnter the coefficient and exponent of the term..");
scanf("%d%d",&a,&b);
p2head=insertpoly(p2head,a,b);
}

//Performing addition of the polynomial

p3head=polyaddition(p1head,p2head);

//Displaying the  Resultant polynomial node

printf("\nThe polynomial 1 is");
display(p1head);
printf("\nThe polynomial 2 is");
display(p2head);
printf("\nThe sum of the two polynomials         is");
display(p3head);
}

struct node* append(struct node* thead,int c,int e)
{
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->coef=c;
newnode->expo=e;
if(thead==NULL){   // checking if the list is empty
newnode->next=NULL;
return newnode;
}
struct node* trav=thead;
//Traversing to point to the last node
while(trav->next!=NULL)
trav=trav->next;
trav->next=newnode;
newnode->next=NULL;
return thead;
}
// Inserting the first node
struct node* insertpoly(struct node* thead,int c,int e)
{
Struct node* newnode=(struct
node*)malloc(sizeof(struct node));
newnode->coef=c;
newnode->expo=e;
if(thead==NULL){
newnode->next=NULL;
return newnode;
}
struct node* prev,* curr;
prev=curr=thead;
while(curr!=NULL && curr->expo>e){
prev=curr;
curr=curr->next;
}
// for inserting before the first node
if(curr==thead)
{
newnode->next=curr;
return newnode;
}
// for inserting before the first node
else if(curr==NULL)
{       
prev->next=newnode;
newnode->next=NULL;
}
else{
newnode->next=curr;
prev->next=newnode;
}
return thead;
}

Struct node* polyaddition(struct node* p1thead,struct node* p2thead)
{
struct node* ans=NULL;
struct node* t1,* t2;
t1=p1thead;
t2=p2thead;
while(t1!=NULL && t2!=NULL){
if(t1->expo > t2->expo){
ans=append(ans,t1->coef,t1->expo);
t1=t1->next;
}
else if(t1->expo < t2->expo){
ans=append(ans,t2->coef,t2->expo);
t2=t2->next;
}
else{
ans=append(ans,(t1->coef)+(t2->coef),t1->expo);
t1=t1->next;
t2=t2->next;
}
}
// Coping the remaining terms of polynomial 1
while(t1!=NULL)
{          
ans=append(ans,t1->coef,t1->expo);
t1=t1->next;
}

// Coping the remaining terms of polynomial 2
while(t2!=NULL)
{            
ans=append(ans,t2->coef,t2->expo);
t2=t2->next;
}
return ans;
}
// Display the resultant polynomial solution

void display(struct node* thead
{
struct node* temp=thead;
if(temp==NULL){
printf("\nEmpty..");
}
else{
while(temp->next!=NULL){
printf(" %dx^%d +",temp->coef,temp->expo);
temp=temp->next;
}
printf(" %dx^%d ",temp->coef,temp->expo);
}
}
