#include <iostream>
#include <iomanip>
#include<windows.h>
using namespace std;

class Team 
{
    private:
        int score;
        string teamName;
        string coachName;
        string HomeCity;

    public:
    Team()
    {
        teamName = "Team Name";
        score = 0;
        coachName = "CoachName";
        HomeCity = "HomeCity";
    }
    void setTeamScore(int s)     { score = s; }
    void setTeamName (string tN) { teamName = tN; }
    void setCoachName(string cN) { coachName = cN; }
    void setHomeCity (string hC) { HomeCity = hC; }

    double getTeamScore() const { return score; }
    string getTeamName()  const { return teamName; }
    string getCoachName() const { return coachName; }
    string getHomeCity()  const { return HomeCity; }
};

class Scoreboard
{
    private:
        int Quarter;
        int down;
        int ToGo;
        bool Possession;//Possesion if the home team has possession of ball true/false
        Team Hometeam;
        Team Visitors;
        

    public:
    Scoreboard()
    {
        Quarter = 1;
        Possession = true;//HomeTeam will have the ball
        down = 0;
        ToGo = 0;
    }
    void SetQuarter(int q)   { Quarter = q; }
    void SetDown   (int d)   { down = d; }
    void SetToGo   (int tG)  { ToGo = tG; }
    void SetPoss   (bool pos){ Possession = pos; }
    void SetHometeam (Team hT) { Hometeam = hT; }
    void SetVisitors (Team vT) { Visitors = vT; }
    
 
    int GetQuarter() const { return Quarter;}
    int GetDown() const { return down;}
    int GetToGo() const { return ToGo;}
    bool GetPoss() const { return Possession;}
    Team GetHomeTeam() const { return Hometeam; }
    Team GetVisitors() const { return Visitors; }
    

    void ShowScoreboard()
    {
        string color,colorRed, colorHome, colorVisitor = "";
        string reset = "\x1b[0m";

        system("cls"); //clears the screen after loop refresh
        color = "\x1b[32;1m";
        colorRed = "\x1b[31;15m";
        colorHome = "\x1b[33;15m";
        colorVisitor = "\x1b[36;15m";

        cout << color << "__________ Football Scoreboard __________" << reset << endl;
        
        for( int i = 0; i < 40; i++) cout << "*";
        cout << endl;
        cout << colorHome <<setw(9)<< "HomeTeam" << colorVisitor << setw(29) <<"Visitors" << reset << endl;
        cout << setw(10) <<  Hometeam.getTeamName() << setw(29) << Visitors.getTeamName()  << endl;
        cout << setw(6) << Hometeam.getTeamScore() << setw(30) << Visitors.getTeamScore() << endl;

        if(Possession)//displays the possession of the ball initially but changes due to user input selection
        {
            cout << setw(22)  << colorRed << "O<"<< reset << " POSS" << endl;
        }
        else
        {
            cout << setw(22) <<  "POSS" << colorRed << " >O" << reset << endl;
        }

        cout << setw(25) << "Quarter: " << Quarter << endl;
        cout << endl << endl;

        cout << setw(10) << GetDown() << " < Down" << setw(16) << "To Go > " << GetToGo() << "\n" << endl;

        cout << colorHome << setw(6) << Hometeam.getCoachName() << colorVisitor << setw(30)<<  Visitors.getCoachName() << reset << endl;
        cout << colorHome<< setw(6) << Hometeam.getHomeCity() << colorVisitor<< setw(30) << Visitors.getHomeCity() << reset << endl;

        for( int i = 0; i < 40; i++) {cout << "*";}
        cout << endl;
    };
};

