#include <iostream>
#include <cstring>
using namespace std;
void Print_StringArray(string array[], int n); // print array function call
int main()
{
    int n = 0, p = 0, m = 0;
    cin >> n; // input of number of rows
    cin >> m; // input of number of columns
    string *inputMatrix = new string[n];
    for (int i = 0; i < n; i++) // input of the inputMatrix
    {
        // cout << "Enter string number " << i + 1 << endl;
        fflush(stdin);
        getline(cin, inputMatrix[i]);
        fflush(stdin);
    }
    fflush(stdin);
    cin >> p;
    cout << p << endl;
    string *wordArray = new string[p];
    for (int i = 0; i < p; i++) // input of the words to be found
    {
        fflush(stdin);
        getline(cin, wordArray[i]);
        fflush(stdin);
    }

    // cout << "\nPrinting out the word matrix\n";
    // Print_StringArray(inputMatrix, n); // print array function call

    // cout << "\nPrinting out the words\n";
    // Print_StringArray(wordArray, p); // print array function call
    for (int i = 0; i < p; i++)
    {
        int X_index = -9999, Y_index = -99999, count = 0;
        char Direction = 'X';
        // cout << "Search word no." << i + 1 << endl;
        for (int j = 0; j < wordArray[i].size(); j++)
        {
            /* code */

            // For right direction
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < inputMatrix[k].size(); l++)
                {
                    // cout << "checking " << wordArray[i][l] << " and " << inputMatrix[k][l] << endl;
                    if (wordArray[i][l] == inputMatrix[k][l])
                    {  
                        
                        // cout<<"\nIt remained outside\n";
                        if (count == 0)
                        {
                            /* code */
                            // cout<<"\nIt came inside\n";
                            X_index = k;
                            Y_index = l;
                            Direction = 'R';
                        }
                        count++;
                    }
                }
                if (count == wordArray[i].size())
                {
                    cout << X_index << " " << Y_index << " " << Direction << endl;
                    break;
                }
            }
            //for left direction
            for (int k = 0; k < n; k++)
            {
                for (int l = inputMatrix[k].size(); l > 0 ; l--)
                {
                    // cout << "checking " << wordArray[i][l] << " and " << inputMatrix[k][l] << endl;
                    if (wordArray[i][l] == inputMatrix[k][l])
                    {  
                        
                        // cout<<"\nIt remained outside\n";
                        if (count == 0)
                        {
                            /* code */
                            // cout<<"\nIt came inside\n";
                            X_index = k;
                            Y_index = l;
                            Direction = 'L';
                        }
                        count++;
                    }
                }
                if (count == wordArray[i].size())
                {
                    cout << X_index << " " << Y_index << " " << Direction << endl;
                    break;
                }
                
            }
            //for up direction
            for (int k = 0; k < n; k++)
            {
                for (int l =0; l>0 ; l--)
                {
                    // cout << "checking " << wordArray[i][l] << " and " << inputMatrix[k][l] << endl;
                    if (wordArray[i][l] == inputMatrix[k][l])
                    {  
                        
                        // cout<<"\nIt remained outside\n";
                        if (count == 0)
                        {
                            /* code */
                            // cout<<"\nIt came inside\n";
                            X_index = k;
                            Y_index = l;
                            Direction = 'U';
                        }
                        count++;
                    }
                }
                if (count == wordArray[i].size())
                {
                    cout << X_index << " " << Y_index << " " << Direction << endl;
                    break;
                }
                
            }
            //for Down Direction
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; m>l ; l++)
                {
                    // cout << "checking " << wordArray[i][l] << " and " << inputMatrix[k][l] << endl;
                    if (wordArray[i][l] == inputMatrix[k][l])
                    {  
                        
                        // cout<<"\nIt remained outside\n";
                        if (count == 0)
                        {
                            /* code */
                            // cout<<"\nIt came inside\n";
                            X_index = k;
                            Y_index = l;
                            Direction = 'L';
                        }
                        count++;
                    }
                }
                if (count == wordArray[i].size())
                {
                    cout << X_index << " " << Y_index << " " << Direction << endl;
                    break;
                }
                
            }

            
        }
    }
}
void Print_StringArray(string array[], int n) // print array function
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; array[i][j] != '\0'; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}