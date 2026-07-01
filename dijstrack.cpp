#include <bits/stdc++.h>
#include<iostream>
#define maxx 200005
#define unoe18 1e18
#define nl "\n"
#define yes "YES\n"
#define no "NO\n"
#define es " "
using namespace std;
typedef long long int ll;
ll gcd(ll a, ll b){if(b==0) return a;return gcd(b, a%b);}

vector<pair<int,int>> grafo[maxx];
ll distancia[maxx];
int padre[maxx]; // es para guradar la ruta;

void dijstrack(ll origen){
    // para la cola= {distancia_actual, nodo};
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>> >cola;
    // como no se conoce ninguna distancia y se va a hacer la comparacion, es necesario poner las distancias en el maximo;
    for(int i=1; i<maxx; i++){
        distancia[i]= unoe18;
        padre[i]= -1;
    }
      // El origen está a distancia 0 de sí mismo
    distancia[origen]=0;

    cola.push({0,origen});
     while(!cola.empty()){
        ll distancia_actual= cola.top().first;
        ll nodo_actual= cola.top().second;
        cola.pop();


        // en lugar de vsitado es compracion de si encontre una disyancia enor, si no, pass;
        if(distancia_actual > distancia[nodo_actual]) continue;
        // si no, recorro todos los veinos

        for(auto vecino: grafo[nodo_actual]){

            ll nodo_vecino= vecino. first;
            ll peso= vecino.second;

            if(distancia[nodo_actual]+ peso< distancia[nodo_vecino]){ // si s[i, se actualiza la distancia en el nodo
                distancia[nodo_vecino]= distancia[nodo_actual]+ peso;
                padre[nodo_vecino]= nodo_actual;
                cola.push({distancia[nodo_vecino], nodo_vecino});

            }
        }
     }


}
void ruta( ll destino){
    if(destino == -1) return;
    ruta(padre[destino]);
    cout<< destino << "-> ";
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll t=1;
 //   cin>> t;
    while(t--){
        ll n,m; cin>> n>> m;
        // n= nodos, m= aristas;
        for(int i=0; i< m; i++){
            ll origen, destino, peso;
            cin>> origen>> destino>> peso;
            grafo[origen].push_back({destino, peso});
            grafo[destino]. push_back({origen, peso});


        }
        ll origen; cin>> origen;
        dijstrack(origen); // asi se calcualn las dtancia minimas del origen a los demas nodos;
        // ahora, si me piden hasta cierto nodo, pues nadamos llamo a la funcion el orgen e imprimo la diacnia en destino;


        // comprobar que funciona

        for(int i = 1; i <= n; i++){
            cout << "Nodo " << i << ": ";

            if(distancia[i] == unoe18){ cout << "UKN";}
            else{ cout << distancia[i] << es; ruta(i); }
            cout << nl;
         }

    }

    return 0;
}
