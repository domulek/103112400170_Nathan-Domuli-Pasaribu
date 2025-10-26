#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("jeruk" , 100, 3000);
    nodeB = alokasi("apel", 75, 4000);
    nodeC = alokasi("pir" , 87, 5000 );
    nodeD = alokasi("semangka", 43, 11500);
    nodeE = alokasi("durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);
    cout << "isi lost detelah dilakukan insert" << endl;
    printList(List);
    cout << " Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "isi list setelah dlakukan update " << endl;
    printList(List);
    cout << "jumlah node : " << endl;
    cout << endl;
    

    return 0;
}