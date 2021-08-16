/*
Final Term Project (With TA Class) //Student ID: 21-45001-2

Disclaimer:
1) Please consider making the console fullscreen and scroll up to see full output when running the code
2) Further instructions will be shown on the console

Index of line numbers for ease of navigation:

1) Person class: 20 // Student class: 66 // Scholarship Student class: 114 // Employee class: 164
   Faculty class: 216 // Officer class: 260 // TA class: 300

2) main function: 343 // demonstration of different class methods and properties: 383

*/
#include <iostream>
#include <string>
using namespace std;

class Person{
//Person class(inherits from no other classes)
//some of the properties contain confidential information about a person, so protected access specifier used..
//every class has dedicated print methods that print almost every property..
protected:
  string name;
  int age;
  string gender;
  string religion;
  string address;
  string phone;
public:
Person(){}
Person(string nme, int ag, string gen, string rel, string add, string ph){ //parameterized constructor
  name=nme;
  age=ag;
  gender=gen;
  religion=rel;
  address=add;
  phone=ph;
}

//some getter methods for accessing protected properties in the main function..
string getname(){
  return name;
}
int getage(){
  return age;
}


//print method for this class
void personinfo(){
  cout<<"Showing Personal Information:"<<endl;
  cout<<"___________________________"<<endl;
  cout<<"Name: "<<name<<endl;
  cout<<"Age: "<<age<<" Years"<<endl;
  cout<<"Gender: "<<gender<<endl;
  cout<<"Religion: "<<religion<<endl;
  cout<<"Address: "<<address<<endl;
  cout<<"Phone Number: "<<phone<<endl;
}
~Person(){}
};


class Student: virtual public Person {
  //Student class (directly inherits from Person class with public access specifier)
  //virtual inheritance is used to avoid ambiguity
  //has a method that returns semester fee that is calculated based on the number of credits..
public:
  string department;
  string identity;
  string batch;
  double cgpa;
  double totalcredits;
  double creditcost;
  double semfee;
Student(){};
Student(string nme, int ag, string gen, string rel, string add, string ph,
        string dep, string id, string btch, double cg,double tocr):Person(nme,ag,gen,rel,add,ph){
          //parameterized constructor
  department=dep;
  identity=id;
  batch=btch;
  cgpa=cg;
  totalcredits=tocr;
  creditcost=totalcredits*5500; // per credit cost 5500 BDT
  semfee=(creditcost+20000); //miscellaneous fee is assumed to be 20000 BDT
}

//print method for this class
void academicinfo(){
  cout<<"Showing Academic Information:"<<endl;
  cout<<"___________________________"<<endl;
  cout<<"Department: "<<department<<endl;
  cout<<"ID: "<<identity<<endl;
  cout<<"Batch: "<<batch<<endl;
  cout<<"CGPA: "<<cgpa<<endl;
}
//returns total credits.. for use in main function
double gettotalcreds(){
  return totalcredits;
}

//method that returns semester fee..for use in main function
double getsemesterfee(){
  return semfee;
}

~Student(){}
};


class StudentSC: public Student {
  //Scholarship student class (directly inherits from Student class with public access specifier)
  //has a working scholarship status method
  //has a method that returns semester fee after applying scholarship
public:
 double gradeB;
 double drop;
 double percent;

StudentSC(){};
StudentSC(string nme, int ag, string gen, string rel, string add, string ph,
          string dep, string id, string btch, double cg,double tocr, double grdb, double drp):Student(nme,ag,gen,rel,add,ph,dep,id,btch,cg,tocr),Person(nme,ag,gen,rel,add,ph){
            //parameterized constructor...constructor of Person class was added since Student class uses virtual inheritance
gradeB=grdb;
drop=drp;
}

//takes "grades lower than B" and "number of courses dropped" as extra parameters in the scholarship student class constructor
//if called, shows scholarship percentage and assigns scholarship percentage to the "percent" variable for future calculations
void scholarstat(){
  if(cgpa>=3.75 && gradeB==0 && drop==0)
  {
    cout<<"Student is Applicable for 45% Scholarship"<<endl;
    percent=0.45;
  }
  else if(cgpa>=3.70 && gradeB==0 && drop<=1)
  {
    cout<<"Student is Applicable for 20% Financial AID"<<endl;
    percent=0.20;
  }
  else if(cgpa>=3.50 && gradeB<=2 && drop<=3)
  {
    cout<<"Student is Applicable for 10% Financial AID"<<endl;
    percent=0.10;
  }
  else
  {
    cout<<"Student is Not Applicable for Scholarship or Financial AID"<<endl;
    percent=0.00;
  }
}

//returns semester fee after applying scholarship
double getscholarsemfee(){
  return (semfee-(semfee*percent));
}
~StudentSC(){}
};


