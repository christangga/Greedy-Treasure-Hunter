/* 	File 	: mainfunction.h 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01
*/

#include "mainfunction.h"

char Pita_Karakter[63]="readme.txt";
ifstream fin;

Peti	*vertex;
Peti	*AdrPeti;
int 	**Graf;
int 	JumlahWarna[3];
int	*LetakMerah, *LetakKuning, *LetakHijau;
int	skor_menang, waktu_main, n_simpul, modal, curr_vertex;
bool	random=false;

bool AllVertexVisited(bool const *flag, int const n_simpul) {
/* mengirim true bila semua vertex telah dikunjungi */
	int i = n_simpul-1;
	while (i>=0) {
		if (!flag[i]) {
			return false;
		}
		else i--;
	}
	return true;
}

void fungsi_seleksi_value(int** const Graf, Hunter AIHunter, Peti vertex, int *candidate, int *distance, int *maxvalue, int const i) {
/*  I.S : semua variable terdefinisi
	F.S : candidate, distance dan maxvalue berisi nilai sesuai kondisi seleksi
*/
		if (Graf[AIHunter.GetSimpul()][i]!=-99) {
			if (vertex.GetCoin()>(*maxvalue)) {
				*maxvalue = vertex.GetCoin();
				*candidate = i;
				*distance = Graf[AIHunter.GetSimpul()][i];
			}
			else if ((vertex.GetCoin()==*maxvalue)) {
				if ((Graf[AIHunter.GetSimpul()][i]<*distance) || (*distance==-1)) {
					*candidate = i;
					*distance = Graf[AIHunter.GetSimpul()][i];
				}
			}
		}
}

void fungsi_seleksi_distance(int** const Graf, Hunter AIHunter, Peti vertex, int *candidate, int *distance, int *maxvalue, int const i) {
/*  I.S : semua variable terdefinisi
	F.S : candidate, distance dan maxvalue berisi nilai sesuai kondisi seleksi
*/
	if (Graf[AIHunter.GetSimpul()][i]!=-99) {
		if ((Graf[AIHunter.GetSimpul()][i]<*distance) || (*distance==-1)) {
			*candidate = i;
			*maxvalue = vertex.GetCoin();
			*distance = Graf[AIHunter.GetSimpul()][i];
		}
		else if ((Graf[AIHunter.GetSimpul()][i])==*distance) {
			if (vertex.GetCoin()>*maxvalue) {
				*maxvalue=vertex.GetCoin();
				*candidate = i;
			}
		}
	}
}

void ShortestPath(int ** const Graf, Djikstra_MAP *Out, int const n_simpul, int const curr_vertex, Peti harta[]) {
/* I.S : semua paramter terdefinisi
   F.S : *Out berisi peta Shortest path ke masing-masing simpul
*/
	//local variables
	bool *flag = new bool[n_simpul];
	string stemp1 = to_string(curr_vertex);

	for (int i = 0; i < n_simpul; i++) {
        (*Out).distance[i] = Graf[curr_vertex][i];
        if ((*Out).distance[i]==-99) (*Out).distance[i]=INT_MAX;
		
		if (i!=curr_vertex) {
			string stemp = to_string(i);

			(*Out).path[i] = stemp1 + "-" + stemp;
	        
	        (*Out).total_harta[i] = harta[i].GetCoin();
	    }
		else {
			(*Out).path[i] = "i"; //artinya idem atau kembali ke diri sendiri	
			(*Out).total_harta[i] = 0;
		} 
		flag[i] = false;
	}
	flag[curr_vertex]=true;
	
	for (int i=0; i < n_simpul; i++) {
		int candidate = 0;
		int minimum = INT_MAX;
		int last=0;
		//vertex terdekat berikutnya
		for (int v=0; v < n_simpul; v++) {
		    if (flag[v]==false) {
				if ((minimum >= Graf[curr_vertex][v]) && (Graf[curr_vertex][v]!=-99) ) {
			    	minimum = Graf[curr_vertex][v]; candidate = v;
				}
				last=v;
			}
		}
		if (minimum==INT_MAX) {
			candidate=last;
		}
		flag[candidate]=true;
	
			for (int v = 0; v < n_simpul; v++) {
				if ((v!=candidate && Graf[candidate][v]!=-99) && ((*Out).distance[candidate]+Graf[candidate][v] < (*Out).distance[v] && (*Out).distance[candidate]+Graf[candidate][v]>0 )) {
		            (*Out).distance[v] = (*Out).distance[candidate] + Graf[candidate][v];   
		            string stemp = to_string(v);
					(*Out).path[v] = (*Out).path[candidate] + "-" + stemp;
		            if (harta[v].GetColor()!='h') {
		            	(*Out).total_harta[v] = (*Out).total_harta[candidate] + harta[v].GetCoin();
					}
				}
		}
	}
}

