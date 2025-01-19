#include <iostream>
#include <fstream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

//�r�n verileri
struct Urun
{
	char ad[80];
	char malzeme[80];
	char gramaj[4];
	char fiyat[4];
	char adet[5];
};

//void belirtme
void Ekle();
void Listeleme();
void Arama();
void Sil();
 void Guncelle();

int main(){
setlocale(LC_ALL,"Turkish");
	
	
	//Gerekli veriler
	string giris,kullanici_ad,sifre;
	
	//Ana Giri� Ekran�
	cout << "*****************************************\n";
    cout << "*                                       *\n";
    cout << "*      F�r�n Otomasyon Sistemine        *\n";
    cout << "*                                       *\n";
    cout << "*            Ho�geldiniz                *\n";
    cout << "*                                       *\n";
    cout << "*      Keyifli Kullan�mlar Dileriz!     *\n";
    cout << "*                                       *\n";
    cout << "*****************************************\n"<<endl;

	//Giri� T�r� Se�im
	cout<<"L�tfen giri� t�r� se�in (Admin(A/a) / M��teri(M/m))"<<endl; 
	cin>>giris;
	
	//Admin se�imi
	if(giris=="a"||giris=="A")
	{
		//Admin Tasar�m
		cout<<"Admin sayfas� y�kleniyor..."; Sleep(2000); system("cls");
			
		cout << "*****************************************\n";
    	cout << "*                                       *\n";
    	cout << "*           Admin giri�ine              *\n";
    	cout << "*                                       *\n";
    	cout << "*            Ho�geldiniz                *\n";
    	cout << "*                                       *\n";
    	cout << "*      Keyifli Kullan�mlar Dileriz!     *\n";
    	cout << "*                                       *\n";
    	cout << "*****************************************\n"<<endl;
    	

		//ADM�N G�R���:
		
		//Kullan�c� ad
	    cout<<"Kullan�c� ad� girin: "<<endl;
	    cin>>kullanici_ad;
	    
		//�ifre	
	    cout<<"�ifreyi girin: "<<endl;
	    cin>>sifre;
	    	
	    	//Ba�ar�l� giri�
	    	if(kullanici_ad=="admin"&&sifre=="1234")
	    	{
	    		//gerekli de�i�kenler
	    		char secim,dongu;
	    		
	    		cout<<"Giri� ba�ar�l�"<<endl<<"Sayfa y�kleniyor..."; Sleep(2000); system("cls");
	    		
	    		//Admin se�im ekran�
	    		do
	    		{
	    			//Admin se�im tasar�m
    				cout << "*********************************************\n";
    				cout << "*           L�tfen se�im yap�n�z            *\n";
    				cout << "*                                           *\n";
    				cout << "*            1- �r�n ekleme                 *\n";
    				cout << "*            2- �r�n silme                  *\n";
    				cout << "*            3- �r�n g�ncelleme             *\n";
    				cout << "*                                           *\n";
    				cout << "*********************************************\n"<<endl;
    				cout<< "secimi giriniz: "<<endl;
    				secim=getche();
    				
    				//admin se�imi
    				switch(secim)
					{
						//�r�n ekleme
						case '1':	
							Ekle();
						break;
						
						//�r�n silme
						case '2':
							Sil();
						break;
						
						//G�ncelleme
						case '3':
							Guncelle();
							
						break;
					}
    				
	    			cout<<"devam etmek istermisiniz? (E/e)"<<endl;
	    			dongu=getche();
				}
				while(dongu=='e'||dongu=='E');
	    		
			}
			//Hatal� giri�
			else
			{
				cout<<"Hatal� giri�"<<endl;
				Sleep(2000);
				system("taskkill /IM Firin_Otomasyon.exe /F");
				
			}
	
	}
	
	//M��teri giri�i
	else if(giris=="m"||giris=="M")
	{
		
		cout<<"M��teri sayfas� y�kleniyor..."; Sleep(2000); system("cls");
		
		char arama;
		string kelime;
		
		//M��teri giri� tasar�m
		cout << "*********************************************\n";
		cout << "*              Ho�geldiniz                  *\n";
		cout << "*                                           *\n";
		cout << "*    Bug�n�n �nerisi: Lezzetli Ekmekler     *\n";
   		cout << "*                                           *\n";
    	cout << "*        Keyifli Al��veri�ler Dileriz!      *\n";
    	cout << "*                                           *\n";
    	cout << "*                                           *\n";
    	cout << "*********************************************\n"<<endl;
    	
    	//M��teri se�mim/tasar�m ekran�
    	cout << "*********************************************\n";
    	cout << "*           L�tfen se�im yap�n�z            *\n";
    	cout << "*                                           *\n";
    	cout << "*            1- �r�n Arama                  *\n";
    	cout << "*            2- �r�nleri Listeleme          *\n";
    	cout << "*                                           *\n";
    	cout << "*********************************************\n"<<endl;
    	
    	//M��teri se�im
    	cout<<"Se�imi girin:";
    	arama=getche();
    	
    	switch(arama)
    	{
    		// Se�ili �r�n� Arama
    		case '1':
    			Arama();
    		break;
    		
    		//�r�n� listeleme
    		case '2':
    			Listeleme();
    		break;
		}
    	
    	
	}
	
	//Hatal� giri�
	else
	{
		cout<<"Ge�ersiz giri�."<<endl; Sleep(500);  cout<< "program yeniden Ba�lat�l�yor..."; Sleep(2000);
		system("start Firin_Otomasyon.exe");
    }
	return 0;
}

