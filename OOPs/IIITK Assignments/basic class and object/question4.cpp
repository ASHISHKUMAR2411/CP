#include<bits/stdc++.h>
using namespace std;

class STUDENT{
    private: 
        int Student_RollNo;
        string Student_Name;
        string Student_DOB;
        int Student_Marks;
    public:
        void AgeCalculate();
        void FindTop5();
        void FindMaxMarks();
        void FindLowestMarks();
        void initialise_Student(int RollNo, string Name,string DOB,int Marks){
            this->Student_RollNo = RollNo;
            this->Student_Name = Name;
            this->Student_DOB = DOB;
            this->Student_Marks = Marks;
        }

};

STUDENT obj[10];

void STUDENT :: AgeCalculate(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDate = ltm->tm_mday;
    string date = Student_DOB.substr(0, 2);
    int dateToInt = stoi(date);
    string month = Student_DOB.substr(3, 5);
    int monthToInt = stoi(month);
    string year = Student_DOB.substr(6, 10);
    int yearToInt = stoi(year);
    int age = 0;
    if(currentYear < yearToInt){
        cout<<"Invalid Year"<<endl;
    }
    else{
        age = currentYear - yearToInt;
        if(monthToInt > currentMonth)
            age--;
        else if(monthToInt == currentMonth && dateToInt > currentDate)
            age--;
        cout<<"The Age is "<<age<<endl;
    }
}

void STUDENT :: FindTop5(){
    vector<int> Mark;
    for(int i = 0; i<10;i++){
        Mark.push_back(obj[i].Student_Marks);
    }
    sort(Mark.begin(),Mark.end(),greater<int>());
    cout<<"Top 5 are : "<<endl;
    for(int i = 0 ; i<5;i++){
        for(int j = 0;j<10;j++){
            if (Mark[i] == obj[j].Student_Marks){
                cout << obj[j].Student_Name << " " << obj[j].Student_RollNo<<endl;
            }
        }
    }
}

void STUDENT :: FindMaxMarks(){
    vector<int> maxMark;
    for (int i = 0; i < 10; i++)
    {
        maxMark.push_back(obj[i].Student_Marks);
    }
    sort(maxMark.begin(), maxMark.end(), greater<int>());
    for(int i = 0;i<10;i++)
        if(maxMark[0] == obj[i].Student_Marks)
            cout << " Maximum Marks is : " << maxMark[0] << " holder is : " << obj[i].Student_Name<<endl;
}

void STUDENT :: FindLowestMarks(){
    vector<int> minMark;
    for (int i = 0; i < 10; i++)
    {
        minMark.push_back(obj[i].Student_Marks);
    }
    sort(minMark.begin(), minMark.end());
    for (int i = 0; i < 10; i++)
        if (minMark[0] == obj[i].Student_Marks)
            cout << " Maximum Marks is : " << minMark[0] << " holder is : " << obj[i].Student_Name << endl;
}

int main(){
    int RollNo, Marks;
    string Name, DOB;
    cout<<"enter the information for students : "<<endl;
    for(int i = 0; i<10;i++){
        cout<<"For Student "<<i+1<<endl;
        cout<<" Enter the name of the student : ";
        cin>>Name;
        cout<<"Enter the Roll No : ";
        cin>>RollNo;
        cout<<"Enter the Marks : ";
        cin>>Marks;
        cout<<"Enter the Date Of Birth in (DD-MM-YYYY) format only : ";
        cin>>DOB;
        obj[i].initialise_Student(RollNo,Name,DOB,Marks);
        obj[i].AgeCalculate();
    }
    obj[0].FindTop5();
    obj[0].FindMaxMarks();
    obj[0].FindLowestMarks();
}