#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>

#include "Characters.h"
#include "Arena.h"

using namespace std;


int main() {
    system("chcp 1251");

    srand(time(NULL));

    Prey prey("prey", Point2D(1, 1), false);
    Predator predator("predator", Point2D(2, 2), false);

    Arena arena(10, 10, &prey, &predator);

    cout << arena;

    for (int i = 0; i <= 10; i++) {

        arena.clearStep();

        Point2D prevPreyLocation(prey.getLocation());
        Point2D prevPredLocation(predator.getLocation());

        prey.autoMove();
        predator.autoMove();

        if (arena.checkOverRun())
        {
            prey.moveTo(prevPreyLocation);
            predator.moveTo(prevPredLocation);
        }

        cout << arena;

        if (arena.ChekWin()) {
            return 0;
        }
         
        /*system("timeout /t 1");
        
        system("cls");*/
    }
    

    //
    //cout << "Enter a name for your prey: ";    
    //cin >> prey_name;
    //cout << "Enter a name for your predator: ";
    //cin >> predator_name;
    //
    //cout << "За кого хотите играть? (0-жертва, 1-хищник)" << endl;
    //cin >> sideChoice;

    //bool preyNpc = true;
    //if (sideChoice == 0) preyNpc = false;

    //Prey prey(prey_name, Point2D(1, 1), preyNpc);
    //Predator predator(predator_name, Point2D(7, 1), !preyNpc);

    //prey.autoMove();
    //predator.autoMove();


    //Arena arena(10, 10, &prey, &predator);
    //cout << arena << endl;

    //while (1) {
    //    
    //    if (sideChoice == 0) {
    //        if (check(prey, predator)) {
    //            
    //            predator.MoveTo(prey.getx(), prey.gety());
    //            
    //            cout << arena;
    //            cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
    //            return 0;
    //        }
    //        else {
    //            prey.AutoMove(arena, sideChoice);
    //            predator.AutoMove(arena, sideChoice);
    //            cout << arena << endl;
    //        }
    //    }
    //    
    //    else {
    //        if (check1(prey, predator)) {
    //            cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
    //            return 0;
    //        }
    //        else {
    //            prey.AutoMove(arena, sideChoice);
    //            predator.AutoMove(arena, sideChoice);
    //            cout << arena << endl;
    //        }
    //    }
    //}

    cout << "Жертва победина  \n" << endl;
    return 0;
}