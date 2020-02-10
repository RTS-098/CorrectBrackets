#include <iostream>

using namespace std;

int positon(string line, char search)
{
    
    int i = 0;
    while (line[i] != search && i<=line.size())
    {
        i++;
    }
    return i;

}

bool check(string line, char search) {

    int i = 0;
    while (line.size()<=i)
    {
        if (line[i]==search)
        {
            return true;
        }
        i++;
    }
    return false;

}

string remove(string line,int pos)
{
    string newstr = line;
    if (pos!=0)
    {
        for (int i = pos; i <= line.size(); i++)
        {
            if (newstr[i] != '\0')
            {
                newstr[i - 1] = newstr[i];
            }
            else newstr[i - 1] = '\0';

        }
    }
    else {
        for (int i = pos; i <= line.size(); i++)
        {
            if (newstr[i] != '\0')
            {
                newstr[i] = newstr[i + 1];
            }
            else newstr[i - 1] = '\0';

        }
    }
    newstr.resize(line.size() - 1);
    return newstr;


}


int main()
{
    string line;
    cin >> line;
    int n = line.size();
    //check if it starts with )
    if (line[0] ==')')
    {
        cout << "False."<<endl;
    }
    else {
        while (line.size() >=0)
        {
            if (check(line, '('))
            {
                int first = positon(line, '(');
                line = remove(line, first);
            }
           
            if (check(line, ')'))
            {
                int last = positon(line, ')');
                line = remove(line, last);
            }              
            if (check(line, '(') == false || check(line, ')') == false)
                break;

            cout << line << endl;
            
        }
    }
    if (line.size()>=1)
    {
        cout << "False." << endl;
    }
    else
    {
        cout << "True." << endl;
    }
    
    return 0;
}