int GetNextVertex(string path, int *i) {
/* mendapatkan vertex berikutnya dari string path
*/
	int t_value=0;
	while ((path[*i]!='-') && (*i < path.length() )) {
		t_value *= 10;
		t_value += path[*i]-'0';		
		*i = *i + 1;
		//cout<<path[*i]<<" "<<*i<<endl;
	}
	if (*i<=path.length()) { //means artinya path[i]=='-'
		*i = *i + 1;
	}
	return t_value;
}

void Preparation() {
/* 	I.S	: Sembarang
	F.S : Isi file eksternal dibaca, variabel-variabel global yang terkait dengan permainan berisi nilai yang sesuai
*/
	//LOCAL VARIABLES
	string Tempstr;
	int	temp[3], len, t_value, total_peti=0, dummy;
	//ALGORITMA
	fin.open(Pita_Karakter);
	getline(fin,Tempstr);
	getline(fin,Tempstr); //modal
	modal = atoi(Tempstr.c_str());
	getline(fin,Tempstr);
	getline(fin,Tempstr); //baca random atau given
	
	//penanganan kasus random atau "given"
	if (Tempstr.compare("[Random]")==0) 
		random=true;
	
	dummy=0;
	getline(fin,Tempstr); //[jumlah peti]
	getline(fin,Tempstr); //angka jumlah peti
	t_value = 0;
	len = Tempstr.length();
	for (int i = 0; i < len; i++) {
		if (Tempstr[i]==',')  {
			total_peti += t_value;
			JumlahWarna[dummy] = t_value;
			dummy++;
			t_value=0;
		}	
		else {
			t_value = t_value*10; 
			t_value += Tempstr[i]-'0';
		}
	}
	total_peti += t_value;
	JumlahWarna[2] = t_value;
		
	if (!random) { //given
		//baca lokasi peti merah
		getline(fin,Tempstr);
		if (Tempstr.compare("0")!=0) {
			LetakMerah = new int[JumlahWarna[0]];
			t_value = 0;
			dummy=0;
			len = Tempstr.length();
			for (int i = 0; i < len; i++) {
				if (Tempstr[i]==',')  {
					total_peti += t_value;
					LetakMerah[dummy] = t_value;
					dummy++;
					t_value=0;
				}	
				else {
					t_value = t_value*10; 
					t_value += Tempstr[i]-'0';
				}
			}
			LetakMerah[dummy] = t_value;
		}
		
		//baca lokasi peti kuning
		getline(fin,Tempstr);
		if (Tempstr.compare("0")!=0) {
			LetakKuning = new int[JumlahWarna[1]];
			t_value = 0;
			dummy=0;
			len = Tempstr.length();
			for (int i = 0; i < len; i++) {
				if (Tempstr[i]==',')  {
					total_peti += t_value;
					LetakKuning[dummy] = t_value;
					dummy++;
					t_value=0;
				}	
				else {
					t_value = t_value*10; 
					t_value += Tempstr[i]-'0';
				}
			}
			LetakKuning[dummy] = t_value;
		}
		//baca lokasi peti hijau
		getline(fin,Tempstr);
		if (Tempstr.compare("0")!=0) {
			LetakHijau = new int[JumlahWarna[2]];
			t_value = 0;
			dummy=0;
			len = Tempstr.length();
			for (int i = 0; i < len; i++) {
				if (Tempstr[i]==',')  {
					total_peti += t_value;
					LetakHijau[dummy] = t_value;
					dummy++;
					t_value=0;
				}	
				else {
					t_value = t_value*10; 
					t_value += Tempstr[i]-'0';
				}
			}
			LetakHijau[dummy] = t_value;
		}
		
		getline(fin,Tempstr); //pemain
		curr_vertex = atoi(Tempstr.c_str())-1;
	}
		
	getline(fin,Tempstr); //skip newline
	getline(fin,Tempstr); //[skor]
	getline(fin,Tempstr); //angka skor
	skor_menang = atoi(Tempstr.c_str());
	
	getline(fin,Tempstr); //skip newline
	getline(fin,Tempstr); //[waktu]
	getline(fin,Tempstr); //angka waktu
	waktu_main = atoi(Tempstr.c_str());
	
	getline(fin,Tempstr); //skip newline
	getline(fin,Tempstr); //[simpul]
	getline(fin,Tempstr); //angka simpul
	n_simpul = atoi(Tempstr.c_str());

	getline(fin,Tempstr); //skip newline
	getline(fin,Tempstr); //[jarak simpul]
	
	//---MULAI BACA GRAF
	Graf = new int*[n_simpul];
	bool minus;
	
	for(int i = 0; i < n_simpul; i++) {
	    Graf[i] = new int[n_simpul];
	}
	
	for (int x = 0; x < n_simpul; x++) {
		t_value = 0;
		int j = 0;
		minus=false;
		getline(fin,Tempstr);
		len = Tempstr.length();
			
		for (int i = 0; i < len; i++) {
			if (Tempstr[i]==',')  {
				Graf[x][j] = t_value;
				if (minus) Graf[x][j]*=-1;
				t_value = 0;
				j++;
				minus=false;
			} else if (Tempstr[i]=='-') {
				minus=true;
			} else {
				t_value = t_value*10;
				t_value += Tempstr[i]-'0';
			}
		}
		
		Graf[x][j] = t_value;
		if (minus) Graf[x][j]*=-1;
	}

	//---END BACA GRAF
		
	//BUAT OBJEK PETI SESUAI ALAMAT SIMPUL
	vertex = new Peti[n_simpul];
	for (int i=0; i < n_simpul; i++) vertex[i].SetPeti(0,0,'i'); //tanda bahwa di vertex ke-i tidak ada peti
	
	if (random) { //random, assign peti 
		//flag
		bool *vis_simpul = new bool[n_simpul];
		for (int i=0; i < n_simpul; i++) vis_simpul[i]=false;
		int simpul_number;
		
		for (int i=0; i < JumlahWarna[0]; i++) { //warna merah
			do {
				srand(time(NULL));
				simpul_number = rand() % (n_simpul); //random from 0 to n_simpul
			} while (vis_simpul[simpul_number]);
			vertex[simpul_number].SetPeti(1,5,'m');
			vis_simpul[simpul_number]=true;
		}
		
		for (int i=0; i < JumlahWarna[1]; i++) { //warna kuning
			do {
				srand(time(NULL));
				simpul_number = rand() % (n_simpul); //random from 0 to n_simpul
			} while (vis_simpul[simpul_number]);
			vis_simpul[simpul_number]=true;
			vertex[simpul_number].SetPeti(3,3,'k');
		}
		
		for (int i=0; i < JumlahWarna[2]; i++) { //warna hijau
			do {
				srand(time(NULL));
				simpul_number = rand() % (n_simpul); //random from 0 to n_simpul
			} while (vis_simpul[simpul_number]);
			vis_simpul[simpul_number]=true;
			vertex[simpul_number].SetPeti(4,1,'h');
		}
		
		delete(vis_simpul);
	}
	else { //given, assign peti 
		//vertex dimulai dari 0
		for (int i=0; i < JumlahWarna[0]; i++) {
			vertex[LetakMerah[i]-1].SetPeti(1,5,'m');
		}
		for (int i=0; i < JumlahWarna[1]; i++) {
			vertex[LetakKuning[i]-1].SetPeti(3,3,'k');
		}
		for (int i=0; i < JumlahWarna[2]; i++) {
			vertex[LetakHijau[i]-1].SetPeti(4,1,'h');
		}
	}
}
