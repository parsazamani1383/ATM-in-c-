#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

struct member
{
    char name_user[100];
    long long int number_bunck;
    char password[5];
    int cash;
} m[100];

struct admin
{
    char name_user[6] = "admin";
    char password[5] = "2024";
} a;

// Function prototypes:
void f1_menu();
void f2_admin(admin);
void f3_member();
void f_menu_admin();
void open_account();
member* open_file_member(int&);
void show_all_user();
void serch_for_accont();
void open_apdate_an_acont();
void updte_acont(int);
void chang_username(int);
void Change_password(int);
void lncrease_balance(int);
void f_menu_member(int);
void Account_balance(int);
void Cash_Transfer(int);
void Cash_withdrawal(int);
void Change_password_member (int);

int main()
{
    while (true)
    {
        system("cls");
        
        f1_menu();
        int y;
        cin >> y;
        switch (y)
        {
            case 1:
                f2_admin(a);
                break;
            case 2:
                f3_member();
                break;
            case 3:
                system("cls");
                cout << "\n****| Goodbye |****\n";
                cout << "enter...";
                getch();

                return 0;
            default:
                cout << "\n\n******| Error |*******\n\n";
                cout << "enter...";
                getch();
                break;
        }
    }
}

void f1_menu()
{
    cout << "  ++| Welcome to ATM |++ \n\n ";
    cout << "***************************\n";
    cout << "  1_ Login as attendant :\n";
    cout << "  2_ Login as user :\n";
    cout << "  3_ Exit  \n\n ";
    cout << "***************************\n";
    cout << " Please enter your request:";
}

void f2_admin(admin a)
{
    string username, password;
    cout << "\n#################################\n\n";
    cout << "  enter your username: ";
    cin >> username;
    cout << "  enter your password: ";
    cin >> password;
    cout << "\n#################################\n";

    if (username == a.name_user && password == a.password)
    {
    	system("cls");
        f_menu_admin();
    }
    else
    {
        cout << " invalid username or password.\n please try again.\n";
        cout << "\n#################################\n\n";
    }
    
}

void f3_member()
{
    int j;
    int index=0;
    member* m = open_file_member(index);
    string username, password;
    bool valid_login = false;

    cout << "\n#################################\n\n";
    cout << "enter your username:";
    cin >> username;
    cout << "enter your password:";
    cin >> password;
    cout << "\n#################################\n\n";

    for (int i = 0; i < 100; i++)
    {
        if (username == m[i].name_user && password == m[i].password)
        {
            valid_login = true;
            j=i;
            break;
        }
    }

    if (valid_login)
    {
        f_menu_member(j);
        // Perform member-specific operations here.
    }
    else
    {
        cout << " Invalid username or password.\n please try again.";
        cout << "\n#################################\n\n";
    }
}

void f_menu_admin()
{
    cout << "\n******************************";
    cout << "\n1-Open an account\n";
    cout << "2-Update an account\n";
    cout << "3-Show all users\n";
    cout << "4-Search for an account\n";
    cout << "5-Back to the main menu\n";
    cout << "******************************\n";
    int x;
    cout << " Please enter your request:";
   cin >> x;
    cout << "\n******************************\n\n";

    switch (x)
    {
        case 1:
            open_account();
            break;
        case 2:
            open_apdate_an_acont();
            break;
        case 3:
            show_all_user();
            break;
        case 4:
            serch_for_accont();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice.\n";
            cout << "enter...";
            getch();
            
            system("cls");
            f_menu_admin();
    }
}

void open_account()
{
    int index = 0, n = 0;

    member* m = open_file_member(index);

    string username, password;
    long long int number;
    int cash;

    cout << "enter user name: ";
    cin >> username;
    cout << "enter a (10-digit) account number: ";
    cin >> number;

    for (int i = 0; i < index ; i++)
    {
        if (username == m[i].name_user || number == m[i].number_bunck)
        {
        	cout <<"\n*********************************\n";
            cout << "***| error :already entered |***";
            cout <<"\n*********************************\n";
            cout << "enter";
            
            getch();
            system("cls");
            f_menu_admin();
        }
    }

    cout << "enter a (4-digit) password: ";
    cin >> password;
    cout << "enter money $: ";
    cin >> cash;

    ofstream file("ATM.txt", ios::app);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***";
        cout <<"\n**************************************\n";
        return;
    }
    file << username << "  " << number << "  " << password << "  " << cash << endl;
    file.close();

    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();
    
    system("cls");
    f_menu_admin();
}

member* open_file_member(int& index)
{
    ifstream file("ATM.txt",ios::app);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***\n";
        cout <<"\n**************************************\n";
        return 0;
    }

    while (file >> m[index].name_user >> m[index].number_bunck >> m[index].password >> m[index].cash)
        index++;

    file.close();

    return m;
}