// structu de�i�ken ekleme
Urun urn;

//�r�n ekleme 
void Ekle()
{
	//urun data ekleme/�a��rma
	ofstream yaz("urun.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
	
	//se�im
	do{
	system("cls");
	
	//Admin se�im tasar�m
    cout << "*********************************************\n";
    cout << "*           L�tfen se�im yap�n�z            *\n";
    cout << "*                                           *\n";
    cout << "*            1- �r�n ekleme                 *\n";
    cout << "*            2- �r�n silme                  *\n";
    cout << "*            3- �r�n g�ncelleme             *\n";
    cout << "*                                           *\n";
    cout << "*********************************************\n"<<endl;
    cout<< "secimi giriniz: "<<endl;
		
	//Kaydedilcek �r�n verisi alma	
	cout << "�r�n ad� giriniz";
	cin>> urn.ad;
	cout << "Malzeme giriniz" << endl;
	cin>> urn.malzeme;
	cout << "Gramaj�n�  giriniz" << endl;
	cin>> urn.gramaj;
	cout << "Fiyat� giriniz giriniz" << endl;
	cin>> urn.fiyat;
	cout << "Adet say�s�n� giriniz giriniz" << endl;
	cin>> urn.adet;
	cout << endl;
	
	yaz.write((char*)&urn, sizeof(urn));	
	
	adet++;	
	
	cout << "Baska Kayit Eklemek Istermisin (E/H)" << endl;
	secim=getche();
	cout << endl;
	
	}while(secim=='e' || secim=='E');
	
	cout << adet << " adet �r�n ekledi.." << endl;
	
	yaz.close();
	
	
}

//�r�n listeleme
void Listeleme()

{
	
	ifstream oku("urun.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(urn);
	cout << "Toplam Ogrenci Kayit Sayisi:"<< kayits << endl;	
	
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			oku.seekg(i*sizeof(urn));
			oku.read((char*)&urn, sizeof(urn));	
		
			cout << "�r�n ad�: "<< urn.ad <<endl ;
			cout << "Malzemesi: "<< urn.malzeme <<endl ;
			cout << "Gramaj�: "<< urn.gramaj <<endl ;
			cout << "Fiyat�: "<< urn.fiyat<<"TL"<<endl ;
			cout << "Adet say�s�: "<< urn.adet <<endl<<endl;
			cout<<"---------------"<<endl<<endl;
			
			
			
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	oku.close();
}

//�r�n arama
void Arama()
{
	char secim;
	
	ifstream oku("urun.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(urn);
	cout << "Sat��taki toplam �r�n say�s�: "<< kayits << endl;

	cout <<"Aranan �r�n�n ad�n� giriniz"<< endl;
	char urun_ad[80];
	cin>> urun_ad;
	
	do
	{
			if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			
			oku.seekg(i*sizeof(urn));
			oku.read((char*)&urn, sizeof(urn));
			
			if(strcmp(urn.ad,urun_ad)==0)
			{
			cout <<  "Aran�lan �r�n Bilgileri:"<< endl;
			cout << "�r�n ad�: "<< urn.ad <<endl ;
			cout << "Malzemesi: "<< urn.malzeme <<endl ;
			cout << "Gramaj�: "<< urn.gramaj <<endl ;
			cout << "Fiyat�: "<< urn.fiyat<<"TL"<<endl ;
			cout << "Adet say�s�: "<< urn.adet <<endl<<endl;
		    }
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	cout<<"Ba�ka �r�n aramak istermisiniz (E/e)"<<endl;
	secim=getche();
	}
	while(secim=='E'||secim=='e');
	oku.close();
 		

}

void Sil()
{
    char urun_ad[80];
    char secim = ' ';
    bool var = false;

    ifstream oku("urun.dat", ios::binary | ios::app);

    oku.seekg(0, ios::end);
    int kayitsayisi = oku.tellg() / sizeof(urn);

    cout << "Kaydini Sileceginiz Urun Adini Giriniz : ";
    cin.ignore(); // Ignore any newline characters in the input buffer
    cin.getline(urun_ad, 80);

    for (int i = 0; i < kayitsayisi; i++)
    {
        oku.seekg(i * sizeof(urn));
        oku.read((char *)&urn, sizeof(urn));

        if (strcmp(urn.ad, urun_ad) == 0)
        {
            cout << "Aran�lan Urun Bilgileri:" << endl;
            cout << "Urun ad�: " << urn.ad << endl;
            cout << "Malzemesi: " << urn.malzeme << endl;
            cout << "Gramaj�: " << urn.gramaj << endl;
            cout << "Fiyat�: " << urn.fiyat << "TL" << endl;
            cout << "Adet say�s�: " << urn.adet << endl
                 << endl;

            cout << "Silmek Istediginiz Urun Bu Mu? [E/H] : ";
            secim = getche();
            cout << endl;

            if (secim == 'H' || secim == 'h')
            {
                // Backup the record to a temporary file
                ofstream yedek("Yedek.dat", ios::app | ios::binary);
                yedek.write((char *)&urn, sizeof(urn));
                yedek.close();
            }
            else if (secim == 'e' || secim == 'E')
            {
                var = true;
                // Skip writing the record to the backup file
            }
        }
        else
        {
            // Write non-matching records to the backup file
            ofstream yedek("Yedek.dat", ios::app | ios::binary);
            yedek.write((char *)&urn, sizeof(urn));
            yedek.close();
        }
    }
    oku.close();

    if (var)
    {
        // Delete the original file and rename the backup file
        remove("urun.dat");
        rename("Yedek.dat", "urun.dat");
        cout << "Kayit Silindi" << endl;
    }
    else
    {
        // Remove the backup file if no records were deleted
        remove("Yedek.dat");
        cout << "Kayit Bulunamadi" << endl;
    }
}

void Guncelle()
{
    char urun_ad[80];
    char secim = ' ';
    bool var = false;

    ifstream oku("urun.dat", ios::binary | ios::app);
    oku.seekg(0, ios::end);
    int kayitsayisi = oku.tellg() / sizeof(urn);

    cout << "Kaydini Duzelteceginiz Urun Adini Giriniz: ";
    cin.ignore(); // Ignore any newline characters in the input buffer
    cin.getline(urun_ad, 80);

    // Open a temporary file to store the updated data
    ofstream yedek("Yedek.dat", ios::app | ios::binary);

    for (int i = 0; i < kayitsayisi; i++)
    {
        oku.seekg(i * sizeof(urn));
        oku.read((char *)&urn, sizeof(urn));

        if (strcmp(urn.ad, urun_ad) == 0)
        {
            cout << "Aranilan Urun Bilgileri:" << endl;
            cout << "Urun adi: " << urn.ad << endl;
            cout << "Malzemesi: " << urn.malzeme << endl;
            cout << "Gramaji: " << urn.gramaj << endl;
            cout << "Fiyati: " << urn.fiyat << "TL" << endl;
            cout << "Adet sayisi: " << urn.adet << endl << endl;

            cout << "Duzeltmek Istediginiz Urun Bu Mu? [E/H]: ";
            secim = getche();
            cout << endl;

            if (secim == 'E' || secim == 'e')
            {
                var = true;
                // Ask the user to input the updated data
                cout << "Yeni Urun Adi: ";
                cin >> urn.ad;
                cout << "Yeni Malzeme: ";
                cin >> urn.malzeme;
                cout << "Yeni Gramaj: ";
                cin >> urn.gramaj;
                cout << "Yeni Fiyat: ";
                cin >> urn.fiyat;
                cout << "Yeni Adet Sayisi: ";
                cin >> urn.adet;

                cout << "Urun bilgileri guncellendi!" << endl;
            }
        }

        // Write the (updated or original) record to the temporary file
        yedek.write((char *)&urn, sizeof(urn));
    }

    oku.close();
    yedek.close();

    // If an update was made, replace the original file with the temporary file
    if (var)
    {
        remove("urun.dat");
        rename("Yedek.dat", "urun.dat");
        cout << "Kayit Duzeltildi." << endl;
    }
    else
    {
        // Remove the temporary file if no updates were made
        remove("Yedek.dat");
        cout << "Kayit Bulunamadi." << endl;
    }
}


