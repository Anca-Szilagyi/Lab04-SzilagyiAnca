#pragma once

class Aplicatie {
private:
    char* nume;
    char* numarInmatriculare;
    char* status;
public:
    Aplicatie();
    Aplicatie(const char*, const char*, const char*);
    Aplicatie(const Aplicatie&);
    Aplicatie& operator=(const Aplicatie& app);

    char* getNume();
    char* getNrInmatriculare();
    char* getStatus();
    void setNume(char* n);
    void setNrInmatriculare(char*);
    void setStatus(char*);
    bool operator==(const Aplicatie& app);
    ~Aplicatie(); //destructor - elibereaza toate resursele alocate de constructor
};

//constructorul poate sa aloce dinamic ceva in memorie;
//constr poate sa deschida/inchida fisiere; etc.