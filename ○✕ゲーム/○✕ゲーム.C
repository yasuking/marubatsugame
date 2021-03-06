#include<stdio.h>
 void print_board(int board[3][3]){
 int i,j;
 for( i = 0; i < 3; i++ ){
 for( j = 0; j < 3; j++ ){
 printf("|");
 if(board[i][j]==0)printf(" − "); //■ - をスペースに変えること
else if(board[i][j]==1)printf(" 〇 ");
 else if(board[i][j]==-1)printf(" × ");
 }
 printf("|\n");
 }
 printf("\n");
 }
 
int judge(int board[3][3]){
 
int x,y;
 
for(x=0;x<3;x++){
 if(board[0][x]!=0){
 if(board[0][x]==board[1][x] && board[1][x]==board[2][x]){
 return board[0][x]; //縦に三つそろった石を返す
}
 }
 }
for(y=0;y<3;y++){
 if(board[y][0]!=0){
 if(board[y][0]==board[y][1] && board[y][1]==board[y][2]){
 return board[y][0]; //横に三つそろった石を返す
}
 }
 }
if(board[1][1]!=0){
 if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
 return board[1][1]; //斜めに三つそろった石を返す
}
if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
 return board[1][1]; //斜めに三つそろった石を返す
}
 }
 
for(x=0;x<3;x++){
 for(y=0;y<3;y++){
 if(board[y][x]==0){
 return 0;//石を打つ位置が残っている
}
 }
 }
return 2; //もう打てないので引き分け
 }
 
void mark_board(int board[3][3],int turn){
 int x,y;
 
if(turn==1){
 printf("〇のターンです\n");
 }else{
 printf("×のターンです\n");
 }
 
do{//◆
 do{//◆
 printf("縦の位置(0〜2)は？");
scanf("%d",&x);
if(x<0 || x>2){
	printf("そこには置けません\n\n");
}
 }while(x<0 || x>2);//◆
 do{//◆
 printf("横の位置(0〜2)は？");
scanf("%d",&y);
if(y<0 || y>2){
	printf("そこには置けません\n\n");
}
if(board[x][y] != 0){
	printf("そこには置けません\n\n");
}
 }while(y<0 || y>2);//◆
 }while(board[x][y] != 0); ////◆ 既に石があるならやり直し
board[x][y]=turn; //■追加
 }
 

void print_message(int result){
 if(result==1) printf("〇の勝ちです\n"); 
else if(result==-1) printf("×の勝ちです\n");
 else printf("引き分けです\n");
 }
 
int main(void){
 int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
 int turn=1;/*1=maru,-1=batsu*/
 int result;
 
while((result=judge(board))==0){
 print_board(board);
 mark_board(board,turn);
 turn*=-1;
 }
 print_board(board);
 print_message(result);
 
return 0;
 }