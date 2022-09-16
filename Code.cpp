/*
 
 自製c++五子棋遊戲
 無版權限制
 高雄中學212黃經幃
 GITHUB連結：https://github.com/SongSongLook/Gobang-game
 made by.songsonglook
 
*/

//程式開始
#include<iostream>
using namespace std;
bool Yco(int Long,char Player,int x,int y,char map[20][20])
{
    int Connect=1;
    for(int i=1;;i++)
    {
        if(map[y][x+i]==Player) Connect++;
        else break;
    }
    for(int i=1;;i++)
    {
        if(map[y][x-i]==Player) Connect++;
        else break;
    }
if(Connect>=Long) return true;
else return false;
}
//程式分割線--------------------------------------------------
bool Xco(int Long,char Player,int x,int y,char map[20][20])
{
    int Connect=1;
    for(int i=1;;i++)
    {
        if(map[y+i][x]==Player) Connect++;
        else break;
}
for(int i=1;;i++)
{
    if(map[y-i][x]==Player) Connect++;
    else break;
}
if(Connect>=Long) return true;
else return false;
}
//程式分割線--------------------------------------------------
bool ObliWin1(int Long,int x,int y,char Player,char map[20][20])
{
    int Connect=1;
    for(int i=1;;i++){
        if(map[y+i][x+i]==Player) Connect++;
        else break;
    }
    for(int i=1;;i++){
        if(map[y-i][x-i]==Player) Connect++;
        else break;
    }
    if(Connect>=Long) return true;
    else return false;
}
bool ObliWin2(int Long,int x,int y,char Player,char map[20][20])
{
    int Connect=1;
    for(int i=1;;i++){
        if(map[y+i][x-i]==Player) Connect++;
        else break;
    }
    for(int i=1;;i++){
        if(map[y-i][x+i]==Player) Connect++;
        else break;
    }
    if(Connect>=Long) return true;
    else return false;
}
//程式分割線--------------------------------------------------
bool winner(int Long,int x,int y,char Player,char map[20][20])
{
    if(Yco(Long,Player,x,y,map)==true||Xco(Long,Player,x,y,map)==true||ObliWin1(Long,Player,x,y,map)==true||ObliWin2(Long,Player,x,y,map)==true) return true;
        else return false;
}
//程式分割線--------------------------------------------------
bool TFset(char Player,int Xcoordinate,int Ycoordinate,char map[20][20]){
    if(Xcoordinate>=0 && Xcoordinate<20 && Ycoordinate>=0 && Ycoordinate<20 && map[Ycoordinate][Xcoordinate]==' ')
    {
    map[Ycoordinate][Xcoordinate]=Player; return true;
    }
    else{ cout<<"輸入錯誤"<<endl; return false;
    }
}
//程式分割線--------------------------------------------------
void show(char map[20][20])
{
    cout<<"  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20"<<endl;
    for(int i=19;i>=0;i--){
        cout<<"  －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－"<<endl;
        if(i+1<10)
            cout<<"0"<<i+1;
        else
            cout<<i+1;
        for(int j=0;j<20;j++) {
            cout<<"|";
            cout<<" "<<map[i][j]<<" "; }
            cout<<"|";
        if(i+1<10)
            cout<<"0"<<i+1<<endl;
        else
            cout<<i+1<<endl;
}
    cout<<"  －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－"<<endl;
    cout<<"  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20"<<endl;
}
//程式分割線--------------------------------------------------
    int main(){
        char Player='O';
        char map[20][20];
        int Xcoordinate,Ycoordinate;
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++) map[i][j]=' ';
        }
        show(map);
        while(1){
            cout<<"(X、Y皆為0時遊戲終止)"<<endl;
            cout<<"(先手O：後手：@)"<<endl;
            cout<<"X:"; cin>>Xcoordinate;
            cout<<"Y:"; cin>>Ycoordinate;
            if(Xcoordinate==0&&Ycoordinate==0) break;
            else{ Xcoordinate=Xcoordinate-1; Ycoordinate=Ycoordinate-1;
                system("CLS");
                bool TFSet=TFset(Player,Xcoordinate,Ycoordinate,map);
                show(map);
                if(winner(5,Player,Xcoordinate,Ycoordinate,map)==true) {
                    cout<<Player<<" WON THE GAME。\n";
                    break;
                }
                if(TFSet==true){
                    if(Player=='O') Player='@';
                    else Player='O';
                }
            }
        }
}


