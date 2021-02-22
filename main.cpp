#include <bits/stdc++.h>
#include <fstream>
using namespace std;
bool isPresent(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '@')
            return true;
    }
    return false;
}
int checkExistingUsers(string email)
{
    fstream file;
    string Email;
    file.open("userEmail.txt",ios::in);
    int i=1;
    while(file>>Email)
    {
        if(Email == email)
        {
            file.close();
            return i;
        }
        i++;
    }
    file.close();
    return 0;
}
int checkPassword(string password,int n)
{
    int i=1;
    fstream file;
    string Password;
    file.open("userPassword.txt",ios::in);
    while(file>>Password)
    {
        if(i==n)
        {
            if(Password == password)
            {
                file.close();
                return 1;
            }
            else
            {
                file.close();
                return 0;
            }
        }
        i++;
    }
    file.close();
    return 0;
}
int main(void)
{
    int flag1 = 1;
    while (flag1 == 1)
    {
        int option;
        fstream userEmail;
        fstream userPassword;
        string name, email, password, confirmPassword;
        cout << "\t\tLog In System" << endl;
        cout << "\t\t1.Log In " << endl;
        cout << "\t\t2.Register " << endl;
        cout<<"\t\t3.Exit "<<endl;
        cout << "\t\tEnter Option : ";
        cin >> option;
        if (option == 1)
        {
            cout<<"\t\tEnter Email : ";
            cin>>email;
            cout<<"\t\tEnter Password : ";
            cin>>password;
            int serialNo = checkExistingUsers(email);
            // cout<<serialNo<<endl;
            if(serialNo!=0 && checkPassword(password,serialNo)==1)
            {
                cout<<"\t\tLog In Successfull "<<endl;
            }
            else 
            {
                cout<<"\t\tInvalid Credentials,Try Again "<<endl;
            }
        }
        else if (option == 2)
        {
            int flag2 = 0;
            while (flag2 == 0)
            {
                cout << "\t\tEnter Name : ";
                cin >> name;
                cout << "\t\tEnter Email : ";
                cin >> email;
                if (!isPresent(email))
                {
                    cout << "\t\tEmail do not conatain a'@',Enter a valid email,Try Again" << endl;
                }
                else if(checkExistingUsers(email)!=0)
                {
                    cout<<"\t\tUser Email Already Exist !!!,Try Again"<<endl;
                }
                else
                {
                    cout << "\t\tEnter Password : ";
                    cin >> password;
                    cout << "\t\tRe- Enter Password : ";
                    cin >> confirmPassword;
                    if (password == confirmPassword)
                    {
                        userEmail.open("userEmail.txt", ios::app);
                        userEmail << email;
                        userEmail << "\n";
                        userEmail.close();
                        userPassword.open("userPassword.txt", ios::app);
                        userPassword << password;
                        userPassword << "\n";
                        userPassword.close();
                        cout<<"\t\tSuccessfull"<<endl;
                        flag2 = 1;
                    }
                    else
                    {
                        cout << "\t\tPasswords Do not match,Try Again" << endl;
                    }
                }
            }
        }
        else if(option==3)
        {
            break;
        }
        else 
        {
            cout<<"\t\tInvalid Entry,Try Again"<<endl;
        }
    }
    return 0;
}
