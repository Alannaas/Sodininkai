//pridedame bibliotekas
#include <iostream>
#include <fstream>

using namespace std;

int didz_koordinates_tikrinimas(int j1, int j2, int j3){ //funkcija, kuri sugràþina skaièiø, kuris yra didþiausias

    if(j1>j2&&j1>j3){
        return j1;
    }
    else if(j2>j1&&j2>j3){
        return j2;
    }
    else return j3;
}

int maz_koordinates_tikrinimas(int k1, int k2, int k3){ //funkcija, kuri sugràþina skaièiø, kuris yra maþiausias
 if(k1<k2&&k1<k3){
    return k1;
 }
 else if(k2<k1&&k2<k3){
    return k2;
 }
 else return k3;
}

int did(int vienas,  int du){ //funkcija, kuri palygina skaièius ir gràþina tà, kuris yra didesnis
    int ats;
     if (vienas > du) {
        ats = vienas;
    }
    else {ats = du;}

    return ats;
}

int maz(int pirmas, int antras){ //funkcija, kuri palygina skaièius ir gràþina tà, kuris yra maþesnis
    int atsakymas;
    if(pirmas < antras){
        atsakymas = pirmas;
    }
    else { atsakymas = antras;}
    return atsakymas;
}

int main() { //pagrindinë funkcija
    ifstream fin("duomenys.txt"); //failas, ið kurio nuraðysime informacijà
    ofstream fout("rezultatai.txt"); //failas, á kurá áraðysime rezultatus

    if (!fin || !fout) {  //tikriname, ar failai atsidaro ir ar jie randami
        cout << "Klaida atidarant failus." << endl;
        return 1;
    }

    int x1_1, y1_1, x1_2, y1_2, x2_1, y2_1, x2_2, y2_2, x3_1, y3_1, x3_2, y3_2; //sukuriami kintamieji

    fin >> x1_1 >> y1_1 >> x1_2 >> y1_2 >> x2_1 >> y2_1 >> x2_2 >> y2_2 >> x3_1 >> y3_1 >> x3_2 >> y3_2; //nuraðoma informacija

    int x_1max = didz_koordinates_tikrinimas(x1_1, x2_1, x3_1); //iðkvieèiame funkcijà, kuri suranda didþiausià kairiojo apatinio kampo x koordinate tarp 3 duotø
    cout<<x_1max<<endl; //patikriname ar suranda skaièius
    int y_1max = didz_koordinates_tikrinimas(y1_1, y2_1, y3_1);//iðkvieèiame funkcijà, kuri suranda didþiausià kairiojo apatinio kampo y koordinate tarp 3 duotø
    cout<<y_1max<<endl; //patikriname, ar suranda skaièius
    int x_2min = maz_koordinates_tikrinimas(x1_2, x2_2, x3_2);//iðkvieèiame funkcijà, kuri suranda maþiausià deðiniojo viðutinio kampo x koordinatæ tarp 3 duotø
    cout<<x_2min<<endl;//patikriname, ar suranda skaièius
    int y_2min = maz_koordinates_tikrinimas(y1_2, y2_2, y3_2);//iðkvieèiame funkcijà, kuri suranda maþiausià deðiniojo viðutinio kampo y koordinatæ tarp 3 duotø
    cout<<y_2min<<endl;//patikriname, ar suranda skaièius


    int didesnisx = did(x_1max, x_2min); //priskiriame reikðmæ skaièiui, kuris yra didesnis tarp maþiausio deðiniojo virðutinio kampo ir didþiausio kairiojo apatinio kampo x
    int didesnisy = did(y_1max, y_2min); //priskiriame reikðmæ skaièiui, kuris yra didesnis tarp maþiausio deðiniojo virðutinio kampo ir didþiausio kairiojo apatinio kampo y
    int mazesnisx = maz(x_1max, x_2min);//priskiriame reikðmæ skaièiui, kuris yra maþesnis tarp maþiausio deðiniojo virðutinio kampo ir didþiausio kairiojo apatinio kampo x
    int mazesnisy = maz(y_1max, y_2min); //priskiriame reikðmæ skaièiui, kuris yra maþesnis tarp maþiausio deðiniojo virðutinio kampo ir didþiausio kairiojo apatinio kampo y


    int ilgis, plotis, plotas; //ávedame kintamuosius


    ilgis = didesnisy - mazesnisy; //apskaièiuojame bendro kvadarato ilgá, kai atimame didesnæ y koordinatæ ið maþesnës
    cout<<ilgis<<endl; //patikriname, ar toks ilgis

    plotis = didesnisx - mazesnisx; //apskaièiuojame bendro kvadrato plotá, kai atimame didesnæ x koordinatë ið maþesnës
    cout<<plotis; //patikriname, ar toks plotis
    plotas = ilgis * plotis; //suskaièiuojame bendro kvadrato plotà

    fout << plotas; //áraðome atsakymà á rezultatø failà

    //uþdarome failus
    fin.close();
    fout.close();

    return 0;
}

