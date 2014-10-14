/* 	File 	: peti.cpp
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/
#include "peti.h"
#include <iostream>
using namespace std;

Peti::Peti() { //CTOR
	explode_time = 0;
	coin = 0;
	color = 'm'; //untuk sementara
}

Peti::Peti(int ex_time, int inside, char ch) { //CTOR dengan parameter
	explode_time = ex_time;
	coin = inside;
	color = ch; 
}

Peti::Peti(const Peti& p) { //CCTOR
	explode_time = p.explode_time;
	coin = p.coin;
	color = p.color;
}

Peti::~Peti() {} //DTOR

void Peti::SetExplodeTime(int x) {
/* I.S : x terdefinisi
   F.S : explode_time menjadi x
*/
	explode_time = x;
}
		
void Peti::SetCoin(int c) {
/* I.S : c terdefinisi
   F.S : coin menjadi x
*/
	coin = c;
}

void Peti::SetColor(char ch) {
/* I.S : ch terdefinisi
   F.S : color menjadi ch
*/
	color = ch;
}

void Peti::SetPeti(int ex_time, int inside, char ch) {
/* I.S : semua variable terdefinisi
   F.S : merubah isi objek peti berdasarkan parameter
*/
	explode_time = ex_time;
	coin = inside;
	color = ch;
}

int Peti::GetExplodeTime() {
/* mendapatkan waktu meledak */
	return explode_time;
}
		
int Peti::GetCoin() {
/* mendapatkan coin yang ada di peti */
	return coin;
}
		
char Peti::GetColor() {
/* mendapatkan warna peti */
	return color;
}
		
int Peti::BukaPeti(int open_time) {
/* membuka isi peti untuk mendapatkan koin, bila tools (open_time cocok)
   yang digunakan tepat maka fungsi akan mengembalikan isi peti
   bila tools yang digunakan tidak cocok, maka Tools meledak ( return -1 )
*/
	if (open_time<=explode_time) {
		return coin;
	}
	else return -1;
}
