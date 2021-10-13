#include <iostream>

typedef struct Node {
    int data;
    struct Node *next;
}Node_t;



void add(Node_t *&LL , const int &value){
    
    
    if(LL==nullptr){
        LL = new Node_t;
        LL->data = value;
    }else{
        Node_t *newNode;
        Node_t *tmp = LL;
    
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        newNode = new Node_t;
        newNode->next = nullptr;
        newNode->data = value;
        tmp->next = newNode;
    }
    
}

void remove(Node_t *&LL){
    if(LL == nullptr){
        return;
    }else{
        //find next head
        //assign new head
        //delete old head
        Node_t *next = LL->next;
        delete LL;
        LL=nullptr;
        LL=next;
    }
}

void print(Node_t *&LL){
    if(LL == nullptr){
        std::cout << "Empty list "<< std::endl;
        return;
    }
    Node_t *current = LL;
    while(current != nullptr){
        std::cout<< current->data <<std::endl;
        current = current->next;
    }
}
int main(){
    Node_t *my_linked_list =nullptr;
    print(my_linked_list);
    add(my_linked_list,2);
    add(my_linked_list,3);
    add(my_linked_list,4);
    print(my_linked_list);
    remove(my_linked_list);
    print(my_linked_list);


};