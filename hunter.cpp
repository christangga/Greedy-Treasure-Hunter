/* 	File 	: hunter.cpp
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/
#include "hunter.h"

Hunter::Hunter() {//CTOR
	s = 0;
	uang = 0;
	waktu_lewat = 0;
	tools[0] = 0;
	tools[1] = 0;
	tools[2] = 0;
}

Hunter::Hunter(int simpul, int waktu, int money) { //CTOR dengan parameter
	s = simpul;
	waktu_lewat = waktu;
	uang = money;
	tools[0] = 0;
	tools[1] = 0;
	tools[2] = 0;
}

Hunter::Hunter(const Hunter& p) { //CCTOR
	s = p.s;
	waktu_lewat = p.waktu_lewat;
	uang = p.uang;
	tools[0] = p.tools[0];
	tools[1] = p.tools[1];
	tools[2] = p.tools[2];
}

Hunter::~Hunter() {

}
		
int Hunter::GetSimpul() {
/* mendapatkan posisi Hunter berada*/
	return s;
}
		
void Hunter::SetSimpul(int sm) {
/* I.S : sm terdefinisi
   F.S : simpul tempat hunter berada sekarang adalah sm
*/
	s = sm;
}

int Hunter::GetTools(int i) {
/* mendapatkan jumlah Tools ke-i */
	return tools[i];
}
		
void Hunter::SetTools(int i, int x) {
/* menambah tools ke-i dengan x */
	tools[i] = x;
}
		
int Hunter::GetUang() {
/* mendapatkan uang milik hunter sekarang */
	return uang;
}
		
void Hunter::SetUang(int u) {
/* I.S : u terdefinisi 
   F.S : uang milik unter ditambah u
*/
	uang += u;
}

int Hunter::GetWaktu() {
/* mendapatkan waktu yang sudah lewat */
	return waktu_lewat;
}

void Hunter::SetWaktu(int t) {
/* I.S : t terdefinisi
   F.S : waktu hunter yang lewat ditambah t
*/
	waktu_lewat += t;
}
	
void Hunter::Belanja(int x, int y, int z) {
/* I.S : x, y dan z terdefinisi. 
   F.S : hunter belanja tools[0] sebanyak x, tools[1] sebanyak y dan tools[2] sebanyak z, uang hunter akan dipotong
	     sesuai belanjaannya. 
*/
	tools[0] = x;
	tools[1] = y;
	tools[2] = z;
	uang -= ((x) + (y*2) + (z*3));
}

bool Hunter::ToolHabis() {
/* mengirimkan true bila Tools telah habis */
	int i = 2;
	while (i>=0) {
		if (tools[i]) {
			return false;
		}
		else i--;
	}
	return true;
}

void Hunter::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
	sprite.setPosition(x, y);
}

float Hunter::getPositionX() {
	return x;
}

float Hunter::getPositionY() {
	return y;
}

void Hunter::load(std::string filename) {
	texture.loadFromFile("images/" + filename);
	sprite.setTexture(texture);
}

void Hunter::draw(sf::RenderWindow& renderWindow) {
	renderWindow.draw(sprite);
}

void Hunter::move(float speedX, float speedY) {
	x += speedX;
	y += speedY;
	sprite.setPosition(x, y);
}
