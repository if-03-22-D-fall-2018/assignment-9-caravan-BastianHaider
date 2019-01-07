/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include "stdlib.h"
#include "general.h"
#include "caravan.h"

#define COUNT_CARAVANS 5

typedef struct NodeImplementation* Node;

struct NodeImplementation
{
    PackAnimal animal;
    struct NodeImplementation* next;
};

struct CaravanImplementation
{
    int length;
    Node head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->head = 0;
  caravan->length = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node currentNode = caravan->head;
    while(currentNode != 0)
    {
        Node to_be_deleted = currentNode;
        currentNode = currentNode->next;
        sfree(to_be_deleted);
    }
    sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal==0)
  {
    return;
  }
  Node newNode = (Node)malloc(sizeof(struct NodeImplementation));
  newNode->animal=animal;
  newNode->next=0;
  Node currentNode = caravan->head;
  if (caravan->head==0)
  {
    caravan->head=newNode;
  }
  else
  {
    while (currentNode->next != 0)
    {
      currentNode=currentNode->next;
    }
    currentNode->next=newNode;
  }
  caravan->length++;
  add_to_caravan(animal, caravan);
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal!=0){
 Node currentNode = caravan->head;
 Node prev;
 if(currentNode != 0 && currentNode->animal == animal)
 {
     caravan->head = currentNode->next;
     sfree(currentNode);
     remove_from_caravan(animal, caravan);
     caravan->length--;
     return;
 }
 while(currentNode != 0 && currentNode->animal != animal)
 {
     prev = currentNode;
     currentNode = currentNode->next;
 }
 if(currentNode==0) return;

 prev->next = currentNode->next;
 sfree(currentNode);
 remove_from_caravan(animal, caravan);
 caravan->length--;
 }
}

int get_caravan_load(Caravan caravan)
{
  int load=0;
  Node currentNode = caravan->head;
  while (currentNode!=0)
  {
    load+=get_load(currentNode->animal);
    currentNode=currentNode->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node currentNode = caravan->head;
    while(currentNode!=0)
    {
        unload(currentNode->animal);
        currentNode = currentNode->next;
    }
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}
void optimize_load(Caravan caravan)
{

}
