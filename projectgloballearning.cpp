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
//This is the implementation file driver file (2/3  files needed to run this program)

/*_________________________START OF projectgloballearning.cpp_________________________*/
#include "projectgloballearning.h"
//Default constructor used to set default values
ProjectGlobalLearning::ProjectGlobalLearning()
{
    //ctor
        this->statsCountMale = 0;
        this->statsCountFemale = 0;
        this->statsCountUnkown = 0;
        this->isAdult=false;
        this->isUnKnown=false;
        this->head=NULL;
        this->tail=NULL;

}

ProjectGlobalLearning::~ProjectGlobalLearning()
{

    //dtor
}

//Called to check if dataset file is available and open it
//Argument required:datasetFileName which is the file name of the .csv file (The_Global_Dataset_3_Sept_2018.csv)
//Values returned:True or False
bool ProjectGlobalLearning::isInputFileOpen(string datasetFileName)
{

   this->inFile.open(datasetFileName.c_str());
    if(!this->inFile.is_open()) { cout<<"ERROR: INPUT FILE NOT FOUND."<<endl; return false; }
    else
        return true;


}


//Called to close Input File
//Argument required:None
//Values returned:None
void ProjectGlobalLearning::isInputFileClosed()
{
    this->inFile.close();
}

//Creates output file and returns true or false depending on whether the files created
//Argument required:datasetFileName which is the file name of the .csv file
//Called in any function that writes to csv file
//Values returned:True or False
bool ProjectGlobalLearning::isOutputFileOpen(string datasetFileName)
{

   this->outFile.open(datasetFileName.c_str());
    if(!this->outFile.is_open()) { cout<<"ERROR: OUTPUT FILE NOT FOUND."<<endl; return false; }
    else
        return true;


}

//Called to close output File
//Argument required:None
//Values returned:None
void ProjectGlobalLearning::isOutputFileClosed()
{
    this->outFile.close();
}


//Write to .csv file
//Accepts file Name (this is for future implementations)
//Argument required:
//fname = file name of the output file accepts any kind of string at moment
//graphLabel_X - X-Axis LABEL NAME
//graphLabel_Y - Y-Axis LABEL NAME
//graphValue_X - X-Axis / Column Values
//graphValue_Y - Y-Axis / Column Values
//bool headerLabel Ensures that header is written only when it is set to True
//Values returned:None

void ProjectGlobalLearning::WriteDatatoCsv(string fname,string graphLabel_X, string graphLabel_Y, string graphValue_X, string graphValue_Y,bool headerLabel)
{
if(headerLabel == true)
outFile<<graphLabel_X<<","<<graphLabel_Y<<"\n"; //for header name,

outFile<<graphValue_X<<","<<graphValue_Y<<"\n";

}


