//Project : Global learning competency
//Research Topic : Human Trafficking
//Dataset Used: Counter-Trafficking Data Collaborative (CTDC). (2018, September 4).
//The Global Dataset. Retrieved December 2, 2018, from https://www.ctdatacollaborative.org/download-global-dataset
//Data structure used Singly Linked List along with C++ Structures
//BY ABHISHEK PATEL.
//Implementation using C++
//Code::Blocks
//Version:	Release 17.12 rev 11256
//SDK Version:	1.33.0
//This is the header file (1/3  files needed to run this program)
//Contains all the function DECLARATIONS
//Contains definition of the Structure "DataSet" which is used to implement the linked list

/*_________________________START OF projectgloballearning.h_________________________*/
#ifndef PROJECTGLOBALLEARNING_H
#define PROJECTGLOBALLEARNING_H
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct DataSet
{
        DataSet *next; //pointer used to store the next location in the 'node' when Linked List is created

        //member variables of the DataSet structure
        //they will be part of 'each' object (node) created while storing data into the Linked List
        string filename;

        string	yearOfRegistration	;

        string	datasource	;

        string	gender	;

        string	ageBroad	;

        string	majorityStatus	;

        string	majorityStatusAtExploit	;

        string	majorityEntry	;

        string	citizenship	;

        string	meansOfControlDebtBondage	;

        string	meansOfControlTakesEarnings	;

        string	meansOfControlRestrictsFinancialAccess	;

        string	meansOfControlThreats	;

        string	meansOfControlPsychologicalAbuse	;

        string	meansOfControlPhysicalAbuse	;

        string	meansOfControlSexualAbuse	;

        string	meansOfControlFalsePromises	;

        string	meansOfControlPsychoactiveSubstances	;

        string	meansOfControlRestrictsMovement	;

        string	meansOfControlRestrictsMedicalCare	;

        string	meansOfControlExcessiveWorkingHours	;

        string	meansOfControlUsesChildren	;

        string	meansOfControlThreatOfLawEnforcement	;

        string	meansOfControlWithholdsNecessities	;

        string	meansOfControlWithholdsDocuments	;

        string	meansOfControlOther	;

        string	meansOfControlNotSpecified	;

        string	meansOfControlConcatenated	;

        string	isForcedLabour	;

        string	isSexualExploit	;

        string	isOtherExploit	;

        string	isSexAndLabour	;

        string	isForcedMarriage	;

        string	isForcedMilitary	;

        string	isOrganRemoval	;

        string	typeOfExploitConcatenated	;

        string	typeOfLabourAgriculture	;

        string	typeOfLabourAquafarming	;

        string	typeOfLabourBegging	;

        string	typeOfLabourConstruction	;

        string	typeOfLabourDomesticWork	;

        string	typeOfLabourHospitality	;

        string	typeOfLabourIllicitActivities	;

        string	typeOfLabourManufacturing	;

        string	typeOfLabourMiningOrDrilling	;

        string	typeOfLabourPeddling	;

        string	typeOfLabourTransportation	;

        string	typeOfLabourOther	;

        string	typeOfLabourNotSpecified	;

        string	typeOfLabourConcatenated	;

        string	typeOfSexProstitution	;

        string	typeOfSexPornography	;

        string	typeOfSexRemoteInteractiveServices	;

        string	typeOfSexPrivateSexualServices	;

        string	typeOfSexConcatenated	;

        string	isAbduction	;

        string	RecruiterRelationship	;

        string	CountryofExploitation	;

        string	recruiterRelationIntimatePartner	;

        string	recruiterRelationFriend	;

        string	recruiterRelationFamily	;

        string	recruiterRelationOther	;

        string	recruiterRelationUnknown	;
};


class ProjectGlobalLearning
{
    public:
          ProjectGlobalLearning();
           ~ProjectGlobalLearning();
           bool isInputFileOpen(string); //Checks and opens Input dataset file
           void isInputFileClosed(); //Closes input dataset file
           bool isOutputFileOpen(string); //Checks and opens / creates output .csv file to output results
           void isOutputFileClosed(); // closes output files opened by isOutputFileOpen function

           // To display menu and call functions corresponding to the menu
           void MenuChoice();
           //Function that are called from MenuChoice()
           void statsByGenderxpercentage(); //Choice #1 in MenuChoice();
           void statsByAgexPercentage(); //Choice #2 in MenuChoice();
           void statsByYearxVictims(int,int);  //Choice #3 in MenuChoice();
           void statsByCountryxVictimCount(int); //Choice #4, #5 & #6 in MenuChoice();


       void fetchDataFromCsv(); //Loads dataset to a linked List via Structure as a node
       void WriteDatatoCsv(string,string,string,string,string,bool); //used for writing the results to csv file

    protected:

    private:
        ifstream inFile; //object of Input stream class to operate on files used for input dataset csv file
        ofstream outFile;//object of Output stream class to operate on files used for output dataset csv file

       //pointers to traverse Linked List
        DataSet *head;
        DataSet *tail;

        //stats counting
        int statsCountMale;
        int statsCountFemale;
        int statsCountUnkown;
        bool isAdult;
        bool isUnKnown;

       };

#endif // PROJECTGLOBALLEARNING_H
