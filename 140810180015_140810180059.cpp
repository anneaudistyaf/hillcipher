/*
Nama : Meira Dwiana Anjani & Anne Audistya Fernanda
NPM : 140810180015 & 140810180059
Kelas : A
Tugas Kriptografi Program Hill Cipher 
*/

#include <iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

int fungsimod(int a, int b)
{
	int result = a % b;
	if (result < 0)
	{
		result += b;
	}
	return result;
}

void enkripsi()
{
	string pesan;
	cout << "Masukkan Plaintext : ";
	getline(cin, pesan);
	//uppercase
	for (int i = 0; i < pesan.length(); i++)
	{
		pesan[i] = toupper(pesan[i]);
	}
	// jika panjang kata/2 = 0
	int lenChk = 0;
	if (pesan.length() % 2 != 0)
	{
		pesan += "0";
		lenChk = 1;
	}
	// message to 2x pesan.length/2 matrix
	int pesan2D[2][pesan.length() / 2];
	int itr1 = 0;
	int itr2 = 0;
	for (int i = 0; i < pesan.length(); i++)
	{
		if (i % 2 == 0)
		{
			pesan2D[0][itr1] = pesan[i] - 65;
			itr1++;
		}
		else
		{
			pesan2D[1][itr2] = pesan[i] - 65;
			itr2++;
		} 
	} 
	// testing matrix alfabet
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < pesan.length() / 2; j++)
		{
			cout << (pesan2D[i][j]) << " ";
		}
	cout << endl;
	}
	cout << "Input key dalam bentuk matriks (satu persatu lalu enter) : " << endl;
	int key2D[2][2], transpose[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "Masukkan matriks 2x2 : "; cin >> key2D[i][j];
		}
	}

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
		transpose[j][i] = key2D[i][j];
		}
	}

	// test matrix key
	for(int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
		cout << (transpose[i][j]) << " ";
		}
	cout <<endl;
	}
	
	// checking validity of the key
	// finding determinant
	int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
	deter = fungsimod(deter, 26);
	// finding multiplicative inverse
	int mulInv = -1;
	for (int i = 0; i < 26; i++)
	{
		int tempInv = deter * i;
		if (fungsimod(tempInv, 26) == 1)
		{
			mulInv = i;
			break;
		}
		else
		{
			continue;
		}
	} // for
	if (mulInv == -1)
	{
		cout << "invalid key" << endl;
	}
	string hasilenkrip = "";
	int itrCount = pesan.length() / 2;
	if (lenChk == 0)
	{
 	// if pesan.length % 2 == 0
		for (int i = 0; i < itrCount; i++)
		{
			int temp1 = pesan2D[0][i] * key2D[0][0] + pesan2D[1][i] *
			key2D[0][1];
			hasilenkrip += (char)((temp1 % 26) + 65);
			int temp2 = pesan2D[0][i] * key2D[1][0] + pesan2D[1][i] *
			key2D[1][1];
			hasilenkrip += (char)((temp2 % 26) + 65);
		}
	}
	else
	{
		// if pesan.length % 2 == 0
		for (int i = 0; i < itrCount - 1; i++)
		{
			int temp1 = pesan2D[0][i] * key2D[0][0] + pesan2D[1][i] *
			key2D[0][1];
			hasilenkrip += (char)((temp1 % 26) + 65);
			int temp2 = pesan2D[0][i] * key2D[1][0] + pesan2D[1][i] *
			key2D[1][1];
			hasilenkrip += (char)((temp2 % 26) + 65);
		}
	}
	cout << endl
	<< "Hasil Enkripsi : " << hasilenkrip << endl;
}


void dekripsi()
{
	string pesan;
	cout << "Input Ciphertext : ";
	getline(cin, pesan);
	//uppercase
	for (int i = 0; i < pesan.length(); i++)
	{
		pesan[i] = toupper(pesan[i]);
	}
	//jika panjang kata/2 = 0
	int lenChk = 0;
	if (pesan.length() % 2 != 0)
	{
		pesan += "0";
		lenChk = 1;
	}
	// message to 2x pesan.length/2 matrix
	int pesan2D[2][pesan.length() / 2];
	int itr1 = 0;
	int itr2 = 0;
	for (int i = 0; i < pesan.length(); i++)
	{
		if (i % 2 == 0)
		{
			pesan2D[0][itr1] = pesan[i] - 65;
			itr1++;
		}
		else
		{
			pesan2D[1][itr2] = pesan[i] - 65;
			itr2++;
		} 
	}
	// test matrix alfabet
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < pesan.length() / 2; j++)
		{
			cout << (pesan2D[i][j]) << " ";
		}
	cout << endl;
	}
	cout << "Input key dalam bentuk matriks (satu persatu lalu enter) : " << endl;
	int key2D[2][2], transpose[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "Masukkan matriks 2x2 : "; cin >> key2D[i][j];
		}
	}

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
		transpose[j][i] = key2D[i][j];
		}
	}

	// test matrix key
	for(int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
		cout << (transpose[i][j]) << " ";
		}
	cout <<endl;
	}
	// cari determinan
	int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
	deter = fungsimod(deter, 26);
	// cari hasil kali inverse
	int mulInv = -1;
	for (int i = 0; i < 26; i++)
	{
		int tempInv = deter * i;
		if (fungsimod(tempInv, 26) == 1)
		{
			mulInv = i;
			break;
		}
		else
		{
			continue;
		}
	} 
	// adjugate matrix
	//swapping
	swap(key2D[0][0], key2D[1][1]);
	// ubah tanda
	key2D[0][1] *= -1;
	key2D[1][0] *= -1;
	key2D[0][1] = fungsimod(key2D[0][1], 26);
	key2D[1][0] = fungsimod(key2D[1][0], 26);
	// multiplying multiplicative inverse with adjugate matrix
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			key2D[i][j] *= mulInv;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			key2D[i][j] = fungsimod(key2D[i][j], 26);
		}
	}
	// ciphertext KE plain text
	string hasildekrip = "";
	int itrCount = pesan.length() / 2;
	if (lenChk == 0)
	{
		// if pesan.length % 2 == 0
		for (int i = 0; i < itrCount; i++)
		{
			int temp1 = pesan2D[0][i] * key2D[0][0] + pesan2D[1][i] *
			key2D[0][1];
			hasildekrip += (char)((temp1 % 26) + 65);
			int temp2 = pesan2D[0][i] * key2D[1][0] + pesan2D[1][i] *
			key2D[1][1];
			hasildekrip += (char)((temp2 % 26) + 65);
		}
	}
	else
	{
		// if pesan.length % 2 == 0
		for (int i = 0; i < itrCount - 1; i++)
		{
			int temp1 = pesan2D[0][i] * key2D[0][0] + pesan2D[1][i] *
			key2D[0][1];
			hasildekrip += (char)((temp1 % 26) + 65);
			int temp2 = pesan2D[0][i] * key2D[1][0] + pesan2D[1][i] *
			key2D[1][1];
			hasildekrip += (char)((temp2 % 26) + 65);
		}
	}
	cout << endl << "Hasil Dekripsi : " << hasildekrip << endl;
}