void show_all_user()
{
    int index=0;
    
    member* m = open_file_member(index);

    system("cls");
    for (int i=0 ; i < index ; i++)
    {
        cout << "user name <" << i+1 <<"> : "<< m[i].name_user <<endl;
        cout << "--------------------------\n";
    }

    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();
    
    system("cls");
    f_menu_admin();

}

void serch_for_accont()
{
    string username;
    cout << "enter a user name: ";
    cin >> username;
    
    int index=0 ,p=0;
    member* m = open_file_member(index);
    for(int i=0 ; i < index ; i++)
    {
        if(username == m[i].name_user)
        {
            cout <<"------------------------------\n";
            cout << "acount number: " << m[i].number_bunck << endl;
            cout << "password: " << m[i].password << endl;
            cout << "-----------------------------\n";
            p=1;
        } 
    } 
    if (p==0)
        {
            cout << "\n********************************\n";
            cout << "***| there is no such user |***";
            cout << "\n**********************************\n";
        }

    cout << "enter...";  
    getch();

    system("cls");
    f_menu_admin();

}

void open_apdate_an_acont()
{
    int index=0;
    member* m = open_file_member(index);

    string username, password;
    bool valid_login = false;
    int s;
    
    cout << "\n#################################\n\n";
    cout << "enter your username:";
    cin >> username;
    cout << "enter your password:";
    cin >> password;
    cout << "\n#################################\n\n";

    for (int i = 0; i < 100; i++)
    {
        if (username == m[i].name_user && password == m[i].password)
        {
            valid_login = true;
            s=i;
            break;
        }
    }
    if (valid_login)
    {
        updte_acont(s);
    }
    else
    {
        cout <<"\n#################################\n\n";
        cout << "there is no such account.";
        cout << "\n#################################\n\n";
        cout <<"enter...";
        getch();

        system("cls");
        f_menu_admin();
    }

}

void updte_acont(int s)
{
    int f;
    f=s;
    int x;

    cout << "\n************************\n";
    cout << "1) Change username.\n";
    cout << "2) Change password.\n";
    cout << "3) Increase balance.\n";
    cout << "4) Back to main menu.";
    cout << "\n************************\n";
    cout << " Please enter your request:";
    cin >> x ;
    cout << "\n************************\n";

    switch(x)
    {
        case 1: 
            chang_username(f);
            break;

        case 2:
            Change_password(f);
            break;    
        
        case 3:
            lncrease_balance(f);
            break;

        case 4:
            return;    

    }

}

void chang_username(int f)
{
    system("cls");
    string username;
    int index=0;
    
    member* m= open_file_member(index);
    
    cout <<"\n enter new username: ";
    cin >> username;
    
    int k=0;
    for (int i=0 ; i < index ; i++)
    {
        if (username == m[i].name_user)
        {
            cout << "\n********************************\n";
            cout << "this username is already entred.";
            cout << "\n********************************\n";
            cout << "enter...";
            getch();
            return;
        }
        
    }

    strcpy(m[f].name_user, username.c_str());

    ofstream file("ATM.txt", ios::out);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***";
        cout <<"\n**************************************\n";
        return;
    }

    for(int i=0 ; i < index ; i++)
    {
        file << m[i].name_user << "  " << m[i].number_bunck << "  " << m[i].password << "  " << m[i].cash << endl;
    }

    file.close();
    
    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();

    system("cls");
    f_menu_admin();

}

void Change_password(int f)
{
    system("cls");
    char new_password[5];
    int index=0;

    member* m= open_file_member(index);

    cout << "\n enter new password: ";
    cin >> new_password;

    strcpy(m[f].password , new_password);

    ofstream file("ATM.txt", ios::out);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***";
        cout <<"\n**************************************\n";
        return;
    }

    for(int i=0 ; i < index ; i++)
    {
        file << m[i].name_user << "  " << m[i].number_bunck << "  " << m[i].password << "  " << m[i].cash << endl;
    }
    file.close();
    
    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();
    
    system("cls");
    f_menu_admin();
    
}

