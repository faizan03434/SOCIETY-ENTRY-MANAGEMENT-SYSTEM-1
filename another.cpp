#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
//prototype start
string login();
void user(string username,string password,string roles);
void header();
int menu();
void addperson(string name1,string number1,string reference1,string time1,string day1,string vehicle1,string place1, 
    int carnumber1);
void beauty();
void viewpersons();
void addnewuser();
void loginpassword();
void addpersonsintoarray(string name1,string number1,string reference1,string time1,string day1,string vehicle1,string place1,int carnumber1);
void sortByName();
void deletePerson(string targetname);
void savepersons();
void saveusers();
void search(string targetname);
void editPerson(string targetname,string newname,string newnumber,string newreference,string newtime,string newday,string newvehicle,string newplace,int  newcarnumber);
void showStats();
void viewAllUsers();
void loadusers() ;
void loadpersons() ;
string getField(string record, int field);
int gatekeeperMenu();
void countentriestoday(string targetday);
void viewTodayEntries(string targetday);
void preapprovevisitor(string name1,string number1,string reference1,string time1,string day1,string vehicle1,string place1,int carnumber1);
void viewvisitorsinside();
void viewmyvisitors() ;
void editpersondetails(string targetname);

//prototype end

//data structure start
const int TOTAL_ENTRIES=10;
int count=0;
string usernameA[TOTAL_ENTRIES];
string passwordA[TOTAL_ENTRIES];
string rolesA[TOTAL_ENTRIES];
string loginusername=" ";

const int TOTAL_PERSONS=20;
int count_persons=0;
string name[TOTAL_PERSONS];
string number[TOTAL_PERSONS];
string reference[TOTAL_PERSONS];
string time[TOTAL_PERSONS];
string day[TOTAL_PERSONS];
string place[TOTAL_PERSONS];
string vehicle[TOTAL_PERSONS];
int carnumber[TOTAL_PERSONS];

//data structure end

