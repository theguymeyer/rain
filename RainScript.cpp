#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ

using namespace std;

#define DROP "0";
#define BLANK " ";

void PrintView(int rows, int cols, list<int>& myDrops) {

    list<int>::iterator iter = myDrops.begin();

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            // if position(r,c) is a RainDrop => cout << DROP; else => cout << BLANK;
            if(c == *iter) {
                cout << DROP;
                break;
            } else {
                cout << BLANK;
            }
            
        }

        // advance iterator at every full row print
        advance(iter,1);
        cout << endl;
    }

}

list<int>* UpdatePosition(list<int>& myDrops, int maxWidth) {

    myDrops.push_front(rand() % maxWidth);
    return &myDrops;


}

/* Expected Input: Terminal height (argv[1]) and width (argv[2]) 
 * Expected Output: Visual effect of rainfall using the ASCII "0"
 */
int main(int argc, char** argv) {

    // seed random
    srand(768);

    long int maxHeight = atol(argv[1]);
    long int maxWidth = atol(argv[2]);

    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    list<int>* drops = new list<int>(maxHeight, -1);
    unsigned int microTimeStep = atoi(argv[3]);

    for(;;) {
        //PrintView(maxHeight, maxWidth, *drops);
        PrintView(size.ws_row, size.ws_col, *drops);

        // new drop
        drops = UpdatePosition(*drops, size.ws_col);

        // delay speed
        usleep(microTimeStep);
    };

    return 0;
}