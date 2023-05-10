#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data) {
    if (last != NULL) return last;
    //asignar memoria al nuevo nodo
    struct Node* newNode = (struct Node*) malloc (sizeof (struct Node));

    //asiganr un dato al nuevo nodo

    newNode ->data = data;
    //asignar como last al nuevo nodo
    last = newNode;

    // se crea enlace a si mismo

    last ->next = last;

    return last;

}
// agregar nodo por el frente 

struct Node* addFront (struct Node* last, int data) {
    
    //se revisa si la lista esta vacia 

    if (last== NULL) return addToEmpty (last, data);

    //se asigna memoria al nuevo nodo

    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));

    //se agrega dato al nuevo nodo 

    newNode -> data = data;

    // se guarda la dirrecciòn de memoria del primer nodo actual en el nuevo nodo

    newNode -> next = newNode;

    return last;

}

// agregar nodo al final 

struct Node* addEnd(struct Node* last, int data) {

    //se revisa si el nodo està vacìo

    if (last == NULL) return addToEmpty (last, data);

    //se asigna memoria al nuevo nodo

    struct Node* newNode = (struct Node*) malloc (sizeof (struct Node));

    // se agrega dato al nuevo nodo 

    newNode -> data = data;

    // se almacena la direcciòn del nodo cabeza al siguiente del nuevo nodo 

    newNode -> next = last -> 


    

}

// insertar nodo despuès de un nodo especìfico

    struct Node* addAfter (struct Node* last, int data, int item) {
        // se revisa si la lista esta vacìa 

        if ( last == NULL) return NULL;

        struct Node * newNode, +p;

        p = last -> next;

        do {
            // si se encontro el elemento se coloca el nuevo nodo despuès de el

            if (p-> data == item){

                //se asigna memoria al nuevo nodo 

                newNode = (struct Node*) malloc (sizeof(struct Node));

                //se agrega dato al nodo 
                newNode -> data = data;
                newNode -> next= p-> next;
                
                p -> next = newNode;

                if (p == last) last = newNode;
                return last
            }
            
            p = p-> next;

        } while (p != last ->next);

        printf ("\n El nodo dado no esta presente en la lista");

        return last;
    }
 // borrar un nodo 

 void deleteNode (struct Node** last, int Key){

    if ( *last == NULL) return;

    if ((*last) ->data == key && (*last)-> next == *last) {
        free (*last);
        *last = NULL;
        return;
     }
 
 struct Node *temp = *last, *d;

 // si se va a eliminar el ultimo 
 if ((*last)-> data == Key){
    while (temp -> next != *last) temp = temp->next;

    temp-> next = (*last) temp-> next;
    free (*last);
    *last = temp -> next;
 }
while (temp-> next != *last && temp->next->data ! = key) {
    
}
 
 }


