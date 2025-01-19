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

//Ürün verileri
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
	
	//Ana Giriþ Ekraný
	cout << "*****************************************\n";
    cout << "*                                       *\n";
    cout << "*      Fýrýn Otomasyon Sistemine        *\n";
    cout << "*                                       *\n";
    cout << "*            Hoþgeldiniz                *\n";
    cout << "*                                       *\n";
    cout << "*      Keyifli Kullanýmlar Dileriz!     *\n";
    cout << "*                                       *\n";
    cout << "*****************************************\n"<<endl;

	//Giriþ Türü Seçim
	cout<<"Lütfen giriþ türü seçin (Admin(A/a) / Müþteri(M/m))"<<endl; 
	cin>>giris;
	
	//Admin seçimi
	if(giris=="a"||giris=="A")
	{
		//Admin Tasarým
		cout<<"Admin sayfasý yükleniyor..."; Sleep(2000); system("cls");
			
		cout << "*****************************************\n";
    	cout << "*                                       *\n";
    	cout << "*           Admin giriþine              *\n";
    	cout << "*                                       *\n";
    	cout << "*            Hoþgeldiniz                *\n";
    	cout << "*                                       *\n";
    	cout << "*      Keyifli Kullanýmlar Dileriz!     *\n";
    	cout << "*                                       *\n";
    	cout << "*****************************************\n"<<endl;
    	

		//ADMÝN GÝRÝÞÝ:
		
		//Kullanýcý ad
	    cout<<"Kullanýcý adý girin: "<<endl;
	    cin>>kullanici_ad;
	    
		//þifre	
	    cout<<"þifreyi girin: "<<endl;
	    cin>>sifre;
	    	
	    	//Baþarýlý giriþ
	    	if(kullanici_ad=="admin"&&sifre=="1234")
	    	{
	    		//gerekli deðiþkenler
	    		char secim,dongu;
	    		
	    		cout<<"Giriþ baþarýlý"<<endl<<"Sayfa yükleniyor..."; Sleep(2000); system("cls");
	    		
	    		//Admin seçim ekraný
	    		do
	    		{
	    			//Admin seçim tasarým
    				cout << "*********************************************\n";
    				cout << "*           Lütfen seçim yapýnýz            *\n";
    				cout << "*                                           *\n";
    				cout << "*            1- Ürün ekleme                 *\n";
    				cout << "*            2- Ürün silme                  *\n";
    				cout << "*            3- Ürün güncelleme             *\n";
    				cout << "*                                           *\n";
    				cout << "*********************************************\n"<<endl;
    				cout<< "secimi giriniz: "<<endl;
    				secim=getche();
    				
    				//admin seçimi
    				switch(secim)
					{
						//Ürün ekleme
						case '1':	
							Ekle();
						break;
						
						//Ürün silme
						case '2':
							Sil();
						break;
						
						//Güncelleme
						case '3':
							Guncelle();
							
						break;
					}
    				
	    			cout<<"devam etmek istermisiniz? (E/e)"<<endl;
	    			dongu=getche();
				}
				while(dongu=='e'||dongu=='E');
	    		
			}
			//Hatalý giriþ
			else
			{
				cout<<"Hatalý giriþ"<<endl;
				Sleep(2000);
				system("taskkill /IM Firin_Otomasyon.exe /F");
				
			}
	
	}
	
	//Müþteri giriþi
	else if(giris=="m"||giris=="M")
	{
		
		cout<<"Müþteri sayfasý yükleniyor..."; Sleep(2000); system("cls");
		
		char arama;
		string kelime;
		
		//Müþteri giriþ tasarým
		cout << "*********************************************\n";
		cout << "*              Hoþgeldiniz                  *\n";
		cout << "*                                           *\n";
		cout << "*    Bugünün Önerisi: Lezzetli Ekmekler     *\n";
   		cout << "*                                           *\n";
    	cout << "*        Keyifli Alýþveriþler Dileriz!      *\n";
    	cout << "*                                           *\n";
    	cout << "*                                           *\n";
    	cout << "*********************************************\n"<<endl;
    	
    	//Müþteri seçmim/tasarým ekraný
    	cout << "*********************************************\n";
    	cout << "*           Lütfen seçim yapýnýz            *\n";
    	cout << "*                                           *\n";
    	cout << "*            1- Ürün Arama                  *\n";
    	cout << "*            2- Ürünleri Listeleme          *\n";
    	cout << "*                                           *\n";
    	cout << "*********************************************\n"<<endl;
    	
    	//Müþteri seçim
    	cout<<"Seçimi girin:";
    	arama=getche();
    	
    	switch(arama)
    	{
    		// Seçili ürünü Arama
    		case '1':
    			Arama();
    		break;
    		
    		//Ürünü listeleme
    		case '2':
    			Listeleme();
    		break;
		}
    	
    	
	}
	
	//Hatalý giriþ
	else
	{
		cout<<"Geçersiz giriþ."<<endl; Sleep(500);  cout<< "program yeniden Baþlatýlýyor..."; Sleep(2000);
		system("start Firin_Otomasyon.exe");
    }
	return 0;
}

