#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<windows.h>
#include<iomanip>
#include <iostream>
#include<fstream> 
//==================================================== 
typedef struct SinhVien 
{ 
  char ma[11]; 
  char hoten[41]; 
  float dtb; 
}SV; 
//==================================================== 
typedef struct node{ 
  SV info;  
  node* pNext; 
}Node; 
//==================================================== 
typedef struct list{ 
  Node* pHead; 
  Node* pTail; 
}List; 
//==================================================== 
void NhapN(int &n) 
{ 
  do 
  { 
    printf("nhap so luong sinh vien (0<N): "); 
       scanf("%d",&n);   
       if( n<1 ) printf("Nhap sai\n"); 
  }while( n<1 ); 
} 
//==================================================== 
void Nhap1SV(SV &x) 
{ 
    printf("nhap ma sinh vien: "); 
    fflush(stdin); gets(x.ma); 
    
    printf("nhap ho ten sinh vien: "); 
    fflush(stdin); gets(x.hoten); 
     
    printf("nhap dtb sinh vien: "); 
    fflush(stdin); scanf("%f",&x.dtb); 
} 
//==================================================== 
void TieuDe()  
{ 
  printf("\n%-15s   %-39s %11s","MA SINH VIEN","HO TEN SINH VIEN","DTB"); 
  printf("\n%-15s   %-39s %11s","============","================","==="); 
} 
//====================================================    
void Xuat1SV(SV x) 
{ 
  printf("\n%-15s   %-39s %12.2f",x.ma,x.hoten,x.dtb); 
} 
//==================================================== 
void Init(List &l)  
{ 
  l.pHead = l.pTail = NULL; 
} 
//==================================================== 
int IsEmpty(List l) 
{ 
  return (l.pHead==NULL)  ; 
} 
//==================================================== 
Node* CreateNode (SV x) 
{ 
  node* p; 
  p  = new Node;  
  if(p == NULL) 
  { 
    printf("Loi cap phat vung nho!"); 
    getch(); 
    exit(0); 
  }   p->info = x; 
  p->pNext = NULL; 
  return p; 
} 
//==================================================== 
void AddHead(List &l, Node* p) 
{ 
  if(IsEmpty(l)) 
  { 
    l.pHead=l.pTail=p; 
  } 
  else 
  { 
    p->pNext=l.pHead; 
    l.pHead=p; 
  } 
} 
//==================================================== 
void AddTail(List &l, Node* p) 
{ 
  if(IsEmpty(l)) 
  { 
    l.pHead=l.pTail=p; 
  } 
  else 
  { 
    l.pTail->pNext = p; 
    l.pTail= p; 
  } 
} 
//==================================================== 
void InputList(List &l) 
{ 
  SV x; 
   
  int n;  NhapN(n); 
  for(int i=0; i<n; i++) 
  { 
    printf("Nhap sinh vien thu %d:\n ", i+1); 
    Nhap1SV(x); 
    Node* p=CreateNode(x); 
    AddTail(l, p); // them node vao cuoi DS 
  } 
} 
//==================================================== 
void ReadFile(const char* filename, List &l) 
{ 
    FILE *f = fopen(filename, "rt"); 
    if (f==NULL) 
    { 
        printf("\nKhong mo duoc file\n"); 
        getch(); 
        exit(0); 
    } 
  SV x; 
  int n; 
  fscanf(f,"%d\n",&n); 
  for(int i=0; i<n; i++) 
  { 
       fscanf(f,"%s ",&x.ma); 
       fscanf(f,"%f ",&x.dtb); 
       fgets(x.hoten, 40, f);  
       x.hoten[strlen(x.hoten)-1] = '\0'; 
               
       Node* p=CreateNode(x); 
    if(p) AddTail(l, p);  
  } 
    fclose(f); 
} 
//==================================================== 
void OutputList(List l) 
{ 
  TieuDe(); 
  for (Node* i = l.pHead; i!=NULL; i = i->pNext) 
    Xuat1SV(i->info); 
} //==================================================== 
void swap(SV &x, SV &y) 
{ 
  SV t = x; 
  x = y; 
  y = t; 
} 
//==================================================== 
void InterchangeSort_Giam_Hoten(List &l) 
{ 
   for (Node* i = l.pHead; i->pNext!=NULL; i = i->pNext) 
       for (Node* j = i->pNext; j!=NULL; j = j->pNext) 
         if(stricmp(i->info.hoten , j->info.hoten) <0) 
            swap(i->info,j->info); 
} 
//==================================================== 
void SelectionSort_Tang_MaSV(List &l) 
{ 
  for (Node* i = l.pHead; i->pNext!=NULL; i = i->pNext) 
  { 
       Node* vtmin = i; 
        for (Node* j = i->pNext; j!=NULL; j = j->pNext) 
          if(stricmp(vtmin->info.ma , j->info.ma) >0) 
           vtmin = j; 
       swap(vtmin->info, i->info); 
   } 
} 
//==================================================== 
Node* TimMaSV(List l, char maX[]) 
{ 
  for(Node* i=l.pHead; i!=NULL; i=i->pNext) 
    if(stricmp(i->info.ma , maX ) ==0) 
      return i; 
  return NULL; 
} 
//==================================================== 
void DeleteFirst(List &l) 
{
	if(l.pHead!=NULL)
	{
		if(l.pHead == l.pTail){
			delete l.pHead;
			l.pHead=l.pTail=NULL;}
		else
		{
	    	Node *pDel=l.pHead;
	    	l.pHead=l.pHead->pNext;
	    	delete pDel;
		}
	}
}
void XoaCuoi(List &l)
{
	Node *p;
	for(Node *k = l.pHead; k != NULL; k = k ->pNext)
	{
		if(k == l.pTail)
		{
			l.pTail = p;
			l.pTail ->pNext = NULL;
			delete k;
			return;
		}
		p = k;
	}
}
//==================================================== 
void ChenYsauX(List &l, Node* pX, SV Y)
{	
	Node* pY = CreateNode(Y);
	if(pX == l.pTail) 
	AddTail(l, pY);
	else{
		pY->pNext = pX->pNext;
		pX->pNext = pY;
	}
}
//==================================================== 
void menu(int &chon) 
{ 
  printf("\n\n=============MENU===================="); 
  printf("\n 1. InterchangeSort GIAM HOTEN"); 
  printf("\n 2. SelectionSort TANG MA SV"); 
  printf("\n 3. Tim SV co MA X"); 
  printf("\n 4. Xoa thong tin SV dau DS"); 
  printf("\n 5. Xoa thong tin SV cuoi DS"); 
  printf("\n 6. Nhap thong tin SV Y sau SV X"); 
  printf("\n\n 0. Thoat"); 
  printf("\n====================================="); 
  printf("\n\n Ban chon cong viec: "); scanf("%d", &chon); 
} 
//==================================================== 
int main() 
{ 
  List l; 
   
  Init(l); 
   
//  InputList(l); 
//  printf("\nDanh sach lien ket vua nhap: \n"); 
//  OutputList(l); 
 
  ReadFile("d:/sinhvien.txt", l); 
  printf("\nDanh sach lien ket doc tu file: \n"); 
  OutputList(l); 
	SV Y;
  char maX[11]; 
  Node* pX; 
  int chon; 
  do{ 
    menu(chon); 
    switch(chon) 
    { 
      case 1: 
        InterchangeSort_Giam_Hoten(l); 
        printf("\n\n\t\t========LIST Interchange Sort GIAM HOTEN================\n\n"); 
        OutputList(l); 
        break; 
       
      case 2: 
        SelectionSort_Tang_MaSV(l); 
        printf("\n\n\t\t========LIST Selection Sort TANG MA SV================\n\n");         
		OutputList(l); 
        break; 
           
      case 3:     
        printf("\n\n Nhap Ma SV can tim: ");  
        fflush(stdin); gets(maX); 
        pX = TimMaSV( l,  maX); 
        if(pX==NULL)   printf("\n Khong tim thay MaX: %s", maX); 
        else 
        { 
          printf("\nThong tin SV duoc tim thay:\n"); 
          TieuDe(); 
          Xuat1SV(pX->info); 
        } 
        break; 
	case 4:
	   DeleteFirst(l);
	   OutputList(l);
	   break; 
	   
	case 5:	 
		XoaCuoi(l); 
		OutputList(l); 
		break;
	case 6:
		printf("Nhap ma sinh vien X: ");
	//			printf("Nhap ma sv can tim: ");
				fflush(stdin);
				gets(maX);
				pX = TimMaSV(l, maX);
				if(pX == NULL)
					printf("K tim thay!");
				else{
					Nhap1SV(Y);
					ChenYsauX(l, pX, Y);
					printf("DS SV sau khi them sau X la: \n");
					OutputList(l);
				}
		break;
		
      default: chon=0; 
    } 
  }while(chon !=0); 
   
  return 0; 
} 
