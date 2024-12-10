#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// EXO 01

void clearScreen () {
    cout << "\033[H\033[2J";
}

const unsigned KReset   (0);
const unsigned KNoir    (30);
const unsigned KRouge   (31);
const unsigned KVert    (32);
const unsigned KJaune   (33);
const unsigned KBleu    (34);
const unsigned KMAgenta (35);
const unsigned KCyan    (36);

void couleur (const unsigned & coul) {
    cout << "\033[" << coul <<"m";
}

// EXO 02

typedef vector <char> CVLine; // un type représentant une ligne de la grille
typedef vector <CVLine> CMatrix; // un type représentant la grille
typedef pair   <unsigned, unsigned> CPosition; // un type représentant une coordonnée dans la grille

const char kTokenPlayer1 = 'X';
const char kTokenPlayer2 = 'O';
const char kEmpty        = '-';

void  showMatrix (const CMatrix & Matrice){ // TODO chancher la matriceafin d'afficher des obstacles et il y aura un joueur
    // cout << "\033[" << KReset <<"m";
    // cout << "\033[H\033[2J";
    for (size_t i = 0; i < size(Matrice); ++i) {
        for (size_t j = 0; j < size(Matrice[i]) ; ++j) {
            if(kTokenPlayer1 == Matrice[i][j]){ // le joueur 1 : cyan
                couleur(KCyan);
            }
            if(kTokenPlayer2 == Matrice[i][j]){ // le joueur 2 : jaune
                couleur(KJaune);
            }
            if(kEmpty == Matrice[i][j]){
                couleur(KReset);
            }
            cout << Matrice[i][j];
        }
        cout << endl;
    }
    couleur(KReset);
}

// EXO 03

void initMat (CMatrix & mat, unsigned nbLine, unsigned nbColumn, CPosition & posPlayer1, CPosition & posPlayer2){
    mat.resize(nbColumn, CVLine( nbLine, kEmpty));
    // initialise posplayer 1
    posPlayer1.first = 0;
    posPlayer1.second = 0;
    // initialise posplayer 2
    posPlayer2.first = nbColumn-1;
    posPlayer2.second = nbLine-1;
    // met les token a leur pos
    mat[posPlayer1.first][posPlayer1.second] = kTokenPlayer1;
    mat[posPlayer2.first][posPlayer2.second] = kTokenPlayer2;

    showMatrix(mat);
}

void moveToken1 (CMatrix & mat, char move, CPosition  & pos){
    switch(move){
        case 'z': // en haut
            mat[pos.first][pos.second] = kEmpty;
            pos.first = pos.first-1;
            mat[pos.first][pos.second]= kTokenPlayer1;
            break;

        case'd': // a droite
            mat[pos.first][pos.second] = kEmpty;
            pos.second = pos.second+1;
            mat[pos.first][pos.second]= kTokenPlayer1;
            break;

        case 'q': // a gauche
            mat[pos.first][pos.second] = kEmpty;
            pos.second = pos.second-1;
            mat[pos.first][pos.second]= kTokenPlayer1;
            break;

        case 's': // en bas
            mat[pos.first][pos.second] = kEmpty;
            pos.first = pos.first+1;
            mat[pos.first][pos.second]= kTokenPlayer1;
            break;

        case 't':
            mat[pos.first][pos.second]= kTokenPlayer1;
            break;

    }

    showMatrix(mat);
}


int ppal (){
    // partie 1
    CMatrix mat;
    CPosition posPlayer1;
    CPosition posPlayer2;

    unsigned nbLine;
    cout <<"donner le nb de ligne"<<endl;
    cin >> nbLine;

    unsigned nbColumnn;
    cout <<"donner le nb de colonne"<<endl;
    cin >> nbColumnn;

    initMat(mat,nbLine,nbColumnn,posPlayer1,posPlayer2);

    // partie2
    char move;

    //partie3
    bool isVictory = false;

    while(isVictory == false){

        cout << "tour a joueur 1" << endl;
        couleur(KVert);
        cin >> move;
        moveToken1(mat,move,posPlayer1);

        cout << " tour a joueur 2" << endl;
        couleur(KVert);
        cin >> move;
        moveToken2(mat,move,posPlayer2);

        if( posPlayer1 == posPlayer2 || posPlayer2 == posPlayer1)
            isVictory = true;
    }
    couleur(KVert);
    cout << " il y a un gagnant" << endl;
    return 0;
}

int main()
{

    // //exo02
    // // declare matrice
    // CMatrix mat (8, CVLine(10, kEmpty)); // le premier 10 est la taille du 1er vecteur, le second la taille du 2nd

    // mat [0][0] = kTokenPlayer1;
    // mat [7][9] = kTokenPlayer2;

    // // afficher martrice
    // showMatrix(mat);

    // exo03
    ppal();

    return 0;
}
