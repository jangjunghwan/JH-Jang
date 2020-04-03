#include <iostream>

using namespace std;

enum StudentName
{
    a,
    b,
    c,
};



int stuent1()
{
    int one_stuent_score;
    int student_scores[5];

    one_stuent_score = 100;

    student_scores[0] = 100; //1st element
    student_scores[1] = 80;  // 2nd elemet
    student_scores[2] = 90;  // 3rd elemet
    student_scores[3] = 50;  // 4th elemet
    student_scores[4] = 0;   // 5th elemet

    for (int i = 0; i < sizeof(student_scores)/sizeof(int); i++)
    {
        cout << student_scores[i] << endl;
    }
}


int myarr()
{
    int my_arr[5] = {1, 2, 3, 4, 5};

    my_arr[a] = 10;

    cout << my_arr[0] << endl;
    cout << my_arr[1] << endl;
}


int main()
{
    myarr();
    
}