#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool lost( int x0, int x1){
    return x1>x0 or 0>x1;
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

bool iscent(int *array[],int perdido, int x, int y ){
    for (int i = 0; i <perdido ; i++) {
        if(array[0][i] == x and array [1][i] == y){
            return true;
        }
    }
    return false;
}

int main(){
    int x0,y0,x1=0,y1=0,perdidos = 0;
    char orientacion;
    string direcciones;
    bool islostx ,islosty ;
    cin>>x0>>y0;
   vector<vector<bool>> scent(y0 + 1, vector<bool> (x0 + 1, false));

    while(cin>>x1>>y1>>orientacion>>direcciones){
        islostx = false, islosty = false;
        for (char & direccion : direcciones) {
            if(!islostx and !islosty){
                switch (direccion){
                    case 'F':
                        switch (orientacion){
                            case 'N':
                                if(!scent[y1][x1]){
                                    y1=y1+1;
                                    islosty = lost(y0,y1);
                                }else{
                                    if ( y1+1<=y0){
                                        y1=y1+1;
                                        islosty = lost(y0,y1);
                                    }
                                }
                                break;
                            case 'S':
                                if(!scent[y1][x1]){
                                    if(lost(y0,y1-1)){
                                        islosty = lost(y0,y1-1);
                                        y1=1;
                                    }else{
                                        y1=y1-1;
                                        islosty = lost(y0,y1);
                                    }
                                }else{
                                    if ( y1-1>=0){
                                        y1=y1-1;
                                        islosty = lost(y0,y1);
                                    }
                                }
                                break;
                            case 'E':
                                if (!scent[y1][x1]){
                                    x1=x1+1;
                                    islostx = lost(x0,x1);
                                }else{
                                    if ( x1+1<=x0){
                                        x1=x1+1;
                                        islosty = lost(x0,x1);
                                    }
                                }
                                break;
                            case 'W':
                                if (!scent[y1][x1]){
                                    if(lost(x0,x1-1)){
                                        islostx = lost(x0,x1-1);
                                        x1=1;
                                    }else{
                                        x1=x1-1;
                                        islostx = lost(x0,x1);
                                    }
                                }else{
                                    if ( x1-1>=0){
                                        x1=x1-1;
                                        islosty = lost(x0,x1);
                                    }
                                }
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
        }
        if (islostx or islosty){
            if (islostx){
                scent[y1][x1-1] = true;
                cout<<x1-1<<" "<<y1<<" "<<orientacion<<" LOST"<<endl;
            }
            else{
                scent[y1-1][x1] = true;
                cout<<x1<<" "<<y1-1<<" "<<orientacion<<" LOST"<<endl;
            }
        } else{
            cout<<x1<<" "<<y1<<" "<<orientacion<<endl;
        }
    }
    return 0;
}