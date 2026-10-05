#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct Customer {
    string id;
    string name;
    string serviceType;
    int arrivalTime;
    int processingTime; // pj
    int waitingWeight;  // wj
};
struct CustomerNode {
    Customer data;
    CustomerNode* next;
    CustomerNode(Customer c) {
        data = c;
        next = NULL;
    }
};
CustomerNode* head = NULL;
struct Action {
    string type;
    Customer customer;
};
struct StackNode {
    Action data;
    StackNode* next;
    StackNode(Action a) {
        data = a;
        next = NULL;
    }
};
StackNode* topStack = NULL;
void push(Action a) {
    StackNode* p = new StackNode(a);
    p->next = topStack;
    topStack = p;
}
bool isStackEmpty() {
    return topStack == NULL;
}
Action pop() {
    Action a;
    a.type = "NONE";
    if (isStackEmpty())
        return a;
    StackNode* temp = topStack;
    a = temp->data;
    topStack = topStack->next;
    delete temp;
    return a;
}

struct QueueNode {
    Customer data;
    QueueNode* next;
    QueueNode(Customer c) {
        data = c;
        next = NULL;
    }
};
QueueNode* frontQ = NULL;
QueueNode* rearQ = NULL;
void enqueue(Customer c) {
    QueueNode* p = new QueueNode(c);

    if (rearQ == NULL) {
        frontQ = rearQ = p;
    } else {
        rearQ->next = p;
        rearQ = p;
    }
}
void dequeue() {
    if (frontQ == NULL) {
        cout << "Queue is empty!\n";
        return;
    }
    QueueNode* temp = frontQ;
    cout << "\nServing Customer:\n";
    cout << "ID: " << temp->data.id << endl;
    cout << "Name: " << temp->data.name << endl;
    frontQ = frontQ->next;
    if (frontQ == NULL)
        rearQ = NULL;
    delete temp;
}
void displayQueue() {
    if (frontQ == NULL) {
        cout << "Queue empty!\n";
        return;
    }
    QueueNode* p = frontQ;
    cout << "Queue: ";
    while (p != NULL) {
        cout << p->data.id;
        if (p->next != NULL)
            cout << " -> ";
        p = p->next;
    }
    cout << endl;
}
Customer inputCustomer() {
    Customer c;
    cout << "ID: ";
    cin >> c.id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, c.name);
    cout << "Service Type: ";
    getline(cin, c.serviceType);
    cout << "Arrival Time: ";
    cin >> c.arrivalTime;
    cout << "Processing Time (pj): ";
    cin >> c.processingTime;
    cout << "Waiting Weight (wj): ";
    cin >> c.waitingWeight;
    return c;
}
void addCustomer() {
    Customer c = inputCustomer();
    CustomerNode* newNode = new CustomerNode(c);
    if (head == NULL) {
        head = newNode;
    } else {
        CustomerNode* p = head;

        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
    Action a;
    a.type = "ADD";
    a.customer = c;
    push(a);
    cout << "Added successfully!\n";
}
CustomerNode* findCustomer(string id) {
    CustomerNode* p = head;
    while (p != NULL) {
        if (p->data.id == id)
            return p;
        p = p->next;
    }
    return NULL;
}
void searchCustomer() {
    string id;
    cout << "Enter ID: ";
    cin >> id;
    CustomerNode* p = findCustomer(id);
    if (p == NULL) {
        cout << "Customer not found!\n";
        return;
    }
    cout << "\nCustomer Information\n";
    cout << "ID: " << p->data.id << endl;
    cout << "Name: " << p->data.name << endl;
    cout << "Service: " << p->data.serviceType << endl;
    cout << "Arrival Time: " << p->data.arrivalTime << endl;
    cout << "Processing Time: " << p->data.processingTime << endl;
    cout << "Waiting Weight: " << p->data.waitingWeight << endl;
}
void updateCustomer() {
    string id;
    cout << "Enter ID: ";
    cin >> id;
    CustomerNode* p = findCustomer(id);
    if (p == NULL) {
        cout << "Customer not found!\n";
        return;
    }
    Action a;
    a.type = "UPDATE";
    a.customer = p->data;
    push(a);
    cin.ignore();
    cout << "New Name: ";
    getline(cin, p->data.name);
    cout << "New Service Type: ";
    getline(cin, p->data.serviceType);
    cout << "New Arrival Time: ";
    cin >> p->data.arrivalTime;
    cout << "New Processing Time: ";
    cin >> p->data.processingTime;
    cout << "New Waiting Weight: ";
    cin >> p->data.waitingWeight;
    cout << "Updated successfully!\n";
}

void deleteCustomerByID(string id) {
    CustomerNode* p = head;
    CustomerNode* prev = NULL;
    while (p != NULL) {
        if (p->data.id == id) {
            if (prev == NULL)
                head = p->next;
            else
                prev->next = p->next;

            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}
void displayCustomers() {
    if (head == NULL) {
        cout << "No customers!\n";
        return;
    }
    CustomerNode* p = head;
    while (p != NULL) {
        cout << "\n-------------------\n";
        cout << "ID: " << p->data.id << endl;
        cout << "Name: " << p->data.name << endl;
        cout << "Service: " << p->data.serviceType << endl;
        cout << "Arrival: " << p->data.arrivalTime << endl;
        cout << "Processing: " << p->data.processingTime << endl;
        cout << "Weight: " << p->data.waitingWeight << endl;

        p = p->next;
    }
}
double ratio(Customer c) {
    return (double)c.waitingWeight / c.processingTime;
}
void sortByRatio() {
    if (head == NULL)
        return;
    for (CustomerNode* i = head; i != NULL; i = i->next) {
        for (CustomerNode* j = i->next; j != NULL; j = j->next) {
            if (ratio(i->data) < ratio(j->data)) {
                Customer temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    cout << "Sorted successfully!\n";
}
void undo() {
    if (isStackEmpty()) {
        cout << "Nothing to undo!\n";
        return;
    }
    Action a = pop();
    if (a.type == "ADD") {
        deleteCustomerByID(a.customer.id);
        cout << "Undo ADD successful!\n";
    }
    else if (a.type == "UPDATE") {
        CustomerNode* p = findCustomer(a.customer.id);
        if (p != NULL)
            p->data = a.customer;
        cout << "Undo UPDATE successful!\n";
    }
}
void report() {
    int totalCustomers = 0;
    CustomerNode* p = head;
    while (p != NULL) {
        totalCustomers++;
        p = p->next;
    }
    int waitingCustomers = 0;
    QueueNode* q = frontQ;
    while (q != NULL) {
        waitingCustomers++;
        q = q->next;
    }
    cout << "\n========== REPORT ==========\n";
    cout << "Total Customers : " << totalCustomers << endl;
    cout << "Waiting Customers : " << waitingCustomers << endl;
    cout << "============================\n";
}
int main() {
    int choice;
    do {
        cout << "\n===== SMART SERVICE DESK =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Display Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Update Customer\n";
        cout << "5. Add Customer To Queue\n";
        cout << "6. Serve Next Customer\n";
        cout << "7. Display Queue\n";
        cout << "8. Sort by wj/pj\n";
        cout << "9. Undo\n";
        cout << "10. Report\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            displayCustomers();
            break;
        case 3:
            searchCustomer();
            break;
        case 4:
            updateCustomer();
            break;
        case 5: {
            string id;
            cout << "Enter customer ID: ";
            cin >> id;
            CustomerNode* p = findCustomer(id);
            if (p != NULL) {
                enqueue(p->data);
                cout << "Added to queue!\n";
            }
            else {
                cout << "Customer not found!\n";
            }
            break;
        }
        case 6:
            dequeue();
            break;
        case 7:
            displayQueue();
            break;
        case 8:
            sortByRatio();
            break;
        case 9:
            undo();
            break;
        case 10:
            report();
            break;
        case 0:
            cout << "Program ended!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}