void lncrease_balance(int f)
{
	system("cls");
	
    int index=0;
    member* m = open_file_member(index);

    int cash;
    cout << "\n enter the amount of money $: ";
    cin >> cash;

    m[f].cash+=cash;
    
    ofstream file("ATM.txt", ios::out);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***";
        cout <<"\n**************************************\n";
        return;
    }

    for(int i=0 ; i < index ; i++)
    {
        file << m[i].name_user << "  " << m[i].number_bunck << "  " << m[i].password << "  " << m[i].cash << endl;
    }
    file.close();
    
    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();
    
    system("cls");
    f_menu_admin();

}
///////////////////////////////////////////////////////////
void f_menu_member(int j)
{
	system("cls");
    cout << "\n******************************\n";
    cout << "1-Account balance\n";
    cout << "2-Cash Transfer\n";
    cout << "3-Cash withdrawal\n";
    cout << "4-Change password\n";
    cout << "5-Back to the main menu\n";
    cout << "\n******************************\n";

    int x;
    cout << " Please enter your request:";
    cin >> x;

    switch(x)
    {
        case 1:
            Account_balance(j);
            break;

        case 2:
           Cash_Transfer(j);
           break;

        case 3:
           Cash_withdrawal(j);
           break;

        case 4:
           Change_password_member (j);

        case 5:
            return;

        default:
            cout << "Invalid choice.\n";
            cout << "enter...";
            getch();
            
            system("cls");
            return;                

    }
}

void Account_balance(int j)
{
    int index=0;
    member* m = open_file_member(index);
    
    system("cls");
    cout << "\n---------------------------\n";
    cout << "Account balance: " << m[j].cash <<"$" ;
    cout << "\n---------------------------\n";
    
    cout <<"enter...";
    getch();
    
    system("cls");
    f_menu_member(j);
    
}

void Cash_Transfer(int j)
{
    int index=0 , p;
    member* m = open_file_member(index);

    string username;
    int cash;
    
    cout << "\n---------------------------\n";
    cout << "enter recipient username: ";
    cin >> username;
    cout << "enter th amount $: ";
    cin >> cash;
    cout << "\n---------------------------\n";

    for(int i=0 ; i < index ; i++)
    {
        if(m[i].name_user == username)
        {
            p=i;
            break;
        }
        else
        {
        	p=-1;
        }
    }
    if(p==-1)
    {
        cout << "\n***| there is no such user |***\n\n";
        cout << "enter...";
        getch();

        system("cls");
        f_menu_member(j);
    }

    if ( m[j].cash >= cash)
    {
        m[j].cash -= cash;
        m[p].cash += cash;
    }
    else
    {
    	cout << "***| error: The acount balance is insufficient. |***\n";
    	
        cout << "enter...";
        getch();
        return;
	}

    ofstream file("ATM.txt", ios::out);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***";
        cout <<"\n**************************************\n";
        return;
    }

    for(int i=0 ; i < index ; i++)
    {
        file << m[i].name_user << "  " << m[i].number_bunck << "  " << m[i].password << "  " << m[i].cash << endl;
    }
    file.close();

    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();
    
    system("cls");
    f_menu_member(j);

}

void Cash_withdrawal(int j)
{
    int index=0;
    member* m = open_file_member(index);

    int cash;
    cout << "\n------------------------------\n";
    cout << "enter Cash withdrawal: ";
    cin >> cash;
    cout << "\n------------------------------\n";

    if (m[j].cash >= cash)
    {
        m[j].cash -= cash;
    }
    else 
    {
        cout << "\n\n***| Insufficient inventory |***\n\n";
        cout << "enter...";
        getch();
        return;
    }
    
    ofstream file("ATM.txt", ios::out);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***";
        cout <<"\n**************************************\n";
        return;
    }

    for(int i=0 ; i < index ; i++)
    {
        file << m[i].name_user << "  " << m[i].number_bunck << "  " << m[i].password << "  " << m[i].cash << endl;
    }
    file.close();

    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();
    
    system("cls");
    f_menu_member(j);
}

void Change_password_member (int j)
{
    int index=0;
    member* m = open_file_member(index);
    
    char password[5] , newpassword[5];
    cout << "\n---------------------------\n";
    cout << "enter the current password: ";
    cin >> password;
    cout << "\n---------------------------\n";

    if ( !strcmp(m[j].password , password) )
    {
        cout << "\n---------------------------\n";
        cout << "\nenter new password: ";
        cin >> newpassword;
        cout << "\n---------------------------\n";

        strcpy(m[j].password , newpassword );
    }
    else 
    {
        cout << "\n***| error: wrong password. |***\n";
        cout << "enter...";
        getch();

        system("cls");
        return;
        
    }

    ofstream file("ATM.txt", ios::out);
    if (!file)
    {
    	cout <<"\n**************************************\n";
        cout << "***| error: the operation failed |***";
        cout <<"\n**************************************\n";
        return;
    }

    for(int i=0 ; i < index ; i++)
    {
        file << m[i].name_user << "  " << m[i].number_bunck << "  " << m[i].password << "  " << m[i].cash << endl;
    }
    file.close();

    cout << "\n\n***| Done |***\n\n";
    cout << "enter...";
    getch();
    
    system("cls");
    f_menu_member(j);

}
