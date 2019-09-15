#include <iostream>
#include <string>

using namespace std;

bool lost(int x0,int x1){
    return x1>x0;
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
    int x0,x1,y0,y1;
    char orientacion;
    string direcciones;
    bool islost = false;
    cin>>x0>>y0;
    while(cin>>x1>>y1>>orientacion>>direcciones){
        for (char & direccion : direcciones) {
            switch (direccion){
                case 'F':
                    if(!islost){
                        switch (orientacion){
                            case 'N':
                                    y1=y1+1;
                                    islost = lost(y0,y1);
                                break;
                            case 'S':
                                    y1=y1-1;
                                    islost = lost(y0,y1);
                                break;
                            case 'E':
                                    x1=x1+1;
                                    islost = lost(x0,x1);
                                break;
                            case 'W':
                                    x1=x1-1;
                                    islost = lost(x0,x1);
                                break;
                            default:
                                break;
                        }
                    }
                case 'R':
                    change(orientacion,'E','W','S','N');
                    break;
                case 'L':
                    change(orientacion,'E','W','S','N');
                    break;
                default:
                    break;
            }
        }
        if (islost){
            cout<<x1-1<<" "<<y1-1<<" "<<orientacion<<" LOST"<<endl;
        } else{
            cout<<x1-1<<" "<<y1-1<<" "<<orientacion<<endl;
        }
    }
    return 0;
}