void ProjectGlobalLearning::fetchDataFromCsv()
{
int counter=0;

 while(!inFile.eof()) //create all nodes
{

DataSet *dataNode = new DataSet;
dataNode->next = NULL;


getline(this->inFile,dataNode->yearOfRegistration	,',');
getline(this->inFile,dataNode->datasource	,',');
getline(this->inFile,dataNode->gender	,',');
getline(this->inFile,dataNode->ageBroad	,',');
getline(this->inFile,dataNode->majorityStatus	,',');
getline(this->inFile,dataNode->majorityStatusAtExploit	,',');
getline(this->inFile,dataNode->majorityEntry	,',');
getline(this->inFile,dataNode->citizenship	,',');
getline(this->inFile,dataNode->meansOfControlDebtBondage	,',');
getline(this->inFile,dataNode->meansOfControlTakesEarnings	,',');
getline(this->inFile,dataNode->meansOfControlRestrictsFinancialAccess	,',');
getline(this->inFile,dataNode->meansOfControlThreats	,',');
getline(this->inFile,dataNode->meansOfControlPsychologicalAbuse	,',');
getline(this->inFile,dataNode->meansOfControlPhysicalAbuse	,',');
getline(this->inFile,dataNode->meansOfControlSexualAbuse	,',');
getline(this->inFile,dataNode->meansOfControlFalsePromises	,',');
getline(this->inFile,dataNode->meansOfControlPsychoactiveSubstances	,',');
getline(this->inFile,dataNode->meansOfControlRestrictsMovement	,',');
getline(this->inFile,dataNode->meansOfControlRestrictsMedicalCare	,',');
getline(this->inFile,dataNode->meansOfControlExcessiveWorkingHours	,',');
getline(this->inFile,dataNode->meansOfControlUsesChildren	,',');
getline(this->inFile,dataNode->meansOfControlThreatOfLawEnforcement	,',');
getline(this->inFile,dataNode->meansOfControlWithholdsNecessities	,',');
getline(this->inFile,dataNode->meansOfControlWithholdsDocuments	,',');
getline(this->inFile,dataNode->meansOfControlOther	,',');
getline(this->inFile,dataNode->meansOfControlNotSpecified	,',');
getline(this->inFile,dataNode->meansOfControlConcatenated	,',');
getline(this->inFile,dataNode->isForcedLabour	,',');
getline(this->inFile,dataNode->isSexualExploit	,',');
getline(this->inFile,dataNode->isOtherExploit	,',');
getline(this->inFile,dataNode->isSexAndLabour	,',');
getline(this->inFile,dataNode->isForcedMarriage	,',');
getline(this->inFile,dataNode->isForcedMilitary	,',');
getline(this->inFile,dataNode->isOrganRemoval	,',');
getline(this->inFile,dataNode->typeOfExploitConcatenated	,',');
getline(this->inFile,dataNode->typeOfLabourAgriculture	,',');
getline(this->inFile,dataNode->typeOfLabourAquafarming	,',');
getline(this->inFile,dataNode->typeOfLabourBegging	,',');
getline(this->inFile,dataNode->typeOfLabourConstruction	,',');
getline(this->inFile,dataNode->typeOfLabourDomesticWork	,',');
getline(this->inFile,dataNode->typeOfLabourHospitality	,',');
getline(this->inFile,dataNode->typeOfLabourIllicitActivities	,',');
getline(this->inFile,dataNode->typeOfLabourManufacturing	,',');
getline(this->inFile,dataNode->typeOfLabourMiningOrDrilling	,',');
getline(this->inFile,dataNode->typeOfLabourPeddling	,',');
getline(this->inFile,dataNode->typeOfLabourTransportation	,',');
getline(this->inFile,dataNode->typeOfLabourOther	,',');
getline(this->inFile,dataNode->typeOfLabourNotSpecified	,',');
getline(this->inFile,dataNode->typeOfLabourConcatenated	,',');
getline(this->inFile,dataNode->typeOfSexProstitution	,',');
getline(this->inFile,dataNode->typeOfSexPornography	,',');
getline(this->inFile,dataNode->typeOfSexRemoteInteractiveServices	,',');
getline(this->inFile,dataNode->typeOfSexPrivateSexualServices	,',');
getline(this->inFile,dataNode->typeOfSexConcatenated	,',');
getline(this->inFile,dataNode->isAbduction	,',');
getline(this->inFile,dataNode->RecruiterRelationship	,',');
getline(this->inFile,dataNode->CountryofExploitation	,',');
getline(this->inFile,dataNode->recruiterRelationIntimatePartner	,',');
getline(this->inFile,dataNode->recruiterRelationFriend	,',');
getline(this->inFile,dataNode->recruiterRelationFamily	,',');
getline(this->inFile,dataNode->recruiterRelationOther	,',');
getline(this->inFile,dataNode->recruiterRelationUnknown	,'\n');


//Check if firstNode else insert
      if(head==NULL)
      {
        head=dataNode;
        tail=dataNode;
        dataNode=NULL;
      }
      else
      {
        tail->next=dataNode;
        tail=dataNode;
      }
    counter++; //debugging to count the total number of records

}
isInputFileClosed(); //close the files.
}


