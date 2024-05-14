#include <iostream>
#include <string>

using namespace std;

class Jucator{
protected:
    int varsta, salariu;
    int  medieGoluriMarcate, minuteJucate;
    string nume, prenume, pozitie;
public:
    Jucator(string poz, string n, string p, int v, int mJ) : pozitie(poz), varsta(v), nume(n), prenume(p), minuteJucate(mJ){}
    Jucator(string poz,  string n, string p, int v, int mgm, int mJ) : pozitie(poz), varsta(v), nume(n), prenume(p), medieGoluriMarcate(mgm), minuteJucate(mJ){}

    void setSalariu(int s){
        salariu = s;
    }

    int getSalariu(){
        return salariu;
    }


    void Salariu(){
        int nr;
        if ( pozitie == "atacant")
            nr = 1;
        else if( pozitie == "mijlocas")
            nr = 2;

        switch(nr){
            case 1:
                {if(medieGoluriMarcate>0 && minuteJucate>=80)
                    setSalariu(5000);
                else if(medieGoluriMarcate == 0 && minuteJucate >= 80)
                    setSalariu(3500);
                else if(medieGoluriMarcate == 0 && minuteJucate < 80)
                    setSalariu(3000);
                break;}
            case 2:
                {if(medieGoluriMarcate>0 && minuteJucate>=80)
                    setSalariu(5000);
                else if(medieGoluriMarcate == 0 && minuteJucate >= 80)
                    setSalariu(4000);
                else if(medieGoluriMarcate == 0 && minuteJucate < 80)
                    setSalariu(3000);
                break;}
                    }
    }

    bool exista(){
        return (getSalariu() == 5000 || getSalariu() == 4000 || getSalariu() == 3000);
    }


    void afiseaza(){
        if(exista()){
            cout << "Noul transfer: " << endl;
            cout << nume << " " << prenume << ", " << pozitie << ", in varsta de " << varsta << " ani va avea un salariu lunar de " << getSalariu() << "$" << endl;
            }
        else
            cout << "Transferul nu s-a efectuat: " << nume << " " << prenume << endl;}

    ~Jucator(){
        cout<<endl<<"Destructorul s-a apelat";
    }

};

class Fundas : public Jucator{
private:
    int recuperari, suturiBlocate;
public:
        Fundas(string poz, string n, string p, int v, int mgm, int mJ, int rc, int sb) : Jucator(poz, n, p, v, mgm, mJ), recuperari(rc), suturiBlocate(sb) {}
        void Salariu(){
            if(medieGoluriMarcate>0 && minuteJucate>=80 && recuperari >= 6 && suturiBlocate > 5 )
                setSalariu(5000);
            else if(medieGoluriMarcate == 0 && minuteJucate >= 80 && recuperari < 6 && suturiBlocate > 5)
                setSalariu(4000);
            else if(medieGoluriMarcate == 0 && minuteJucate < 80 && recuperari < 6 && suturiBlocate < 5)
                setSalariu(3000);

        }

        void afiseaza(){
            if(exista())
                {cout << "Noul transfer: " << endl;
                cout << nume << " " << prenume << ", " << pozitie << ", in varsta de " << varsta << " ani va avea un salariu lunar de " << getSalariu() << "$" << endl;}
            else
                cout << "Transferul nu s-a efectuat: " << nume << " " << prenume << endl;
            }


};

class Portar : public Jucator{
private:
    int penaltyuriAparate,  medieGoluriPrimite;
public:
    Portar(string poz, string n, string p, int v, int mJ, int mgp, int pa) : Jucator(poz, n, p, v, mJ), medieGoluriPrimite(mgp), penaltyuriAparate(pa) {}
    void Salariu(){
        if(medieGoluriPrimite<5 && minuteJucate == 90 && penaltyuriAparate > 3)
            setSalariu(5000);
        else if(medieGoluriPrimite > 5 && minuteJucate == 90 && penaltyuriAparate < 3)
            setSalariu(4000);
        else if(medieGoluriPrimite > 5 && minuteJucate < 90 && penaltyuriAparate < 2)
            setSalariu(3000);
    }
    void afiseaza(){
        if(exista()){
            cout << "Noul transfer: " << endl;
            cout << nume << " " << prenume << ", " << pozitie << ", in varsta de " << varsta << " ani va avea un salariu lunar de " << getSalariu() << "$" << endl;}
        else
            cout << "Transferul nu s-a efectuat: " << nume << " " << prenume << endl;

    }


};

int main()
{
    Portar p1("portar", "Florin", "Nita", 21, 90, 2, 6);
    p1.Salariu();
    p1.afiseaza();
    cout<<endl;
    Jucator j1("atacant", "Adi", "Popa", 23, 5, 75);
    j1.Salariu();
    j1.afiseaza();
    cout<<endl;
    Fundas f1("fundas", "J.", "Dawa", 26, 0, 85, 5, 6);
    f1.Salariu();
    f1.afiseaza();
    cout<<endl;
    Jucator j2("mijlocas", "Toni", "Kroos", 27, 8, 90);
    j2.Salariu();
    j2.afiseaza();
    cout<<endl;
    Jucator j3("mijlocas", "Luca", "Modric", 30, 4, 70);
    j3.Salariu();
    j3.afiseaza();
    return 0;
}
