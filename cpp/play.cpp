#include "Gomoku.h"
#include <iostream>
#include "RandomPolicy.h"
#include "MinimaxPolicy.h"
#include <time.h>

using namespace std;



int main(){
    int iteration = 1;
    vector<int> numberWin(2);
    vector<int> numSteps(2);
    srand((unsigned)time(NULL));

    for (int i = 0; i < iteration; i++) {
        Gomoku newGame(1);
        //print "start a new Gomoku game with board size %dx%d"%(boardSize, boardSize)
    
        //baselinePolicy = game.BaselinePolicy()
        RandomPolicy randomPolicy;
        MinimaxPolicy minimaxPolicy(1);
        //vector<vector<int> > time_to_move;
        bool init = true;
        while (newGame.isEnd() < 0) {
            
            int nextPlayer = newGame.nextPlayer;
            //start = time.time()
            int action = -1;
            
            if (nextPlayer == 1){
            
                if (init) {
                    init = false;
                    action = 108;
                } else
                    action = minimaxPolicy.getNextAction(newGame);        
                //action = minimaxPolicy.getNextAction(newGame)
                //print "player 1 selects ", action
            }else
                action = randomPolicy.getNextAction(newGame);
                //action = baselinePolicy.getNextAction(newGame)
                //print "player 2 selects ", action
            //print time.time() - start
            //time_to_move[nextPlayer - 1].append(time.time() - start)
            //print "player %d places on (%d, %d)"%(nextPlayer, action[0], action[1])
            newGame.updateBoard(action);
            //newGame.print_board();
            //inp = input('Enter')
            //cout << action << endl;
            //cout << newGame.isEnd() << endl;
            newGame.print_board();
            tuple<int,int,int> state = newGame.currentGame();
            int losePlayer = get<0>(state);
            int totalStep0 = get<1>(state);
            int totalStep1 = get<2>(state);
            cout << totalStep0 + totalStep1 << endl;
            //system("pause");
        }
        //cout << newGame.isEnd() << endl;

        tuple<int,int,int> state = newGame.currentGame();
        int losePlayer = get<0>(state);
        int totalStep0 = get<1>(state);
        int totalStep1 = get<2>(state);
        //losePlayer, totalStep0, totalStep1 = newGame.currentGame()
        int winPlayer = 3 - losePlayer;
        if (newGame.isEnd() != 0) {
            numberWin[winPlayer-1] += 1;
            const int j = winPlayer-1;
            if (winPlayer == 1) {
                numSteps[winPlayer-1] = totalStep0;
            } else if(winPlayer == 2) {
                numSteps[winPlayer-1] = totalStep1;
            }
            
            cout << "#### player "<< winPlayer << "wins" << endl;
        } else {
            cout << "break even!";
        }
        newGame.print_board();
        //print(newGame.isEnd())
    }
    return 0;
}