//Selection Menu #1 choice
//Function to calculate total of victims based on gender criteria  and then output the results in percentage format to .csv file
//Called upon valid user input from MenuChoice() function
//Valid user inputs are #1
//Argument required:None
//Values returned:None
//writes data to statsByGenderxpercentage.csv
void ProjectGlobalLearning::statsByGenderxpercentage()
{
    //COUNTERS FOR each gender and non-identified cases which weren't reported
    int maleVictimsCount = 0;
    int femaleVictimsCount = 0;
    int unKnownOrTransgenderVictimsCount = 0;
    double victimsCountPercentage = 0;
    double victimsCountTotal = 0;
    DataSet *tempNode=new DataSet;
    tempNode = head;
    cout<<"--------------------------------------"<<endl;
    cout<<"Assisted/Reported Case Stats by Gender"<<endl;
    cout<<"--------------------------------------"<<endl;
    while(tempNode!=NULL)
    {
        if(tempNode->gender == "Male")
        {
            maleVictimsCount++;
        }
        else if(tempNode->gender == "Female")
        {
            femaleVictimsCount++;
        }
        else if(tempNode->gender == "Unknown")
        {
            unKnownOrTransgenderVictimsCount++;
        }

        tempNode  = tempNode->next;//Go to end of list
    }

    victimsCountTotal = maleVictimsCount + femaleVictimsCount + unKnownOrTransgenderVictimsCount;
    //Write to statsByGenderxpercentage.csv
    //With header Gender, % , Male / Female / Unknown , percentage count
    isOutputFileOpen("statsByGenderxpercentage.csv");
    victimsCountPercentage = (ceil((maleVictimsCount*100)/ victimsCountTotal));
    cout<<"Males: "<<victimsCountPercentage<<" %"<<endl;
    WriteDatatoCsv("statsByGenderxpercentage.csv","Gender","%","Male",to_string(victimsCountPercentage),true);

    victimsCountPercentage = (ceil((femaleVictimsCount*100)/ victimsCountTotal));
    cout<<"Females: "<<victimsCountPercentage<<" %"<<endl;
    WriteDatatoCsv("statsByGenderxpercentage.csv","Gender","%","Female",to_string(victimsCountPercentage),false);

    victimsCountPercentage =  (ceil((unKnownOrTransgenderVictimsCount*100)/ victimsCountTotal));
    cout<<"Unknown [Gender not disclosed when reported]: "<<victimsCountPercentage<<" %"<<endl;
    WriteDatatoCsv("statsByGenderxpercentage.csv","Gender","%", "Unknown",to_string(victimsCountPercentage),false);


    isOutputFileClosed();

}