int gcd(int m, int n){
	if (n > m)
		swap(m,n);
	
	do{
		int temp = m % n;
		m = n;
		n = temp;
	} while (n != 0);
	
	return m;
}

int findInvers(int m, int n){
	int t0 = 0,t1 = 1,invers,q,r,b = m;
	while(r != 1){
		q = m/n;
		r = m%n;
		invers = t0 - q * t1;
		if(invers < 0){
			invers = b - (abs(invers)%b);
		}else{
			invers %= b;
		}
		t0 = t1;
		t1 = invers;
		m = n;
		n = r;	
	}
	return invers;
}
void findKey(){
	//deklarasi
	string plainteks,cipherteks;
	int key[2][2],det,detInv,adj[2][2],plainteksInv[2][2],plainMatrix[2][2],cipMatrix[2][2],counter;
	int p,c;
	int transpose[2][2];
	
	//input plainteks
	cout << "Masukan Plainteks : ";
	cin.ignore();
	getline(cin,plainteks);
	
	//assign plainteks ke plainMatrix
	counter = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			p = toupper(plainteks[counter]) - 65;
			plainMatrix[i][j] = p;
			counter++;
		}
	}
	
	//input cipherteks
	cout << "Masukan Cipherteks : ";
	getline(cin,cipherteks);
	
	//assign cipherteks ke cipMatrix
	counter = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			c = toupper(cipherteks[counter]) - 65;
			cipMatrix[i][j] = c;
			counter++;
		}
	}
	
	//mencari determinan
	det = (plainMatrix[0][0] * plainMatrix[1][1]) - (plainMatrix[0][1] * plainMatrix[1][0]);
	if(gcd(det,26)==1){
		//mencari inverse dari determinan
		detInv = findInvers(26,det);
		
		//menghitung matriks adjoin
		adj[0][0] = plainMatrix[1][1];
		adj[0][1] = (-1)*plainMatrix[0][1];
		adj[1][0] = (-1)*plainMatrix[1][0];
		adj[1][1] = plainMatrix[0][0];
		
		//menghitung matriks invers dari plainteks
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				plainteksInv[i][j] = detInv * adj[i][j];
				if(plainteksInv[i][j] < 0){
					plainteksInv[i][j] = 26 - (abs(plainteksInv[i][j])%26); 
				}else{
					plainteksInv[i][j] = plainteksInv[i][j];
					plainteksInv[i][j] = plainteksInv[i][j] % 26;
				}
			} 
		}
		
		//mencari key
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				key [i][j] = 0;
				for(int k = 0; k < 2; k++){
					key [i][j] += (plainteksInv[i][k] * cipMatrix[k][j]);
				}
				key [i][j] %= 26;
			}
		}
		
//		//output key
//		cout << "Key : " <<endl;
//		for(int i = 0; i < 2; i++){
//			for(int j = 0; j < 2; j++){
//				cout << key[i][j]<<"\t";
//			}
//			cout<<endl;
//		}

		//output key
		for (int i = 0; i < 2; i++){
    	for (int j = 0; j < 2; j++){
      		transpose[j][i] = key[i][j];
    		}
  		}
  	
	    for(int i = 0; i < 2; i++){
	        for (int j = 0; j < 2; j++){
	            cout << (transpose[i][j]) << "\t";
	        }
	        cout <<endl;
	    } 	 	
	}else{
		cout << "Determinan tidak relatif prima dengan jumlah huruf" <<endl;
		cout << "Key tidak dapat dicari" <<endl<<endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	int menu;
	bool stop;
	stop = false;
	while (!stop)
	{
		cout << "        HILL CIPHER        " << endl;
		cout << "      Anne dan Meira       " << endl;
		cout << "==============================" << endl;
		cout << "= 1. Enkripsi                =" << endl;
		cout << "= 2. Dekripsi                =" << endl;
		cout << "= 3. Cari Kunci              =" << endl;
		cout << "==============================" << endl;
		cout << "Pilih menu : ";
		cin >> menu;
		cin.ignore();
		switch (menu)
		{
			case 1:
			cout << endl << "---ENKRIPSI---" << endl;
			enkripsi();
			break;
			case 2:
			cout << endl << "---DEKRIPSI---" << endl;
			dekripsi();
			break;
			case 3:
			findKey();
			case 4:
			stop = true;
			break;
		}
	}
}
