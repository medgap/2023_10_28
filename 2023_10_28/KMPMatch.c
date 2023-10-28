#include<stdio.h>
#include<stdlib.h>

typedef struct String{
    char* data;
    int len;
}String;

String* initString(){
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

void StringAssign(String* s,char* data){
    if(s->data){
        free(s->data);
    }
    else{
        int len = 0;
        char* temp = data;
        while(*temp){
            len++;
            temp++;
        }
        if(len == 0){
            s->data = NULL;
            s->len = 0;
        }
        else{
            s->data = (char*)malloc(sizeof(char)*(len + 1));
            temp = data;
            s->len = len;
            for(int i = 0; i < len; i++,temp++){
                s->data[i] = *temp;
        }
        }
        
    }
}

int* getNext(String* s){
    int i = 0;
    int j = -1;
    int* next = (int*)malloc(sizeof(s->len));
    next[i] = j;
    while(i < s->len - 1){
        if(j == -1 || s->data[i] == s->data[j]){
            i++;
            j++;
            next[i] = j;
            //next[++i] = ++j;
        }
        else{
            j = next[j];
        }
    }
    return next;
}

void KMPMatch(String* master,String* sub,int* next){
    int i = 0;
    int j = 0;
    while(i < master->len && j < sub->len){
        if(j == -1 || master->data[i] == sub->data[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j == sub->len){
        printf("KMP match success.\n");
    }
    else{
        printf("KMP match fail.\n");
    }
}
void PrintNext(int* next,int len){
    for(int i = 0; i < len; i++){
        printf(i == 0 ? "%d" : "->%d",next[i]);
    }
    printf("\n");
}

int main(int argc,char* argv[]){
    String* s1 = initString();
    String* s2 = initString();
    //StringAssign(s1,"ABACCABABD");
    //StringAssign(s2,"ABD");
    StringAssign(s1,argv[1]);
    StringAssign(s2,argv[2]);
    int* next = getNext(s2);
    PrintNext(next,s2->len);
    KMPMatch(s1,s2,next);
    return 0;
}