//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Christian Drew
// Description : ABCU Course Advising Program - Binary Search Tree
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// This holds information about one course
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// One node in the binary search tree
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }
};

// The Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

    void addNode(Node* node, Course course) {
        if (course.courseNumber < node->course.courseNumber) {
            if (node->left == nullptr) {
                node->left = new Node(course);
            } else {
                addNode(node->left, course);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node(course);
            } else {
                addNode(node->right, course);
            }
        }
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->course.courseNumber << ": " << node->course.courseTitle << endl;
            inOrder(node->right);
        }
    }

public:
    BinarySearchTree() { root = nullptr; }

    void Insert(Course course) {
        if (root == nullptr) {
            root = new Node(course);
        } else {
            if (Search(course.courseNumber).courseNumber.empty()) {
                addNode(root, course);
            }
        }
    }

    void PrintAll() {
        inOrder(root);
    }

    Course Search(string courseNumber) {
        Node* current = root;
        while (current != nullptr) {
            if (courseNumber == current->course.courseNumber) {
                return current->course;
            } else if (courseNumber < current->course.courseNumber) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        Course empty;
        return empty;
    }
};

// Reads the courses.txt file
void loadCourses(string filename, BinarySearchTree& bst) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> parts;

        while (getline(ss, token, ',')) {
            parts.push_back(token);
        }

        if (parts.size() < 2) continue;

        Course course;
        course.courseNumber = parts[0];
        course.courseTitle = parts[1];

        for (size_t i = 2; i < parts.size(); i++) {
            if (!parts[i].empty()) {
                course.prerequisites.push_back(parts[i]);
            }
        }

        bst.Insert(course);
    }
    file.close();
    cout << "Courses loaded successfully." << endl;
}

int main() {
    BinarySearchTree bst;
    string filename;
    int choice = 0;

    cout << "Welcome to ABCU Course Advising System" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "  1. Load Courses\n";
        cout << "  2. Print All Courses (sorted)\n";
        cout << "  3. Print Course Information\n";
        cout << "  9. Exit\n";
        cout << "Enter choice: ";

        // This extra check prevents infinite loop when you type letters instead of numbers
        if (!(cin >> choice)) {
            cin.clear();              // clear the error
            cin.ignore(10000, '\n');  // ignore bad input
            cout << "Invalid option. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Enter filename (or press Enter for courses.txt): ";
            cin.ignore();
            getline(cin, filename);
            if (filename.empty()) filename = "courses.txt";
            loadCourses(filename, bst);
        }
        else if (choice == 2) {
            cout << "\nHere is the list of all courses:\n";
            bst.PrintAll();
        }
        else if (choice == 3) {
            string courseNum;
            cout << "Enter course number (example: CSCI300): ";
            cin >> courseNum;
            Course c = bst.Search(courseNum);
            if (!c.courseNumber.empty()) {
                cout << c.courseNumber << ": " << c.courseTitle << endl;
                if (c.prerequisites.empty()) {
                    cout << "No prerequisites" << endl;
                } else {
                    cout << "Prerequisites: ";
                    for (size_t i = 0; i < c.prerequisites.size(); i++) {
                        cout << c.prerequisites[i] << " ";
                    }
                    cout << endl;
                }
            } else {
                cout << "Course " << courseNum << " was not found." << endl;
            }
        }
        else if (choice == 9) {
            cout << "Good bye." << endl;
            break;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}