#include <iostream>
#include <unistd.h>
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
        int quarter;
        int down;
        int toGo;
        bool poss;//Possesion if the home team has possession of ball true/false
        Team Hometeam;
        Team Visitors;
        Team coachName;
        Team HomeCity;

    public:
    Scoreboard()
    {
        quarter = 1;
        poss = true;//HomeTeam will have the ball
        down = 0;
        toGo = 0;
    }
    void setQuarter(int q)   { quarter = q; }
    void setDown   (int d)   { down = d; }
    void setToGo   (int tG)  { toGo = tG; }
    void setPoss   (bool pos){ poss = pos; }
    void setHometeam (Team hT) { Hometeam = hT; }
    void setVisitors (Team vT) { Visitors = vT; }
    void setcoachName (Team cH) { coachName = cH;}
    void setHomeCity (Team Hc) { HomeCity = Hc;}
 
    int getQuarter() const { return quarter;}
    int getDown() const { return down;}
    int getToGo() const { return toGo;}
    bool getPoss() const { return poss;}
    Team getHometeam() const { return Hometeam; }
    Team getVisitors() const { return Visitors; }
    Team getcoachName() const { return coachName;}
    Team getHomeCity() const { return HomeCity; }

    void showScoreboard()
    {
        string color,colorRed, colorHome, colorVisitor = "";
        string reset = "\x1b[0m";

        system("cls"); //clears the screen after loop refresh
        color = "\x1b[32;1m";
        colorRed = "\x1b[31;15m";
        colorHome = "\x1b[33;15m";
        colorVisitor = "\x1b[36;15m";

        cout << color << "__________ Football Scoreboard __________" << reset << endl;
        //cout << setw(24) << "||10:37||" << endl;
        for( int i = 0; i < 40; i++) {cout << "*";}
        cout << endl;
        cout << colorHome <<setw(9)<< "HomeTeam" << colorVisitor << setw(29) <<"Visitors" << reset << endl;
        cout << setw(10) <<  Hometeam.getTeamName() << setw(29) << Visitors.getTeamName()  << endl;

        cout << setw(6) << Hometeam.getTeamScore() << setw(30) << Visitors.getTeamScore() << endl;

        if(poss == true)//displays the possession of the ball initially but changes due to user input selection
        {
            cout << setw(22)  << colorRed << "O<"<< reset << " POSS" << endl;
        }
        else
        {
            cout << setw(22) <<  "POSS" << colorRed << " >O" << reset << endl;
        }

        cout << setw(25) << "Quarter: " << quarter << endl;
        cout << "\n" << endl;

        cout << setw(10) << getDown() << " < Down" << setw(16) << "To Go > " << getToGo() << "\n" << endl;

        cout << colorHome << setw(6) << Hometeam.getCoachName() << colorVisitor << setw(30)<<  Visitors.getCoachName() << reset << endl;
        cout << colorHome<< setw(6) << Hometeam.getHomeCity() << colorVisitor<< setw(30) << Visitors.getHomeCity() << reset << endl;

        for( int i = 0; i < 40; i++) {cout << "*";}
        cout << endl;
    };
};

