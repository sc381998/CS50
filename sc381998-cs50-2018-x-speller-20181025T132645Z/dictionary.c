// Implements a dictionary's functionality
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#define DICTIONARY "dictionaries/large"

#include "dictionary.h"
typedef struct node
{
    bool is_word;
    struct node* children[27];
}node;
node* first;
int word_count=0;
bool upload_helper(node* node_ptr);
int get_index(char c);
node* create_init_node();
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node* node_ptr=first;
    for(int i=0,len=strlen(word); i<=len;i++)
{
    if(word[i]=='\0')
    {
        if(node_ptr->is_word==true)
        return true;
        else
        return false;
    }
    int index=get_index(word[i]);
    if(node_ptr->children[index]==NULL)
    return false;
    node_ptr=node_ptr->children[index];
}
return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file =  fopen(dictionary,"r");
    if(file == NULL)
    {
        fprintf(stderr,"File does not exist\n");
        return false;
    }
    first=create_init_node();
    int index;
    node* node_ptr=first;
    for(char c = fgetc(file); c!=EOF;c=fgetc(file))
    {
        if(c!= '\n')
        {
            index=get_index(c);
            if(node_ptr->children[index]==NULL)
            {
                node_ptr->children[index]=create_init_node();
                }
                node_ptr=node_ptr->children[index];
        }
        else
        {
            node_ptr->is_word=true;
            word_count++;
            node_ptr=first;
        }
    }
    fclose(file);
    return true;

}
int get_index(char c)
{
    if(c=='\n')
    return 26;
    else if(c>='a'&&c<='z')
    return c-'a';
    else if(c>='A'&&c<='Z')
    return (c-'A');
    return 1;
}
node* create_init_node()
{
    node* node_ptr=malloc(sizeof(node));
    node_ptr->is_word=false;
    for(int i=0;i<27;i++){
    node_ptr->children[i]=NULL;
    }
return node_ptr;
}
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
  if(upload_helper(first))
  return true;
  return false;
}
bool upload_helper(node* node_ptr)
{
        for(int i=0;i<27;i++)
        {
    if(node_ptr->children[i]!=NULL)
    upload_helper(node_ptr->children[i]);
}free(node_ptr);
return true;
}