//Selection Menu #2 choice
//Function to calculate total of victims based on age criteria  and then output the results in percentage format to .csv file
//Called upon valid user input from MenuChoice() function
//Valid user inputs are #2
//Argument required:None
//Values returned:None
//writes data to statsByAgexPercentage.csv
void ProjectGlobalLearning::statsByAgexPercentage()
{
    //Data corresponds to ageBroad variable in Structure Loaded from the dataset
    //Set separate variables for each age group
    //AgeStatByRangePercentage = (float)(AgeStatByRange0_8 * 100/(totalCountofAgeStatByRange));
    //which gives percentage of that particular age board when compared to the entire age board range
    int AgeStatByRange0_8   = 0;
    int AgeStatByRange9_17  = 0;
    int AgeStatByRange18_20 = 0;
    int AgeStatByRange21_23 = 0;
    int AgeStatByRange24_26 = 0;
    int AgeStatByRange27_29 = 0;
    int AgeStatByRange30_38 = 0;
    int AgeStatByRange39_47 = 0;
    int AgeStatByRange48_above = 0;
    int AgeStatByRangeUnknowns = 0;
    int totalCountofAgeStatByRange = 0;
    float AgeStatByRangePercentage = 0;

    DataSet *tempNode=new DataSet;
    tempNode = head;
    //Increment the appropriate age group counters
    while(tempNode!=NULL)
    {
        if(tempNode->ageBroad == "0--8")
            {
               AgeStatByRange0_8++;
            }
        else if(tempNode->ageBroad == "9--17")
            {
               AgeStatByRange9_17++;
            }
        else if(tempNode->ageBroad == "18--20")
            {
               AgeStatByRange18_20++;
            }
        else if(tempNode->ageBroad == "21--23")
            {
               AgeStatByRange21_23++;
            }
        else if(tempNode->ageBroad == "24--26")
            {
               AgeStatByRange24_26++;
            }
        else if(tempNode->ageBroad == "27--29")
            {
               AgeStatByRange27_29++;
            }
        else if(tempNode->ageBroad == "30--38")
            {
               AgeStatByRange30_38++;
            }
        else if(tempNode->ageBroad == "39--47")
            {
               AgeStatByRange39_47++;
            }
        else if(tempNode->ageBroad == "48+")
            {
               AgeStatByRange48_above++;
            }
        else if(tempNode->ageBroad == "Unknown")
            {
               AgeStatByRangeUnknowns++;
            }



            tempNode  = tempNode->next;//Go to end of list
    }
    totalCountofAgeStatByRange = (
                             AgeStatByRange0_8
                           + AgeStatByRange9_17
                           + AgeStatByRange18_20
                           + AgeStatByRange21_23
                           + AgeStatByRange24_26
                           + AgeStatByRange27_29
                           + AgeStatByRange30_38
                           + AgeStatByRange39_47
                           + AgeStatByRange48_above
                           + AgeStatByRangeUnknowns
                           );
cout<<"------------------------------------------------------"<<endl;
cout<<"Assisted/Reported Case Stats by Age Group (Worldwide):"<<endl;
cout<<"------------------------------------------------------"<<endl;
//Create output file statsByAgexPercentage
//Write to statsByAgexPercentage.csv with headers Age Range, %,age board range, age stat count by percentage
//Display the count
isOutputFileOpen("statsByAgexPercentage.csv");
AgeStatByRangePercentage = (float)(AgeStatByRange0_8 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","0 to 8",to_string(AgeStatByRangePercentage),true);
cout<<"Between:   0-8 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange9_17 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","9 to 17",to_string(AgeStatByRangePercentage),false);
cout<<"Between:  9-17 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange18_20 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","18 to 20",to_string(AgeStatByRangePercentage),false);
cout<<"Between: 18-20 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange21_23 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","21 to 23",to_string(AgeStatByRangePercentage),false);
cout<<"Between: 21-23 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange24_26 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","24 to 26",to_string(AgeStatByRangePercentage),false);
cout<<"Between: 24-26 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange27_29 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","27 to 29",to_string(AgeStatByRangePercentage),false);
cout<<"Between: 27-29 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange30_38 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","30 to 38",to_string(AgeStatByRangePercentage),false);
cout<<"Between: 30-38 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange39_47 * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","39-47",to_string(AgeStatByRangePercentage),false);
cout<<"Between: 39-47 :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

AgeStatByRangePercentage = (float)(AgeStatByRange48_above * 100/(totalCountofAgeStatByRange));
WriteDatatoCsv("statsByAgexPercentage.csv","Age Range","%","48+",to_string(AgeStatByRangePercentage),false);
cout<<"Between:   48+ :"<<to_string(AgeStatByRangePercentage)<<" %"<<endl;

isOutputFileClosed(); //close the output file

}


//Selection Menu #3 choice
//Function to calculate total of victims based on by year criteria  and then output the results in percentage format to .csv file
//Called upon valid user input from MenuChoice() function
//Valid user inputs are #3 with arguments passed are starting year and endyear which corresponds to yearOfRegistration variable in Structure
//Argument required:None
//Values returned:None
//writes data to statsByYearxVictims.csv
void ProjectGlobalLearning::statsByYearxVictims(int startYear, int endYear)
{
    int victimsStatByYear = 0;
    DataSet *tempNode=new DataSet;

    bool headerLable = true;
    int yearValue = startYear;

    isOutputFileOpen("statsByYearxVictims.csv");

cout<<"------------------------------------"<<endl;
cout<<"Assisted/Reported Case Stats by Year"<<endl;
cout<<"------------------------------------"<<endl;

while(yearValue <= endYear)
{
tempNode = head;

    while(tempNode!=NULL)
    {
        if(tempNode->yearOfRegistration == to_string(yearValue) && (tempNode->gender == "Male" || tempNode->gender == "Female" || tempNode->gender == "Unknown"))
            {
               victimsStatByYear++;

            }

            tempNode  = tempNode->next;//Go to end of list
    }

cout<<"Year:"<<yearValue<<" Cases-Per-Year :"<< victimsStatByYear<<endl;
WriteDatatoCsv("statsByYearxVictims.csv","Year","Records",to_string(yearValue),to_string(victimsStatByYear),headerLable);
headerLable = false; //set to false to not write header twice
yearValue++; // increment each year
victimsStatByYear = 0; //reset stats at increment of each year
}//while statement ends
isOutputFileClosed();
}