//main function start
int main(){//Main function implementation

    
    user("admin","123","ADMIN");
    user("gatekeeper", "123", "GATEKEEPER");
    user("member", "123", "MEMBER");
    loadusers();
    loadpersons();
    while(true){
        system("cls");
        string data = login();
        
        if( data == "ADMIN"){
            system("cls");
        int adminoption=' ';
        while(true){
            header();
            adminoption = menu();
            if(adminoption==1){
                header();
                string name1,number1,reference1,time1,day1,vehicle1,place1; 
                int carnumber1;
        cout<<"1-Name of entry: ";
cin>>name1;
cout<<"enter the 11-digit contact number: ";
cin>>number1;
if (number1.length() != 11) {
    cout << "Invalid number! It must be exactly 11 digits." << endl;
    beauty();
    continue; 
}
cout<<"2-Enter the reference: ";
cin>>reference1;
cout<<"3-Entry time of entry(morning/afternoon): ";
cin>>time1;
cout<<"4-Entry day: ";
cin>>day1;
cout<<"5-Vehicle type(car/bike): ";
cin>>vehicle1;
cout<<"6-Place of visiting: ";
cin>>place1;
cout<<"7-Enter the car/bike number in 4 digits: ";
cin>>carnumber1;
            addperson(name1,number1,reference1,time1,day1,vehicle1,place1,carnumber1);
            }else if(adminoption==2){
                viewpersons();
            }else if(adminoption==3){
                addnewuser();
            }else if(adminoption==4){
                loginpassword();
            }else if(adminoption==5){
                sortByName();
            }
            else if(adminoption==6){
                string name;
                cout<<"Enter the name to delete ";
                cin>>name;
                deletePerson(name);
            }
            else if(adminoption==7){
                string name;
                cout<<"Enter the name to search ";
                cin>>name;
                search(name);
            }
            else if(adminoption==8){
                string targetname;
                cout<<"Entet the name which you want to edit ";
                cin>>targetname;
                editpersondetails(targetname);

            }
            else if(adminoption==9){
                showStats();
            }
             else if(adminoption==10){
                viewAllUsers();
             }
            else if(adminoption==11){
                break;
            }
            else{
                cout<<"Wrong input . Try again ";
            }
            beauty();

        }//end of the while loop for admin menu
        }
    
    if (data == "GATEKEEPER") {
    system("cls");
    int gateOption = ' ';
    while (true) {
        header();
        gateOption = gatekeeperMenu();
        if (gateOption == 1) {
               string name1,number1,reference1,time1,day1,vehicle1,place1; 
    int carnumber1;
        cout<<"1-Name of entry: ";
cin>>name1;
cout<<"enter the 11-digit contact number: ";
cin>>number1;
if (number1.length() != 11) {
    cout << "Invalid number! It must be exactly 11 digits." << endl;
    beauty();
    continue; 
}
cout<<"2-Enter the reference: ";
cin>>reference1;
cout<<"3-Entry time of entry(morning/afternoon): ";
cin>>time1;
cout<<"4-Entry day: ";
cin>>day1;
cout<<"5-Vehicle type(car/bike): ";
cin>>vehicle1;
cout<<"6-Place of visiting: ";
cin>>place1;
cout<<"7-Enter the car/bike number in 4 digits: ";
cin>>carnumber1;
            addperson(name1,number1,reference1,time1,day1,vehicle1,place1,carnumber1);
        } else if (gateOption == 2) {
            cout<<"Enter the day to view the enteries of the day ";
            string day;
            cin>>day;
            viewTodayEntries(day);
        } else if (gateOption == 3) {
                string name;
                cout<<"Enter the name to search ";
                cin>>name;
            search(name);
        } else if (gateOption == 4) {
            string day;
            cout<<"Enter the day for which you want to count the enteries ";
            cin>>day;
            countentriestoday(day);
        } else if (gateOption == 5) {
            break;
        } else {
            cout << "Wrong input. Try again.\n";
        }
        beauty();
    }//end of while loop for gatekeeper menu
}if (data == "MEMBER") {
    system("cls");
    int memberOption = ' ';
    while (true) {
        header();
        cout << "Member Menu" << endl;
        cout << "1- View my visitor history" << endl;
        cout << "2- View visitors currently inside" << endl;
        cout << "3- View today's entries" << endl;
        cout << "4- Pre-approve a visitor" << endl;
        cout << "5- Logout" << endl;
        cout << "Choose option: ";
        cin >> memberOption;
        if (memberOption == 1) {
            viewmyvisitors();
        } else if (memberOption == 2) {
            viewvisitorsinside();
        } else if (memberOption == 3) {
            cout<<"Enter the day to view the enteries of the day ";
            string day;
            cin>>day;
            viewTodayEntries(day);
        } else if (memberOption == 4) {
            header();
string name1,number1,reference1,time1,day1,vehicle1,place1; 
int carnumber1;
cout<<"1-Name of entry: ";
cin>>name1;
cout<<"enter the 11-digit contact number: ";
cin>>number1;
if (number1.length() != 11) {
    cout << "Invalid number! It must be exactly 11 digits." << endl;
    beauty();
    continue; 
}
cout<<"2-Enter the reference: ";
cin>>reference1;
cout<<"3-Entry time of entry(morning/afternoon): ";
cin>>time1;
cout<<"4-Entry day: ";
cin>>day1;
cout<<"5-Vehicle type(car/bike): ";
cin>>vehicle1;
cout<<"6-Place of visiting: ";
cin>>place1;
cout<<"7-Enter the car/bike number in 4 digits: ";
cin>>carnumber1;
        preapprovevisitor(name1,number1,reference1,time1,day1,vehicle1,place1,carnumber1);
        } else if (memberOption == 5) {
            break;
        } else {
            cout << "Invalid option. Try again."<<endl;
        }
        beauty();
    }//end of while loop for member menu
}
}
}//end of while loop
//main function end
//functionality use
string login()
{
    cout<<"Enter the username "<<endl;
    string username;
    cin>>username;
    cout<<"Enter the password "<<endl;
    string password;
    cin>>password;

    for(int i=0;i<TOTAL_ENTRIES;i++){
        if(usernameA[i]==username && passwordA[i] ==password){
            loginusername =username;
return rolesA[i];
        }
    }\
    loginusername=" ";
    return "Wrong";
}
void user(string username,string password,string roles){
    if(count <TOTAL_ENTRIES){
     usernameA[count] = username;
     passwordA[count] = password;
     rolesA[count] = roles ;
     count++;}
     else{
        cout<<"NO more space to add persons "<<endl;
     }
}
void header(){
cout<<"############################################################################################################"<<endl;
cout<<"##                             SOCIETY  ENTRY MANAGEMENT SYSTEM                                           ##"<<endl;
cout<<"############################################################################################################"<<endl;
}
int menu(){
    cout<<"Main menu"<<endl;
cout<<"SYSTEM FEATURES ..........."<<endl;
cout<<"1-Add person"<<endl;
cout<<"2-view person details"<<endl;
cout<<"3-Add Users"<<endl;
cout<<"4-change password"<<endl;
cout<<"5-Sort the data by name "<<endl;
cout<<"6- Delete persons "<<endl;
cout<<"7- search person by name "<<endl;
cout<<"8- Edit person details "<<endl;
cout<<"9- show status "<<endl;
cout<<"10- View all users "<<endl;
cout<<"11- logout"<<endl;
int option;
cout<<"Choose option ";
cin>>option;
return option;
}
int gatekeeperMenu() {
    cout << "Gatekeeper Menu" << endl;
    cout << "1- Add visitor entry" << endl;
    cout << "2- View today's entries" << endl;
    cout << "3- Search visitor by name" << endl;
    cout << "4- Count of today's entries" << endl;
    cout << "5- Logout" << endl;
    int option;
    cout << "Choose option: ";
    cin >> option;
    return option;
}
void addperson(string name1,string number1,string reference1,string time1,string day1,string vehicle1,string place1, 
    int carnumber1){ 
        addpersonsintoarray(name1,number1,reference1,time1,day1,vehicle1,place1,carnumber1);
        savepersons();
        cout << "Person added successfully!"<<endl;
    }


