//Project : Global learning competency
//Research Topic : Human Trafficking
//Dataset Used: Counter-Trafficking Data Collaborative (CTDC). (2018, September 4). The Global Dataset.
//Retrieved December 2, 2018, from https://www.ctdatacollaborative.org/download-global-dataset
//Data structure used Singly Linked List along with C++ Structures
//BY ABHISHEK PATEL.
//Implementation using C++
//Code::Blocks
//Version:	Release 17.12 rev 11256
//SDK Version:	1.33.0
//This is the main driver file (3/3  files needed to run this program)
//The code below creates object of type ProjectGlobalLearning that is used to call functions defined in implementation file (2/3)


/*_________________________START OF main.cpp_________________________*/
//include header file
#include "projectgloballearning.h"
// The following are part of the header file
// And don't need to be included again

/*
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
*/
int main()
{
    ProjectGlobalLearning PG; //OBJECT to access member functions of ProjectGlobalLearning Class
    if(PG.isInputFileOpen("The_Global_Dataset_3_Sept_2018.csv"))//open the dataset .csv  file and check if it exists via isFileOpen() function
    {
        //Loads data from the The_Global_Dataset_3_Sept_2018.csv file into structure called "DataSet"
        //Create Singly Linked List using "DataSet" structure
        PG.fetchDataFromCsv();
        cout<<endl;
        PG.MenuChoice();
        /*
            1.Gender //statsByGenderxpercentage();
            2.Age //statsByAgexPercentage();
            3.Year //statsByYearxVictims(2002,2018);  Start to End Year of the dataset
            4.Adult count(based on citizenship) //statsByCountryxVictimCount(1);
            5.Minor's count(based on citizenship) //statsByCountryxVictimCount(2);
            6.Total count(based on citizenship) //statsByCountryxVictimCount(3);
            0.Exit //exit the program
        */
        PG.isInputFileClosed(); //close the dataset The_Global_Dataset_3_Sept_2018.csv  file

    }
 return 0;
}