class Employee: virtual public Person {
  //Employee class (directly inherits from Person class with public access specifier)
  //virtual inheritance is used to avoid ambiguity
  //has a method that raises the salary by a given amount
  //has promotion/demotion methods that set "Seasonal Employee" to "Permanent Employee" and vice versa
public:
  string type;
  string employeeID;
  string joindate;
  int salary;
Employee(){};
Employee(string nme, int ag, string gen, string rel, string add, string ph,
        string tpe,string empID,string joinD,int slry):Person(nme,ag,gen,rel,add,ph){
          //parameterized constructor
  type=tpe;
  employeeID=empID;
  joindate=joinD;
  salary=slry;
}

//print method for this class
void employeeinfo(){
  cout<<"Showing Employment Specific Information:"<<endl;
  cout<<"________________________________________"<<endl;
  cout<<"Type: "<<type<<endl;
  cout<<"Employee ID: "<<employeeID<<endl;
  cout<<"Join Date: "<<joindate<<endl;
  cout<<"Salary: "<<salary<<" BDT"<<endl;
}

//promotes seasonal employee to permanent / permanent employee stays permanent
void promote(){
    cout<<"Employee has been promoted"<<endl;
  type="Permanent";
}

//demotes permanent employee to seasonal / seasonal employee stays seasonal
void demote(){
  cout<<"Employee has been demoted"<<endl;
  type="Seasonal";
}

//method that raises the salary of the employee by a given integer amount
void raisesalary(int n){
  cout<<"Salary has been raised by "<<n<<" BDT"<<endl;
  salary=salary+n;
}

~Employee(){}
};


class Faculty: public Employee{
  //Faculty class (directly inherits from Employee class with public access specifier)
  //has methods for setting courses and getting the list of courses for that Faculty
public:
  string facultydepartment;
  string position;
  string specialization;
  string course1,course2,course3;
Faculty(){}
Faculty(string nme, int ag, string gen, string rel, string add, string ph,
        string tpe,string empID,string joinD,int slry,string fctdep,string pos, string speci):Employee(nme,ag,gen,rel,add,ph,tpe,empID,joinD,slry),Person(nme,ag,gen,rel,add,ph){
          //parameterized constructor...constructor of Person class was added since Employee class uses virtual inheritance
    facultydepartment=fctdep;
    position=pos;
    specialization=speci;
}

//print method for this class
void facultyinfo(){
  cout<<"Showing Faculty Information:"<<endl;
  cout<<"____________________________"<<endl;
  cout<<"Department: "<<facultydepartment<<endl;
  cout<<"Position: "<<position<<endl;
  cout<<"Specialization: "<<specialization<<endl;
}
//sets 3 courses for the Faculty
void setcourses(string x, string y, string z){
  course1=x;
  course2=y;
  course3=z;
}
//prints the list of courses for the faculty
void getcourselist(){
  cout<<"Showing Course list for the Faculty:"<<endl;
  cout<<"____________________________________"<<endl;
  cout<<"Course 1: "<<course1<<endl;
  cout<<"Course 2: "<<course2<<endl;
  cout<<"Course 3: "<<course3<<endl;
}

~Faculty(){}
};


