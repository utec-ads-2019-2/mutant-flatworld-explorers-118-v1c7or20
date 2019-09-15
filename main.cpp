#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool lost(int x0,int x1){
    return x1>x0 and 0<x1;
}
void change(char &orientacion, char w, char x, char y, char z){
    switch (orientacion){
        case 'N':
            orientacion=w;
            break;
        case 'S':
            orientacion=x;
            break;
        case 'E':
            orientacion=y;
            break;
        case 'W':
            orientacion=z;
            break;
        default:
            break;
    }
}

int main(){
    int x0,y0,x1=0,y1=0;
    char orientacion;
    string direcciones;
    bool islostx ,islosty ;
    cin>>x0>>y0;
    int scent[2][x0*y0];

    while(cin>>x1>>y1>>orientacion>>direcciones){
        islostx = false, islosty = false;
        for (char & direccion : direcciones) {
            switch (direccion){
                case 'F':
                        switch (orientacion){
                            case 'N':
                                y1=y1+1;
                                islosty = lost(y0,y1);
                                break;
                            case 'S':
                                y1=y1-1;
                                islosty = lost(y0,y1);
                                break;
                            case 'E':
                                x1=x1+1;
                                islostx = lost(x0,x1);
                                break;
                            case 'W':
                                x1=x1-1;
                                islostx = lost(x0,x1);
                                break;
                            default:
                                break;
                        }
                    break;
                case 'R':
                    change(orientacion,'E','W','S','N');
                    break;
                case 'L':
                    change(orientacion,'W','E','N','S');
                    break;
                default:
                    break;
            }
        }
        if (islostx or islosty){
            if (islostx){
                cout<<x1-1<<" "<<y1<<" "<<orientacion<<" LOST"<<endl;
            }
            else{
                cout<<x1<<" "<<y1-1<<" "<<orientacion<<" LOST"<<endl;
            }
        } else{
            cout<<x1<<" "<<y1<<" "<<orientacion<<endl;
        }
    }
    return 0;
}