void SBEdit()
{
    Scoreboard s;
    Team HometeamBoard;
    Team VisitorsBoard;
      
    char choice = '\0';
    int newTeamScore = 0;
    int newQuarter = 0;
    int newDown;
    int newToGo;
    bool newPoss;
    string newTeamName = "";
    string newCoachName = "";
    string newHomeCity = "";
    string MenuColor = "";
    string MenuReset = "";

    s.SetHometeam(HometeamBoard);
    s.SetVisitors(VisitorsBoard);
      
    do 
    {
        s.ShowScoreboard();
        MenuColor = "\x1b[31;15m";
        MenuReset = "\x1b[0m";
        cout << MenuColor;//Change Menu color to red
        cout << "\nMenu:" << endl;
        cout << "A. Update Hometeam Name" << endl;
        cout << "B. Update Visitors Name" << endl;
        cout << "C. Update Hometeam Score" << endl;
        cout << "D. Update Visitors Score" << endl;
        cout << "E. Update Quarter " << endl;
        cout << "F. Update Downs " << endl;
        cout << "G. Update To Go " << endl;
        cout << "H. Update Hometeam Coach" << endl; 
        cout << "I. Update Visitors Coach" << endl;
        cout << "J. Update Hometeam HomeCity" << endl;
        cout << "K. Update Visitors HomeCity" << endl;
        cout << "L. Update Possesion" << endl;// updates the possession of the ball by user input 

        cout << "X. To Exit Scoreboard\n" << endl;
        cout << "Input Your Choice....> ";
        cout << MenuReset;// reset menu color to white for legibility in choice selection
        cin >> choice;
        choice=tolower(choice);
        switch (choice)
        {

            case 'a':

                cout << "\nHometeam Name Update \n";
                cout << "What Is The New Team Name? ";
                cin >> newTeamName;
                HometeamBoard.setTeamName(newTeamName);
                cout << "Updating Team Name for Hometeam to " << HometeamBoard.getTeamName() << endl;
                Sleep(1000); 
                break;

            case 'b':

                cout << "\nVisitors Name Update \n";
                cout << "What Is The New Team Name?...> ";
                cin >> newTeamName;
                VisitorsBoard.setTeamName(newTeamName);
                cout << "Updating Team  Name for Visitors to  " << VisitorsBoard.getTeamName() << endl;
                Sleep(1000);
                break;

            case 'c':

                cout << "\nHometeam Score Update \n" ;
                cout << "What is the new score?...> ";
                cin >> newTeamScore;
                HometeamBoard.setTeamScore(newTeamScore);
                cout << "\nUpdating New Hometown Score To ..." << HometeamBoard.getTeamScore() << endl;
                Sleep(1000);
                break;

            case 'd':

                cout << "\nVisitor Score Update \n" ;
                cout << "What Is The New Score?...> ";
                cin >> newTeamScore;
                VisitorsBoard.setTeamScore(newTeamScore);
                cout << "\nUpdating New Visitor Score To ..." << VisitorsBoard.getTeamScore() << endl;
                Sleep(1000);
                break;

            case 'e':

                cout << "\nQuarter Update \n";
                cout << "What Is The Updated Quarter? ...>";
                cin >> newQuarter;
                s.SetQuarter(newQuarter);
                cout << "\nUpdating Quarter To ..." << s.GetQuarter() << endl;
                Sleep(1000);
                break;

            case 'f':

                cout << "\nDown Update \n";
                cout << "What is the new Down? ...>";
                cin >> newDown;
                s.SetDown(newDown);
                cout << "\nUpdating Down To ..." << s.GetDown() << endl;
                Sleep(1000);
                break;

            case 'g':

                cout << "\nTo Go Update \n";
                cout << "What Is The New To Go? ...>";
                cin >> newToGo;
                s.SetToGo(newToGo);
                cout << "\nUpdating  To Go To ..." << s.GetToGo() << endl;
                Sleep(1000);
                break;

            case 'h':

                cout << "\nHometeam Coach Name Update\n";
                cout << "What Is The Coach Name?...>";
                cin >> newCoachName;
                HometeamBoard.setCoachName(newCoachName);
                cout << "\nUpdating Coach Name To ..." << HometeamBoard.getCoachName() << endl;
                Sleep(1000);
                break;

            case 'i':

                cout << "\nVisitors Coach Name Update\n";
                cout << "What Is The Coach Name?...>";
                cin >> newCoachName;
                VisitorsBoard.setCoachName(newCoachName);
                cout << "\nUpdating Coach Name To ..." << VisitorsBoard.getCoachName() << endl;
                Sleep(1000);
                break;

            case 'j':

                cout << "\nHometeam City Update\n";
                cout << "What Is The City Name?...>";
                cin >> newHomeCity;
                HometeamBoard.setHomeCity(newHomeCity);
                cout << "\nUpdating Hometeam City Name To ..." << HometeamBoard.getCoachName() << endl;
                Sleep(1000);
                break;

            case 'k':

                cout << "\nVisitors City Update\n";
                cout << "What Is The City Name?...>";
                cin >> newHomeCity;
                VisitorsBoard.setHomeCity(newHomeCity);
                cout << "\nUpdating Visitors City Name To ..." << VisitorsBoard.getCoachName() << endl;
                Sleep(1000);
                break;

            case 'l':

                cout << "\nPossession Update\n";
                cout << "Who Has Possesion?( 1 For Hometeam, 0 For Visitors)...>";
                cin >> newPoss;
                s.SetPoss(newPoss);
                cout << "\nUpdating Possesssion To ... " << s.GetPoss() << endl;
                Sleep(2000);
                break;

            case 'x':

                cout << "\nGame Over!!!" << endl;
                cout << "\nTerminating. " << endl;
                break;

            default:

                cout<<"Invalid Choice!!! Enter a valid choice or press X to exit"<<endl;
                break;

        }
        s.SetHometeam(HometeamBoard);
        s.SetVisitors(VisitorsBoard);    

    }while(choice != 'x');
}