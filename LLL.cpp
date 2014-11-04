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

int remove_by_name(node *& head, char * name){
    if (!head){
        cout << "No student in list." << endl;
        return 1;
    }
    else{
        if (!head->next){
            if (strcmp(head->name, name) == 0){
                delete head;
                head = NULL;
                return 0;
            }
            else {
                cout << "Student with name " << name << " is not found" << endl;
                return 1;
            }
        }
        else{
            if(head->name == name){
                node * temp = head;
                head = head->next;
                delete temp;
                temp = NULL;
                return 0;
            } else {
                node * current = head->next;
                node * prev = head;
                while((strcmp(current->name, name) !=0) && current){
                    current = current->next;
                    prev = prev->next;
                }
                if (!current){
                    cout << "There is no student with name " << name << endl;
                    return 1;
                }
                else {
                    prev->next = current->next;
                    delete current;
                    current = NULL;
                    return 0;
                }
            }
        }
    }   
}

int remove_by_id(node *& head, int id){
    if (!head){
        cout << "No student in list." << endl;
        return 1;
    }
    else{
        if (!head->next){
            if (head->id == id){
                delete head;
                head = NULL;
                return 0;
            }
            else {
                cout << "Student with id " << id  << " is not found" << endl;
                return 1;
            }
        }
        else{
            node * current = head->next;
            node * prev = head;
            while((current->id != id) && current){
                current = current->next;
                prev = prev->next;
            }
            if (!current){
                cout << "There is no student with id " << id << endl;
                return 1;
            }
            //ADD AN IF HERE LIKE remove_by_name
            else {
                prev->next = current->next;
                delete current;
                current = NULL;
                return 0;
            }
        }
    }   
}

int remove(node *& head){
    int choice = 0;
    char t_name[20];
    int t_id = 0;

    cout << "1. Remove by name.";
    cout << "\n2. Remove by id.";
    cout << "\n3. Cancel.";
    cout << "\nRemove move by: ";

    cin >> choice;
    cin.ignore(100, '\n');
    
    while((choice < 1) || (choice >2)) {
        cout << "Cant recognize the remove option: ";
        cout << "\nPlease pick the existent remove option(1-2)" << endl;
        cout << "Remove by: " ;
        cin >> choice;
        cin.ignore(100, '\n');
    }
    if (choice == 1) {
        cout << "Please enter the student's name: ";
        cin >> t_name;
        cin.ignore(100,'\n');
        remove_by_name(head, t_name);
        return 0;
    } else if (choice == 2){
        cout << "Please enter the student's id: ";
        cin >> t_id;
        cin.ignore(100, '\n');
        remove_by_id(head, t_id);
        return 0;
    } else {
        cout << "Remove process canceled." << endl;
        return 0;
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
    } else if (choice == 2) {
        remove(head);
        display(head);
        return 2;
    }   else cout << "The option is underconstruction." << endl << endl;
    
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
    cout  << deb_int << " operations" << endl;
    return 0;
}