void scorebaordEdit()
{
    Scoreboard s;
    Team HometeamBoard;//object for Team that becomes Scoreboard member
    Team VisitorsBoard;//object for Team that becomes Scoreboard member
      
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

    s.setHometeam(HometeamBoard);
    s.setVisitors(VisitorsBoard);
      
    do 
    {
        s.showScoreboard();
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
        cout << "Enter Choice Here....> ";
        cout << MenuReset;// reset menu color to white for legibility in choice selection
        cin >> choice;

        if(choice == 'A' || choice == 'a')
        {
            cout << "\nHometeam Name Update \n";
            cout << "What Is The New Team Name? ";
            cin >> newTeamName;
            HometeamBoard.setTeamName(newTeamName);
            cout << "Updating Team Name for Hometeam to " << HometeamBoard.getTeamName() << endl;
            Sleep(1); 

        }
        else if(choice == 'B' || choice == 'b')
        {
            cout << "\nVisitors Name Update \n";
            cout << "What Is The New Team Name?...> ";
            cin >> newTeamName;
            VisitorsBoard.setTeamName(newTeamName);
            cout << "Updating Team  Name for Visitors to  " << VisitorsBoard.getTeamName() << endl;
            Sleep(1);
        }
        else if(choice == 'C' || choice == 'c')
        {
            cout << "\nHometeam Score Update \n" ;
            cout << "What is the new score?...> ";
            cin >> newTeamScore;
            HometeamBoard.setTeamScore(newTeamScore);
            cout << "\nUpdating New Hometown Score To ..." << HometeamBoard.getTeamScore() << endl;
            Sleep(1);
        }
        else if(choice == 'D' || choice == 'd')
        {
            cout << "\nVisitor Score Update \n" ;
            cout << "What Is The New Score?...> ";
            cin >> newTeamScore;
            VisitorsBoard.setTeamScore(newTeamScore);
            cout << "\nUpdating New Visitor Score To ..." << VisitorsBoard.getTeamScore() << endl;
            Sleep(1);
        }    
        else if(choice == 'E' || choice == 'e')
        {
            cout << "\nQuarter Update \n";
            cout << "What Is The Updated Quarter? ...>";
            cin >> newQuarter;
            s.setQuarter(newQuarter);
            cout << "\nUpdating Quarter To ..." << s.getQuarter() << endl;
            Sleep(1);
        }
        else if(choice == 'F' || choice == 'f')
        {
            cout << "\nDown Update \n";
            cout << "What is the new Down? ...>";
            cin >> newDown;
            s.setDown(newDown);
            cout << "\nUpdating Down To ..." << s.getDown() << endl;
            Sleep(1);
        }
        else if(choice == 'G' || choice == 'g')
        {
            cout << "\nTo Go Update \n";
            cout << "What Is The New To Go? ...>";
            cin >> newToGo;
            s.setToGo(newToGo);
            cout << "\nUpdating  To Go To ..." << s.getToGo() << endl;
            Sleep(1);
        }
        else if(choice == 'H' || choice == 'h')
        {
            cout << "\nHometeam Coach Name Update\n";
            cout << "What Is The Coach Name?...>";
            cin >> newCoachName;
            HometeamBoard.setCoachName(newCoachName);
            cout << "\nUpdating Coach Name To ..." << HometeamBoard.getCoachName() << endl;
            Sleep(1);
        }
        else if(choice == 'I' || choice == 'i')
        {
            cout << "\nVisitors Coach Name Update\n";
            cout << "What Is The Coach Name?...>";
            cin >> newCoachName;
            VisitorsBoard.setCoachName(newCoachName);
            cout << "\nUpdating Coach Name To ..." << VisitorsBoard.getCoachName() << endl;
            Sleep(1);
        }
        else if(choice == 'J' || choice == 'j')
        {
            cout << "\nHometeam City Update\n";
            cout << "What Is The City Name?...>";
            cin >> newHomeCity;
            HometeamBoard.setHomeCity(newHomeCity);
            cout << "\nUpdating Hometeam City Name To ..." << HometeamBoard.getCoachName() << endl;
            Sleep(1);
        }
        else if(choice == 'K' || choice == 'k')
        {
            cout << "\nVisitors City Update\n";
            cout << "What Is The City Name?...>";
            cin >> newHomeCity;
            VisitorsBoard.setHomeCity(newHomeCity);
            cout << "\nUpdating Visitors City Name To ..." << VisitorsBoard.getCoachName() << endl;
            Sleep(1);
        }
        else if(choice == 'L' || choice == 'l')
        {
            cout << "\nPossession Update\n";
            cout << "Who Has Possesion?( 1 For Hometeam, 0 For Visitors)...>";
            cin >> newPoss;
            s.setPoss(newPoss);
            cout << "\nUpdating Possesssion To ... " << s.getPoss() << endl;
            Sleep(2);
        }
        s.setHometeam(HometeamBoard);
        s.setVisitors(VisitorsBoard);               
    }
    while(choice != 'x' && choice != 'X');
    {
        cout << "\nAnd That's Game Over.... See Ya Later Champ" << endl;
        cout << "\nGO Cowboys! " << endl;
    }
}