/*
 Sam Sytsma
 C++ Fall 2022
 Due: Dec. 12, 2022
 Lab 7 Battleship
 This Lab is a demo of my ability to write a C++ program that runs battleship.
 */

#include <iostream>
#include <iomanip>

using namespace std;

typedef char board[10][10][6];

void iniBoard(board Board);
void OutputBoard(board Board, int player);
void uPlacement(board Board);
void cPlacement(board Board);
void XPlacement(int& xpoint);
void YPlacement(int& ypoint);
void DirectionPlacement(int& dir);
/*
         __________________________________________________________
*/
int main() {
    bool again = true ;
    bool game = true ;
    int player = 0 ;
    int wins = 0 ;
    int losses = 0 ;
    
    board Board;
    iniBoard(Board);
    uPlacement(Board);
    cPlacement(Board);
    
    return 0;
}
/*
         __________________________________________________________
*/
void iniBoard(board Board) {
    for ( int y = 0 ; y < 10 ; y++ ) {
        for ( int x = 0 ; x < 10 ; x++ ) {
            for ( int z = 0 ; z < 6 ; z ++ ) {
                Board [ y ] [ x ] [ z ] = '~' ;
            }
        }
    }
}
void OutputBoard(board Board, int player ) {
    for ( int z = 0 ; z < player+2 ; z++ ) {
        cout << endl ;
        cout << "   1 2 3 4 5 6 7 8 9 10" << endl ;
        for ( int y = 0 ; y < 10 ; y++ ) {
            cout << setw(2) << y +1 ;
            cout << ' ' ;
            for ( int x = 0 ; x < 10 ; x++ ) {
                cout << Board [ y ] [ x ] [ z ] << ' ' ;
            }
            cout << endl ;
        }
    }
}
void uPlacement(board Board){
    int dir;
    int xpoint;
    int ypoint;
    char stype;
    int slength;
    
    for (int a = 0; a < 5; a++){
        bool print = true;
        OutputBoard (Board, 0);
        switch (a) {
            case 0:
                stype = '5';
                slength = 5;
                cout << "\nPlease place your Carrier (length 5): \n";
                break;
            case 1:
                stype = '4';
                slength = 4;
                cout << "\nPlease place your Battleship (length 4): \n";
                break;
            case 2:
                stype = '3';
                slength = 3;
                cout << "\nPlease place your Cruiser (length 3): \n";
                break;
            case 3:
                stype = '2';
                slength = 3;
                cout << "\nPlease place your Submarine (length 3): \n";
                break;
            case 4:
                stype = '1';
                slength = 2;
                cout << "\nPlease place your Destroyer (length 2): \n";
                break;
        }
        XPlacement(xpoint);
        if ( !cin ){
            cout << "No input" ;
            break;
        }
        if (xpoint > 10 || xpoint < 0){
            cout << "Invalid" << endl ;
            a-- ;
            continue ;
        }
        YPlacement(ypoint);
        if ( !cin ){
            cout << "No input" ;
        }
        if (ypoint > 10 || ypoint < 0){
            cout << "Invalid" << endl ;
            a-- ;
            continue ;
        }
        DirectionPlacement(dir);
        
        for ( int x = 0 ; x < slength ; x++ ) {
            if ( dir == 1 ) {
                if ( Board [ ypoint-x ] [ xpoint ] [ 1 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 2 ) {
                if ( Board [ ypoint+x ] [ xpoint ] [ 1 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 3 ) {
                if ( Board [ ypoint ] [ xpoint-x ] [ 1 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 4 ) {
                if ( Board [ ypoint ] [ xpoint+x ] [ 1 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else {
                if ( Board [ ypoint ] [ xpoint+x ] [ 1 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            }
            if ( !print ) {
                break ;
            }
        }
        for ( int x = 0 ; x < slength ; x++ ) {
            if ( dir == 1 ) {
                if ( ypoint-x < 0 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 2 ) {
                if ( ypoint+x > 9 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 3 ) {
                if ( xpoint-x < 0 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 4 ) {
                if ( xpoint+x > 9 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else {
                if ( xpoint+x > 9 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            }
            if ( !print ) {
                break ;
            }
        }
        if ( print ) {
            for ( int x = 0 ; x < slength ; x++ ) {
                if ( dir == 1 ) {
                    Board [ ypoint-x ] [ xpoint ] [ 1 ] = '#' ;
                    Board [ ypoint-x ] [ xpoint ] [ 4 ] = stype ;
                } else if ( dir == 2 ) {
                    Board [ ypoint+x ] [ xpoint ] [ 1 ] = '#' ;
                    Board [ ypoint+x ] [ xpoint ] [ 4 ] = stype ;
                } else if ( dir == 3 ) {
                    Board [ ypoint ] [ xpoint-x ] [ 1 ] = '#' ;
                    Board [ ypoint ] [ xpoint-x ] [ 4 ] = stype ;
                } else if ( dir == 4 ) {
                    Board [ ypoint ] [ xpoint+x ] [ 1 ] = '#' ;
                    Board [ ypoint ] [ xpoint+x ] [ 4 ] = stype ;
                } else {
                    Board [ ypoint ] [ xpoint+x ] [ 1 ] = '#' ;
                    Board [ ypoint ] [ xpoint+x ] [ 4 ] = stype ;
                }
            }
        }
    }
}
void cPlacement(board Board){
    int dir;
    int xpoint;
    int ypoint;
    char stype;
    int slength;
    
    cout << "The computer will now place its ships...";
    
    for (int a = 0; a < 5; a++){
        bool print = true;
        switch (a) {
            case 0:
                stype = '5';
                slength = 5;
                break;
            case 1:
                stype = '4';
                slength = 4;
                break;
            case 2:
                stype = '3';
                slength = 3;
                break;
            case 3:
                stype = '2';
                slength = 3;
                break;
            case 4:
                stype = '1';
                slength = 2;
                break;
        }
        srand(time(NULL));
        
        xpoint = rand() %10;
        if ( xpoint > 10 || xpoint < 0 ) {
                    a-- ;
                    continue ;
                }
        ypoint = rand() %10;
        if ( ypoint > 10 || ypoint < 0 ) {
                    a-- ;
                    continue ;
                }
        dir = rand() %4+1;
        for ( int x = 0 ; x < slength ; x++ ) {
            if ( dir == 1 ) {
                if ( Board [ ypoint-x ] [ xpoint ] [ 3 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 2 ) {
                if ( Board [ ypoint+x ] [ xpoint ] [ 3 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 3 ) {
                if ( Board [ ypoint ] [ xpoint-x ] [ 3 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 4 ) {
                if ( Board [ ypoint ] [ xpoint+x ] [ 3 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else {
                if ( Board [ ypoint ] [ xpoint+x ] [ 3 ] == '#' ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            }
            if ( !print ) {
                break ;
            }
        }
        for ( int x = 0 ; x < slength ; x++ ) {
            if ( dir == 1 ) {
                if ( ypoint-x < 0 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 2 ) {
                if ( ypoint+x > 9 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 3 ) {
                if ( xpoint-x < 0 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else if ( dir == 4 ) {
                if ( xpoint+x > 9 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            } else {
                if ( xpoint+x > 9 ) {
                    cout << "Invalid" << endl ;
                    a-- ;
                    print = false ;
                }
            }
            if ( !print ) {
                break ;
            }
        }
        if ( print ) {
            for ( int x = 0 ; x < slength ; x++ ) {
                if ( dir == 1 ) {
                    Board [ ypoint-x ] [ xpoint ] [ 3 ] = '#' ;
                    Board [ ypoint-x ] [ xpoint ] [ 5 ] = stype ;
                } else if ( dir == 2 ) {
                    Board [ ypoint+x ] [ xpoint ] [ 3 ] = '#' ;
                    Board [ ypoint+x ] [ xpoint ] [ 5 ] = stype ;
                } else if ( dir == 3 ) {
                    Board [ ypoint ] [ xpoint-x ] [ 3 ] = '#' ;
                    Board [ ypoint ] [ xpoint-x ] [ 5 ] = stype ;
                } else if ( dir == 4 ) {
                    Board [ ypoint ] [ xpoint+x ] [ 3 ] = '#' ;
                    Board [ ypoint ] [ xpoint+x ] [ 5 ] = stype ;
                } else {
                    Board [ ypoint ] [ xpoint+x ] [ 3 ] = '#' ;
                    Board [ ypoint ] [ xpoint+x ] [ 5 ] = stype ;
                }
            }
        }
    }
}
void DirectionPlacement(int& dir){
    cout << "Please choose a direction you would like your ship to point(1: Up | 2:Down | 3:Left | 4:Right): ";
    cin >> dir;
}
void XPlacement(int& xpoint){
    cout << "Please choose a x location (top) to place your ship(1-10): ";
    cin >> xpoint;
    xpoint = xpoint - 1;
}
void YPlacement(int& ypoint){
    cout << "Please choose a y location (side) to place your ship(1-10): ";
    cin >> ypoint;
    ypoint = ypoint - 1;
}

