#include <iostream>
using namespace std;

struct task {
    string name;
    int priority;
    int exe_time;
    task *next;
} *head, *newtask, *pre, *temp;

int main() {
    head = NULL;
    int n;
    cout << "Assignment No 4: Expected output:\n";
    cout << "Enter number of tasks to schedule: ";
    cin >> n;
    cout << endl;

       for (int i = 0; i < n; i++) {
        newtask = new task();
        cout << "Task " << i + 1 << " Name: ";
        cin >> newtask->name;
        cout << "Priority (higher = more important): ";
        cin >> newtask->priority;
        cout << "Execution Time (ms): ";
        cin >> newtask->exe_time;
        cout << endl;

        newtask->next = NULL;

        if (head == NULL) {  
            // If first task, make it head
            head = newtask;
        } 
        else if (newtask->priority > head->priority) {  
            // Insert at beginning if higher priority
            newtask->next = head;
            head = newtask;
        } 
        else {
                       pre = head;
            temp = head->next;
            while (temp != NULL && temp->priority >= newtask->priority) {
                pre = temp;
                temp = temp->next;
            }
            newtask->next = pre->next;
            pre->next = newtask;
        }
    }

     cout << "\nScheduled Tasks (Highest Priority First):\n" << endl;
    task* display = head;
    while (display != NULL) {
        cout << "Task: " << display->name
             << ", Priority: " << display->priority
             << ", Execution Time: " << display->exe_time << " ms\n" << endl;
        display = display->next;
    }

       for (task* i = head; i != NULL; i = i->next) {
        for (task* j = i->next; j != NULL; j = j->next) {
            if (i->exe_time > j->exe_time) {
                // Swap node data
                swap(i->name, j->name);
                swap(i->priority, j->priority);
                swap(i->exe_time, j->exe_time);
            }
        }
    }

     cout << "\nExecuting Tasks according to execution time(lower execution time will have higher priority):\n" << endl;
    temp = head;
    while (temp != NULL) {
        cout << "Executing Task '" << temp->name 
             << "' : " << temp->exe_time << " ms...\n" << endl;
        temp = temp->next;
    }

    cout << "All tasks executed." << endl;
    return 0;
}

