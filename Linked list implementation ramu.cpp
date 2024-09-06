#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int row;    // Row index of the non-zero element
    int col;    // Column index of the non-zero element
    int value;  // Non-zero element
    Node* next; // Pointer to the next node
};

// Class for sparse matrix using linked list
class SparseMatrix {
private:
    Node* head; // Head of the linked list

public:
    // Constructor to initialize the linked list
    SparseMatrix() {
        head = nullptr;
    }

    // Function to create a new node and insert it at the end of the linked list
    void insert(int row, int col, int value) {
        Node* newNode = new Node;
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode; // If the list is empty, set the new node as the head
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next; // Traverse to the end of the list
            }
            temp->next = newNode; // Insert new node at the end
        }
    }

    // Function to display the linked list representation
    void display() {
        if (head == nullptr) {
            cout << "Sparse matrix is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "\nSparse Matrix in Linked List form: " << endl;
        while (temp != nullptr) {
            // Display the row, column, value, and address of the current node
            cout << "Row: " << temp->row << ", Column: " << temp->col << ", Value: " << temp->value
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // Destructor to free the memory
    ~SparseMatrix() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SparseMatrix sm;
    int rows, cols, value;

    // Input number of rows and columns for the matrix
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    cout << "\nEnter the elements of the matrix (enter 0 for zero elements):\n";

    // Input matrix values row by row
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element at [" << i << "][" << j << "]: ";
            cin >> value;

            // Insert non-zero elements into the linked list
            if (value != 0) {
                sm.insert(i, j, value);
            }
        }
    }

    // Display the linked list representation of the sparse matrix
    sm.display();

    return 0;
}