void addpersonsintoarray(string name1,string number1,string reference1,string time1,string day1,string vehicle1,string place1,int carnumber1){
    name[count_persons]=name1;
    number[count_persons]=number1;
    reference[count_persons]=reference1;
    time[count_persons]=time1;
    day[count_persons]=day1;
    vehicle[count_persons]=vehicle1;
    place[count_persons]=place1;
    carnumber[count_persons]=carnumber1;
    count_persons++;
   }
   void viewTodayEntries(string targetday) {
    cout << "\n--- Entries for " << targetday<< " ---\n";
    cout<<"Name\t\tNumber\t\tReference\t\tTime\t\tDay\t\tvehicle\t\tcarnumber\t\tplace"<<endl;
    bool found = false;
    for (int x = 0; x < count_persons; x++) {
        if (day[x] == targetday) {
            cout << name[x] << "\t\t" << number[x] << "\t" << reference[x] << "\t\t"
                 << time[x] << "\t\t" << day[x] << "\t\t" << vehicle[x] << "\t    "
                 << carnumber[x] << "\t" << place[x] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found for " << targetday << endl;
    }
    beauty();
}
void beauty(){
    cout<<"Press anykey to continue "<<endl;
    getch();
    system("CLS");
}
void countentriestoday(string targetday) {
    int countToday = 0;
    for (int i = 0; i < count_persons; i++) {
        if (day[i] == targetday) {
            countToday++;
        }
    }
    cout << "Total entries in "<<targetday<<" are : " << countToday << endl;
    beauty();
}
void viewpersons(){
    cout<<"Name\t\tNumber     \t\tReference\tTime\t\tDay\t\tvehicle\t\tcarnumber\t\tplace"<<endl;
     for(int x=0;x<count_persons;x++){
        cout<<name[x]<<"\t\t"<<number[x]<<"\t\t"<<reference[x]<<"\t\t"<<time[x]<<"\t\t"<<day[x]<<"\t\t"<<vehicle[x]<<"\t\t"<<carnumber[x]<<"\t\t"<<place[x]<<endl;
     }
}
void addnewuser(){
    if(count<TOTAL_ENTRIES){
    cout<<"Enter the username "<<endl;
    string username;
    cin>>username;
    cout<<"Enter the password "<<endl;
    string password;
    cin>>password;
    cout<<"Enter roles (ADMIN,GATEKEEPER,MEMBER)";
    string role;
    cin>>role;
    user(username , password , role);
    cout<<"User added successfully"<<endl;
    }
    else{
        cout<<"no more space to add new users!"<<endl;
    }
    saveusers();
}
void loginpassword(){
    if(loginusername != " "){
        for(int i=0; i<count; i++){
            if(usernameA[i] == loginusername){
                string oldPassword, newPassword;
                cout << "Enter your old password: ";
                cin >> oldPassword;
                if(passwordA[i] == oldPassword){
                    cout << "Enter new password: ";
                    cin >> newPassword;
                    passwordA[i] = newPassword;
                    cout << "Password changed successfully!" << endl;
                } else {
                    cout << "Incorrect old password!" << endl;
                }
                break;
            }
        }
    }
}
void sortByName() {
    for(int i = 0; i < count_persons - 1; i++) {
        for(int j = i + 1; j < count_persons; j++) {
            if(name[i] > name[j]) {
                swap(name[i], name[j]);
                swap(number[i], number[j]);
                swap(reference[i], reference[j]);
                swap(time[i], time[j]);
                swap(day[i], day[j]);
                swap(vehicle[i], vehicle[j]);
                swap(place[i], place[j]);
                swap(carnumber[i], carnumber[j]);
            }
        }
    }
    viewpersons();
    cout << "Data sorted by name successfully!" << endl;
    beauty();
}
void deletePerson(string targetname) {
    bool deleted = false;
    for(int i = 0; i < count_persons; i++) {
        if(name[i] == targetname) {
            for(int j = i; j < count_persons - 1; j++) {
                name[j] = name[j+1];
                number[j] = number[j+1];
                reference[j] = reference[j+1];
                time[j] = time[j+1];
                day[j] = day[j+1];
                vehicle[j] = vehicle[j+1];
                place[j] = place[j+1];
                carnumber[j] = carnumber[j+1];
            }
            count_persons--;
            deleted = true;
            cout << "Record deleted successfully!" << endl;
            break;
        }
    }
    if(!deleted) {
        cout << "No such person found!" << endl;
    }
    beauty();
    savepersons();
}
void savepersons(){
    fstream file;
    file.open("data32.txt",ios::out);
    for(int i=0;i<count_persons;i++){
        file<<name[i]<<','<<number[i]<<','<<reference[i]<<','<<time[i]<<','<<day[i]<<','<<vehicle[i]<<','<<place[i]<<','<<carnumber[i]<<'\n';
    }
    file.close();
}
void saveusers(){
    fstream file;
    file.open("data31.txt",ios::out);
    for(int i=0;i<count;i++){
        file<<usernameA[i]<<','<<passwordA[i]<<','<<rolesA[i]<<'\n';
    }
    file.close();
}
void search(string targetname){
    bool found=false;
    for(int i=0;i<count_persons;i++){
        if(name[i]==targetname){
            cout<<name[i]<<"\t\t"<<number[i]<<"\t\t"<<reference[i]<<"\t\t"<<time[i]<<"\t\t"<<day[i]<<"\t\t"<<vehicle[i]<<"\t\t"<<carnumber[i]<<"\t\t"<<place[i]<<endl;
            found=true;
            break;
        }
        }
           if(!found){
            cout<<"the person is not registrered in my data "<<endl;
    }
}
void editPerson(string targetname,string newname,string newnumber,string newreference,string newtime,string newday,string newvehicle,string newplace,int  newcarnumber) {
    bool found = false;
    for (int i = 0; i < count_persons; i++) {
        if (name[i] == targetname) {
            found = true;
            name[i] = newname;
            number[i] = newnumber;
            reference[i] = newreference;
            time[i] = newtime;
            day[i] = newday;
            vehicle[i] = newvehicle;
            place[i] = newplace;
            carnumber[i] = newcarnumber;
            cout << "Details updated successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Person not found!" << endl;
    }
    savepersons();
     beauty();
}
void showStats() {
    int total = count_persons;
    int carCount = 0, bikeCount = 0;
    int morningCount = 0, afternoonCount = 0;
    int monday = 0, tuesday = 0, wednesday = 0, thursday = 0, friday = 0, saturday = 0, sunday = 0;
    for (int i = 0; i < count_persons; i++) {
        if (vehicle[i] == "car") {
            carCount++;
        } else if (vehicle[i] == "bike") {
            bikeCount++;
        }
        if (time[i] == "morning") {
            morningCount++;
        } else if (time[i] == "afternoon") {
            afternoonCount++;
        }
        if (day[i] == "monday") {
            monday++;
        } else if (day[i] == "tuesday") {
            tuesday++;
        } else if (day[i] == "wednesday") {
            wednesday++;
        } else if (day[i] == "thursday") {
            thursday++;
        } else if (day[i] == "friday") {
            friday++;
        } else if (day[i] == "saturday") {
            saturday++;
        } else if (day[i] == "sunday") {
            sunday++;
        }
    }
    cout << "Total persons entered: " << total << endl;
    cout << "Car entries: " << carCount << endl;
    cout << "Bike entries: " << bikeCount << endl;
    cout << "Morning entries: " << morningCount << endl;
    cout << "Afternoon entries: " << afternoonCount << endl;
    cout << "---------Entries by Day--------- "<<endl;
    cout << "Monday   : " << monday << endl;
    cout << "Tuesday  : " << tuesday << endl;
    cout << "Wednesday: " << wednesday << endl;
    cout << "Thursday : " << thursday << endl;
    cout << "Friday   : " << friday << endl;
    cout << "Saturday : " << saturday << endl;
    cout << "Sunday   : " << sunday << endl;
    beauty();
}
void viewAllUsers() {
    cout << "Total registered users: " << count << endl;
    cout << "Username\tRole" << endl;
    for (int i = 0; i < count; i++) {
        cout << usernameA[i] << "\t\t" << rolesA[i] << endl;
    }
    beauty();
}
string getField(string record, int field) {
    int commaCount = 1;
    string item = "";
    for (int i = 0; i < record.length(); i++) {
        if (record[i] == ',') {
            commaCount++;
        } else if (commaCount == field) {
            item += record[i];
        }
    }
    return item;
}
void loadusers() {
    fstream file;
    file.open("data31.txt", ios::in);
    string record;
    while (getline(file, record)) {
        if (count < TOTAL_ENTRIES) {
            usernameA[count] = getField(record, 1);
            passwordA[count] = getField(record, 2);
            rolesA[count] = getField(record, 3);
            count++;
        }
    }
    file.close();
}
void loadpersons() {
    fstream file;
    file.open("data32.txt", ios::in);
    string record;
    while (getline(file, record)) {
        if (count_persons < TOTAL_PERSONS) {
            name[count_persons] = getField(record, 1);
            number[count_persons] = getField(record, 2);
            reference[count_persons] = getField(record, 3);
            time[count_persons] = getField(record, 4);
            day[count_persons] = getField(record, 5);
            vehicle[count_persons] = getField(record, 6);
            place[count_persons] = getField(record, 7);
            carnumber[count_persons] = stoi(getField(record, 8));
            count_persons++;
        }
    }
    file.close();
}
void viewvisitorsinside() {
    cout << "View all visitors that are currently inside : "<<endl;
    viewpersons();
}
void viewmyvisitors() {
    cout << "Visitors referred by you is "<< loginusername <<" :" <<endl;
    cout<<"Name\t\tNumber     \t\tReference\t\tTime\t\tDay\t\tvehicle\t\tcarnumber\t\tplace"<<endl;
    bool found = false;
    for (int i = 0; i < count_persons; i++) {
        if (reference[i] == loginusername) {
            cout << name[i] << "\t\t" << number[i] << "\t\t" << reference[i] << "\t\t"
                 << time[i] << "\t\t" << day[i] << "\t\t" << vehicle[i] << "\t\t"
                 << carnumber[i] << "\t\t" << place[i] << endl;
                 found = true;
        }
    }
    if (!found) {
        cout << "No visitors found with your name as reference.\n";
    }
}
void preapprovevisitor(string name1,string number1,string reference1,string time1,string day1,string vehicle1,string place1, 
    int carnumber1) {
    addperson(name1,number1,reference1,time1,day1,vehicle1,place1,carnumber1);        
    cout << "Visitor pre-approved successfully!" << endl;
}
void editpersondetails(string targetname){
                    string newname, newnumber, newreference, newtime, newday, newvehicle,newplace;
                int  newcarnumber;
                cout<<"------- Edit he details ------- "<<endl;
                cout<<"Enter the new name ";
                cin>>newname;
            cout << "Enter new 11-digit contact number: ";
            cin >> newnumber;
            while (newnumber.length() != 11) {
                cout << "Invalid number! It must be exactly 11 digits. Try again: ";
                cin >> newnumber;
            }
            cout << "Enter new reference: ";
            cin >> newreference;
            cout << "Enter new time (morning/afternoon): ";
            cin >> newtime;
            cout << "Enter new day: ";
            cin >> newday;
            cout << "Enter new vehicle type (car/bike): ";
            cin >> newvehicle;
            cout << "Enter new place: ";
            cin >> newplace;
            cout << "Enter new car/bike number (4 digits): ";
            cin >> newcarnumber;
                
                editPerson(targetname,newname,newnumber,newreference,newtime,newday,newvehicle,newplace,newcarnumber);
            }
//functionality end