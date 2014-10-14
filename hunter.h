/* 	File 	: hunter.h 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#ifndef _HUNTER_H
#define _HUNTER_H

#include "stdafx.h"

class Hunter {
public:
	Hunter(); //CTOR
	Hunter(int simpul, int waktu, int money); //CTOR dengan parameter
	Hunter(const Hunter& p); //CCTOR
	~Hunter(); //DTOR
		
	int GetSimpul();
	/* mendapatkan posisi Hunter berada*/
		
	void SetSimpul(int sm);
	/* I.S : sm terdefinisi
		F.S : simpul tempat hunter berada sekarang adalah sm
	*/
		
	int GetTools(int i);
	/* mendapatkan jumlah Tools ke-i */
		
	void SetTools(int i, int x);
	/* menambah tools ke-i dengan x */
		
	int GetUang();
	/* mendapatkan uang milik hunter sekarang */
		
	void SetUang(int u);
	/* I.S : u terdefinisi 
		F.S : uang milik unter ditambah u */
		
	int GetWaktu();
	/* mendapatkan waktu yang sudah lewat */
		
	void SetWaktu(int t);
	/* I.S : t terdefinisi
		F.S : waktu hunter yang lewat ditambah t
	*/
		
	void Belanja(int x, int y, int z);
	/* I.S : x, y dan z terdefinisi. 
		F.S : hunter belanja tools[0] sebanyak x, tools[1] sebanyak y dan tools[2] sebanyak z, uang hunter akan dipotong
		        sesuai belanjaannya. 
	*/
		
	bool ToolHabis();
	/* mengirimkan true bila Tools telah habis */
		
	// FUNGSI DAN PROSEDUR UNTUK MENAMPILKAN KE LAYAR

	void setPosition(float x, float y);
	//I.S : posisi hunter belum terdefinisi
	//F.S : posisi hunter berada pada absis x dan ordinat y (titik 0,0 berada di pojok kiri atas)

	float getPositionX();
	// mengembalikan nilai absis hunter di layar

	float getPositionY();
	//mengembalikan nilai ordinat hunter di layar

	void move(float speedX, float speedY);
	// I.S : hunter berada di posisi awalnya
	// F.S : posisi hunter berpindah sejauh speedX (absis) dan speedY (ordinat)

	void load(string filename);
	// I.S : masukan tidak terdefinisi
	// F.S : mendapat masukan dari file input (filename.txt)

	void draw(sf::RenderWindow& renderWindow);
	//I.S : belum ada tampilan pada layar
	//F.S : menampilan gambar pada layar

private	:
	float x, y;
	int s; //s menyatakan simpul posisi Hunter
	int uang; //uang Hunter terkini
	int	waktu_lewat; //waktu permainan yang sudah dilewati hunter
	int tools[3]; //tools[0] untuk tools jenis normal, tools[1] untuk jenis 2x, tools[2] untuk jenis 4x
	sf::Sprite sprite;
	sf::Texture texture;

};

#endif
