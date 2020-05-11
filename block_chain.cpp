#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
struct blockchain
{
int data;
int previous_hash;
int current_hash;
int index;


struct blockchain *next;
};
char final_hash[50];
#define INT_BITS 32 
int binaryNum[32],counter=1;
int array[81],counter1=0;
void sum(int arr[])
{
	//cout<<endl<<"printing "<<endl;	
	int sum=0;	
	for(int is=31;is>=0;is--)
	{
		if(arr[is]!=0)
		{
			sum=sum+pow(2,is);		
		}
		//cout<<arr[is];
	}
	array[counter1]=sum;
	//cout<<array[counter1]<<endl;
	counter1++;
	
	
	//cout<<endl<<sum<<endl;
}
void verify(struct blockchain *first_block,struct blockchain *second_block)
{
	second_block=first_block->next;	
	int qwe=counter;
	while(qwe>1)
	{	
		
		if(first_block->current_hash==second_block->index)
			{
			cout<<"there is error"<<first_block->index;	
			cout<<"previous hash for second block"<<second_block->previous_hash<<endl<<"current hash for first block "<<first_block->current_hash;
			return;
			}
		qwe--;
		first_block=second_block;
		second_block=second_block->next;
	}
		cout<<"The blockchain is verified and has no error"<<endl;
}
int hex_dec(char hexVal[]) 
{    
    int len = strlen(hexVal); 
      
    // Initializing base value to 1, i.e 16^0 
    int base = 1; 
      
    int dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {    
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            dec_val += (hexVal[i] - 55)*base; 
          
            // incrementing base by power 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
} 
char A[9],B[9],C[9],D[9],E[9];
int W0[32],W1[32],W2[32],W3[32],W4[32],W5[32],W6[32],W7[32],W8[32],W9[32],
	W10[32],W11[32],W12[32],W13[32],W14[32],W15[32],W16[32],W17[32],W18[32],W19[32],
	W20[32],W21[32],W22[32],W23[32],W24[32],W25[32],W26[32],W27[32],W28[32],W29[32],
	W30[32],W31[32],W32[32],W33[32],W34[32],W35[32],W36[32],W37[32],W38[32],W39[32],
	W40[32],W41[32],W42[32],W43[32],W44[32],W45[32],W46[32],W47[32],W48[32],W49[32],
	W50[32],W51[32],W52[32],W53[32],W54[32],W55[32],W56[32],W57[32],W58[32],W59[32],
	W60[32],W61[32],W62[32],W63[32],W64[32],W65[32],W66[32],W67[32],W68[32],W69[32],
	W70[32],W71[32],W72[32],W73[32],W74[32],W75[32],W76[32],W77[32],W78[32],W79[32];
int binary[]={0,0,0,0,0,0,0,0};
char hexa[9];

int padded[512];
int dec_binary(int n)
{
	
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
	return i-1;
}
int shifting(int n,int d)
{
   return (n << d)|(n >> (INT_BITS - d)); 
} 
int function(int i,int B1,int C1,int D1)
{
	int answer;	
	if(i>=0 && i<20)
	{
		answer=(B1&C1)|((~B1)&D1);
	}
	else if(i>=20 && i<40)
	{
		answer=B1^C1^D1;
	}
	else if(i>=40 && i<60)
	{
		answer=(B1&C1)|(B1&D1)|(C1&D1);
	}
	else if(i>=60 && i<80)
	{
		answer=B1^C1^D1;
	}
	return answer;
}

int get_dec();
/*int calculate_W(int i)
{
	switch(i)
	{
		case 0:return get_dec(i);
		case 1: return W1;
		case 2:	return W2;
		case 3:	return W3;
		case 4:	return W4;
		case 5: return W5;
		case 6:	return W6;
		case 7:	return W7;
		case 8:	return W8;
		case 9:	return W9;
		case 10:return W10;
		case 11: return W11;
		case 12:	return W12;
		case 13:	return W13;
		case 14:	return W14;
		case 15: return W15;
		case 16:	return W16;
		case 17:	return W17;
		case 18:	return W18;
		case 19:	return W19;
		case 20:return W20;
		case 21: return W21;
		case 22:	return W22;
		case 23:	return W23;
		case 24:	return W24;
		case 25: return W25;
		case 26:	return W26;
		case 27:	return W27;
		case 28:	return W28;
		case 29:	return W29;
		case 30:return W30;
		case 31: return W31;
		case 32:	return W32;
		case 33:	return W33;
		case 34:	return W34;
		case 35: return W35;
		case 36:	return W36;
		case 37:	return W37;
		case 38:	return W38;
		case 39:	return W39;
		case 40:return W40;
		case 41: return W41;
		case 42:	return W42;
		case 43:	return W43;
		case 44:	return W44;
		case 45: return W45;
		case 46:	return W46;
		case 47:	return W47;
		case 48:	return W48;
		case 49:	return W49;
		case 50:return W50;
		case 51: return W51;
		case 52:	return W52;
		case 53:	return W53;
		case 54:	return W54;
		case 55: return W55;
		case 56:	return W56;
		case 57:	return W57;
		case 58:	return W58;
		case 59:	return W59;
		case 60:return W60;
		case 61: return W61;
		case 62:	return W62;
		case 63:	return W63;
		case 64:	return W64;
		case 65: return W65;
		case 66:	return W66;
		case 67:	return W67;
		case 68:	return W68;
		case 69:	return W69;
		case 70:return W70;
		case 71: return W71;
		case 72:	return W72;
		case 73:	return W73;
		case 74:	return W74;
		case 75: return W75;
		case 76:	return W76;
		case 77:	return W77;
		case 78:	return W78;
		case 79:	return W79;
	}
}*/
int calculate_temp()
{
	int i=0;
	int A1,B1,C1,D1,E1;
	long long int temp;
		A1=hex_dec(A);
		//cout<<A1<<endl;
		//int total=dec_binary(A1);
		A1=shifting(A1,5);
		//cout<<A1<<endl;
		B1=hex_dec(B);
		C1=hex_dec(C);
		D1=hex_dec(D);
		E1=hex_dec(E);
	while(i<80)
	{
		int foo=function(i,B1,C1,D1);
		char answer[9];
		if(i>=0 && i<20)
		{
		char answer[]="5A827999";
		}
		else if(i>=20 && i<40)
		{
		char answer[]="6ED9EBA1";
		}
		else if(i>=40 && i<60)
		{
			char answer[]="8F1BBCDC";
		}
		else if(i>=60 && i<80)
		{
			char answer[]="CA62C1D6";
		}
	
		int k=hex_dec(answer);
		temp=shifting(A1,5)+foo+E1+array[i]+k;	
		E1=D1;
		D1=C1;
		C1=shifting(B1,30);
		B1=A1;
		A1=temp;
		i++;
	}
		int A2=A1+hex_dec(A);
		int B2=B1+hex_dec(B);
		int C2=C1+hex_dec(C);
		int D2=D1+hex_dec(D);
		int E2=E1+hex_dec(E);
		
		int hashed_dec=shifting(A2,128)|shifting(B2,96)|shifting(C2,64)|shifting(D2,32)|E2;
		//cout<<endl<<hashed_dec<<endl;
		return hashed_dec;
		
}
int exor(int data1,int data2,int data3,int data4)
{
	if(data1==0 && data2==0 && data3==0 && data4==0)
	{
		return 0;
	}
	if(data1==1 && data2==1 && data3==1 && data4==1)
	{
		return 0;
	}
	return 1;
}
void convert_binary(int data)
{
	
	for(int i=0;data>0;i++)
	{
		binary[i]=data%2;
		data=data/2;
		
	}	

	
}
void convert_hex(int data)
{
	int temp, i = 1, j, r;
    
    
    temp = data;
    while (temp != 0)
    {
        r = temp % 16;
        if (r < 10)
            hexa[i++] = r + 48;
        else
            hexa[i++] = r + 55;
        temp = temp / 16;
    }
}

int hashf(struct blockchain *new_block)
{
	convert_binary(new_block->data);
	convert_hex(new_block->data);
	char hexr1[9]="67DE2A01";
	char hexr2[9]="BB03E28C";
	char hexr3[9]="011EF1DC";
	char hexr4[9]="9293E9E2";
	char hexr5[9]="CDEF23A9";
	int j=7,i=511;
	for(;j>=0;i--)
	{
		
		padded[i]=binary[j];	
		j--;
	}
	padded[i]=1;
	i--;
	for(;i>=0;i--)
	{
		padded[i]=0;
	}
	padded[3]=1;
	
	for(int d=0;d<32;d++)
	{
		W0[d]=padded[d];
		W1[d]=padded[d+32];
		W2[d]=padded[d+64];
		W3[d]=padded[d+96];
		W4[d]=padded[d+128];
		W5[d]=padded[d+160];
		W6[d]=padded[d+192];
		W7[d]=padded[d+224];
		W8[d]=padded[d+256];
		W9[d]=padded[d+288];
		W10[d]=padded[d+320];
		W11[d]=padded[d+352];
		W12[d]=padded[d+384];
		W13[d]=padded[d+416];
		W14[d]=padded[d+448];
		W15[d]=padded[d+480];

	}
	for(int mvr=0;mvr<32;mvr++)
	{
		W16[mvr]=exor(W13[mvr],W8[mvr],W2[mvr],W0[mvr]);
		W17[mvr]=exor(W14[mvr],W9[mvr],W3[mvr],W1[mvr]);
		W18[mvr]=exor(W15[mvr],W10[mvr],W4[mvr],W2[mvr]);
		W19[mvr]=exor(W16[mvr],W11[mvr],W5[mvr],W3[mvr]);
		W20[mvr]=exor(W17[mvr],W12[mvr],W6[mvr],W4[mvr]);
		W21[mvr]=exor(W18[mvr],W13[mvr],W7[mvr],W5[mvr]);
		W22[mvr]=exor(W19[mvr],W14[mvr],W8[mvr],W6[mvr]);
		W23[mvr]=exor(W20[mvr],W15[mvr],W9[mvr],W7[mvr]);
		W24[mvr]=exor(W21[mvr],W16[mvr],W10[mvr],W8[mvr]);
		W25[mvr]=exor(W22[mvr],W17[mvr],W11[mvr],W9[mvr]);
		W26[mvr]=exor(W23[mvr],W18[mvr],W12[mvr],W10[mvr]);
		W27[mvr]=exor(W24[mvr],W19[mvr],W13[mvr],W11[mvr]);
		W28[mvr]=exor(W25[mvr],W20[mvr],W14[mvr],W12[mvr]);
		W29[mvr]=exor(W26[mvr],W21[mvr],W15[mvr],W13[mvr]);
		W30[mvr]=exor(W27[mvr],W22[mvr],W16[mvr],W14[mvr]);
		W31[mvr]=exor(W28[mvr],W23[mvr],W17[mvr],W15[mvr]);
		W32[mvr]=exor(W29[mvr],W24[mvr],W18[mvr],W16[mvr]);
		W33[mvr]=exor(W30[mvr],W25[mvr],W19[mvr],W17[mvr]);
		W34[mvr]=exor(W31[mvr],W26[mvr],W20[mvr],W18[mvr]);
		W35[mvr]=exor(W32[mvr],W27[mvr],W21[mvr],W19[mvr]);
		W36[mvr]=exor(W33[mvr],W28[mvr],W22[mvr],W20[mvr]);
		W37[mvr]=exor(W34[mvr],W29[mvr],W23[mvr],W21[mvr]);
		W38[mvr]=exor(W35[mvr],W30[mvr],W24[mvr],W22[mvr]);
		W39[mvr]=exor(W36[mvr],W31[mvr],W25[mvr],W23[mvr]);
		W40[mvr]=exor(W37[mvr],W32[mvr],W26[mvr],W24[mvr]);
		W41[mvr]=exor(W38[mvr],W33[mvr],W27[mvr],W25[mvr]);
		W42[mvr]=exor(W39[mvr],W34[mvr],W28[mvr],W26[mvr]);
		W43[mvr]=exor(W40[mvr],W35[mvr],W29[mvr],W27[mvr]);
		W44[mvr]=exor(W41[mvr],W36[mvr],W30[mvr],W28[mvr]);
		W45[mvr]=exor(W42[mvr],W37[mvr],W31[mvr],W29[mvr]);
		W46[mvr]=exor(W43[mvr],W38[mvr],W32[mvr],W30[mvr]);
		W47[mvr]=exor(W44[mvr],W39[mvr],W33[mvr],W31[mvr]);
		W48[mvr]=exor(W45[mvr],W40[mvr],W34[mvr],W32[mvr]);
		W49[mvr]=exor(W46[mvr],W41[mvr],W35[mvr],W33[mvr]);
		W50[mvr]=exor(W47[mvr],W42[mvr],W36[mvr],W34[mvr]);
		W51[mvr]=exor(W48[mvr],W43[mvr],W37[mvr],W35[mvr]);
		W52[mvr]=exor(W49[mvr],W44[mvr],W38[mvr],W36[mvr]);
		W53[mvr]=exor(W50[mvr],W45[mvr],W39[mvr],W37[mvr]);
		W54[mvr]=exor(W51[mvr],W46[mvr],W40[mvr],W38[mvr]);
		W55[mvr]=exor(W52[mvr],W47[mvr],W41[mvr],W39[mvr]);
		W56[mvr]=exor(W53[mvr],W48[mvr],W42[mvr],W40[mvr]);
		W57[mvr]=exor(W54[mvr],W49[mvr],W43[mvr],W41[mvr]);
		W58[mvr]=exor(W55[mvr],W50[mvr],W44[mvr],W42[mvr]);
		W59[mvr]=exor(W56[mvr],W51[mvr],W45[mvr],W43[mvr]);
		W60[mvr]=exor(W57[mvr],W52[mvr],W46[mvr],W44[mvr]);
		W61[mvr]=exor(W58[mvr],W53[mvr],W47[mvr],W45[mvr]);
		W62[mvr]=exor(W59[mvr],W54[mvr],W48[mvr],W46[mvr]);
		W63[mvr]=exor(W60[mvr],W55[mvr],W49[mvr],W47[mvr]);
		W64[mvr]=exor(W61[mvr],W56[mvr],W50[mvr],W48[mvr]);
		W65[mvr]=exor(W62[mvr],W57[mvr],W51[mvr],W49[mvr]);
		W66[mvr]=exor(W63[mvr],W58[mvr],W52[mvr],W50[mvr]);
		W67[mvr]=exor(W64[mvr],W59[mvr],W53[mvr],W51[mvr]);
		W68[mvr]=exor(W65[mvr],W60[mvr],W54[mvr],W52[mvr]);
		W69[mvr]=exor(W66[mvr],W61[mvr],W55[mvr],W53[mvr]);
		W70[mvr]=exor(W67[mvr],W62[mvr],W56[mvr],W54[mvr]);
		W71[mvr]=exor(W68[mvr],W63[mvr],W57[mvr],W55[mvr]);
		W72[mvr]=exor(W69[mvr],W64[mvr],W58[mvr],W56[mvr]);
		W73[mvr]=exor(W70[mvr],W65[mvr],W59[mvr],W57[mvr]);
		W74[mvr]=exor(W71[mvr],W66[mvr],W60[mvr],W58[mvr]);
		W75[mvr]=exor(W72[mvr],W67[mvr],W61[mvr],W59[mvr]);
		W76[mvr]=exor(W73[mvr],W68[mvr],W62[mvr],W60[mvr]);
		W77[mvr]=exor(W74[mvr],W69[mvr],W63[mvr],W61[mvr]);
		W78[mvr]=exor(W75[mvr],W70[mvr],W64[mvr],W62[mvr]);
		W79[mvr]=exor(W76[mvr],W71[mvr],W65[mvr],W63[mvr]);
	}
	sum(W0);
	sum(W1);
	sum(W2);
	sum(W3);
	sum(W4);
	sum(W5);
	sum(W6);
	sum(W7);
	sum(W8);
	sum(W9);
	sum(W10);
	sum(W11);
	sum(W12);
	sum(W13);
	sum(W14);
	sum(W15);
	sum(W16);
	sum(W17);
	sum(W18);
	sum(W19);
	sum(W20);
	sum(W21);
	sum(W22);
	sum(W23);
	sum(W24);
	sum(W25);
	sum(W26);
	sum(W27);
	sum(W28);
	sum(W29);
	sum(W30);
	sum(W31);
	sum(W32);
	sum(W33);
	sum(W34);
	sum(W35);
	sum(W36);
	sum(W37);
	sum(W38);
	sum(W39);
	sum(W40);
	sum(W41);
	sum(W42);
	sum(W43);
	sum(W44);
	sum(W45);
	sum(W46);
	sum(W47);
	sum(W48);
	sum(W49);
	sum(W50);
	sum(W51);
	sum(W52);
	sum(W53);
	sum(W54);
	sum(W55);
	sum(W56);
	sum(W57);
	sum(W58);
	sum(W59);
	sum(W60);
	sum(W61);
	sum(W62);
	sum(W63);
	sum(W64);
	sum(W65);
	sum(W66);
	sum(W67);
	sum(W68);
	sum(W69);
	sum(W70);
	sum(W71);
	sum(W72);
	sum(W73);
	sum(W74);
	sum(W75);
	sum(W76);
	sum(W77);
	sum(W78);
	sum(W79);
	//cout<<"binary"<<endl;
	
	
	//cout<<endl<<"sum0"<<sum0<<endl;
	for(int qwe=0;qwe<9;qwe++)
	{
	A[qwe]=hexr1[qwe];
	B[qwe]=hexr2[qwe];
	C[qwe]=hexr3[qwe];
	D[qwe]=hexr4[qwe];
	E[qwe]=hexr5[qwe];
	}
	
	new_block->current_hash=calculate_temp();
	

	return new_block->current_hash;	
}
void add_new_block(struct blockchain *new_block,struct blockchain *prev_block)
{
	cout<<"Enter the data of the new block"<<endl;
	cin>>new_block->data;
	new_block->index=counter;
	new_block->previous_hash=prev_block->current_hash;
	counter++;
	new_block->current_hash=hashf(new_block);
	//cout<<new_block->current_hash;
}
int main()
{
	
	
	struct blockchain *first_block=NULL;
	first_block=(struct blockchain*)malloc(sizeof(struct blockchain));	
	struct blockchain *prev_block=NULL;
	prev_block=(struct blockchain*)malloc(sizeof(struct blockchain));		
	struct blockchain *new_block=NULL;
	new_block=(struct blockchain*)malloc(sizeof(struct blockchain));
	struct blockchain *mover_block=NULL;
	mover_block=(struct blockchain*)malloc(sizeof(struct blockchain));
	struct blockchain *new1_block=NULL;
	new1_block=(struct blockchain*)malloc(sizeof(struct blockchain));
	first_block->next=new_block;
	
	cout<<"Let us first create the genesis block"<<endl;
	cout<<"enter the Data of the genesis block"<<endl;
	cin>>first_block->data;
	first_block->previous_hash=1;
	first_block->index=counter;
	counter+=1;
	cout<<"Created hash for the genesis block:";
	first_block->current_hash=hashf(first_block);
	cout<<first_block->current_hash;
	cout<<endl<<"Previous hash for genesis block:"<<first_block->previous_hash<<endl;
	prev_block=first_block;
	int choice;
	label:
	new_block->next=new1_block;
	cout<<"1.Add a new block"<<endl<<"2.Verify the whole blockchain"<<endl<<"3.Exit"<<endl;	
	cin>>choice;
	switch(choice){
	case 1:
	{
		cout<<"Let us create a new block"<<endl;
		add_new_block(new_block,prev_block);
		cout<<"New has for this block is:"<<new_block->current_hash<<endl<<"Previous hash is:"<<new_block->previous_hash<<endl;
		prev_block=new_block;
		new_block=new1_block;
		goto label;			
		break;
	}
	case 2:
	{
		cout<<"Let us verify the whole block chain"<<endl;
		verify(first_block,mover_block);		
		goto label;		
		break;	
	}
	case 3:
	{
		cout<<"GoodBye.!"<<endl;
		break;	
	}
	}
}