//Selection Menu #4 #5 #6 choice
//when argument (1) calls a function to calculate total of victims by country of citizenship based in adult criteria  and then output the results in percentage format to .csv file
//when argument (2) calls a function to calculate total of victims by country of citizenship based in adult criteria  and then output the results in percentage format to .csv file
//when argument (3) calls a function to calculate total of victims by country of citizenship and then output the results in percentage format to .csv file
//Called upon valid user input from MenuChoice() function
//Valid user inputs are #4,5,6 with respective arguments passed 1,2,3 (integers only)
//Argument required:integer only (only called for valid user inputs as above)
//Values returned:None
void ProjectGlobalLearning::statsByCountryxVictimCount(int criteria)
{
cout<<"------------------------------------------------------"<<endl;
cout<<"Assisted/Reported Case Stats by Country of Citizenship"<<endl;
cout<<"------------------------------------------------------"<<endl;
    //country codes as per dataset
    string country[] = {"AF","AL","BD","BF","BG","BO","BY","CD","CI","CN","CO","ER","GH","GN","GW","HT","ID","IN","KG","KH","KR","KZ","LA","LK","MD","MG","ML","MM","MX","NE","NG","NP","PH","RO","SL","SN","SV","TH","TJ","TM","UA","UG","US","UZ","VN","ZZ"};
    int array_size = sizeof(country)/sizeof(country[0]); //get size of the array
    DataSet *tempNode=new DataSet; //temp node to traverse through the linked list
    tempNode = head; // set tempNode to start of linked list
    //Set initial counts to zero
    int adultVictimsStatsByCountry = 0;
    int minorVictimsStatsByCountry = 0;
    int statsByCountryxTotalVictimCount = 0;
    int counter = 0; //counter to go through country[counter] array, where counter acts as index
    bool headerLable = true; //when writing output to csv file this the header is only written to file if this variable is true



    if(criteria == 1) //adults
    {
     isOutputFileOpen("statsByCountryxAdultVictimCount.csv");
     cout<<"Majority Status:Adult"<<endl;
    }

    else if(criteria == 2) //minors
    {
        isOutputFileOpen("statsByCountryxMinorVictimCount.csv");
        cout<<"Majority Status:Minor"<<endl;
    }

    else if(criteria == 3) //adults & minors
    {
        isOutputFileOpen("statsByCountryxTotalVictimCount.csv");
        cout<<"Majority Status:Adults & Minors"<<endl;
    }



//traversing through the linked list

while(counter < array_size) //to go through entire country list in country[] array
{
        while(tempNode!=NULL) //until the reach the last node
    {
        //tempNode->majorityStatus implies whether "Adult" or "Minor"
        //tempNode->citizenship stored in structure via initial dataset Load - represents the Country code e.g: "US","MD"
        if(tempNode->citizenship == country[counter] && tempNode->majorityStatus == "Adult" && criteria==1)
        {
            adultVictimsStatsByCountry++; //increment counter for each valid count
        }
        else if(tempNode->citizenship == country[counter] && tempNode->majorityStatus == "Minor" && criteria==2)
        {
            minorVictimsStatsByCountry++;
        }
        else if(tempNode->citizenship == country[counter] && (tempNode->majorityStatus == "Adult" || tempNode->majorityStatus == "Minor")  && criteria==3)
        {
            statsByCountryxTotalVictimCount++;
        }
        tempNode  = tempNode->next;//Go to end of list
    }//inner while
    tempNode = head; //to reset position to head node

    string buffer = country[counter]; //to print country name onto csv file

    //Start writing each element to output file
    if(criteria == 1)
    {
        //Call WriteDatatoCsv()
        //Write to statsByCountryxAdultVictimCount.csv with headers Country , Adults , country name, stats counts per criteria
        //Check if headerLable true but if set to false do not write "Country", "Adults" header again
        WriteDatatoCsv("statsByCountryxAdultVictimCount.csv","Country","Adults",buffer,to_string(adultVictimsStatsByCountry),headerLable);
        cout<<country[counter]<<": "<<adultVictimsStatsByCountry<<endl;

    }

    else if(criteria == 2)
    {
        //Call WriteDatatoCsv()
        //Write to statsByCountryxAdultVictimCount.csv with headers Country , Minors , country name, stats counts per criteria
        //Check if headerLable true but if set to false do not write "Country", "Minors" header again
        WriteDatatoCsv("statsByCountryxMinorVictimCount.csv","Country","Minors",buffer,to_string(minorVictimsStatsByCountry),headerLable);
        cout<<country[counter]<<": "<<minorVictimsStatsByCountry<<endl;
    }

    else if(criteria == 3)
    {
        //Call WriteDatatoCsv()
        //Write to statsByCountryxAdultVictimCount.csv with headers Country , Total_Assisted_Count , country name, stats counts per criteria
        //Check if headerLable true but if set to false do not write "Country", "Total_Assisted_Count" header again
        WriteDatatoCsv("statsByCountryxTotalVictimCount.csv","Country","Total_Assisted_Count",buffer,to_string(statsByCountryxTotalVictimCount),headerLable);
        cout<<country[counter]<<": "<<statsByCountryxTotalVictimCount<<endl;
    }



    headerLable = false; //set to false to avoid re-writing the header titles
    counter++; //used as index for country[]
    //and end of each country[counter] increment reset the count for each country
    minorVictimsStatsByCountry = 0;
    adultVictimsStatsByCountry = 0;
    statsByCountryxTotalVictimCount = 0;

} //outer wwhile


isOutputFileClosed(); //close the output .(statsByCountryxAdultVictimCount.csv / statsByCountryxMinorVictimCount.csv /statsByCountryxTotalVictimCount.csv)


}

