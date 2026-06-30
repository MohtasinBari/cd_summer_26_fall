#include <iostream>
using namespace std;

int main() {

    char s[] = "cout << a + b % 60 * 2.5";
    int i = 0;
  while (s[i] != '\0') 
  {

        if (s[i] == ' ') {
            i++;
            continue;
        }
  if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {

            char token[20];
            int j = 0, dot = 0;

        while ((s[i] >= 'a' && s[i] <= 'z') ||
                   (s[i] >= '0' && s[i] <= '9') ||
                    s[i] == '.') {

                if (s[i] == '.')
                    dot++;

                token[j++] = s[i++];
            }

            token[j] = '\0';

            if (token[0] == 'c')
                cout << token << " -> Keyword\n";
            else if (token[0] >= '0' && token[0] <= '9') {
                if (dot == 0)
                    cout << token << " -> Integer\n";
                else
                    cout << token << " -> Float\n";
            }
            else
                cout << token << " -> Identifier\n";
        }
        else {

            if (s[i] == '<' && s[i + 1] == '<') {
                cout << "<< -> Operator\n";
                i += 2;
            }
            else {
                cout << s[i] << " -> Operator\n";
                i++;
            }
        }
    }
         
    return 0;

}
