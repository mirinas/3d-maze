#include <iostream>
#include <fstream>
#include <queue>
#include <tuple>

using namespace std;

struct ps{
    int x;
    int y;
    int z;

    ps(int x, int y, int z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
};

int arr[50][50][50];
int i;
int j;
int k;

void read(){
    for(int c=0; c<50; c++){
        for(int b=0; b<50; b++){
            for(int a=0; a<50; a++){
                arr[a][b][c]=-2;
            }
        }
    }

    fstream fin("input.txt");
    for(k=0; !fin.eof(); k++){
        string a="";
        getline(fin, a);
        for(j=0; a!="" && !fin.eof(); j++){
            for(i=0; i<a.length(); i++){
                switch(a[i]){
                case 'W':
                    arr[i][j][k]=-1;
                    break;
                case 'O':
                    arr[i][j][k]=0;
                    break;
                }
            }
            getline(fin, a);
        }
    }
}

void write(){
    cout<<"i="<<i<<", j="<<j<<", k="<<k<<endl;
    for(int c=0; c<k; c++){
        for(int b=0; b<j; b++){
            for(int a=0; a<i; a++){
                switch(arr[a][b][c]){
                case -1:
                    cout<<"W ";
                    break;
                case 0:
                    cout<<"O ";
                    break;
                default:
                    if(arr[a][b][c]>9){
                        cout<<arr[a][b][c];
                    }else{
                        cout<<arr[a][b][c]<<" ";
                    }

                }
                //cout<<arr[a][b][c]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int laisva(int x, int y, int z, int x0, int y0){
    if(arr[x][y][z]!=0){
        if(arr[x][y][z+1]!=0){
            return -1;
        }else{
            if(arr[x0][y0][z+1]==0){
                return 1;
            }
        }
    }else{
        return 0;
    }
}

void ejimas(int x, int y, int z){
    if(arr[x+1][y][z]>=arr[x][y][z]){
        arr[x][y][z]=arr[x+1][y][z]+1;
    }
    if(arr[x-1][y][z]>=arr[x][y][z]){
        arr[x][y][z]=arr[x-1][y][z]+1;
    }
    if(arr[x][y+1][z]>=arr[x][y][z]){
        arr[x][y][z]=arr[x][y+1][z]+1;
    }
    if(arr[x][y-1][z]>=arr[x][y][z]){
        arr[x][y][z]=arr[x][y-1][z]+1;
    }
    if(arr[x][y][z+1]>=arr[x][y][z]){
        arr[x][y][z]=arr[x][y][z+1]+1;
    }
    //istrizai
    if(arr[x+1][y][z-1]>=arr[x][y][z]){
        arr[x+1][y][z]=arr[x+1][y][z-1]+1;
        arr[x][y][z]=arr[x+1][y][z-1]+2;
    }
    if(arr[x-1][y][z-1]>=arr[x][y][z]){
        arr[x-1][y][z]=arr[x-1][y][z-1]+1;
        arr[x][y][z]=arr[x-1][y][z-1]+2;
    }
    if(arr[x][y+1][z-1]>=arr[x][y][z]){
        arr[x][y+1][z]=arr[x][y+1][z-1]+1;
        arr[x][y][z]=arr[x][y+1][z-1]+2;
    }
    if(arr[x][y-1][z-1]>=arr[x][y][z]){
        arr[x][y-1][z]=arr[x][y-1][z-1]+1;
        arr[x][y][z]=arr[x][y-1][z-1]+2;
    }
}

void eiti(int x, int y, int z){
    queue<ps> eile;
    eile.push(ps(x, y, z));

    while(!eile.empty()){
        ps pos = eile.front();
        eile.pop();
        int a = pos.x;
        int b = pos.y;
        int c = pos.z;
        if(c>0){
            while(arr[a][b][c-1]!=-1){
                ejimas(a, b, c);
                //arr[a][b][c]--;
                c--;
            }
        }
        ejimas(a, b, c);

        int h;
        h=laisva(a+1, b, c, a, b);
        if(h!=-1){
            eile.push(ps(a+1, b, c+h));
        }
        h=laisva(a-1, b, c, a, b);
        if(h!=-1){
            eile.push(ps(a-1, b, c+h));
        }
        h=laisva(a, b+1, c, a, b);
        if(h!=-1){
            eile.push(ps(a, b+1, c+h));
        }
        h=laisva(a, b-1, c, a, b);
        if(h!=-1){
            eile.push(ps(a, b-1, c+h));
        }
    }
}

int main(){
    read();
    eiti(6, 9, 11);

    write();
    return 0;
}
