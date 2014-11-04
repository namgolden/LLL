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
    if (!head){
        cout << "No Student in list." << endl;
        return 2;
    }
    else {
        cout << "\nStudent's list: " << endl;
        if (!head->next){
            cout << head->id << '\t' << head->name << '\t' << head->score << endl << endl;
            return 1;
        }
        else {
            node * current = head;
            while (current){
                cout << current->id << '\t' << current->name << '\t' << current->score << endl;
                current = current->next;
            }
            cout << "\n\n";
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
    char t_name[20];
    int t_score;

    cout << "Please enter a id: ";
    cin >> t_id;
    cin.ignore(100, '\n');
    cout << "Please enter a name (8 characters minimum 19 characters maximum): ";
    cin.get(t_name, 20, '\n');
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

int menu(node *& head){
    cout << "1. Add a new student." << endl;
    cout << "2. Delete a student." << endl;
    cout << "3. Search for a student." << endl;
    cout << "4. Exit." << endl;
    cout << "Please choose an option: ";
    
    int choice = 0;

    while ((choice <= 0) || (choice > 4 )){
        cin >> choice;
        cin.ignore(100, '\n');
        if ((choice < 1) || (choice > 4)){
            cout << "\nPlease only choose the existent options. " << endl;
            cout << "Please choose an option: ";
        }
    }
    if (choice == 1) {
        add(head);
        display(head);
        return 1;
    } else if (choice == 4){
        cout << "Thanks!" << endl;
        return 4;
    } else cout << "The option is underconstruction." << endl << endl;
    return 0;
}

int main(){
    node * head;
    int deb_int = 0;
    cout << "Chao mung cac ban den voi danh sach sinh vien" << endl;
    
    while (menu(head) != 4){
        ++deb_int;
    }

    cin.get();
    cout << "Chao tam biet" << endl;
    return 0;
}



