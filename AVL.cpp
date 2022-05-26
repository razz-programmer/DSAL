#include <iostream>

using namespace std;
class Node
{
    int data,height;
    Node *left,*right;

    public:
        Node()
        {
            data=height=0;
            left=right=NULL;

        }
        friend class AVL;
};


class AVL
{
    Node *root;
    public:
        AVL()
        {
            root=NULL;
        }
        Node *insert(Node *,int);
        Node *LL(Node*);
        Node *RR(Node*);
        Node *LR(Node*);
        Node *RL(Node*);
        Node *leftRotate(Node*);
        Node *rightRotate(Node*);
        int balFactor(Node*);
        int getHeight(Node*);
        void inorder(Node*);
        void insert();
        void inorder();

};

int AVL::getHeight(Node *root)
{
    int hl,hr;
    if(root==NULL)
        return 0;
    //Calculating height of left sub tree
    if(root->left==NULL)
        hl=0;
    else
        hl=1+root->left->height;
    //Calculating height of right sub tree
    if(root->right==NULL)
        hr=0;
    else
        hr=1+root->right->height;
    if(hl>hr)
        return hl;
    return hr;


}



int AVL::balFactor(Node *root)
{
    int hl,hr;
    if(root==NULL)
        return 0;
    //Calculating height of left sub tree
    if(root->left==NULL)
        hl=0;
    else
        hl=1+root->height;
    //Calculating height of right sub tree
    if(root->right==NULL)
        hr=0;
    else
        hr=1+root->height;
   return hl-hr;


}



Node *AVL::insert(Node*root,int val)
{
    if(root==NULL)//tree is empty
    {
        root = new Node;//allocates new space
        root->data=val;//stores value in data segment of root Node
        cout<<"\n"<<val<<" added ";


    }
    /*2.Left */
    if(val<root->data)
    {

        root->left=insert(root->left,val);
        if(balFactor(root)==2)
        {
            if(val<root->left->data)
                root=LL(root);
                else
                    LR(root);


        }
//        cout<<"left sub tree";

    }
    if(val>root->data)
    {

        root->right=insert(root->right,val);
        if(balFactor(root)==-2)
        {
            if(val>root->right->data)
                root=RR(root);
                else
                    RL(root);



        }
//        cout<<"Right sub tree";
    }
    root->height=getHeight(root);
    return root;
}
        Node * AVL::LL(Node* root)
        {
            cout<<"\n Single LL Rotation";
            root=rightRotate(root);
            return root;
        }

        Node * AVL::RR(Node* root)
        {
            cout<<"Single RR rotation";
            root=leftRotate(root);
            return root;
        }

        Node * AVL::LR(Node* root)
        {       cout<<"Double LR rotation";
                root->left=leftRotate(root->left);
                root=rightRotate(root);
                return root;
        }
        Node * AVL::RL(Node* root )
        {   cout<<"Double RL rotation";
            root->right=rightRotate(root->right);
            root=leftRotate(root);
            return root;
        }

void AVL::inorder(Node *root)
{
    //LVR(left-?>root->right
          if(root!=NULL)
          {
          inorder(root->left);
          cout<<"\t"<<root->data;
          inorder(root->right);

          }

}


Node* AVL::rightRotate(Node*x)
{
     Node *y; //new root
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->height=getHeight(x);
    y->height=getHeight(y);

    return y;
}

Node* AVL::leftRotate(Node*x)
{
    Node *y; //new root
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->height=getHeight(x);
    y->height=getHeight(y);

    return y;
}

void AVL::insert()
{
    int val;
    cout<<"Enter value which you want to insert:";
    cin>>val;
    root=insert(root,val);
}

void AVL::inorder()
{
    inorder(root);
}


int main()
{
    int ch;
   AVL obj;
    int x;
   do{

    //insert traversal/exit


    cout<<"\n-------------------MENU-------------------";
    cout<<"\n1.Insert";
    cout<<"\n2.Traversal";
    cout<<"\n3.Exit";
    cout<<"\nEnter your Choice:";
    cin>>ch;



    switch(ch)
   {
   case 1:
       obj.insert();
       break;
   case 2:
       obj.inorder();
       break;

   case 3:exit(0);

   default:
            cout<<"Enter valid choice!!!!";

   }}while(ch!=3);





    return 0;

}



/*
input: 10 20 30 5 3 40 35
output
RR
LL
RL

*/
