#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    // Constructeur
    Employe(string n, int i, float salaire) {
        nom = n;
        id = i;
        salaireDeBase = salaire;
    }

    // Methode virtuelle
    virtual void afficherInfos() const {
        cout << "Nom: " << nom << endl;
        cout << "ID: " << id << endl;
        cout << "Salaire de base: " << salaireDeBase << " DH" << endl;
    }

    // Destructeur virtuel
    virtual ~Employe() {
        cout << "Destructeur Employe: " << nom << endl;
    }
};

// Classe Permanent
class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float salaire, float prime)
        : Employe(n, i, salaire) {
        primeAnnuelle = prime;
    }

    void afficherInfos() const override {
        cout << "\n--- Employe Permanent ---" << endl;
        Employe::afficherInfos();
        cout << "Prime annuelle: " << primeAnnuelle << " DH" << endl;
    }

    ~Permanent() override {
        cout << "Destructeur Permanent" << endl;
    }
};

// Classe Contractuel
class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;

public:
    Contractuel(string n, int i, float salaire,
                int duree, float taux)
        : Employe(n, i, salaire) {
        dureeContrat = duree;
        tauxHoraire = taux;
    }

    float calculerSalaireMensuel(int heures) const {
        return heures * tauxHoraire;
    }

    void afficherInfos() const override {
        cout << "\n--- Employe Contractuel ---" << endl;
        Employe::afficherInfos();
        cout << "Duree du contrat: " << dureeContrat << " mois" << endl;
        cout << "Taux horaire: " << tauxHoraire << " DH" << endl;
        cout << "Salaire mensuel (160 heures): "
             << calculerSalaireMensuel(160) << " DH" << endl;
    }

    ~Contractuel() override {
        cout << "Destructeur Contractuel" << endl;
    }
};

int main() {

    // Tableau dynamique de pointeurs
    Employe** employes = new Employe*[3];

    // Creation des employes
    employes[0] = new Permanent("Amine", 101, 5000, 2000);

    employes[1] = new Contractuel("Sara", 102, 3000, 12, 50);

    employes[2] = new Permanent("Youssef", 103, 6000, 3000);

    // Affichage polymorphique
    cout << "===== LISTE DES EMPLOYES =====" << endl;

    for (int i = 0; i < 3; i++) {
        employes[i]->afficherInfos();
    }

    // Liberation de la memoire
    cout << "\n===== LIBERATION DE LA MEMOIRE =====" << endl;

    for (int i = 0; i < 3; i++) {
        delete employes[i];
    }

    delete[] employes;

    return 0;
}