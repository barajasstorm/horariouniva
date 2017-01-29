//
//  main.cpp
//  moodle
//
//  Created by Juan Barajas on 1/29/17.
//  Copyright © 2017 Juan Barajas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//function prototypes
void create();
void display();

//global variables
vector<int> dia;
vector<string> materia, salon, horario, url;

// main menu
int main()
{
    int op;
    do
    {
        cout << "Menu Principal\n";
        cout << "1. Crear Nuevo Bloque\n";
        cout << "2. Generar HTML del Bloque\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> op;
        cout << endl;
        
        switch(op)
        {
            case 1: create();
                break;
            case 2: display();
                break;
            default:
                break;
        }
    } while (op!=3);
    return 0;
}

// create schedule
void create()
{
    int hiper, dia0, resp, cont = 1;
    string materia0, salon0, horario0, url0;
    
    cout << "Tu bloque de horario tendra hipervinculos? (Si = 1, No = 2): ";
    cin >> hiper;
    do
    {
        cin.ignore();
        cout << endl << "Agregando materia #" << cont << endl;
        cout << "Nombre de Materia: ";
        getline(cin, materia0);
        cout << "Salon: ";
        getline(cin, salon0);
        cout << "\nElegir Dia:" << endl;
        cout << "1. Lunes" << endl;
        cout << "2. Martes" << endl;
        cout << "3. Miercoles" << endl;
        cout << "4. Jueves" << endl;
        cout << "5. Viernes" << endl;
        cout << "Opcion: ";
        cin >> dia0;
        cin.ignore();
        cout << "\nHorario (Ejemplo: 7:00-8:45)" << endl;
        cout << "Ingresar: ";
        getline(cin, horario0);
        if(hiper == 1)
        {
            cout << "Ingresar URL de la materia: ";
            cin >> url0;
        }
        
        materia.push_back(materia0);
        salon.push_back(salon0);
        dia.push_back(dia0);
        horario.push_back(horario0);
        url.push_back(url0);
        
        cout << "\nDeseas agregar otra matera? (Si = 1, No = 2): ";
        cin >> resp;
        cont++;
    } while(resp!=2);
}

// generate html code
void display()
{
    int countdays = 0;
    bool days[5] = {false, false, false, false, false};
    cout << "<p><marquee behavior=\"scroll\" direction=\"left\">Ghost in the wires</marquee></p>" << endl;
    cout << "<p></p>" << endl;
    cout << "<title> Cuatrimestre </title>" << endl;
    cout << "<!-- CSS -->" << endl;
    cout << "<!-- HTML -->" << endl;
    cout << "<table class=\"bottomBorder\" style=\"width: 557px; height: 126px;\">" << endl;
    cout << "<tbody>" << endl;
    cout << "<tr>" << endl;
    cout << "<th><strong>Class</strong>" << endl;
    cout << "</th>" << endl;
    cout << "<th><strong>Room</strong>" << endl;
    cout << "</th>" << endl;
    for(int i=0; i<materia.size(); i++)
    {
        if(dia[i]==1) days[0] = true;
        if(dia[i]==2) days[1] = true;
        if(dia[i]==3) days[2] = true;
        if(dia[i]==4) days[3] = true;
        if(dia[i]==5) days[4] = true;
    }
    for(int i=0; i < 5; i++)
    {
        if(days[i]==true)
        {
            cout << "<th style=\"text-align: center;\"><strong>";
            if(i==0) cout << "Monday";
            if(i==1) cout << "Tuesday";
            if(i==2) cout << "Wednesday";
            if(i==3) cout << "Thursday";
            if(i==4) cout << "Friday";
            cout << "</strong>" << endl;
            cout << "</th>" << endl;
            countdays++;
        }
    }
    cout << "</tr>" << endl;
    for(int i=0; i < materia.size(); i++)
    {
        cout << "<tr>" << endl;
        cout << "<td><span style=\"color: #000000;\"><a href=\"";
        cout << url[i];
        
        
        cout << "\"><span style=\"color: #000000;\">";
        cout << materia[i];
        cout << "</span></a>.</span>" << endl;
        cout << "</td>" << endl;
        cout << "<td>";
        cout << salon[i];
        cout << "</td>";
        for(int x=0; x < 5; x++)
        {
            if(days[x]==true)
            {
                if(dia[i]==x+1)
                {
                    cout << "<td style=\"text-align: center;\"><a href=\"";
                    if(!url[i].empty())
                    {
                        cout << url[i];
                    }
                    else
                    {
                        cout << "#";
                    }
                    cout << "\">";
                    cout << horario[i];
                    cout << "</a>" << endl;
                    cout << "</td>" << endl;
                } else
                {
                    cout << "<td style=\"text-align: center;\"></td>" << endl;
                }
            }
        }
        cout << "</tr>" << endl;
    }
    cout << "</tbody>" << endl;
    cout << "</table>" << endl;
    cout << endl << endl;
    cout << "Kicking ass homie!!" << endl << endl;
}