class Officer: public Employee{
  //Officer class(directly inherits from Employee class with public access specifier)
  //has methods for setting different works and getting the list of works for that Officer
public:
  string officename;
  string officerposition;
  string work1,work2,work3;
Officer(){}
Officer(string nme, int ag, string gen, string rel, string add, string ph,
        string tpe,string empID,string joinD,int slry,string ofcn, string ofcpos):Employee(nme,ag,gen,rel,add,ph,tpe,empID,joinD,slry),Person(nme,ag,gen,rel,add,ph){
          //parameterized constructor...constructor of Person class was added since Employee class uses virtual inheritance
    officename=ofcn;
    officerposition=ofcpos;
}

//print method for this class
void officerinfo(){
  cout<<"Showing Officer Information:"<<endl;
  cout<<"____________________________"<<endl;
  cout<<"Office Name: "<<officename<<endl;
  cout<<"Position: "<<officerposition<<endl;
}
//sets 3 different works for the officer
void setworks(string x, string y, string z){
  work1=x;
  work2=y;
  work3=z;
}
//prints the list of works for the officer
void getworkslist(){
  cout<<"Showing Work list for the Officer:"<<endl;
  cout<<"____________________________________"<<endl;
  cout<<"Work 1: "<<work1<<endl;
  cout<<"Work 2: "<<work2<<endl;
  cout<<"Work 3: "<<work3<<endl;
}

~Officer(){}
};

class TA: public Employee, public Student{
  //TA class(directly inherits from Employee class and Student class)
  //inherits from Person class through both Employee and Student classes ..ambiguity present
  //virtual inheritance was used in Student class and Employee class before to remove ambiguity
  //constructor of Person class is added to have the properties of Person class
  //has a TA Eligibility method that determines eligibilty by considering CGPA
public:
  string graduationstatus;
  string eligibility;
TA(){}
TA(string nme, int ag, string gen, string rel, string add, string ph,
   string tpe,string empID,string joinD,int slry,
   string dep, string id, string btch, double cg,double tocr,string gs,string elig):Employee(nme,ag,gen,rel,add,ph,tpe,empID,joinD,slry),Student(nme,ag,gen,rel,add,ph,dep,id,btch,cg,tocr),Person(nme,ag,gen,rel,add,ph){
     //parameterized constructor
     graduationstatus=gs;
     eligibility=elig;
}
//print method for this class
void TAinfo(){
  cout<<"Showing TA Specific Information:"<<endl;
  cout<<"________________________________"<<endl;
  cout<<"Graduation Status: "<<graduationstatus<<endl;
  cout<<"Eligibility: "<<eligibility<<endl;
}


//assumption: if CGPA falls lower than 3.5 , he/she can no longer stay as a TA
//a method that determines the eligibility to stay as a TA based on CGPA and prints accordingly
void TAeligibility(){
  if(cgpa<3.5){
    eligibility="Not Eligible";
    cout<<name<<" is not Eligible to stay as a TA || CGPA: "<<cgpa<<endl;
  }
  else{
    eligibility="Eligible";
    cout<<name<<" is Eligible to stay as a TA || CGPA: "<<cgpa<<endl;
  }
}


~TA(){}
};

