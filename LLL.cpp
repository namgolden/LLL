//Nam Hai Dinh
//building LLL using struct for everything ^^

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

struct node {
    int id;
    char * name;
    int score;
    node * next;
};

int display(node * head){
    if (!head)
        return 2;
    else {
        if (!head->next){
            cout << head->id << '\t' << head->name << '\t' << head->score << endl;
            return 1;
        }
        else {
            node * current = head;
            while (current){
                cout << current->id << '\t' << current->name << '\t' << current->score << endl;
                current = current->next;
            }
            return 0;
        }
        
    }
}

int display1(node * target, int num){
    if (target)
        cout << target->id << '\t' << target->name << '\t' << target->score << endl;
    else cout << "Target node is null." << endl;
    return 0;
}

int ini_node(node *& target){
    target->id = 0;
    target->name = NULL;
    target->score = 0;
    target->next = NULL;
    return 0;
}

int edit_node(node *& target){
    int t_id;
    char t_name[10];
    int t_score;

    cout << "Please enter a id: ";
    cin >> t_id;
    cin.ignore(100, '\n');
    cout << "Please enter a name (8 characters minimum): ";
    cin.get(t_name, 11, '\n');
    cin.ignore(100,'\n');
    while (strlen(t_name) < 8){
        cout << "8 Characters of name is required." << endl;
        cout << "Please re-enter student name: ";
        cin.get(t_name, 11, '\n');
        cin.ignore(100,'\n');
    }
    cout << "Please enter the score of this student: ";
    cin >> t_score;

    target->id = t_id;
    target->name = new char(strlen(t_name)+1);
    strcpy(target->name, t_name);
    target->score = t_score;
/*
//debug 
    
*/ 

    return 0;
}

int add(node *& head){
    if (!head){
        head = new node();
        ini_node(head);
        edit_node(head);
        return 1;
    }
    else {
        if (!head->next){
            head->next = new node;
            node * current = head->next;
            ini_node(current);
            edit_node(current);
            return 0;
        }
        else {
            node * current = head->next;
            //traverse
            while (current->next){
                current = current->next;
            }
            current->next = new node;
            current = current->next;
            ini_node(current);
            edit_node(current);
            return 0;
        }
    }
}

int main(){
    node * head;

    cout << "Chao mung cac ban den voi danh sach sinh vien" << endl;
    cout << "Add new node" << endl;
    add(head);
    add(head);
    add(head);
    display(head);
    cin.get();
    cout << "Chao tam biet" << endl;
}



