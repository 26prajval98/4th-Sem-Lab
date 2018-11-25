#include <iostream>

using namespace std;

class node{
private:
    int data;
public:
    node *next = NULL;
    void setData(int n){
        data = n;
    };
    void printData(void){
        cout<<data;
    };
    bool matchData(int n){
        if(n==data)
            return true;
        else
            return false;
    };
};

node* createNode(){
    return new node();
};

void createList(int data, node* head){
    while(head->next!=NULL){
        head = head->next;
    };
    head->next = createNode();
    head = head->next;
    head->setData(data);
    cout<<"Data added\n";
};

void deleteNode(int data, node* head){
    //cout<<"Hey\n";
    while(head->next!=NULL){
        if(head->next->matchData(data)){
            cout<<"Deleted\n";
            node *temp = head->next;
            head->next = temp->next;
            delete temp;
            return ;
        }
        head = head->next;
    }
    cout<<"Not present\n";
}

void printList(node* head){
    head = head->next;
    while(head!=NULL){
        head->printData();
        cout<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

int main(){
    node* head = new node();
    while(1){
        int option;
        cout<<"1: Insert,  2: Print,  3:Exit,  4:Delete\nEnter option\n";
        cin>>option;
        if(option==1){
            int data;
            cout<<"Enter data:  ";
            cin>>data;
            createList(data,head);
        }
        else if(option==2){
            printList(head);
        }
        else if(option==3){
            break;
        }
        else if(option==4){
            int data;
            cout<<"Enter data:  ";
            cin>>data;
            deleteNode(data,head);
        }
        else{
            cout<<"Invalid";
        }
    }
    return 0;
}