int main(){
//creating parameterized objects for Student, Scholarship Student,Faculty, Officer and TA Classes

Student s1("Alvee Hamid",23,"Male","Islam","C-12,Dallas Goli,Motijheel,Dhaka-1219","01798765243",
            "IPE","21-87651-2","21",3.5, 17);

StudentSC s2("Rabbi Faiyaz",22,"Male","Islam","D-16,Goran Bazar,Khilgaon,Dhaka-1218","01798123453",
            "CSE","20-12651-1","20",3.8, 16, 0, 0);

Faculty f1("Syeda Hasan",28,"Female","Islam","F-17,Malibagh Lane,Dhaka-1217","017986367267",
           "Permanent","18-56741-3","31/12/2018",66000,"FST","Lecturer", "Artifical Intelligence");

Officer o1("Afsara Adiba",30,"Female","Islam","G-12,Mouchak Lane,Dhaka-1217","017123467267",
           "Seasonal","18-56741-3","31/12/2018",32000,"OSA","Manager");

TA t1("Sathman Gazi",25,"Male","Islam","G-18,Modhubag Lane,Dhaka-1217","01789765426","Seasonal","19-4700-7","20/07/20",15000,
                   "FST", "19-4700-7","19", 3.3,15,"Not Graduated","Eligible");
//decoration
cout<<"______________________"<<endl;
cout<<"University Info System"<<endl;
cout<<"______________________"<<endl;
cout<<endl;

//accessing and printing object properties
cout<<s1.getname()<<","<<s1.getage()<<" is a Student without scholarship.(1)"<<endl;
cout<<s2.getname()<<","<<s2.getage()<<" is a Student with scholarship.(2)"<<endl;
cout<<f1.getname()<<","<<f1.getage()<<" is a Faculty.(3)"<<endl;
cout<<o1.getname()<<","<<o1.getage()<<" is an Officer.(4)"<<endl;
cout<<t1.getname()<<","<<t1.getage()<<" is a TA.(5)"<<endl;
cout<<endl;

//main program starts here
cout<<"Please input the correct value to see the demonstration of the class methods: (example: 1/2/3/4/5)"<<endl<<endl;
for(int i=0; ; i++){
int n;cin>>n;
if(n==0){
  cout<<"Program ended"<<endl;
  break;//exits program
}

//demonstration of different class methods and properties
switch(n){

  case 1://Demonstration of Student methods and properties
  cout<<"........"<<endl;
  s1.personinfo();cout<<endl;
  s1.academicinfo();cout<<endl;
  cout<<"Semester Fee for "<<s1.getname()<<": "<<s1.getsemesterfee()<<" BDT"<<" || Total Credits: "<<s1.gettotalcreds()<<endl;cout<<endl;
  cout<<"Input (1/2/3/4/5) to perform another action or input 0 to close the program"<<endl;cout<<endl;
  break;

  case 2://Demonstration of Scholarship Student methods and properties
  cout<<"........"<<endl;
  s2.personinfo();cout<<endl;
  s2.academicinfo();cout<<endl;
  s2.scholarstat();cout<<endl;
  cout<<"Semester Fee for "<<s2.getname()<<": "<<s2.getscholarsemfee()<<" BDT"<<" || Total Credits: "<<s2.gettotalcreds()<<endl;cout<<endl;
  cout<<"Input (1/2/3/4/5) to perform another action or input 0 to close the program"<<endl;cout<<endl;
  break;

  case 3://Demonstration of Faculty methods and properties
  cout<<"........"<<endl;
  f1.personinfo();cout<<endl;
  f1.promote();
  f1.raisesalary(5000);cout<<endl;
  f1.employeeinfo();cout<<endl;
  f1.facultyinfo();cout<<endl;
  f1.setcourses("Object Oriented Programming(Java)","Discrete Mathematics","Introduction to Computer Studies");
  f1.getcourselist();cout<<endl;
  cout<<"Input (1/2/3/4/5) to perform another action or input 0 to close the program"<<endl;cout<<endl;
  break;

  case 4://Demonstration of Officer methods and properties
  cout<<"........"<<endl;
  o1.personinfo();cout<<endl;
  o1.promote();
  o1.raisesalary(5000);cout<<endl;
  o1.employeeinfo();cout<<endl;
  o1.officerinfo();cout<<endl;
  o1.setworks("Manage Vaccinated Student List", "Keep track of Student Behavior","Answer Student Queries");
  o1.getworkslist();cout<<endl;
  cout<<"Input (1/2/3/4/5) to perform another action or input 0 to close the program"<<endl;
  break;

  case 5://Demonstration of TA methods and properties
  cout<<"........"<<endl;
  t1.personinfo();cout<<endl;
  t1.employeeinfo();cout<<endl;
  t1.academicinfo();cout<<endl;
  t1.TAeligibility();cout<<endl;
  t1.TAinfo();cout<<endl;
  cout<<"Input (1/2/3/4/5) to perform another action or input 0 to close the program"<<endl;
  break;

  default:
  cout<<"Please input a valid number."<<endl;
  }
}

  return 0;
}
