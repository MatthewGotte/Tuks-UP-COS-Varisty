#include "SoccerPlayer.h"
#include "AttackPlayStyle.h"
#include "DefendPlayStyle.h"
#include "PossessionPlayStyle.h"

using namespace std;

int main(){
    PlayStyle** playStyles = new PlayStyle*[3];
    playStyles[0] = new AttackPlayStyle();
    playStyles[1] = new DefendPlayStyle();
    playStyles[2] = new PossessionPlayStyle();

    SoccerPlayer* messi = new SoccerPlayer("messi",playStyles[0]);

    int noPlayers;
    cout << "How many players? > ";
    cin >> noPlayers;
    cout << endl;
    SoccerPlayer** players = new SoccerPlayer*[noPlayers];
    for (int i = 0; i < noPlayers; i++) {
        cout << "Player " << i + 1 << ": name > ";
        string name;
        cin >> name;
        cout << "Style " << i + 1 << ": 1=>Attack, 2=>Defend, 3=>Possession > ";
        int style;
        cin >> style;
        if (style <= 0 || style > 3) {
            cout << "Invalid response!" << endl;
            return 0;
        }
        players[i] = new SoccerPlayer(name, playStyles[style - 1]);
        cout << endl;
    }

    cout << "Change a play style before game?[y/n] > ";
    char res;
    cin >> res;
    while (res == 'y') {
        cout << "Player number to change > ";
        int change;
        cin >> change;
        change--;
        if (change < 0 || change >= noPlayers) {
            cout << "Invalid player number! try again" << endl;
            continue;
        }
        //ask for new style:
        cout << "New style for " << change << ": 1=>Attack, 2=>Defend, 3=>Possession > ";
        int nStyle;
        cin >> nStyle;
        if (nStyle <= 0 || nStyle > 3) {
            cout << "Invalid style number! try again" << endl;
            continue;
        }
        players[change]->setPlayStyle(playStyles[nStyle - 1]);
        cout << "Player " << change << " style updated to ";
        if (nStyle == 1)
            cout << "Attack" << endl;
        else if (nStyle == 2)
            cout << "Defend" << endl;
        else cout << "Possession" << endl;
        //ask again:
        cout << endl;
        cout << "Change another player's style before game?[y/n] > ";
        char res;
        cin >> res;
        if (res != 'y')
            break;
    }

    cout << endl << "GAME STARTING" << endl;

    for (int i = 0; i < noPlayers; i++) {
        players[i]->play();
        players[i]->commitFoul();
        players[i]->play();
        players[i]->commitFoul();
        players[i]->play();
        players[i]->commitFoul();
        cout << endl;
    }

    //cleanup:
    for (int i = 0; i < noPlayers; i++) {
        delete players[i];
    }
    delete [] players;

    return 0;
}