//Selection Menu
//Function takes user input and selects and calls appropriate function
//Valid user inputs are #1,2,3,4,5,6 & 0 for exit
//Argument required:None
//Values returned:None
//Option 0 : terminates the program
void ProjectGlobalLearning::MenuChoice()
{
    int choice = -1;

    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    cout<<" These data consist of information on identified and reported victims of human trafficking."<<endl;
    cout<<" Choose from following options to display stats (and write to .csv files):"<<endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;

        while(choice != 0)
    {

    cout<<"\n\n\nDisplay Statistic of reported cases by:\n"<<endl;
    cout<<"1.Gender"<<endl;
    cout<<"2.Age"<<endl;
    cout<<"3.Year"<<endl;
    cout<<"4.Adult count(based on citizenship)"<<endl;
    cout<<"5.Minor's count(based on citizenship)"<<endl;
    cout<<"6.Total count(based on citizenship)"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"Enter choice below:"<<endl;
    cin>> choice;
    system("CLS");


        switch(choice)
        {
            case 1:{cout<<"\n\n\n"; statsByGenderxpercentage();                  break;} //calls a function to calculate total of victims based on gender criteria  and then output the results in percentage format to .csv file
            case 2:{cout<<"\n\n\n"; statsByAgexPercentage();                     break;} //calls a function to calculate total of victims based on age criteria  and then output the results in percentage format to .csv file
            case 3:{cout<<"\n\n\n"; statsByYearxVictims(2002,2018);              break;} //calls a function to calculate total of victims based on by year criteria  and then output the results in percentage format to .csv file
            case 4:{cout<<"\n\n\n"; statsByCountryxVictimCount(1);               break;} //calls a function to calculate total of victims by country of citizenship based in adult criteria  and then output the results in percentage format to .csv file
            case 5:{cout<<"\n\n\n"; statsByCountryxVictimCount(2);               break;} //calls a function to calculate total of victims by country of citizenship based in minors criteria  and then output the results in percentage format to .csv file
            case 6:{cout<<"\n\n\n"; statsByCountryxVictimCount(3);               break;} //calls a function to calculate total of victims by country of citizenship and then output the results in percentage format to .csv file
            case 0:{ system("CLS");
                     exit(1); break;} //exit the program if this option is selected
            default:{
                system("CLS");
                cout<<"Wrong option. Choose from following choices."<<endl; }break;
        }
    }//end of while

}



