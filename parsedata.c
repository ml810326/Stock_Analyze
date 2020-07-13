#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 100

struct node{
   char* date;
   float open;
   float high;
   float low;
   float close;
   struct node* next;
};
typedef struct node Node;

int main(int argc, const char* argv[]){
    char file_name[] = "Test.csv";
    FILE *fp;
    Node *first, *curr, *pre;

    fp = fopen(file_name, "r");

    if(!fp){
        fprintf(stderr, "failed to open file\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    char *result = NULL;
    int i = 0;

    fgets(line, MAX_LINE_SIZE, fp);
    while(fgets(line, MAX_LINE_SIZE, fp)!=NULL){
        curr = (Node *)malloc(sizeof(Node));
        result = strtok(line, ",");
	curr->date = result;
        result = strtok(NULL, ",");
        curr->open = strtof(result, NULL);
        result = strtok(NULL, ",");
        curr->high = strtof(result, NULL);
        result = strtok(NULL, ",");
        curr->low = strtof(result, NULL);
        result = strtok(NULL, ",");
        curr->close = strtof(result, NULL);
        if(i==0)
            first = curr;
        else
            pre->next = curr;
        curr->next = NULL;
        pre=curr;
        i++;
    }

    fclose(fp);

    curr = first;
    while(curr!=NULL){
        printf("date: %s\n", curr->date);
        printf("open: %f\n", curr->open);
        printf("high: %f\n", curr->high);
        printf("low: %f\n", curr->low);
        printf("close: %f\n", curr->close);
        printf("====================\n");
        curr = curr->next;
    }

    return 0;
}
