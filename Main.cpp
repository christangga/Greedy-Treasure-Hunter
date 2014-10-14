/* 	File 	: Main.cpp 
	Author 	: Jan Wira Gotama Putra (13512015), 
			  Christ Angga Saputra (13512019),
			  Ivana Clairine Irsan (13512041),
			  Kelas 01 */

#include "mainfunction.h"
#include <string>
using namespace std;

int main() {
	Preparation();
	int experting, MODEGAME;
	int greedy_code;
	int hx0=0, hx2=0, hx4=0;
	int tmp_modal = modal;
	Game::Start(tmp_modal, greedy_code, hx0, hx2, hx4, experting, MODEGAME);

	ofstream fout;
	fout.open("output.txt");
	//yang blm ditambahin itu greedy mode (by value atau by distance
	//trus kecepatan gerak AI

	//Output ke file eksternal

	//GUI
	sf::RenderWindow renderWindow(sf::VideoMode(1024, 640, 32), "Graph");
	sf::Texture bgtexture;
	bgtexture.loadFromFile("images/background.png");
	sf::Sprite bgsprite(bgtexture);
	renderWindow.draw(bgsprite);
	
	sf::CircleShape circleShape(300, n_simpul);
	circleShape.setPosition(sf::Vector2f(212, 20));
	sf::CircleShape* gambarsimpul = new sf::CircleShape[n_simpul];
	sf::Texture texturemerah;
	texturemerah.loadFromFile("images/petimerah.png");
	sf::Sprite gambarmerah(texturemerah);
	sf::Texture texturekuning;
	texturekuning.loadFromFile("images/petikuning.png");
	sf::Sprite gambarkuning(texturekuning);
	sf::Texture texturehijau;
	texturehijau.loadFromFile("images/petihijau.png");
	sf::Sprite gambarhijau(texturehijau);
	for (int i=0; i<n_simpul; ++i) {
		gambarsimpul[i].setRadius(20);
		gambarsimpul[i].setPosition(circleShape.getPoint(i).x + 192, circleShape.getPoint(i).y);
		gambarsimpul[i].setFillColor(sf::Color::Cyan);
		renderWindow.draw(gambarsimpul[i]);
		if (vertex[i].GetColor() == 'm') {
			gambarmerah.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
			renderWindow.draw(gambarmerah);
		} else if (vertex[i].GetColor() == 'k') {
			gambarkuning.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
			renderWindow.draw(gambarkuning);
		} else if (vertex[i].GetColor() == 'h') {
			gambarhijau.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
			renderWindow.draw(gambarhijau);
		}
	}

	//menampilkan sisa tools yang dimiliki

	sf::Texture SisaMerah;
	SisaMerah.loadFromFile("images/toolsmerahmini.png");
	sf::Sprite Merah(SisaMerah);
	Merah.setPosition(850, 370);

	sf::Texture SisaKuning;
	SisaKuning.loadFromFile("images/toolskuningmini.png");
	sf::Sprite Kuning(SisaKuning);
	Kuning.setPosition(850, 460);

	sf::Texture SisaHijau;
	SisaHijau.loadFromFile("images/toolshijaumini.png");
	sf::Sprite Hijau(SisaHijau);
	Hijau.setPosition(850, 550);

	int n_sisi = 0;
	for (int i=0; i<n_simpul; ++i) {
		for (int j=0; j<=i; ++j) {
			if (Graf[i][j] > 0) {
				n_sisi++;
			}
		}
	}
	
	//GUI Font
	sf::Font font;
	font.loadFromFile("fonts/COUR.TTF");
	sf::Text* text = new sf::Text[2*n_sisi];
	sf::VertexArray gambarsisi(sf::Lines, 2*n_sisi);
	for (int i=0; i<2*n_sisi; i++) {
		gambarsisi[i].color = sf::Color::Black;
		text[i].setFont(font);
		text[i].setColor(sf::Color::Black);
		text[i].setCharacterSize(20);
		text[i].setStyle(sf::Text::Bold);
	}

	sf::Text Status;
	Status.setFont(font);
	Status.setColor(sf::Color::Magenta);
	Status.setCharacterSize(50);
	Status.setStyle(sf::Text::Bold);
	Status.setPosition(30, 500);

	sf::Text ToolsMerah;
	ToolsMerah.setFont(font);
	ToolsMerah.setColor(sf::Color::Red);
	ToolsMerah.setCharacterSize(50);
	ToolsMerah.setPosition(930, 380);

	sf::Text ToolsKuning;
	ToolsKuning.setFont(font);
	ToolsKuning.setColor(sf::Color::Red);
	ToolsKuning.setCharacterSize(50);
	ToolsKuning.setPosition(930, 470);

	sf::Text ToolsHijau;
	ToolsHijau.setFont(font);
	ToolsHijau.setColor(sf::Color::Red);
	ToolsHijau.setCharacterSize(50);
	ToolsHijau.setPosition(930, 560);

	sf::Texture PetiMerahMini;
	PetiMerahMini.loadFromFile("images/petimerah.png");
	sf::Sprite MerahMini(PetiMerahMini);
	MerahMini.setPosition(10, 80);	

	sf::Texture PetiKuningMini;
	PetiKuningMini.loadFromFile("images/petikuning.png");
	sf::Sprite KuningMini(PetiKuningMini);
	KuningMini.setPosition(10, 120);	

	sf::Texture PetiHijauMini;
	PetiHijauMini.loadFromFile("images/petihijau.png");
	sf::Sprite HijauMini(PetiHijauMini);
	HijauMini.setPosition(10, 160);	

	sf::Text textx;
	textx.setFont(font);
	textx.setColor(sf::Color::Black);
	textx.setStyle(sf::Text::Bold);
	textx.setCharacterSize(15);
	textx.setPosition(50,80);

	sf::Text texty;
	texty.setFont(font);
	texty.setColor(sf::Color::Black);
	texty.setStyle(sf::Text::Bold);
	texty.setCharacterSize(15);
	texty.setPosition(50,120);

	sf::Text textz;
	textz.setFont(font);
	textz.setColor(sf::Color::Black);
	textz.setStyle(sf::Text::Bold);
	textz.setCharacterSize(15);
	textz.setPosition(50,160);

	//GUI sisi
	int k=0;
	for (int i=0; i<n_simpul; ++i) {
		for (int j=0; j<i; ++j) {
			if (Graf[i][j] > 0) {
				gambarsisi[k].position = sf::Vector2f(gambarsimpul[i].getPosition() + sf::Vector2f(20, 20));
				k++;
				gambarsisi[k].position = sf::Vector2f(gambarsimpul[j].getPosition() + sf::Vector2f(20, 20));
				k++;
				text[k / 2].setPosition(sf::Vector2f((gambarsimpul[i].getPosition().x + gambarsimpul[j].getPosition().x) / 2, (gambarsimpul[i].getPosition().y + gambarsimpul[j].getPosition().y) / 2));
				string str = to_string(Graf[i][j]);
				text[k / 2].setString(str);
			}
		}
	}

	sf::Text text1;
	text1.setFont(font);
	text1.setColor(sf::Color::Magenta);
	text1.setCharacterSize(50);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(10, 10);
	string str = to_string(waktu_main);
	text1.setString(str);
	
	//---GREEDY
	if (random) {
		srand((unsigned) time(NULL));
		curr_vertex = rand() % (n_simpul); //random from 0 to n_simpul-1
	}
	int humancurr_vertex = curr_vertex;
	Hunter AIHunter(curr_vertex,0,modal);
	Hunter Human(humancurr_vertex, 0, modal);

	//peti 4x 3 koin, 2x 2 koin, normal 1 koin
	//belanja tools
	int x4 = modal/3;
	if (x4>JumlahWarna[0]) {
		x4 = JumlahWarna[0];
		modal -= (x4*3);
	}
	else modal-=(x4*3);
	int x2 = modal/2;
	if (x2>JumlahWarna[1]) {
		x2 = JumlahWarna[1];
		modal-=(x2*2);
	}
	else modal -= (x2*2);
	//--end belanja tools, beli tools buat peti ijo rugi karna cuman balik modal tapi waktu berkurang waktu banyak
	
	bool *visit = new bool[n_simpul];
	for (int i=0; i < n_simpul; i++)
		visit[i] = false;
	AIHunter.Belanja(0,x2,x4);
	visit[curr_vertex] = true;
	Human.Belanja(hx4, hx2, hx0);

	//GUI Greedy / Dijkstra
	if (experting==1) {
		AIHunter.setPosition(gambarsimpul[curr_vertex].getPosition().x, gambarsimpul[curr_vertex].getPosition().y);
		AIHunter.load("walk1.png");
		Human.setPosition(gambarsimpul[Human.GetSimpul()].getPosition().x, gambarsimpul[Human.GetSimpul()].getPosition().y);
		Human.load("walkhuman.png");
		int waktu_sisa=waktu_main;
		bool stop_cond=false;

		int sisa_langkah = 0;
		bool IsPlaying = true;
		int clickedsimpul = -1;
		while (renderWindow.isOpen() && IsPlaying) {
			sf::Event event;
				if (IsPlaying) {
				while (renderWindow.pollEvent(event)) {
					switch(event.type) {
					case (sf::Event::Closed):
						renderWindow.close();
						break;
					case (sf::Event::KeyPressed):
						if (event.key.code == sf::Keyboard::Escape) {
							renderWindow.close();
						}
						if (event.key.code == sf::Keyboard::Space) {
							IsPlaying = true;
						}
						break;
					case (sf::Event::MouseButtonPressed):
						for (int i=0; i<n_simpul; ++i) {
							if (event.mouseButton.x - 20 >= gambarsimpul[i].getPosition().x - 20 &&
								event.mouseButton.x - 20 <= gambarsimpul[i].getPosition().x + 20 &&
								event.mouseButton.y - 20 >= gambarsimpul[i].getPosition().y - 20 &&
								event.mouseButton.y - 20 <= gambarsimpul[i].getPosition().y + 20) {
									clickedsimpul = i;
									gambarsimpul[i].setPosition(event.mouseButton.x - 20, event.mouseButton.y - 20);
							}
						}
						break;
					case (sf::Event::MouseMoved):
						if (sf::Mouse::isButtonPressed && clickedsimpul != -1) {
							gambarsimpul[clickedsimpul].setPosition(sf::Vector2f(event.mouseMove.x - 20, event.mouseMove.y - 20));
							if (AIHunter.GetSimpul() == clickedsimpul) {
								AIHunter.setPosition(gambarsimpul[clickedsimpul].getPosition().x, gambarsimpul[clickedsimpul].getPosition().y);
							}
							int k=0;
							for (int i=0; i<n_simpul; ++i) {
								for (int j=0; j<i; ++j) {
									if (Graf[i][j] > 0) {
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[i].getPosition() + sf::Vector2f(20, 20));
										k++;
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[j].getPosition() + sf::Vector2f(20, 20));
										k++;
										text[k / 2].setPosition(sf::Vector2f((gambarsimpul[i].getPosition().x + gambarsimpul[j].getPosition().x) / 2, (gambarsimpul[i].getPosition().y + gambarsimpul[j].getPosition().y) / 2));
										string str = to_string(Graf[i][j]);
										text[k / 2].setString(str);
									}
								}
							}
						}
						break;
					case (sf::Event::MouseButtonReleased):
						if (clickedsimpul != -1) {
							gambarsimpul[clickedsimpul].setPosition(sf::Vector2f(event.mouseButton.x - 20, event.mouseButton.y - 20));
							if (AIHunter.GetSimpul() == clickedsimpul) {
								AIHunter.setPosition(gambarsimpul[clickedsimpul].getPosition().x, gambarsimpul[clickedsimpul].getPosition().y);
							}
							int k=0;
							for (int i=0; i<n_simpul; ++i) {
								for (int j=0; j<i; ++j) {
									if (Graf[i][j] > 0) {
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[i].getPosition() + sf::Vector2f(20, 20));
										k++;
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[j].getPosition() + sf::Vector2f(20, 20));
										k++;
										text[k / 2].setPosition(sf::Vector2f((gambarsimpul[i].getPosition().x + gambarsimpul[j].getPosition().x) / 2, (gambarsimpul[i].getPosition().y + gambarsimpul[j].getPosition().y) / 2));
										string str = to_string(Graf[i][j]);
										text[k / 2].setString(str);
									}
								}
							}
							clickedsimpul = -1;
						}
						break;
					}
				}
				renderWindow.clear(sf::Color::White);
				renderWindow.draw(bgsprite);
				for (int i=0; i<n_simpul; ++i) {
					renderWindow.draw(gambarsimpul[i]);
					if (vertex[i].GetColor() == 'm') {
						gambarmerah.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
						renderWindow.draw(gambarmerah);
					} else if (vertex[i].GetColor() == 'k') {
						gambarkuning.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
						renderWindow.draw(gambarkuning);
					} else if (vertex[i].GetColor() == 'h') {
						gambarhijau.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
						renderWindow.draw(gambarhijau);
					}
				}
				renderWindow.draw(Merah);
				renderWindow.draw(Kuning);
				renderWindow.draw(Hijau);

				string getm = to_string(AIHunter.GetTools(2));
				ToolsMerah.setString(getm);
				renderWindow.draw(ToolsMerah);
				string getk = to_string(AIHunter.GetTools(1));
				ToolsKuning.setString(getk);
				renderWindow.draw(ToolsKuning);
				string geth = to_string(AIHunter.GetTools(0));
				ToolsHijau.setString(geth);
				renderWindow.draw(ToolsHijau);
				
				string strs = to_string(AIHunter.GetUang());
				Status.setString(strs);
				renderWindow.draw(Status);
				renderWindow.draw(gambarsisi);

				renderWindow.draw(gambarsisi);
				for (int i=0; i<2*n_sisi; ++i) {
					renderWindow.draw(text[i]);
				}
				renderWindow.draw(text1);
				AIHunter.draw(renderWindow);
				renderWindow.display();
				sf::sleep(sf::milliseconds(20));
			}
			bool jalan=false;
			int human_candidate;
			int candidate;
			int waktu_ambil_peti=0;
			if (IsPlaying) {
				if (waktu_main>0 && IsPlaying) {
					//bagian AI
					jalan=false;
					if (waktu_main>0  && !stop_cond && !AllVertexVisited(visit,n_simpul) && !AIHunter.ToolHabis()) {
						jalan=true;
						char color = vertex[AIHunter.GetSimpul()].GetColor(); //'i' for invalid
						fout<<AIHunter.GetSimpul()+1;
						if (color!='i') {
							//buka peti sesuai warna
							int retval=-1;
							switch(color) {
								case 'm' : {
									if (AIHunter.GetTools(2)) {
										retval = vertex[AIHunter.GetSimpul()].BukaPeti(1);
										if (retval > 0) {
											AIHunter.SetUang(retval);
											AIHunter.SetWaktu(1);
											waktu_main--;
											waktu_ambil_peti=1;
											fout<<",M"<<endl;
										}
										else fout<<",-"<<endl;
										AIHunter.SetTools(2,AIHunter.GetTools(2)-1);
									}
									else fout<<",-"<<endl;
									break;
								}
								case 'k' : {
									if (AIHunter.GetTools(1)) {
										retval = vertex[AIHunter.GetSimpul()].BukaPeti(2);
										if (retval > 0) {
											AIHunter.SetUang(retval);
											AIHunter.SetWaktu(2);
											waktu_main-=2;
											waktu_ambil_peti=2;
											fout<<",K"<<endl;
										}
										else fout<<",-"<<endl;
										AIHunter.SetTools(1,AIHunter.GetTools(1)-1);
									}
									else if (AIHunter.GetTools(2)) {
										retval = vertex[AIHunter.GetSimpul()].BukaPeti(1);
										if (retval > 0) {
											AIHunter.SetUang(retval);
											AIHunter.SetWaktu(1);
											waktu_main--;
											waktu_ambil_peti=1;
											fout<<",K"<<endl;
										}
										else fout<<",-"<<endl;
										AIHunter.SetTools(2,AIHunter.GetTools(2)-1);
									}
									else fout<<",-"<<endl;
									break;
								}
								default : fout<<",-"<<endl;
								//hijau tidak akan dibuka karena hanya balik modal
							}
							if (retval>0) vertex[AIHunter.GetSimpul()].SetPeti(0,0,'i');
							color='i'; //peti sudah dibuka
						}
						else fout<<",-"<<endl;
						visit[AIHunter.GetSimpul()]=true;
						if (!AllVertexVisited(visit,n_simpul)) {
							candidate = AIHunter.GetSimpul();
							curr_vertex = candidate;
							int maxvalue=0; //max coin value
							int distance=-1; //distance awal
							for (int i=0; i < n_simpul; i++) { //fungsi seleksi
								if (i!=AIHunter.GetSimpul() && Graf[AIHunter.GetSimpul()][i]<=(waktu_main)) { //uji peta
									if (greedy_code == 1) { //fungsi layak greedy by value
										fungsi_seleksi_value(Graf,AIHunter,vertex[i],&candidate,&distance,&maxvalue,i);
									} else if (!visit[i]) { //fungsi layak greedy by distance
										fungsi_seleksi_distance(Graf,AIHunter,vertex[i],&candidate,&distance,&maxvalue,i);
									}
								}
							} 
							//tidak ada vertex yang memenuhi
							if (candidate == AIHunter.GetSimpul()) {
								stop_cond=true;
								waktu_main=0;
								//permainan di terminate, artinya waktu tersisa tidak mencukupi
							} else {
								AIHunter.SetSimpul(candidate);
								AIHunter.SetWaktu(distance);
								waktu_main-=distance;
							}
						}
						else jalan=false;
					}
					if (MODEGAME==1 && (stop_cond || !jalan)) IsPlaying=false;
					int diftime = 0, counter = 0;
					if (jalan && !stop_cond) {
						do {
											
							float x = (gambarsimpul[candidate].getPosition().x - gambarsimpul[curr_vertex].getPosition().x) / Graf[curr_vertex][candidate] / 50;
							float y = (gambarsimpul[candidate].getPosition().y - gambarsimpul[curr_vertex].getPosition().y) / Graf[curr_vertex][candidate] / 50;
							AIHunter.move(x, y);
							if (AIHunter.getPositionX() <= gambarsimpul[candidate].getPosition().x + 20 &&
								AIHunter.getPositionX() >= gambarsimpul[candidate].getPosition().x - 20 &&
								AIHunter.getPositionY() <= gambarsimpul[candidate].getPosition().y + 20 &&
								AIHunter.getPositionY() >= gambarsimpul[candidate].getPosition().y - 20) {
									AIHunter.setPosition(gambarsimpul[candidate].getPosition().x, gambarsimpul[candidate].getPosition().y);
							}
							counter++;
							if (counter== 50) {
								diftime++;
								counter = 0;
							}
							string str = to_string(waktu_main - diftime + Graf[curr_vertex][candidate] /*tambah waktu buka peti*/);
							text1.setString(str);

							//string keterangan
							textx.setString("(5c) meledak (1s)");
							texty.setString("(3c) meledak (2s)");
							textz.setString("(1c) meledak (4s)");
							

							//draw
							renderWindow.clear(sf::Color::White);
							renderWindow.draw(bgsprite);
							for (int i=0; i<n_simpul; ++i) {
								renderWindow.draw(gambarsimpul[i]);
								if (vertex[i].GetColor() == 'm') {
									gambarmerah.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
									renderWindow.draw(gambarmerah);
								} else if (vertex[i].GetColor() == 'k') {
									gambarkuning.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
									renderWindow.draw(gambarkuning);
								} else if (vertex[i].GetColor() == 'h') {
									gambarhijau.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
									renderWindow.draw(gambarhijau);
								}
							}
							renderWindow.draw(Merah);
							renderWindow.draw(Kuning);
							renderWindow.draw(Hijau);
							renderWindow.draw(MerahMini);
							renderWindow.draw(KuningMini);
							renderWindow.draw(HijauMini);

							string getm = to_string(AIHunter.GetTools(2));
							ToolsMerah.setString(getm);
							renderWindow.draw(ToolsMerah);
							string getk = to_string(AIHunter.GetTools(1));
							ToolsKuning.setString(getk);
							renderWindow.draw(ToolsKuning);
							string geth = to_string(AIHunter.GetTools(0));
							ToolsHijau.setString(geth);
							renderWindow.draw(ToolsHijau);

							string strs = to_string(AIHunter.GetUang());
							Status.setString(strs);
							renderWindow.draw(Status);
							renderWindow.draw(gambarsisi);
							
							renderWindow.draw(textx);
							renderWindow.draw(texty);
							renderWindow.draw(textz);

							for (int i=0; i<2*n_sisi; ++i) {
								renderWindow.draw(text[i]);
							}
							renderWindow.draw(text1);
							AIHunter.draw(renderWindow);
							if (MODEGAME==2) Human.draw(renderWindow);
							renderWindow.display();
							sf::sleep(sf::milliseconds(17));
						} while (AIHunter.getPositionX() != gambarsimpul[candidate].getPosition().x ||
							AIHunter.getPositionY() != gambarsimpul[candidate].getPosition().y);
					}
				
					//bagian manusia
					waktu_ambil_peti=0;
					bool manusia_bisa_jalan=false;
					if (MODEGAME==2 && waktu_main>0) { //bagian manusia
						humancurr_vertex=Human.GetSimpul();
						char color = vertex[Human.GetSimpul()].GetColor(); //'i' for invalid
						if (color!='i' && !Human.ToolHabis()) {
							switch(color) {
								case 'm': {
									if (Human.GetTools(2)) {
										int retval = vertex[Human.GetSimpul()].BukaPeti(1);
										if (retval > 0) {
											Human.SetUang(retval);
											Human.SetWaktu(1);
											waktu_main--;
											waktu_ambil_peti=1;
											vertex[Human.GetSimpul()].SetPeti(0,0,'i');
										}
										Human.SetTools(2,Human.GetTools(2)-1);
									}
									break;		  
								}
								case 'k': {
									if (Human.GetTools(1)) {
										int retval = vertex[Human.GetSimpul()].BukaPeti(2);
										if (retval > 0) {
											Human.SetUang(retval);
											Human.SetWaktu(2);
											waktu_main-=2;
											waktu_ambil_peti=2;
											vertex[Human.GetSimpul()].SetPeti(0,0,'i');
										}
										Human.SetTools(1,Human.GetTools(1)-1);
									}
									else if (Human.GetTools(2)) {
										int retval = vertex[Human.GetSimpul()].BukaPeti(1);
										if (retval > 0) {
											Human.SetUang(retval);
											Human.SetWaktu(1);
											waktu_main--;
											waktu_ambil_peti=1;
											vertex[Human.GetSimpul()].SetPeti(0,0,'i');
										}
										Human.SetTools(2,Human.GetTools(2)-1);
									}
									break;		  
								}
								case 'h': {
									if (Human.GetTools(0)) {
										int retval = vertex[Human.GetSimpul()].BukaPeti(4);
										if (retval > 0) {
											Human.SetUang(retval);
											Human.SetWaktu(4);
											waktu_main-=4;
											waktu_ambil_peti=4;
											vertex[Human.GetSimpul()].SetPeti(0,0,'i');
										}
										Human.SetTools(0,Human.GetTools(0)-1);
									}
									else if (Human.GetTools(1)) {
										int retval = vertex[Human.GetSimpul()].BukaPeti(2);
										if (retval > 0) {
											Human.SetUang(retval);
											Human.SetWaktu(2);
											waktu_main-=2;
											waktu_ambil_peti=1;
											vertex[Human.GetSimpul()].SetPeti(0,0,'i');
										}
										Human.SetTools(1,Human.GetTools(1)-1);
									}
									else if (Human.GetTools(2)) {
										int retval = vertex[Human.GetSimpul()].BukaPeti(1);
										if (retval > 0) {
											Human.SetUang(retval);
											Human.SetWaktu(1);
											waktu_main--;
											waktu_ambil_peti=1;
											vertex[Human.GetSimpul()].SetPeti(0,0,'i');
										}
										Human.SetTools(2,Human.GetTools(2)-1);
									}
									break;		  
								}
							}
						}
						//available vertex
						for (int i=0; i<n_simpul; i++) {
							if (Graf[Human.GetSimpul()][i]!=-99 && i!=Human.GetSimpul()) {
								if (Graf[Human.GetSimpul()][i] <= (waktu_main) ) {
									manusia_bisa_jalan=true;
								}
							}
						}
						if (manusia_bisa_jalan) {
							int next_vertex=1;
							bool stop=false;
								while (!stop) {
									sf::Event event;
									while (renderWindow.pollEvent(event)) {
										if (event.type == sf::Event::MouseButtonPressed) {
											for (int i=0; i<n_simpul && !stop; ++i) {
												if (event.mouseButton.x - 20 >= gambarsimpul[i].getPosition().x - 20 &&
													event.mouseButton.x - 20 <= gambarsimpul[i].getPosition().x + 20 &&
													event.mouseButton.y - 20 >= gambarsimpul[i].getPosition().y - 20 &&
													event.mouseButton.y - 20 <= gambarsimpul[i].getPosition().y + 20) {
														next_vertex = i;
														stop=true;
												}
											}
										}
									}
								}

							int distance1=0;
							if (Graf[Human.GetSimpul()][next_vertex]!=-99) {
								distance1 = Graf[Human.GetSimpul()][next_vertex];
								Human.SetSimpul(next_vertex);
							}
							waktu_main-=distance1;
							human_candidate=next_vertex;
						}
						else {
							//waktu main udah habis, do nothing
						}
					}
					if (MODEGAME==2 && manusia_bisa_jalan) { //render human
						diftime=0; counter=0;
						do {
							float x = (gambarsimpul[human_candidate].getPosition().x - gambarsimpul[humancurr_vertex].getPosition().x) / Graf[humancurr_vertex][human_candidate] / 50;
							float y = (gambarsimpul[human_candidate].getPosition().y - gambarsimpul[humancurr_vertex].getPosition().y) / Graf[humancurr_vertex][human_candidate] / 50;
							Human.move(x, y);
							if (Human.getPositionX() <= gambarsimpul[human_candidate].getPosition().x + 20 &&
								Human.getPositionX() >= gambarsimpul[human_candidate].getPosition().x - 20 &&
								Human.getPositionY() <= gambarsimpul[human_candidate].getPosition().y + 20 &&
								Human.getPositionY() >= gambarsimpul[human_candidate].getPosition().y - 20) {
									Human.setPosition(gambarsimpul[human_candidate].getPosition().x, gambarsimpul[human_candidate].getPosition().y);
							}
							counter++;
							if (counter== 50) {
								diftime++;
								counter = 0;
							}
							//tmp_clock = waktu_main - waktu_ambil_peti- diftime + Graf[humancurr_vertex][human_candidate];
							string str = to_string(waktu_main- diftime + Graf[humancurr_vertex][human_candidate] /*tambah waktu buka peti*/);
							text1.setString(str);

							//string keterangan
							textx.setString("(5c) meledak (1s)");
							texty.setString("(3c) meledak (2s)");
							textz.setString("(1c) meledak (4s)");

							//draw
							renderWindow.clear(sf::Color::White);
							renderWindow.draw(bgsprite);
							for (int i=0; i<n_simpul; ++i) {
								renderWindow.draw(gambarsimpul[i]);
								if (vertex[i].GetColor() == 'm') {
									gambarmerah.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
									renderWindow.draw(gambarmerah);
								} else if (vertex[i].GetColor() == 'k') {
									gambarkuning.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
									renderWindow.draw(gambarkuning);
								} else if (vertex[i].GetColor() == 'h') {
									gambarhijau.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
									renderWindow.draw(gambarhijau);
								}
							}
							
							renderWindow.draw(Merah);
							renderWindow.draw(Kuning);
							renderWindow.draw(Hijau);
							renderWindow.draw(MerahMini);
							renderWindow.draw(KuningMini);
							renderWindow.draw(HijauMini);

							string getm = to_string(Human.GetTools(2));
							ToolsMerah.setString(getm);
							renderWindow.draw(ToolsMerah);
							string getk = to_string(Human.GetTools(1));
							ToolsKuning.setString(getk);
							renderWindow.draw(ToolsKuning);
							string geth = to_string(Human.GetTools(0));
							ToolsHijau.setString(geth);
							renderWindow.draw(ToolsHijau);
							
							string strs = to_string(Human.GetUang());
							Status.setString(strs);
							renderWindow.draw(Status);
							renderWindow.draw(gambarsisi);

							renderWindow.draw(textx);
							renderWindow.draw(texty);
							renderWindow.draw(textz);

							for (int i=0; i<2*n_sisi; ++i) {
								renderWindow.draw(text[i]);
							}
							renderWindow.draw(text1);
							Human.draw(renderWindow);
							AIHunter.draw(renderWindow);
							renderWindow.display();
							sf::sleep(sf::milliseconds(17));
						} while (Human.getPositionX() != gambarsimpul[human_candidate].getPosition().x ||
							Human.getPositionY() != gambarsimpul[human_candidate].getPosition().y);
					}

				}
				else IsPlaying=false;
			}
		}
	}
	else { //experting ==2
		//DJIKSTRA
		AIHunter.setPosition(gambarsimpul[curr_vertex].getPosition().x, gambarsimpul[curr_vertex].getPosition().y);
		AIHunter.load("walk1.png");

		int sisa_langkah = 0;
		bool IsPlaying = true;
		int clickedsimpul = -1;
		while (renderWindow.isOpen() && IsPlaying) {
			sf::Event event;
			if (IsPlaying) {
				while (renderWindow.pollEvent(event)) {
					switch(event.type) {
					case (sf::Event::Closed):
						renderWindow.close();
						break;
					case (sf::Event::KeyPressed):
						if (event.key.code == sf::Keyboard::Escape) {
							renderWindow.close();
						}
						if (event.key.code == sf::Keyboard::Space) {
							IsPlaying = true;
						}
						break;
					case (sf::Event::MouseButtonPressed):
						for (int i=0; i<n_simpul; ++i) {
							if (event.mouseButton.x - 20 >= gambarsimpul[i].getPosition().x - 20 &&
								event.mouseButton.x - 20 <= gambarsimpul[i].getPosition().x + 20 &&
								event.mouseButton.y - 20 >= gambarsimpul[i].getPosition().y - 20 &&
								event.mouseButton.y - 20 <= gambarsimpul[i].getPosition().y + 20) {
									clickedsimpul = i;
									gambarsimpul[i].setPosition(event.mouseButton.x - 20, event.mouseButton.y - 20);
							}
						}
						break;
					case (sf::Event::MouseMoved):
						if (sf::Mouse::isButtonPressed && clickedsimpul != -1) {
							gambarsimpul[clickedsimpul].setPosition(sf::Vector2f(event.mouseMove.x - 20, event.mouseMove.y - 20));
							if (AIHunter.GetSimpul() == clickedsimpul) {
								AIHunter.setPosition(gambarsimpul[clickedsimpul].getPosition().x, gambarsimpul[clickedsimpul].getPosition().y);
							}
							int k=0;
							for (int i=0; i<n_simpul; ++i) {
								for (int j=0; j<i; ++j) {
									if (Graf[i][j] > 0) {
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[i].getPosition() + sf::Vector2f(20, 20));
										k++;
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[j].getPosition() + sf::Vector2f(20, 20));
										k++;
										text[k / 2].setPosition(sf::Vector2f((gambarsimpul[i].getPosition().x + gambarsimpul[j].getPosition().x) / 2, (gambarsimpul[i].getPosition().y + gambarsimpul[j].getPosition().y) / 2));
										string str = to_string(Graf[i][j]);
										text[k / 2].setString(str);
									}
								}
							}
						}
						break;
					case (sf::Event::MouseButtonReleased):
						if (clickedsimpul != -1) {
							gambarsimpul[clickedsimpul].setPosition(sf::Vector2f(event.mouseButton.x - 20, event.mouseButton.y - 20));
							if (AIHunter.GetSimpul() == clickedsimpul) {
								AIHunter.setPosition(gambarsimpul[clickedsimpul].getPosition().x, gambarsimpul[clickedsimpul].getPosition().y);
							}
							int k=0;
							for (int i=0; i<n_simpul; ++i) {
								for (int j=0; j<i; ++j) {
									if (Graf[i][j] > 0) {
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[i].getPosition() + sf::Vector2f(20, 20));
										k++;
										gambarsisi[k].position = sf::Vector2f(gambarsimpul[j].getPosition() + sf::Vector2f(20, 20));
										k++;
										text[k / 2].setPosition(sf::Vector2f((gambarsimpul[i].getPosition().x + gambarsimpul[j].getPosition().x) / 2, (gambarsimpul[i].getPosition().y + gambarsimpul[j].getPosition().y) / 2));
										string str = to_string(Graf[i][j]);
										text[k / 2].setString(str);
									}
								}
							}
							clickedsimpul = -1;
						}
						break;
					}
				}
				renderWindow.clear(sf::Color::White);
				renderWindow.draw(bgsprite);
				for (int i=0; i<n_simpul; ++i) {
					renderWindow.draw(gambarsimpul[i]);
					if (vertex[i].GetColor() == 'm') {
						gambarmerah.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
						renderWindow.draw(gambarmerah);
					} else if (vertex[i].GetColor() == 'k') {
						gambarkuning.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
						renderWindow.draw(gambarkuning);
					} else if (vertex[i].GetColor() == 'h') {
						gambarhijau.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
						renderWindow.draw(gambarhijau);
					}
				}
				renderWindow.draw(gambarsisi);
				for (int i=0; i<2*n_sisi; ++i) {
					renderWindow.draw(text[i]);
				}
				renderWindow.draw(text1);
				AIHunter.draw(renderWindow);
				renderWindow.display();
				sf::sleep(sf::milliseconds(20));
			}
			bool jalan=false;
			int candidate;
			int waktu_ambil_peti=0;
			if (IsPlaying) {
				if (waktu_main>AIHunter.GetWaktu() && !AllVertexVisited(visit,n_simpul) && !AIHunter.ToolHabis()) {
				Djikstra_MAP Out;
				Out.distance = new int[n_simpul];
				Out.path = new string[n_simpul];
				Out.total_harta = new int[n_simpul];
		
				double best_option=0;
				string best_path;
				int	total_money;
				bool stop=true;
				curr_vertex=AIHunter.GetSimpul();
				ShortestPath(Graf, &Out, n_simpul, curr_vertex, vertex);
				for (int i=0; i<n_simpul; i++) {
					if (Out.distance[i] > 0 && Out.distance[i]<=waktu_main) {
						double temp = (double)Out.total_harta[i]/(double)Out.distance[i];
						if (temp>0) {
							if (temp>best_option) {
								best_option=temp;
								best_path=Out.path[i];
								total_money=Out.total_harta[i];
								stop=false;
							}
						}
					}
				}
		
				if (stop) {
					AIHunter.SetWaktu(waktu_main+1);
				}
				else {
					int start=0, next_location;
					next_location=GetNextVertex(best_path, &start); //current location
			
					AIHunter.SetWaktu(Graf[curr_vertex][next_location]);
					AIHunter.SetSimpul(next_location);
					while (curr_vertex!=-1 && waktu_main>AIHunter.GetWaktu() && !AllVertexVisited(visit,n_simpul) && !AIHunter.ToolHabis() ) {
						char color = vertex[AIHunter.GetSimpul()].GetColor(); //'i' for invalid
						fout<<AIHunter.GetSimpul()+1;
						if (color!='i') {
							//buka peti sesuai warna
							int retval=-1;
							switch(color) {
								case 'm' : {
									if (AIHunter.GetTools(2)) {
										retval = vertex[AIHunter.GetSimpul()].BukaPeti(1);
										if (retval > 0) {
											AIHunter.SetUang(retval);
											AIHunter.SetWaktu(1);
											vertex[AIHunter.GetSimpul()].SetPeti(0,0,'i');
											fout<<",M"<<endl;
										}
										else fout<<",-"<<endl;
										AIHunter.SetTools(2,AIHunter.GetTools(2)-1);
									}
									else fout<<",-"<<endl;
									break;
								}
								case 'k' : {
									if (AIHunter.GetTools(1)) {
										retval = vertex[AIHunter.GetSimpul()].BukaPeti(2);
										if (retval > 0) {
											AIHunter.SetUang(retval);
											AIHunter.SetWaktu(2);
											vertex[AIHunter.GetSimpul()].SetPeti(0,0,'i');
											fout<<",K"<<endl;
										}
										else fout<<",-"<<endl;
										AIHunter.SetTools(1,AIHunter.GetTools(1)-1);
									}
									else if (AIHunter.GetTools(2)) {
										retval = vertex[AIHunter.GetSimpul()].BukaPeti(1);
										if (retval > 0) {
											AIHunter.SetUang(retval);
											AIHunter.SetWaktu(1);
											vertex[AIHunter.GetSimpul()].SetPeti(0,0,'i');
											fout<<",K"<<endl;
										}
										else fout<<",-"<<endl;
										AIHunter.SetTools(2,AIHunter.GetTools(2)-1);
									}
									else fout<<",-"<<endl;
									break;
								}
								default : fout<<",-"<<endl;
								//hijau tidak akan dibuka karena hanya balik modal
							}
						}
						else fout<<",-"<<endl;
						visit[AIHunter.GetSimpul()]=true;

						if (start<best_path.length()) {
							curr_vertex = AIHunter.GetSimpul();
							next_location=GetNextVertex(best_path, &start);
							
							AIHunter.SetWaktu(Graf[AIHunter.GetSimpul()][next_location]);

							candidate=next_location;
							AIHunter.SetSimpul(next_location);
							
							int diftime = 0, counter = 0;
							
								do {
									float x = (gambarsimpul[candidate].getPosition().x - gambarsimpul[curr_vertex].getPosition().x) / Graf[curr_vertex][candidate] / 50;
									float y = (gambarsimpul[candidate].getPosition().y - gambarsimpul[curr_vertex].getPosition().y) / Graf[curr_vertex][candidate] / 50;
									AIHunter.move(x, y);
									if (AIHunter.getPositionX() <= gambarsimpul[candidate].getPosition().x + 20 &&
										AIHunter.getPositionX() >= gambarsimpul[candidate].getPosition().x - 20 &&
										AIHunter.getPositionY() <= gambarsimpul[candidate].getPosition().y + 20 &&
										AIHunter.getPositionY() >= gambarsimpul[candidate].getPosition().y - 20) {
											AIHunter.setPosition(gambarsimpul[candidate].getPosition().x, gambarsimpul[candidate].getPosition().y);
									}
									counter++;
									if (counter== 50) {
										diftime++;
										counter = 0;
									}

									string str = to_string(waktu_main - AIHunter.GetWaktu() - diftime + Graf[curr_vertex][candidate] /*tambah waktu buka peti*/);
									text1.setString(str);

									//string keterangan
									textx.setString("(5c) meledak (1s)");
									texty.setString("(3c) meledak (2s)");
									textz.setString("(1c) meledak (4s)");

									//draw
									renderWindow.clear(sf::Color::White);
									renderWindow.draw(bgsprite);
									for (int i=0; i<n_simpul; ++i) {
										renderWindow.draw(gambarsimpul[i]);
										if (vertex[i].GetColor() == 'm') {
											gambarmerah.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
											renderWindow.draw(gambarmerah);
										} else if (vertex[i].GetColor() == 'k') {
											gambarkuning.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
											renderWindow.draw(gambarkuning);
										} else if (vertex[i].GetColor() == 'h') {
											gambarhijau.setPosition(circleShape.getPoint(i).x +192, circleShape.getPoint(i).y);
											renderWindow.draw(gambarhijau);
										}
									}
									
									renderWindow.draw(Merah);
									renderWindow.draw(Kuning);
									renderWindow.draw(Hijau);
									renderWindow.draw(MerahMini);
									renderWindow.draw(KuningMini);
									renderWindow.draw(HijauMini);

									string getm = to_string(AIHunter.GetTools(2));
									ToolsMerah.setString(getm);
									renderWindow.draw(ToolsMerah);
									string getk = to_string(AIHunter.GetTools(1));
									ToolsKuning.setString(getk);
									renderWindow.draw(ToolsKuning);
									string geth = to_string(AIHunter.GetTools(0));
									ToolsHijau.setString(geth);
									renderWindow.draw(ToolsHijau);


									string strs = to_string(AIHunter.GetUang());
									Status.setString(strs);
									renderWindow.draw(Status);
									renderWindow.draw(gambarsisi);
									renderWindow.draw(textx);
									renderWindow.draw(texty);
									renderWindow.draw(textz);

									for (int i=0; i<2*n_sisi; ++i) {
										renderWindow.draw(text[i]);
									}
									renderWindow.draw(text1);
									AIHunter.draw(renderWindow);
									if (MODEGAME==2) Human.draw(renderWindow);
									renderWindow.display();
									sf::sleep(sf::milliseconds(17));
								} while (AIHunter.getPositionX() != gambarsimpul[candidate].getPosition().x ||
									AIHunter.getPositionY() != gambarsimpul[candidate].getPosition().y);
						}
						else curr_vertex=-1;
					}
				}
			} else IsPlaying = false;
		} 
	  }
	}

	bool keluar = false;
	while (!keluar) {
		sf::Event event;
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::MouseButtonPressed) {
				keluar = true;
			}
		}
		renderWindow.clear(sf::Color::White);
		
		sf::Texture texture;
		texture.loadFromFile("images/endpage.png");
		sf::Sprite endpage;
		endpage.setTexture(texture);

		sf::Text textmenang;
		textmenang.setFont(font);
		textmenang.setColor(sf::Color::Red);
		textmenang.setCharacterSize(30);
		textmenang.setStyle(sf::Text::Bold);
		textmenang.setPosition(540, 530);
		string str = to_string(AIHunter.GetUang());
		string strx = "Uang final AI " + str;
		textmenang.setString(strx);

		sf::Text textmenang1;
		textmenang1.setFont(font);
		textmenang1.setColor(sf::Color::Red);
		textmenang1.setCharacterSize(30);
		textmenang1.setStyle(sf::Text::Bold);
		textmenang1.setPosition(540, 560);

		str = to_string(skor_menang);
		strx = "Skor Minimal Menang " + str;
		textmenang1.setString(strx);

		renderWindow.draw(endpage);
		renderWindow.draw(textmenang);
		renderWindow.draw(textmenang1);
		if (MODEGAME==2) {
			sf::Text textmenang2;
			textmenang2.setFont(font);
			textmenang2.setColor(sf::Color::Red);
			textmenang2.setCharacterSize(30);
			textmenang2.setStyle(sf::Text::Bold);
			textmenang2.setPosition(540, 500);
			str = to_string(Human.GetUang());
			strx = "Uang final Manusia " + str;
			textmenang2.setString(strx);
			renderWindow.draw(textmenang2);
			//tampilin uang manusia, uang hunter, skor menang
		}
		renderWindow.display();
	}
	//cout << "final uang = " << AIHunter.GetUang() << endl;
	//cout << "final uang = " << Human.GetUang() << endl;
	fin.close();
	fout.close();
	return 0;
}
