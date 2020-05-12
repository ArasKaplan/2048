#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{
	int button,previous[100][100],oldboard[100][100], highscore, score,i,k,answer,status,i1,k1,j,counter,x,z,norandom,samecounter,button1;
	status=1;	
	srand(time(NULL));
	int board[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	button=1;
	norandom=0;
	highscore=0;
	score=0;
	samecounter=0;
	button1=0;
	printf("Yukariya kaydirmak icin W tusuna basiniz.\n");// Instruction paneli
	printf("Saga kaydirmak icin D tusuna basiniz.\n");
	printf("Sola kaydirmak icin A tusuna basiniz.\n");
	printf("Asagiya kaydirmak icin S tusuna basiniz.\n");
	printf("Son hareketi geri almak icin R tusuna basiniz.\n");
	printf("Kapatmak icin E tusuna basiniz.\n");
	printf("Tabloyu sifirlamak icin X tusuna basiniz. \n");		
	while(status==1)
	{
		printf("score = %d", score);
		printf("                highscore= %d\n",highscore);
		
		if(button!=0) //button kontrolunun varlýgý hareket geri alýndýktan sonra boþ matrise tekrar random sayý atanmasýný engelliyor
		{
			do 
			{
				i1=rand()%4;
				k1=rand()%4;//Random sayinin atanacagi tile seciliyor
				counter=0;
				if(board[i1][k1]==0)
					{
						j=rand()%11; //Oyunlarda kullanilan RNG(Random Number Generator)ýn basit bir versiyonu--
						if(j>9)     // --Herhangi bir sayýya kadar limit belirlenir--
							{		//Eðer sayý belirtilmis olasýlýktan fazlaysa ilk sartý--
								board[i1][k1]=4;		
								counter++;
							}
						else			//--Deðilse ikinci þartý yerine getirir.
							{
								board[i1][k1]=2;
								counter++;
							}
					}
			} while(counter!=1); //Oyunun açýlýþýnda matrisin tamamen boþ olmamasý için önce deðer atanmasý yapýlmalýdýr.
		}
		if(button==0) //Buttonun sýfýrlanmasý bir sonraki hamlede random atanmasýný saðlayacak
		{
			button=1;
		}
		for(i=0;i<4;i++)
		{
			printf("\n");
			for(k=0;k<4;k++)
			{
				if(i==i1 && k==k1 && norandom==0)//  norandom kontrolü yapýlmadýðýnda geri alýnan hamleden sonra --
				{
					printf("|%d*|",board[i][k]); //--Eski hamledeki random sayýnýn olduðu yere konan yýldýz--
				}
				else 							//--Yeni matristeki yere de konuyor.
				{
				printf("|%d|",board[i][k]);
				}
			}
		}
		printf("\n");
		printf("\n");
		printf("Tablonun bir el onceki hali");
		printf("\n");
		for(i=0;i<4;i++)
		{
			printf("\n");
			for(k=0;k<4;k++)
			{
				printf("|%d|",oldboard[i][k]);
			}
		}
		norandom=0;
		printf("\n");
		
		scanf(" %c",&answer);	
		if(answer=='w'|| answer=='W')
		{
			//PART0     R tuþuna basýldýðýnda geri dönmek için checkpoint güncellenir.
			for(i=0;i<4;i++)
			{
				for(k=0;k<4;k++)
				{
						oldboard[i][k]=board[i][k];
				}
			}
			
			//Öncelikle yapýlacak hamle yönünde sayýlarý sýralanýr
			
			for(z=0;z<3;z++)//PART1       
			{							//Bu iþlemin 3 kere tekrar edilmesinin nedeni 0,2,2,2 gibi durumlardýr
				for(k=0;k<4;k++)		//Eðer ki 3 den az tekrar edilseydi (Özellikle 0 dan sonra 3 sayý gelmesi durumunda)
				{						//2,2,0,2 gibi devam edebilirdi
					for(i=3;i>0;i--)
						{
							if(board[i-1][k]==0 && board[i][k]!=0) //Kendinden bir sonra gelecek sayý 0 ise kendisini o sayýyla deðiþiyor
							{
							board[i-1][k]=board[i][k];
							board[i][k]=0;
							}		
						}
				}
			}
			for(k=0;k<4;k++)//PART2
			{
				for(i=0;i<3;i++) 		//Burada ise sayý kendinden bir sonra gelecek sayý ile aynýysa sayý iki katýna çýkýyor öbürü de 0 oluyor.
				{
					if(board[i][k]!=0 && board[i][k]==board[i+1][k])
					{
						board[i][k]=board[i][k]*2;
						board[i+1][k]=0;
					}
				}
			}
			for(z=0;z<2;z++)//PART3
			{
				for(k=0;k<4;k++)          //Part2 den sonra bu part olmasaydý sayýlar arasýnda 0 lar olacaðý muhtemeldir.
				{
					for(i=3;i>0;i--)
						{
							if(board[i-1][k]==0 && board[i][k]!=0)
							{
							board[i-1][k]=board[i][k];
							board[i][k]=0;
							}		
						}
				}
			}
		}
		
		if(answer=='s' || answer=='S' )
		{
			for(i=0;i<4;i++)
			{
				for(k=0;k<4;k++)
				{
					oldboard[i][k]=board[i][k];
				}
			}			
			for(z=0;z<3;z++)// PART1
			{
				for(k=0;k<4;k++)
				{
					for(i=0;i<3;i++)
						{
							if(board[i+1][k]==0 && board[i][k]!=0)
							{
							board[i+1][k]=board[i][k];
							board[i][k]=0;
							}		
						}
				}
			}
			for(k=0;k<4;k++)//PART2
			{
				for(i=3;i>0;i--)
				{
					if(board[i][k]!=0 && board[i][k]==board[i-1][k])
					{
						board[i][k]=board[i][k]*2;
						board[i-1][k]=0;
					}
				}
			}
			for(z=0;z<2;z++)//PART3
			{
				for(k=0;k<4;k++)
				{
					for(i=0;i<3;i++)
						{
							if(board[i+1][k]==0 && board[i][k]!=0)
							{
							board[i+1][k]=board[i][k];
							board[i][k]=0;
							}		
						}
				}
			}
	
		}
		if(answer=='a' || answer=='A')
		{
			for(i=0;i<4;i++)
			{
				for(k=0;k<4;k++)
				{
					oldboard[i][k]=board[i][k];
				}
			}			
			for(z=0;z<3;z++)//PART1
			{
				for(i=0;i<4;i++)
				{
					for(k=3;k>0;k--)
					{
						if(board[i][k-1]==0 && board[i][k]!=0)
						{
							board[i][k-1]=board[i][k];
							board[i][k]=0;
						}
					}
				}
			}
			for(i=0;i<4;i++)//PART2
			{
				for(k=0;k<3;k++)
				{
					if(board[i][k]==board[i][k+1] && board[i][k]!=0)
					{
						board[i][k]=board[i][k]*2;
						board[i][k+1]=0;
					}
				}
			}
			for(z=0;z<3;z++)//PART3
			{
				for(i=0;i<4;i++)
				{
					for(k=3;k>0;k--)
					{
						if(board[i][k-1]==0 && board[i][k]!=0)
						{
							board[i][k-1]=board[i][k];
							board[i][k]=0;
						}
					}
				}
			}
		}
		if(answer=='d' || answer=='D')
		{
			for(i=0;i<4;i++)
			{
				for(k=0;k<4;k++)
				{
					oldboard[i][k]=board[i][k];
				}
			}		
			for(z=0;z<3;z++)//PART1
			{
				for(i=0;i<4;i++)
				{
					for(k=0;k<3;k++)
					{
						if(board[i][k+1]==0 && board[i][k]!=0)
						{
							board[i][k+1]=board[i][k];
							board[i][k]=0;
						}
					}
				}
			}
			for(i=0;i<4;i++)//PART2
			{
				for(k=3;k>0;k--)
				{
					if(board[i][k]==board[i][k-1] && board[i][k]!=0)
					{
						board[i][k]=board[i][k]*2;
						board[i][k-1]=0;
					}
				}
			}
			for(z=0;z<3;z++)//PART3
			{
				for(i=0;i<4;i++)
				{
					for(k=0;k<3;k++)
					{
						if(board[i][k+1]==0 && board[i][k]!=0)
						{
							board[i][k+1]=board[i][k];
							board[i][k]=0;
						}
					}
				}
			}
		}
		if(answer=='e' || answer=='E') //Büyük looptan çýkýþ saðlar
		{
			status=0;
		}
		if(answer=='r' || answer=='R')  //Önceki hamleye dönüþ
		{
			for(i=0;i<4;i++)
			{
				for(k=0;k<4;k++)
				{
					board[i][k]=oldboard[i][k];
				}
			}
			button=0;
			norandom=1;
		}
		samecounter=0;
		for(i=0;i<4;i++)//Önceki tablo ile þimdiki tablo ayný ise yeni random karakter atanmaz
		{
			for(k=0;k<4;k++)
			{
				if(oldboard[i][k]==board[i][k])
				{
					samecounter++;
				}
			}
		}
		if(samecounter==16)
		{
			button=0;
		}
		if(answer=='x' || answer=='X') //Yeni oyuna baþladýðýmýzda önceki tablonun da sýfýrlanmasý gerek
		{
			for(i=0;i<4;i++)
			{
				for(k=0;k<4;k++)
				{
					board[i][k]=0;
					oldboard[i][k]=0;
					button=1;
				}
			}
		}
		score=0;
		for(i=0;i<4;i++)
		{
			for(k=0;k<4;k++)
			{
				if(board[i][k]!=0)//Oyunun skor formülü
				{
					score=score+(((log2(board[i][k]))-1)*board[i][k]);
				}
			}
		}
		if(score>highscore)//highscore güncellemesi
		{
			highscore=score;
		}
		for(i=0;i<4;i++)
		{
			for(k=0;k<4;k++)
			{
				if(board[i][k]==2048)
				printf("Tebrikler Kazandiniz!");
			}
		}
	}
}

