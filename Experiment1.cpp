#include <iostream>
using namespace std;


int getLength(char str[])
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}


void checkNumeric()
{
    char s[100];
    cout << "Enter input: ";
    cin >> s;
    
    int len = getLength(s);
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            cout << "not numeric" << endl;
            return;
        }
    }
    cout << "numeric constant" << endl;
}


void findOperators()
{
    char s[100];
    cout << "Enter input: ";
    cin >> s;
    
    int len = getLength(s);
    int i = 1;
    bool found = false;
    
    for (int j = 0; j < len; j++) {
        if (s[j] == '+' || s[j] == '-' || s[j] == '*' || 
            s[j] == '/' || s[j] == '%' || s[j] == '=') {
            cout << "operator" << i << ": " << s[j] << endl;
            i++;
            found = true;
        }
    }
    if (!found) {
        cout << "No operators found" << endl;
    }
}


void checkComment()
{
    char line[100];
    cout << "Enter a comment line: ";
    cin >> line;
    
    int len = getLength(line);
    
    if (len >= 2 && line[0] == '/' && line[1] == '/')
        cout << "The comment line is valid" << endl;
    else
        cout << "The comment line is invalid" << endl;
}


void checkIdentifier()
{
    char s[100];
    cout << "Enter a string to check: ";
    cin >> s;
    
    int len = getLength(s);
    
    if (len == 0) {
        cout << "Invalid Identifier - Empty string" << endl;
        return;
    }
    
    if (!((s[0] >= 'A' && s[0] <= 'Z') || 
          (s[0] >= 'a' && s[0] <= 'z') || 
          s[0] == '_')) {
        cout << "Invalid Identifier - First character must be alphabet or underscore" << endl;
        return;
    }
    
    for (int i = 1; i < len; i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || 
              (s[i] >= 'a' && s[i] <= 'z') || 
              (s[i] >= '0' && s[i] <= '9') || 
              s[i] == '_')) {
            cout << "Invalid Identifier - Characters must be alphanumeric or underscore" << endl;
            return;
        }
    }
    
    cout << "Valid Identifier" << endl;
}


void findAverage()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    if (size <= 0) {
        cout << "Invalid array size!" << endl;
        return;
    }
    
    int arr[100];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    double average = (double)sum / size;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
}


void findMinMax()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    if (size <= 0) {
        cout << "Invalid array size!" << endl;
        return;
    }
    
    int arr[100];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    cout << "Minimum value = " << min << endl;
    cout << "Maximum value = " << max << endl;
}


void concatNames()
{
    char firstName[50], lastName[50], fullName[100];
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    
    int len1 = getLength(firstName);
    int len2 = getLength(lastName);
    
    int i = 0;
    while (i < len1) {
        fullName[i] = firstName[i];
        i++;
    }
    
    fullName[i] = ' ';
    i++;
    
    int j = 0;
    while (j < len2) {
        fullName[i] = lastName[j];
        i++;
        j++;
    }
    
    cout << "First Name = \"" << firstName << "\"" << endl;
    cout << "Last Name = \"" << lastName << "\"" << endl;
    cout << "Full Name = \"";
    for (int k = 0; k < i; k++) {
        cout << fullName[k];
    }
    cout << "\"" << endl;
}

int main()
{
    int choice;
    cout << "1. Check if input is numeric" << endl;
    cout << "2. Find operators in input" << endl;
    cout << "3. Check if input is a valid comment" << endl;
    cout << "4. Check if input is an Identifier" << endl;
    cout << "5. Find average of array elements" << endl;
    cout << "6. Find min and max of array elements" << endl;
    cout << "7. Concatenate first and last name" << endl;
    cout << "Enter your choice (1-7): ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            checkNumeric();
            break;
        case 2:
            findOperators();
            break;
        case 3:
            checkComment();
            break;
        case 4:
            checkIdentifier();
            break;
        case 5:
            findAverage();
            break;
        case 6:
            findMinMax();
            break;
        case 7:
            concatNames();
            break;
        default:
            cout << "Invalid choice! Please select 1-7." << endl;
    }
    
    return 0;
}
