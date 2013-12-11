#include "test.h"
#include <stdlib.h>

scheduler* create(){
    scheduler *queue = calloc(sizeof(scheduler),1);
    return queue;
}
int frontInsert(pro *process,scheduler *queue){
    if(queue->front == NULL)
        process->next = NULL;
    else process->next = queue->front;
    queue->front = process;
    queue->length++;
    return queue->length;        
}
int insert(scheduler *queue,pro *process){
    pro *previous,*next,*temp;
    temp = queue->front;
    if(queue->length == 0)                
        return frontInsert(process,queue);
    if(process->priority < temp->priority)
        return frontInsert(process,queue);
    while(temp != NULL){
        previous = temp;
        next = temp->next;
        temp = temp->next;
        if(process->priority < next->priority){
        	previous->next = process;
    		process->next = next;
    		return ++queue->length;
        }
    };
    return 0;
}