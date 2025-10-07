/******************************************************************************
Cosette Bosshardt
COP3014 0006
Homework 7

This assignment will take in the file a user entered and will enter in 
all that information into an array of type Movies Structure
from then my program will be able to perform specific menu taks. I attempted
the extra credit option menu 6

*******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;


//Structure defintion here
struct Movies
{
    string genre;
    string title;
    int year;
    int runtime;
    string rating;
};


//Function Prototypes
void Menu();
bool File_Open(Movies* arr);
void Normalized_Time(int tot_hrs, int& hrs, int& mins);
void rating_sort(string rating, const Movies *arr, int num_movies);
void export_genre(const Movies *arr, int num_movies);
void LoadMovieFile(Movies*& MyMovies, int& num_movies);
void Sort_By_Year(Movies* arr, int num);

int main() 
{
    //Declaring My Variables
    fstream MovieFile;
    int num_movies, total_min;
    string user_choice, filename, rating;
    char yes_or_no;
    int hours=0;
    int min=0;

  
    
   //Use this pointer whenever you need to create a dynamic array. 
	Movies* movieArr = 0; //Initialize pointer to 0, it is not currently in use
    
    
    do{ //enter dowhile loop
     
    Menu();//Display The Menu Options
    cout<<"Enter choice ";
    cin>>user_choice; //user inputs what menu options they want
    
    if(user_choice=="1") //if =1 then load my LoadMovieFile function
        {
            LoadMovieFile(movieArr, num_movies); 
            cout<<endl;
        }

    else if(user_choice=="2")
    {
        if(File_Open(movieArr)==false) //there is no movie file
            cout<<"\nTotal Movie Database Runtime: 0 hrs 0 mins"<<endl; //there is no time
        
        if(File_Open(movieArr)==true) //movie file is open
        {
            for(int i=0; i<num_movies; i++) //step thru my looop
               total_min+=movieArr[i].runtime; //add up all the minutes
            
            Normalized_Time(total_min, hours, min); //call function
            
            cout<<"\nTotal Movie Database Runtime: "<<hours<<" hrs "<<min<<" mins"<<endl;
            
            //reset all my time variables now that the time has been displayed
            hours=0; 
            total_min=0;
            min=0; 
        }
    }

    else if(user_choice=="3") //account for 3
    {
        if(File_Open(movieArr)==false) //file is not open
        cout<<"\nLoad movie file first! Use option 1."<<endl;
        
        if(File_Open(movieArr)==true) //file is open yay
        {
            cout<<"\nView movies with which rating? (G, PG, PG-13, R): "; //which rating?
            cin>>rating; //enter in rating
            
           rating_sort(rating, movieArr, num_movies); //call function to do it
        }
    }

    else if(user_choice=="4") //account for 4
    {
        if(File_Open(movieArr)==true) //if the movie file is open
        {
            cout<<"\nExporting database by genre..."<<endl;
            export_genre(movieArr,num_movies); //call this function to do it
            cout<<"...export complete"<<endl;
        }
        
        else if(File_Open(movieArr)==false) //movie file not open
            cout<<"\nLoad movie file first! Use option 1."<<endl;
    }
     
 
    else if(user_choice=="5") //acount for 5
    {
        if(File_Open(movieArr)==true) //if the file is open
        { 
            delete[] movieArr; //delete the dynamic memory
            movieArr=0; //set ptr to 0 
            cout<<"\nMovie database cleared successfull."<<endl;
        }
        
        else //there is no movie file open
        cout<<"Movie database already empty."<<endl;
    }

    //EXTRA CREDIT
    else if(user_choice == "6") //Account for 6
    {
        if(File_Open(movieArr)==true) //if the file is open
         {
             Sort_By_Year(movieArr, num_movies); //call this function to sort by year
             cout<<endl;
         }
         
         if(File_Open(movieArr)==false) //if the file is close
             cout<<"\nLoad movie file first! User option 1!"<<endl;
    }

    else if(user_choice == "q" || user_choice == "Q")
    {
        delete[] movieArr; //delete the dynamic memory
        movieArr=0; //set ptr to 0 
        cout<<"Thanks for using the Movie Database Organizer!"<<endl;
        break; //leave do while loop
    }

    else //User entry invalid
        cout<<"Invalid User Entry. Please try again"<<endl; //repeat loop
        
cout<<endl;
}while(user_choice!="q");

    
    return 0;
}


//Function definitions

//Will print mneu
void Menu() 
{
    cout<<"1 - Load Movie File"<<endl;
    cout<<"2 - View Total Movie Database Runtime"<<endl;
    cout<<"3 - View Movies by Rating"<<endl;
    cout<<"4 - Export Movies by Genre"<<endl;
    cout<<"5 - Clear Currently Loaded Database"<<endl;
    cout<<"6 - Print Database By Year"<<endl;
    
}

//Will test if "file is open" by making sure the array is not zero
bool File_Open(Movies* arr)
{
    bool open; //define a bool variable
    if(arr == 0) //if array = 0
    open=false; //file is closed
    
    if(arr != 0) //if array !=0
    open=true; //file is open
    
    return open; //return my bool
}

//Function to take the time and make it normal
void Normalized_Time(int tot_min, int& hrs, int& mins)
{
    hrs= tot_min/60.0;
    mins= tot_min%60;
}

//Function will sort movies by rating
void rating_sort(string rating, const Movies *arr, int num_movies)
{
    //declare count variable here
    int rating_count=0;
    
    if(rating=="G") 
    {
         cout<<"Movies rated G:"<<endl;
        //Step thru arr to find match
        for(int i=0; i<num_movies; i++)
        {
            if(arr[i].rating=="G")
            {
                cout<<arr[i].title<<endl; 
                rating_count++;
            }
        }
    }
    
    if(rating=="PG")
    {
         cout<<"Movies rated PG:"<<endl;
        //Step thru arr to find match
        for(int i=0; i<num_movies; i++)
        {
            if(arr[i].rating=="PG")
             {
                 cout<<arr[i].title<<endl;
                 rating_count++;
             }
            
        }
    }
    
    if(rating=="PG-13")
    {
         cout<<"Movies rated PG-13:"<<endl;
        //Step thru arr to find match
        for(int i=0; i<num_movies; i++)
        {
            if(arr[i].rating=="PG-13")
            {
                cout<<arr[i].title<<endl;
                rating_count++;
            }
        }
    }
    
    if(rating=="R")
    {
        cout<<"Movies rated R:"<<endl;
        //Step thru arr to find match
        for(int i=0; i<num_movies; i++)
        {
            if(arr[i].rating=="R")
            {
               cout<<arr[i].title<<endl;
               rating_count++;
            }
               
        }
    }
    
    else
    {
        cout<<"Movies rated "<<rating<<endl;
        for(int i=0; i<num_movies; i++)
        {
            if(arr[i].rating==rating)
            {
               cout<<arr[i].title<<endl;
               rating_count++;
            }
        }
    }
    
    if(rating_count==0)
        cout<<"No movies with rating "<<rating<<endl;
    
}

void export_genre(const Movies *arr, int num_movies)
{
    //Make my ofstream object
    ofstream F_export;
    
    F_export.open("action.txt"); //open a action.txt file
    
    //Step through the num movies
    for(int i=0; i<num_movies; i++)
    {
        if(arr[i].genre == "ACTION")
        {
            F_export<<arr[i].title<<"\t"<<arr[i].year<<endl;
        }
    }   
    
    F_export.close(); //close the action text
    
    F_export.open("drama.txt"); //open a drama.txt file
    
    for(int i=0; i<num_movies; i++)//Step through array to find drama matches
    {
        if(arr[i].genre == "DRAMA")
            F_export<<arr[i].title<<"\t"<<arr[i].year<<endl;
    }   
   
   F_export.close(); //close the drama text
   
   F_export.open("comedy.txt"); //open a comedy.txt file
   
   for(int i=0; i<num_movies; i++) //step through array to find comedy matches
    {
        if(arr[i].genre == "COMEDY")
            F_export<<arr[i].title<<"\t"<<arr[i].year<<endl;
    }   
    
    F_export.close(); //close the comedy txt
    
    F_export.open("scifi.txt"); //open a scifi file
    
    for(int i=0; i<num_movies; i++) //step through array to see if there r any sci fi
    {
        if(arr[i].genre == "SCIENCE FICTION")
            F_export<<arr[i].title<<"\t"<<arr[i].year<<endl;
    }   
    
    F_export.close(); //close my file
}

void LoadMovieFile(Movies*& movieArr, int& num_movies)
{
    //Define my function variables
    fstream MovieFile;
    string filename;
    char yes_or_no;

    if (movieArr != 0) //Check if a database is already loaded
    {
        cout << "There is a database already loaded. This will overwrite the current database." << endl;
        cout << "Do you want to continue? (y/n): ";
        
        do{
            cin >> yes_or_no;
            yes_or_no = tolower(yes_or_no); //Change to lower
    
            if (yes_or_no == 'n') 
            {
                cout << "Returning to the main menu";
                return; //return to the main
            } 
            
            else if (yes_or_no == 'y') 
            {
                delete[] movieArr; // Delete the dynamically allocated memory
                movieArr = 0;  // Reset the pointer to 0
                num_movies=0;
                break;
            }
            
            else
                cout<<"Enter y or n ";
        }while(yes_or_no!='n' || yes_or_no!='y');
    }
    
  
        // Prompt the user for the file name and attempt to open the file
        do {
            cout <<"Which movie file would you like to open?";
            cin >> filename;
            MovieFile.open(filename, ios::in); //read the file in
    
            if (MovieFile.fail()) //If that file fails prompt user to try again
            {
                cout << "That is not a valid file.  Try again!" << endl;
            }
        } while (MovieFile.fail()); //condition for my while loop
    
        MovieFile >> num_movies; // Read in the number of movies
    
        movieArr = new Movies[num_movies]; // Create the array
    
        // Read in the data w a for loop
        for (int i = 0; i < num_movies; i++)
        {
            MovieFile.ignore(); // Ignore the newline character
            getline(MovieFile, movieArr[i].genre, ':');
            getline(MovieFile, movieArr[i].title, ',');
            MovieFile >> movieArr[i].year >> movieArr[i].runtime >> movieArr[i].rating;
        }
    
        MovieFile.close(); //close the file
        cout << "Database loaded";
    
}

void Sort_By_Year(Movies* arr, int num)
{
    bool swap = false; // Initialize swap bool to false
    
    //enter do while loop
    do{
        swap = false; // Reset swap to false each time looop completed
        
        for (int i = 0; i < num - 1; ++i)  //Step thru outer loop
        {
            for (int j = 0; j < num - i - 1; ++j) //step thru this inner loop
            {
                
                if (arr[j].year > arr[j + 1].year) //if the years r in the wrong order
                {
                    swap = true; //set swap = true
                    
                    // Swap titles
                    string temp = arr[j].title;
                    arr[j].title = arr[j + 1].title;
                    arr[j + 1].title = temp;
                    
                    // Swap years
                    int tempYear = arr[j].year;
                    arr[j].year = arr[j + 1].year;
                    arr[j + 1].year = tempYear;
                    
                }
            }
        }
    } while(swap==true); //continue to check if i made a swap
    
    for(int i = 0; i < num; i++)//step thru the loop and print out the sorted order
    {
        cout<<arr[i].year<<" : "<<arr[i].title<<endl;
    }
}
      



