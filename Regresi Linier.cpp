//Taufik Lesmana NK & Anton Saputra//
//3411151079  & 3411151080//
//SIE B//
//regresi linier//
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define nmax 100

int main  (){
	
//kamus data
int angka, jarak;
int x[nmax+1];
int y[nmax+1];
float pre[nmax+1], error[nmax+1];
float m, c, fx, err;
int sigmax, sigmay, sigmaerror, sigmaxy=0, jumxkuadrat=0, jumykuadrat=0, kuadrattotalx;
int n, i;
int xkuadrat[nmax+1], ykuadrat[nmax+1], xy[nmax+1];

//algoritma
printf ("\n MENGHITUNG REGRESI LINIER \n");
printf("==================================\n");
printf ("\nMasukkan jumlah N : "); scanf ("%d", &n);
printf ("\n\n");

//nilai x
for(i=1;i<=n;i++){
	printf ("Masukkan nilai X : ");scanf("%d", &angka);
	x[i]=angka;
	xkuadrat[i]=pow(x[i], 2);
    sigmax=sigmax + x[i];
    jumxkuadrat=jumxkuadrat + xkuadrat[i];
} 

//tampil x
for (i=1; i<=n;i++){
	printf ("\n X[%d] = %d \n", i, x[i]);
} 

//nilai y
printf("\n==========================================\n");
for (i=1;i<=n;i++){
	printf("Masukkan nilai Y : "); scanf("%d", &angka);
	y[i]=angka;
	sigmay=sigmay + y[i];
    ykuadrat[i]=pow(y[i], 2);
    jumykuadrat=jumykuadrat + ykuadrat[i];
    xy[i]=x[i]*y[i];
    sigmaxy=sigmaxy + xy[i];
}

//tampil y
for (i=1; i<=n;i++){
	printf ("\n Y[%d] = %d \n",i, y[i]);
} printf ("\n======================\n");

  //menghitung m
  m=((angka*sigmaxy)-(sigmax*sigmay)) / ((angka*jumxkuadrat)-pow(sigmax, 2));
  printf("\nNilai m = %.2f \n", m);
  
  //menghitung c
  c=((sigmay*jumxkuadrat)-(sigmax*sigmaxy)) / ((angka*jumxkuadrat)-pow(sigmax, 2));
  printf("\nNilai c = %.2f \n", c);
  
  //menghitung prediksi
  printf ("\n========================================");
  printf ("\n======= PREDIKSI ==========\n");
  for (i=1; i<=n;i++){
      pre[i]=(m*x[i])+c;
      printf ("\nNilai Prediksi jika f[%d] = %.2f \n", x[i], pre[i]);
  }
  
  //menghitung error
   for (i=1; i<=n;i++){
   	error[i]=y[i]-pre[i];
   	if (error[i]<0){
          error[i]=pre[i]-y[i];
	  }
   	sigmaerror=sigmaerror + error[i];
   	err=sigmaerror/n;
   }
   
   //tampil error tiap prediksi
    printf ("\n================================================");
   printf ("\n========= SELISIH WAKTU (ERROR) ===============\n");
   for (i=1; i<=n;i++){
    	printf ("\nSelisih Waktu jika f(x)=%.2f yaitu %.2f \n", pre[i], error[i]);
}
   //tampil nilai error keseluruhan
   printf ("\n=========================");
  // printf ("\nNilai Sigma error = %f \n ", sigmaerror);
   printf ("\n====== ERROR ======\n");
   printf ("\nMaka nilai error sebesar %.2f \n ", err);
  
}

