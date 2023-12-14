//pridedame bibliotekas
#include <iostream>
#include <fstream>

using namespace std;

int didz_koordinates_tikrinimas(int j1, int j2, int j3){ //funkcija, kuri sugr��ina skai�i�, kuris yra did�iausias

    if(j1>j2&&j1>j3){
        return j1;
    }
    else if(j2>j1&&j2>j3){
        return j2;
    }
    else return j3;
}

int maz_koordinates_tikrinimas(int k1, int k2, int k3){ //funkcija, kuri sugr��ina skai�i�, kuris yra ma�iausias
 if(k1<k2&&k1<k3){
    return k1;
 }
 else if(k2<k1&&k2<k3){
    return k2;
 }
 else return k3;
}

int did(int vienas,  int du){ //funkcija, kuri palygina skai�ius ir gr��ina t�, kuris yra didesnis
    int ats;
     if (vienas > du) {
        ats = vienas;
    }
    else {ats = du;}

    return ats;
}

int maz(int pirmas, int antras){ //funkcija, kuri palygina skai�ius ir gr��ina t�, kuris yra ma�esnis
    int atsakymas;
    if(pirmas < antras){
        atsakymas = pirmas;
    }
    else { atsakymas = antras;}
    return atsakymas;
}

int main() { //pagrindin� funkcija
    ifstream fin("duomenys.txt"); //failas, i� kurio nura�ysime informacij�
    ofstream fout("rezultatai.txt"); //failas, � kur� �ra�ysime rezultatus

    if (!fin || !fout) {  //tikriname, ar failai atsidaro ir ar jie randami
        cout << "Klaida atidarant failus." << endl;
        return 1;
    }

    int x1_1, y1_1, x1_2, y1_2, x2_1, y2_1, x2_2, y2_2, x3_1, y3_1, x3_2, y3_2; //sukuriami kintamieji

    fin >> x1_1 >> y1_1 >> x1_2 >> y1_2 >> x2_1 >> y2_1 >> x2_2 >> y2_2 >> x3_1 >> y3_1 >> x3_2 >> y3_2; //nura�oma informacija

    int x_1max = didz_koordinates_tikrinimas(x1_1, x2_1, x3_1); //i�kvie�iame funkcij�, kuri suranda did�iausi� kairiojo apatinio kampo x koordinate tarp 3 duot�
    cout<<x_1max<<endl; //patikriname ar suranda skai�ius
    int y_1max = didz_koordinates_tikrinimas(y1_1, y2_1, y3_1);//i�kvie�iame funkcij�, kuri suranda did�iausi� kairiojo apatinio kampo y koordinate tarp 3 duot�
    cout<<y_1max<<endl; //patikriname, ar suranda skai�ius
    int x_2min = maz_koordinates_tikrinimas(x1_2, x2_2, x3_2);//i�kvie�iame funkcij�, kuri suranda ma�iausi� de�iniojo vi�utinio kampo x koordinat� tarp 3 duot�
    cout<<x_2min<<endl;//patikriname, ar suranda skai�ius
    int y_2min = maz_koordinates_tikrinimas(y1_2, y2_2, y3_2);//i�kvie�iame funkcij�, kuri suranda ma�iausi� de�iniojo vi�utinio kampo y koordinat� tarp 3 duot�
    cout<<y_2min<<endl;//patikriname, ar suranda skai�ius


    int didesnisx = did(x_1max, x_2min); //priskiriame reik�m� skai�iui, kuris yra didesnis tarp ma�iausio de�iniojo vir�utinio kampo ir did�iausio kairiojo apatinio kampo x
    int didesnisy = did(y_1max, y_2min); //priskiriame reik�m� skai�iui, kuris yra didesnis tarp ma�iausio de�iniojo vir�utinio kampo ir did�iausio kairiojo apatinio kampo y
    int mazesnisx = maz(x_1max, x_2min);//priskiriame reik�m� skai�iui, kuris yra ma�esnis tarp ma�iausio de�iniojo vir�utinio kampo ir did�iausio kairiojo apatinio kampo x
    int mazesnisy = maz(y_1max, y_2min); //priskiriame reik�m� skai�iui, kuris yra ma�esnis tarp ma�iausio de�iniojo vir�utinio kampo ir did�iausio kairiojo apatinio kampo y


    int ilgis, plotis, plotas; //�vedame kintamuosius


    ilgis = didesnisy - mazesnisy; //apskai�iuojame bendro kvadarato ilg�, kai atimame didesn� y koordinat� i� ma�esn�s
    cout<<ilgis<<endl; //patikriname, ar toks ilgis

    plotis = didesnisx - mazesnisx; //apskai�iuojame bendro kvadrato plot�, kai atimame didesn� x koordinat� i� ma�esn�s
    cout<<plotis; //patikriname, ar toks plotis
    plotas = ilgis * plotis; //suskai�iuojame bendro kvadrato plot�

    fout << plotas; //�ra�ome atsakym� � rezultat� fail�

    //u�darome failus
    fin.close();
    fout.close();

    return 0;
}

