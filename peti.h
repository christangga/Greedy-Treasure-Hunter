/* 	File 	: peti.h 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/
#ifndef _Peti_H
#define _Peti_H

class Peti {
	public	:
		Peti(); //CTOR
		Peti(int ex_time, int inside, char ch); //CTOR dengan parameter
		Peti(const Peti& p); //CCTOR
		~Peti(); //DTOR
		
		void SetExplodeTime(int x);
		/* I.S : x terdefinisi
		   F.S : explode_time menjadi x
		*/
		
		void SetCoin(int c);
		/* I.S : c terdefinisi
		   F.S : coin menjadi x
		*/
		
		void SetColor(char ch);
		/* I.S : ch terdefinisi
		   F.S : color menjadi ch
		*/
		
		void SetPeti(int ex_time, int inside, char ch); //hanya untuk mempermudah agar tidak panjang mengetik, karena akan sering digunakan
		/* I.S : semua variable terdefinisi
		   F.S : merubah isi objek peti berdasarkan parameter
		*/
		
		int GetExplodeTime();
		/* mendapatkan waktu meledak */
		
		int GetCoin();
		/* mendapatkan coin yang ada di peti */
		
		char GetColor();
		/* mendapatkan warna peti */
		
		int BukaPeti(int open_time);
		/* membuka isi peti untuk mendapatkan koin, bila tools (open_time cocok)
		   yang digunakan tepat maka fungsi akan mengembalikan isi peti
		   bila tools yang digunakan tidak cocok, maka Tools meledak ( return -1 )
		*/
		
	private	:
		int		explode_time; //waktu Tools akan meledak begitu dibuka
		int		coin; //koin yang terdapat dalam suatu Tools
		char 	color; //warna Tools, m untuk merah, k untuk kuning dan h untuk hijau, i for invalid (sudah dibuka)
};


#endif
