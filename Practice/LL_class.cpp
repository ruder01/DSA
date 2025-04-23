#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};

class LinkedList{
    Node* head=NULL;
    Node* tail=NULL;
    int size=0;
public:
    void insert_at_end(int x){
        Node* temp=new Node(x);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insert_at_front(int x){
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
        size++;
    }
    void insert_at_index(int x,int idx){
        if(idx==0) insert_at_front(x);
        else if(idx==size) insert_at_end(x);
        else if(idx>=size) cout<<"Invalid Index\n";
        else{
            Node* temp=new Node(x);
            Node* travel=head;
            int x=0;
            while(x!=idx-1){
                travel=travel->next;
                x++;
            }
            temp->next=travel->next;
            travel->next=temp;
            size++;
        }

    }
    void delete_at_head(){
        if(size==0) cout<<"List is Empty\n";
        else{
            head=head->next;
            size--;
        }
    }
    void delete_at_tail(){
        if(size==0) cout<<"List is Empty\n";
        else{
            Node* travel=head;
            while(travel->next->next!=NULL){
                travel=travel->next;
            }
            travel->next=NULL;
            tail=travel;
            size--;
        }
    }
    void delete_at_index(int idx){
        if(idx==0) delete_at_head();
        else if(idx==size-1) delete_at_tail();
        else if(idx>=size) cout<<"Invalid index\n";
        else{
            Node* travel=head;
            int x=0;
            while(x!=idx-1){
                travel=travel->next;
                x++;
            }
            travel->next=travel->next->next;
            size--;
        }
        
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    LinkedList ll;
    cout<<"Insertion Process: \n";
    ll.insert_at_end(2);
    ll.insert_at_end(4);
    ll.insert_at_end(5);
    ll.insert_at_front(1);
    ll.insert_at_index(3,2);
    ll.display();
    cout<<"Deletion Process: \n";
    // ll.delete_at_head();
    // ll.delete_at_tail();
    ll.delete_at_index(2);
    ll.display();

}