// structu deðiþken ekleme
Urun urn;

//Ürün ekleme 
void Ekle()
{
	//urun data ekleme/çaðýrma
	ofstream yaz("urun.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
	
	//seçim
	do{
	system("cls");
	
	//Admin seçim tasarým
    cout << "*********************************************\n";
    cout << "*           Lütfen seçim yapýnýz            *\n";
    cout << "*                                           *\n";
    cout << "*            1- Ürün ekleme                 *\n";
    cout << "*            2- Ürün silme                  *\n";
    cout << "*            3- Ürün güncelleme             *\n";
    cout << "*                                           *\n";
    cout << "*********************************************\n"<<endl;
    cout<< "secimi giriniz: "<<endl;
		
	//Kaydedilcek ürün verisi alma	
	cout << "Ürün adý giriniz";
	cin>> urn.ad;
	cout << "Malzeme giriniz" << endl;
	cin>> urn.malzeme;
	cout << "Gramajýný  giriniz" << endl;
	cin>> urn.gramaj;
	cout << "Fiyatý giriniz giriniz" << endl;
	cin>> urn.fiyat;
	cout << "Adet sayýsýný giriniz giriniz" << endl;
	cin>> urn.adet;
	cout << endl;
	
	yaz.write((char*)&urn, sizeof(urn));	
	
	adet++;	
	
	cout << "Baska Kayit Eklemek Istermisin (E/H)" << endl;
	secim=getche();
	cout << endl;
	
	}while(secim=='e' || secim=='E');
	
	cout << adet << " adet ürün ekledi.." << endl;
	
	yaz.close();
	
	
}

//Ürün listeleme
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
		
			cout << "Ürün adý: "<< urn.ad <<endl ;
			cout << "Malzemesi: "<< urn.malzeme <<endl ;
			cout << "Gramajý: "<< urn.gramaj <<endl ;
			cout << "Fiyatý: "<< urn.fiyat<<"TL"<<endl ;
			cout << "Adet sayýsý: "<< urn.adet <<endl<<endl;
			cout<<"---------------"<<endl<<endl;
			
			
			
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	oku.close();
}

//Ürün arama
void Arama()
{
	char secim;
	
	ifstream oku("urun.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(urn);
	cout << "Satýþtaki toplam ürün sayýsý: "<< kayits << endl;

	cout <<"Aranan Ürünün adýný giriniz"<< endl;
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
			cout <<  "Aranýlan Ürün Bilgileri:"<< endl;
			cout << "Ürün adý: "<< urn.ad <<endl ;
			cout << "Malzemesi: "<< urn.malzeme <<endl ;
			cout << "Gramajý: "<< urn.gramaj <<endl ;
			cout << "Fiyatý: "<< urn.fiyat<<"TL"<<endl ;
			cout << "Adet sayýsý: "<< urn.adet <<endl<<endl;
		    }
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	cout<<"Baþka ürün aramak istermisiniz (E/e)"<<endl;
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
            cout << "Aranýlan Urun Bilgileri:" << endl;
            cout << "Urun adý: " << urn.ad << endl;
            cout << "Malzemesi: " << urn.malzeme << endl;
            cout << "Gramajý: " << urn.gramaj << endl;
            cout << "Fiyatý: " << urn.fiyat << "TL" << endl;
            cout << "Adet sayýsý: " << urn.adet << endl
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


